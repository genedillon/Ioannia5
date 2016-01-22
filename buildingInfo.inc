<!-- start buildingInfo.inc - shows in header -->
<% IF BuildingInfoDisplayOn THEN %>
<div id="buildingInfoBox">	
	<!-- <div class="vertLine<% IF TSLiveAllOn = 0 THEN %> vertLineSlideNoTSL<% IF SlideshowOn = 0 THEN %> vertLineNo<% END IF %><% END IF %>"></div> -->
	<div class="vertLine"></div>
	<div class="bldgInfo<% IF TSLiveAllOn = 0 THEN %> bldgInfoNoTSL<% END IF %>">
		<div class="mgmtCont">
		<%response.write (ManagementHeader)%><br>
			<% IF qProperty("ManagementContact") > "" THEN %><%response.write (qProperty("ManagementContact"))%><% END IF %>
			<% IF qProperty("ManagementCompany") > "" THEN %><BR><%response.write (qProperty("ManagementCompany"))%><% END IF %>
			<% IF qProperty("ManagementLocation") > "" THEN %><BR><%response.write (qProperty("ManagementLocation"))%><% END IF %>
			<% IF qProperty("ManagementPhone") > "" THEN %><BR><%response.write (qProperty("ManagementPhone"))%><% END IF %>
			<% IF qProperty("EmergencyContact") > "" THEN %><BR><%response.write (qProperty("EmergencyContact"))%><% END IF %>
			<% IF qProperty("Description") > "" THEN %><BR><%response.write (qProperty("Description"))%><% END IF%>
		</div>
		<div class="leaseCont">
		<%response.write (LeasingHeader)%><br>
			<% IF qProperty("LeasingContact") > "" THEN %><%response.write (qProperty("LeasingContact"))%><% END IF %>
			<% IF qProperty("LeasingCompany") > "" THEN %><BR><%response.write (qProperty("LeasingCompany"))%><% END IF %>
			<% IF qProperty("LeasingLocation") > "" THEN %><BR><%response.write (qProperty("LeasingLocation"))%><% END IF %>
			<% IF qProperty("LeasingPhone") > "" THEN %><BR><%response.write (qProperty("LeasingPhone"))%><% END IF %>
			<% IF qProperty("LeasingLine5") > "" THEN %><BR><%response.write (qProperty("LeasingLine5"))%><% END IF %>
		</div>
	</div>
</div>
<% END IF %>

<!-- end buildingInfo.inc -->