<!DOCTYPE html>
<html>
<head>
	<meta charset="ISO-8859-1"><!-- utf-8 -->
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>TouchSource Directory</title>
<!-- Get the date -->
<% todaydate = FormatDateTime(Date(), 0)%>

<%
Session.timeout = 15
Set conn = server.createObject("ADODB.Connection")
conn.open "3339"
Set Session("MyDB_conn")=conn
%>

<!-- Initialize Variables and Run All Queries -->
<!--#include file ="dbQueries.inc"-->

<!-- Initialize pathways for standard /custom, css links, variables, button on/off logic, show/hide elements -->
<!--#include file ="configProgram.inc"-->

<!-- Button text, column header text, background images -->
<!--#include file ="textLabels.inc"-->
	
<!-- Refresh page every 60 mins if inactive -->
<script type="text/javascript">
	var timeoutHandle;
	function firstTimer() {
		console.debug('Initialize Timer - 60 mins');
		timeoutHandle = window.setTimeout(function() {
			if (stateInUse == false) {
				timeoutHandle = window.location.reload(); 
			} else if (stateInUse == true) {
				window.clearTimeout(timeoutHandle);
				secondTimer();
			}
		},3600000);
	}
	firstTimer();
	function secondTimer() {
		console.debug('Secondary Timer - 15 secs');
		var timeoutHandleShort = window.setTimeout(function(){
			if (stateInUse == false) {
				timeoutHandleShort = window.location.reload();
			} else if (stateInUse == true) {
				window.clearTimeout(timeoutHandleShort);
				secondTimer();
			}
		},15000);
	}
</script>

</head>

<body class="bgMain" onload="showTimeDate()">

<div id="closeSeq1" style="z-index: 10000; position: absolute; width: 100px; height: 100px; top: 0px; left: 980px; background: #fff; opacity: .0;"></div>

<button id="closeSeq2" onclick="closeWindow()" style="z-index: 10000; position: absolute; width: 100px; height: 100px; top: 1820px; left: 0px; display:none; opacity: 0;"></button>


<% IF StaticOn THEN %>

	<!--#include file ="staticHeaderFooter.inc"-->

	<!--#include file ="staticListings.inc"-->

	<!--#include file ="staticTSLive.inc"-->

<% ELSE %>

	<!-- Display Header -->
	<div class="pageHeader">
		<div id="currentDate" class="dateCont"></div>
		<div id="currentTime" class="timeCont"></div>
		<% IF MainLogoType = "Logo Only" AND MainLogoDisplay THEN %>
			<div class="mainLogoOnly">
				<div class='mainLogoPlacement'>
					<img src="<%response.write (CustomProgramPath)%><%response.write (BuildingLogo)%>" border="0">
				</div>
			</div>
		<% ELSE %>
			<% IF MainLogoDisplay THEN %>
				<div class="mainLogo">
					<div class='mainLogoPlacement'>
						<img src="<%response.write (CustomProgramPath)%><%response.write (BuildingLogo)%>" border="0">
					</div>
				</div>
			<% END IF %>
			<!-- Phase one method -->
			<div class="addressCont<% IF qContent("PropNameFont") > "" THEN%> addressResize<% END IF %>" data-fontsize="<%response.write (qContent("PropNameFont"))%>">
				<%response.write (qProperty("PropertyName"))%>
			</div>
			<!-- Phase 2 - Non scripted method below -->
			<!-- <div class="addressCont<% IF qContent("PropNameFont") > "" THEN%> addressResize<% END IF %>"> -->
				<!-- <div class="buildingName"><%response.write (qProperty("PropertyName"))%></div> -->
				<!-- <div class="buildingAddress"><%response.write (qProperty("Address"))%></div> -->
			<!-- </div> -->	
		<% END IF %>	
	</div>

	<!-- Display Buttons -->
	<!--#include file ="displayButtons.inc"-->

	<!-- Display Listing Area / Keyboard / Scroll and Back Button Logic -->
	<!--#include file ="contentListings.inc"-->

	<!-- Display TSLive Elements - Always shown, or accessible by buttons -->
	<!--#include file ="tsLive.inc"-->

	<!-- Display Standard TS Elements, Slideshow, ScrollMsg, TouchSource URL/Info, PDF Display, and ADA functionality -->
	<!--#include file ="tsStandards.inc"-->
	

<% END IF %>



<!-- Scripts -->
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery-2.1.3.min.js" language="javascript"></script>
	<!--<script src="<%response.write (TS41FilePath)%>scriptFiles/timeDate.js" type="text/javascript"></script>-->
	<script src="<%response.write (TS41FilePath)%>scriptFiles/idle-timer.js"></script>
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery-ui-1.9.2.custom.min.js" language="javascript"></script>
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery.cycle2.min.js" type="text/javascript"></script><!-- jquery.malsup.com/cycle2 -->
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery.cycle2.swipe.js" type="text/javascript"></script>
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery.cycle2.center.js" type="text/javascript"></script>
	<script src="scroll_detail.js" language="javascript"></script>
	<% IF StaticOn THEN %> 
		<script src="staticList.js" language="javascript"></script>
	<%ELSE%>
	<script src="transitions.js" language="javascript"></script>
	<!--<script src="jquery.instagram.js"></script>-->
	<%END IF%>
	<script src="<%response.write (TS41FilePath)%>scriptFiles/jquery.li-scroller.1.0.js" type="text/javascript"></script>
	<script src="<%response.write (TS41FilePath)%>scriptFiles/twitter-display.js" type="text/javascript"></script>
	<!--<script src="../scriptFiles/screenSaver.js" type="text/javascript"></script>-->


<% conn.close
set conn = nothing
%>

<script type = "text/javascript"> 
   function closeWindow(){ 
        self.close(); 
   } 
</script> 

<script type = "text/javascript"> 
   function closeSequence() {
   	$('#closeSeq2').fadeIn();
		setTimeout(function() {
			   $('#closeSeq2').fadeOut();
		}, 2000);
   }
   $(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#closeSeq1' ,function(){
	closeSequence();
});
</script> 

</body>
</html>
