<% StaticOn = 0 %>
<% TSLiveAllOn = 0 %>

<% CombinedOn = 0 %>
<% CompaniesOn = 0 %>
<% IndivsOn = 0 %>
<% SpaceOn = 0 %>
<% BldgAmenOn = 0 %>
<% AnnOn = 0 %>
<% List12On = 0 %>
<% BuildingInfoButtonOn = 0 %>

<% PDFOn = 0 %>
<% PDF2On = 0 %>
<% PDF3On = 0 %>
<% PDF4On = 0 %>
<% URLOn = 0 %>
<% URL2On = 0 %>
<% VideoOn = 0 %>
<% Video2On = 0 %>
<% List12URLOn = 0 %>
<% List12VideoOn = 0 %>

<% TSLiveAmenButtonOn = 0 %>
<% TSLiveTrafButtonOn = 0 %>
<% TSLiveTransitButtonOn = 0 %>

<% SlideshowOn = 0 %>
<% ScrollMsgOn = 0 %>
<% TouchSourceOn = 0 %>

<% TSLiveNewsOn = 0 %>
<% TSLiveWeatherOn = 0 %>
<% TSLiveStocksOn = 0 %>
<% TSLiveTrafficDisplayOn = 0 %>
<% TSLiveTransitDisplayOn = 0 %>
<% TwitterOn = 0 %>

<% SlideShowFull = 0 %> <!-- ===changing this variable has no effect for VERT, only one size used=== -->
<% MainLogoDisplay = 0 %>
<% SlideShowType = "pics" %>
<% BuildingLogo = "mainLogo.png" %>
	
	<%
	StrSQLQuery = "SELECT * FROM Content WHERE PropNum  = "&request.querystring("PropNum")&""
	Set qContent = Server.CreateObject("ADODB.recordset")
	qContent.Open strSQLQuery, conn, 3, 3
	%>

<%
StrSQLQuery = "SELECT * FROM Property WHERE PropNum  = "&request.querystring("PropNum")&""
Set qProperty = Server.CreateObject("ADODB.recordset")
qProperty.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT CompanyName as ListingName, CompanyName, Suite, Floor, Building, Phone, Description, CompImage as ListingImage, Logo, MapName as Title, Directions as Ranking, Directions as IndMemo, Directions as IndCustom1, Directions as IndCustom2, Type, CompanyID as ListingID, CompanyID FROM Companies WHERE PropNum  = "&request.querystring("PropNum")&" UNION ALL SELECT IndividualName as ListingName, CompanyName, Suite, Floor, iBuilding as Building, Phone, IndMemo as Description, IndImage as ListingImage, IndCustom2 as Logo, Title, Ranking, IndMemo, IndCustom1, IndCustom2, Type, IndId as ListingID, CompanyID FROM Individuals WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY ListingName ASC"
Set qCombList = Server.CreateObject("ADODB.recordset")
qCombList.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT CompanyName as ListingName, CompanyName, Suite, Floor, Building, Phone, Description, CompImage as ListingImage, Logo, MapName as Title, Directions as Ranking, Directions as IndMemo, Directions as IndCustom1, Directions as IndCustom2, Type, CompanyID as ListingID, CompanyID FROM Companies WHERE PropNum  = "&request.querystring("PropNum")&" UNION ALL SELECT IndividualName as ListingName, CompanyName, Suite, Floor, iBuilding as Building, Phone, IndMemo as Description, IndImage as ListingImage, IndCustom2 as Logo, Title, Ranking, IndMemo, IndCustom1, IndCustom2, Type, IndId as ListingID, CompanyID FROM Individuals WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY CompanyName ASC, Type ASC, Ranking DESC, ListingName ASC"
Set qStaticIndentedList = Server.CreateObject("ADODB.recordset")
qStaticIndentedList.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM Companies WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY CompanyName ASC"
Set qCompanies = Server.CreateObject("ADODB.recordset")
qCompanies.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM Individuals WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY IndividualName ASC"
Set qIndividuals = Server.CreateObject("ADODB.recordset")
qIndividuals.Open strSQLQuery, conn, 3, 3
%>
	
<%
StrSQLQuery = "SELECT Individuals.IndividualName, Individuals.Title, Companies.CompanyName, Individuals.Suite, Individuals.iBuilding, Individuals.Phone, Individuals.CompanyID, Individuals.IndID, Individuals.IndImage, Individuals.IndCustom1, Individuals.IndCustom2, Companies.CompanyID, Companies.Floor, Companies.Building	FROM Companies 	INNER JOIN Individuals ON Companies.CompanyID = Individuals.CompanyID	WHERE Individuals.IndividualName LIKE '"&request.querystring("letter")&"%' AND Individuals.PropNum  = "&request.querystring("PropNum")&"	ORDER BY Individuals.IndividualName ASC"
Set Names = Server.CreateObject("ADODB.recordset")
Names.Open strSQLQuery, conn, 3, 3
%>

	
<%
StrSQLQuery = "SELECT * FROM Space WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY Val(Suite) ASC"
Set LeaseSpace = Server.CreateObject("ADODB.recordset")
LeaseSpace.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM Images  WHERE PropNum  = "&request.querystring("PropNum")&" AND (StartDate <= #"&TodayDate&"# AND ExpireDate >= #"&TodayDate&"#) AND (Show = '1') ORDER by Val (Position) ASC"
Set ImageDisplay = Server.CreateObject("ADODB.recordset")
ImageDisplay.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM Amenities WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY AmenityName ASC"
Set qAmenities = Server.CreateObject("ADODB.recordset")
qAmenities.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM Announcements WHERE #"&TodayDate&"# >= DisplayStart AND PropNum  = "&request.querystring("PropNum")&"  ORDER BY StartDate ASC, StartTime ASC"
Set qMeetings = Server.CreateObject("ADODB.recordset")
qMeetings.Open strSQLQuery, conn, 3, 3
%>	

<%
StrSQLQuery = "SELECT * FROM List12 WHERE PropNum  = "&request.querystring("PropNum")&"  ORDER BY Text1 ASC"
Set List12List = Server.CreateObject("ADODB.recordset")
List12List.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM List12 WHERE PropNum  = "&request.querystring("PropNum")&" AND Text2 > ''  ORDER BY Text2 ASC"
Set URLList = Server.CreateObject("ADODB.recordset")
URLList.Open strSQLQuery, conn, 3, 3
%>

<%
StrSQLQuery = "SELECT * FROM List12 WHERE PropNum  = "&request.querystring("PropNum")&" AND Text3 > ''  ORDER BY Text3 ASC"
Set VideoList = Server.CreateObject("ADODB.recordset")
VideoList.Open strSQLQuery, conn, 3, 3
%>