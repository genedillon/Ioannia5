<%@ Language="VBScript" %>
<%
Option Explicit
%>
<!DOCTYPE html>
<html lang="en-gb">
<head>
	<meta charset="ISO-8859-1"><!-- utf-8 -->
	<title>Twitter API Display</title>
	<script language="javascript" src="http://127.0.0.1/TS41/scriptFiles/jquery-2.1.3.min.js"></script>
	<script language="javascript" src="http://127.0.0.1/TS41/scriptFiles/twitter-display.js"></script>
	<link rel="stylesheet" type="text/css" href="twitter.css" media="screen" />
</head>

<body>
	<% Server.Execute("tweets.asp") %>
</body>
</html>