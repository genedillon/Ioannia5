<%@ Language="VBScript" %>
<%
' a short version of Twitter.asp containing only the essentials;
' called by the twitter-display.js doReload function to avoid meta tags, etc, in the body
Option Explicit
%>

<head>
	<meta charset="ISO-8859-1">
</head>

<% Server.Execute("tweets.asp") %>

<script language="javascript">
	init();
</script>