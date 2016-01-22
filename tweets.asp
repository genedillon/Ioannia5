<%@ Language="VBScript" %><%

Option Explicit

' Configure Twitter API authentication.
' TODO: Enter your own consumer key and consumer secret here so the code can log you in.
' Get your consumer key and consumer secret here: https://dev.twitter.com/apps
' NOTE: These are dummy values and will not work.

const TWITTER_API_CONSUMER_KEY = 	"1bVnZCWSBVwh92XMkgU0fUkXo"
const TWITTER_API_CONSUMER_SECRET = 	"oIZNve2d5rA9kh472Zr3AmuRsVrb7wQFLzQg77eA2H5yFf9geh"
'const TWITTER_API_CONSUMER_KEY = 	"6EjmluEUiRGcYOgySUyO1XvbP"
'const TWITTER_API_CONSUMER_SECRET = 	"xzakLnSY6q0E2VtDOIytYQNuCIUEXcHctIRdOpa86QIDKD2Mwc"
'
' Twitter API client.
Dim objASPTwitter

' Tweets will be obtained by parsing data from Twitter API.
Dim objTweets

' database vars
Dim conn, StrSQLQuery, twitterFeeds, thisFeedDateLimit
Dim contCount : contCount = 0

' get _mode_ from query string ...
Dim mode : mode = LCase(Request.QueryString("mode"))
' write _mode_ as attribute of tweetStore div for transmittal to display.js
If IsEmpty(mode) Or IsNull(mode) Or (mode = "") Then
	mode = "slide" ' default mode
End If
'Response.write("Tweets.asp debug: query string mode = " & mode & "<br><br>")

Call Page_Load

Sub Page_Load()
	'On Error Resume Next

	Set objASPTwitter = New ASPTwitter
	Call objASPTwitter.Configure(TWITTER_API_CONSUMER_KEY, TWITTER_API_CONSUMER_SECRET)

	Call objASPTwitter.Login
	'Response.Write "<textarea>" & objASPTwitter.strBearerToken & "</textarea>"
	'objASPTwitter.strBearerToken = "**** caching reccomended ***"

	Call GetTwitterParams
End Sub

Sub GetTwitterParams
	' get parameters from DB and prequalify prior to accessing Twitter API
	Session.timeout = 15
	Set conn = server.createObject("ADODB.Connection")
	conn.open "Update"
	Set Session("MyDB_conn")=conn

	StrSQLQuery = "SELECT * FROM List12 WHERE (Text1 > '')"
	Set twitterFeeds = Server.CreateObject("ADODB.recordset")
	twitterFeeds.Open strSQLQuery, conn, 3, 3

	'Response.write "*DEBUG: twitterFeeds = " & twitterFeeds.recordcount & "<br>"
	Response.write("<div id='tweetStore' attr-mode='" & mode & "'>")

	If twitterFeeds.recordcount = 0 Then
		Response.write("<div class='tweetContainer' attr-count='1' >")
		Response.write("<div class='tweet'>")
		Response.write("Sorry. There are no Tweets available at this time. (db)")
		Response.write("</div></div>")
	Else
		dim recCount : recCount = 1

		do until twitterFeeds.EOF
			Dim thisScreenName : thisScreenName = twitterFeeds("Text1")
			Dim thisTweetCount : thisTweetCount = twitterFeeds("Text5")
			Dim thisFeedIncRT : thisFeedIncRT = LCase(twitterFeeds("Text6")) ' include retweets or not
			Dim thisFeedExcReplies : thisFeedExcReplies = LCase(twitterFeeds("Text7")) ' exclude replies or not
			thisFeedDateLimit = LCase(twitterFeeds("Text8")) ' limit tweets displayed by date
			Dim skipIter : skipIter = False 'causes iteration to abort when error is encountered

			'Response.write(" DEBUG: recCount = " & recCount & " >>> ")
			'Response.write "<div class='debugdata'>*DEBUG " & thisRecCount & "<br>thisScreenName = " & thisScreenName & "<br>thisTweetCount = " & thisTweetCount & "<br>thisFeedRT = " & thisFeedRT & "</div>"
			'Response.write("<div id='tweetContainer" & recCount & ">")

			' ERROR DISPLAY: use this for displaying errors
			'Response.write("<div id='tweetContainer' attr-count='" & thisTweetCount & "'>")

			' qualify database settings
			If IsEmpty(thisScreenName) Or IsNull(thisScreenName) Or thisScreenName = "@" Then
				Response.write("<p class='dataerror'>*ERROR: The Screen Name is empty in List12 record #" & recCount & ". Skipping.</p>")
				skipIter = True
			Else

				If IsEmpty(thisTweetCount) Or IsNull(thisTweetCount) Or Not IsNumeric(thisTweetCount) Then
					Response.write("<p class='dataerror'>*ERROR: The Tweet count is empty or not a number in List12 record #" & recCount & ". Using 10.</p>")
					thisTweetCount = 10 ' default value: 10 tweets
					'skipIter = True
				End If

				'check retweets for empty or null
				If IsEmpty(thisFeedIncRT) Or IsNull(thisFeedIncRT) Then
					Response.write("<p class='dataerror'>*ERROR: The Retweet setting is empty or invalid in List12 record #" & recCount & ". Using 0 = No retweets.</p>")
					thisFeedRT = 0 ' default value: don't include retweets
					'skipIter = True
				End If

				'check retweets for empty or null
				If thisFeedIncRT <> "1" And thisFeedIncRT <> "0" Then
					Response.write("<p class='dataerror'>*ERROR: The Retweet setting must contain 1 (true) or 0 (false) in List12 record #" & recCount & ". Using 0 = No retweets.</p>")
					thisFeedRT = 0 ' default value: don't include retweets
					'skipIter = True
				End If

				'check replies for empty or null
				If IsEmpty(thisFeedExcReplies) Or IsNull(thisFeedExcReplies) Then
					Response.write("<p class='dataerror'>*ERROR: The Include Replies setting is empty or invalid in List12 record #" & recCount & ". Using 1 = No replies retrieved.</p>")
					thisFeedExcReplies = 1 ' default value: exclude replies
					'skipIter = True
				End If

				'check replies for 1 or 0
				If thisFeedExcReplies <> "1" And thisFeedExcReplies <> "0" Then
					Response.write("<p class='dataerror'>*ERROR: The Include Replies setting must contain 1 (true) or 0 (false) in List12 record #" & recCount & ". Using 1 = No replies retrieved.</p>")
					thisFeedExcReplies = 1 ' default value: exclude replies
					'skipIter = True
				End If
			End If

			' access the Twitter API
			If skipIter = False Then
				Response.write("<div class='tweetContainer' attr-count='" & thisTweetCount & "' >")
				Call LoadTweetsUserTimeline(thisScreenName, thisTweetCount, thisFeedIncRT, thisFeedExcReplies)
				Response.write("</div><!-- close container" & recCount &  " -->")
			End If

			' ERROR DISPLAY: Use write stmnt to display errors 
			'Response.write("</div><!-- close container" & recCount &  " -->")

			recCount = recCount + 1
			twitterFeeds.movenext
		loop

	End If

	Response.write("</div><!-- close tweetStore -->")

	conn.close
	set conn = nothing
End Sub

Sub LoadTweetsUserTimeline(thisName, thisTweetCount, thisFeedIncRT, thisFeedExcReplies)
	' Configure the API call.
	On Error Resume Next

	Dim sScreenName : sScreenName = thisName
	Dim iCount : iCount = thisTweetCount
	Dim bIncludeRTs : bIncludeRTs = thisFeedIncRT
	Dim bExcludeReplies : bExcludeReplies = thisFeedExcReplies
	'Dim bExcludeReplies : bExcludeReplies = True
	
	'Response.write("**sScreenName: " & sScreenName & "<br>**iCount: " & iCount & "<br>**bIncludeRTs: " & bIncludeRTs & "<br>**bExcludeReplies: " & bExcludeReplies & "<br><br>")

	Set objTweets = objASPTwitter.GetUserTimeline(sScreenName, iCount, bExcludeReplies, bIncludeRTs)

	If IsNull(objTweets.length) Then
		Response.write("<div class='tweeterror'>**ERROR: There is a problem with the screenname " & sScreenName & "</div>")
	ElseIf Not IsObject(objTweets) Then
		Response.write("<div class='tweeterror'>**ERROR: The User Name " & sScreenName & " is invalid or some other error has ocurred.</div>")
	Else
		Dim screenName, tweetText, tweetDate, displayDate
		Dim tweetDateAdj, tweetDateConv, todaysdate
		Dim oTweet

		Dim len : len = objTweets.length

		If len = 0 Then
			' this error is written to tweetStore as a tweet that will be posted as a normal tweet
			Response.write("<div class='tweet'>Sorry, there are no tweets from this user.</div>")
		Else
			'contCount = contCount + 1
			'Response.write(" **contCount = " & contCount & "<br>")

			For Each oTweet In objTweets
				If IsTweet(oTweet) Or IsRetweet(oTweet) Then
					'Response.write("<div class='tweet'>") ' test position; see *** below for normal
					screenName = oTweet.user.screen_name
					tweetText = oTweet.text
					tweetDate = oTweet.created_at

					' display only tweets from today if set in db
					If thisFeedDateLimit = "today" Then
						'Response.write("thisFeedDateLimit is today<br>")
						'Response.write("tweetDate: " & tweetDate & "<br>")
						tweetDateAdj = Mid(tweetDate,5,3) & "-" & Mid(tweetDate,9,2) & "-" & Right(tweetDate,4)
						'Response.write("tweetDateAdj: " & tweetDateAdj & "<br>")
						tweetDateConv = DateValue(Mid(tweetDate,5,3) & "-" & Mid(tweetDate,9,2) & "-" & Right(tweetDate,4))
						'Response.write("tweetDateConv: " & tweetDateConv & "<br>")

						todaysdate = Date
						'Response.write("todaysdate: " & todaysdate & "<br>")

						If tweetDateConv <> todaysdate Then
							'Response.write("<b>The dates DON'T match</b><br><br>")
							'Response.write("</div><!-- close tweet -->")
							Exit For
						Else
							'Response.write("<b>The dates match!</b><br><br>")
						End If

					End If

					' remove urls from posted text'
					dim httpCharStart : httpCharStart = InStr(tweetText,"http")
					'Response.write("httpCharEnd = " & httpCharEnd & "<br>")
					If httpCharStart > 0 Then
						tweetText = Left(tweetText,httpCharStart-1)
					End If

					' remove unnecessary ?s and ??s from posted text -- Done in twitter-display.js

					'Response.write("tweetDate: " & tweetDate & "<br>")
					displayDate = Mid(tweetDate,1,10) & ", " &  Right(tweetDate,4) & " - " & Mid(tweetDate,12,5)

					Response.write("<div class='tweet'>") ' normal position, see *** above
					Response.write("<span class='tweetScreenName'>" & screenName & "</span> - <br>" & tweetText & " - " & "<span class='tweetDate'>" & displayDate & "</span>")
					Response.write("</div><!-- close tweet -->")
				End If
				
			Next
			
		End If
	End If

End Sub


'''''''''''''''''''''''''''''''''''''''''''
' The following is from the sample code

Sub WriteTweetsUserTimeline()
	%>
	<h2>User Timeline</h2>

	<ul class="Tweets"><%

	If objTweets.length = 0 Then
		%><li>Tweets.asp: No tweets.</li><%
	End If
	
	If Err Then
		%><li>Tweets.asp: invalid API response.</li><%
	End if

	Dim oTweet
	For Each oTweet In objTweets
		
		' Workarounds.
		' JSON parser bug workaround:
		'	- API can return invalid tweets, probably due to characters.
		' Twitter API bugs:
		'	- Filtering by the API can return additional invalid items, and seems to filter only after retrieving the requested number of items, so you get less than you asked for.
		'	- API sometimes seems to exclude replies even if that filter is not set, resulting in "*up to* count" responses and associated issues.
		If IsTweet(oTweet) Or IsRetweet(oTweet) Then
			
			' NOTE: A JSON viewer can be useful here: http://www.jsoneditoronline.org/
			Dim screen_name, text
			If Not IsRetweet(oTweet) Then
				screen_name = oTweet.user.screen_name
				text = URLsBecomeLinks(oTweet.text)
			Else 
				screen_name = oTweet.retweeted_status.user.screen_name
				text = URLsBecomeLinks(oTweet.retweeted_status.text)
			End If
		
			%>
		<li>
			<b class="screen_name">@<%= screen_name %></b>
			<span class="text"><%= text %></span>
		</li><%
		
		End If
		
	Next

	%>
	</ul><%

	Response.Flush()
End Sub

' Search

Sub LoadTweetsSearch()
	' Configure the API call.
	Dim sQuery : sQuery = "#news"
	Dim iCount : iCount = 10
	Dim lMaxID : lMaxID = Null
	
	Set objTweets = objASPTwitter.GetSearch(sQuery, iCount, lMaxID)
End Sub

Sub WriteTweetsSearch()
	%>
	<h2>Search</h2>

	<ol id="Tweets"><%

	If objTweets.statuses.length = 0 Then
		%><li>Tweets.asp: No tweets.</li><%
	End If
	
	If Err Then
		%><li>Tweets.asp: invalid API response.</li><%
	End if

	Dim oTweet
	For Each oTweet In objTweets.statuses
		
		' Workarounds.
		' JSON parser bug workaround:
		'	- API can return invalid tweets, probably due to characters.
		' Twitter API bugs:
		'	- Filtering by the API can return additional invalid items, and seems to filter only after retrieving the requested number of items, so you get less than you asked for.
		'	- API sometimes seems to exclude replies even if that filter is not set, resulting in "*up to* count" responses and associated issues.
		If IsTweet(oTweet) Or IsRetweet(oTweet) Then
			
			' NOTE: A JSON viewer can be useful here: http://www.jsoneditoronline.org/
			Dim screen_name, text
			If Not IsRetweet(oTweet) Then
				screen_name = oTweet.user.screen_name
				text = URLsBecomeLinks(oTweet.text)
			Else 
				screen_name = oTweet.retweeted_status.user.screen_name
				text = URLsBecomeLinks(oTweet.retweeted_status.text)
			End If
		
			%>
		<li>
			<b class="screen_name">@<%= screen_name %></b>
			<span class="text"><%= text %></span>
		</li><%
		
		End If
		
	Next

	%>
	</ol><%

	Response.Flush()
End Sub

Function IsTweet(ByRef oTweet)
	IsTweet = HasKey(oTweet, "user") 
End Function

Function IsRetweet(ByRef oTweet)
	IsRetweet = HasKey(oTweet, "retweeted_status") 
End Function

Function IsReply(ByRef oTweet)
	IsReply = Not oTweet.get("in_reply_to_user_id") = Null
End Function

Function HasKey(ByRef oTweet, ByVal sKeyName)
	HasKey = Not CStr("" & oTweet.get(sKeyName)) = ""
End Function

Function URLsBecomeLinks(sText)
	' Wrap URLs in text with HTML link anchor tags.
	Dim objRegExp
	Set objRegExp = New RegExp
	objRegExp.Pattern = "(http://[^\s<]*)"
	objRegExp.Global = True
	objRegExp.ignorecase = True
	UrlsBecomeLinks = "" & objRegExp.Replace(sText, "<a href=""$1"" target=""_blank"">$1</a>")
	Set objRegExp = Nothing
End Function

%>
<!--#include file="Libs\ASPTwitter.asp"-->