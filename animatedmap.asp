<%
'/*
'*Tokenize the query string and extract values
'*Essentially build the GET request from the URL
'*@TODO: Refactor searchTable and searchID into request class
'*/
queryString = Request.querystring()
index = InStr(queryString, "=")
searchTable = Left(queryString, index-1)
searchID = Mid(queryString, index+1)
'/*
'*Create a connection and a session for accessing the db
'*/
Set connection = Server.CreateObject("ADODB.Connection")
connection.Open "3339"
Session.timeout = 15
Set Session("MyDB_conn")=connection
'/*
'*Request for data based on key given in GET variables
'*@TODO: Refactor to switch statement
'*/
If searchTable = "Companies" Then
	'/*
	'*Set query, create a record set, execute query, and count results
	'*@TODO: collapse ifelse to only contain logic for creating sql query to reduce code duplication
	'*@note: reassigning queryString
	'*/
	queryString = "SELECT * FROM Companies WHERE CompanyID LIKE "&"'"&searchID&"'"
	Set qCompanies = Server.CreateObject("ADODB.recordset")
	qCompanies.Open queryString, connection, 3, 3
	count = qCompanies.recordcount
	'/*
	'*Many to one mapping of corner cases empty set to "empty"
	'*/
	suite = qCompanies("building")
	building = qCompanies("phone")
  	company = qCompanies("CompanyName")
	If building = "" Or IsEmpty(building) Or IsNull(building) Then
		building = "empty"
	End If
ElseIf searchTable = "Individuals" Then
	'/*
	'*Set query, create a record set, execute query, and count results
	'*@note: reassigning queryString
	'*/
	queryString = "SELECT * FROM individuals WHERE IndID LIKE "&"'"&searchID&"'"
	Set qIndividuals = Server.CreateObject("ADODB.recordset")
	qIndividuals.Open queryString, connection, 3, 3
	count = qIndividuals.recordcount

	suite = qIndividuals("Suite")
	building = qIndividuals("iBuilding")
	If building = "" Or IsEmpty(building) Or IsNull(building) Then
		building = "empty"
	End If
End If
'/*
'*Close all connections and release variables for garbage collection
'*/
connection.close
set connection = nothing
'/*
'*Write the final response to the server
'*/
%>
<div id="infobox-wrapper" style="opacity: 0.0; position: absolute; z-index: 100;"></div>
<div id='mapvar_company' class='hidden'><% Response.write(company) %></div>
<div id='mapvar_bldg' class='hidden'><% Response.write(building) %></div>
<div id='mapvar_suite' class='hidden'><% Response.write(suite) %></div>
<% '/*
'*Move the scripts to the bottom of the body so they are non blocking and set canvas size
'*/ %>
<canvas id="canvas" style="border:1px solid #d3d3d3;">Your browser does not support the HTML5 canvas tag.</canvas>
<% '/*
'*Load the scripts files before the driver
'*/ %>
<script language="javascript" src="scriptFiles/infobox/infobox.js"></script>
<script language="javascript" src="scriptFiles/indexScripts.js"></script>
<% '/*
'*Load the driver to launch the app
'*/ %>
<script language="javascript" src="scriptFiles/indexDriver.js"></script>
