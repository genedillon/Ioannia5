<!-- begin staticHeaderFooter.inc -->
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
				<!-- <div class="<% IF StaticOn THEN%>mainLogoBoxAddToAddress<%ELSE%>bldgInfo<% END IF %>"> -->
				<div class="mainLogo">
					<div class="mainLogoPlacement">
						<!-- Image size should be constrained to ?W by ?H -->
						<!-- <img src="<%response.write (CustomProgramPath)%><%response.write (BuildingLogo)%>" border="0" class="mainLogoHeaderMargin"> -->
						<img src="<%response.write (CustomProgramPath)%><%response.write (BuildingLogo)%>" border="0">
					</div>
				</div>
			<% END IF %>
			<div class="addressCont<% IF qContent("PropNameFont") > "" THEN%> addressResize<% END IF %>">
				<!-- Phase 1 method -->
				<div class="addressText">
					<%response.write (qProperty("PropertyName"))%>
				</div>
			</div>
		<% END IF %>
	</div>



<!-- Mgmt and Leasing Info at bottom if no TSLive -->
<% IF BuildingInfoDisplayOn AND (qContent("TSLive") = 0) THEN %>
		<!-- buildinginfo.inc-->
<% END IF %>	


<!-- Slideshow, Scrolling Message and TS Info always visible -->
<% IF SlideshowOn THEN %>
	<div class="slideWrapper">	
	<div id="tsSlideshow" class="cycle-slideshow <%response.write(SlideShowType)%> activeRight" 
				data-cycle-speed="400"     
				data-cycle-timeout="8000"    
				data-cycle-center-horz=true 
				data-cycle-center-vert=true 
				data-cycle-swipe=true 
				data-cycle-swipe-fx=scrollHorz>
		<%IF ImageDisplay.recordcount > 0 THEN%>
		<% do until ImageDisplay.EOF%>
		<img src="<%response.write (CustomProgramPath)%><%response.write(ImageDisplay("Filename"))%>"<%IF ImageDisplay.recordcount = 1 THEN%> data-cycle-timeout="720000"<%ELSE%><%IF ImageDisplay("Duration") > "" THEN%> data-cycle-timeout="<%response.write(ImageDisplay("Duration"))%>000"<%END IF%><%END IF%> >

		<% ImageDisplay.movenext
		loop %>
		<%ELSE%>
		<img src="<%response.write (TemplatePath)%>images/stock1.jpg">
		<img src="<%response.write (TemplatePath)%>images/stock2.jpg">
		<%END IF%>
		</div>	
	</div>
<% END IF %>


<!-- PDF Modal -->
<iframe id="pdfWindow" src="" frameborder="0" scrolling="no"></iframe>
<div id="pdfMask"></div>
<div class="closePDF">Close</div>


<% IF ScrollMsgOn THEN %>
	<!-- Scrolling Message -->
	<div id="scrollingMessage"<% IF TSLiveAllOn = 0 THEN %> class="scrollNoTSLive"<% END IF %>>
		<ul id="tickerMessage">
			<li><%response.write (qProperty("ScrollMsg"))%></li>
		</ul>
	</div>
<% END IF %>

<% IF TwitterOn THEN %>
	<div id="tweetsCont"></div>
	<% Server.Execute("tweets.asp") %>
	<svg class="twitterIcon"><use xlink:href="#twitterSVG" /></svg>
<% END IF %>

<% IF TouchSourceOn THEN %>
	<div class="tsInfo<% IF TSLiveAllOn = 0 THEN %> tsInfoNoTSLive<% END IF %>">
		<%response.write (TouchSourceLabel)%>
	</div>
<% END IF %>

<!-- ============================= BEGIN SVG ICON CODE ================================ -->
<svg xmlns="http://www.w3.org/2000/svg" style="display:none">
	<symbol id="twitterSVG" viewBox="0 0 30 30">
		<path d="M14.3,11.3c-0.1-0.5-0.6-2.5,1.2-4.7c1.1-1.4,4.8-3,7.8,0c0.8-0.2,1.6-0.4,3.3-1.3
		c-0.6,1.9-2.3,2.8-2.3,2.8c1,0,2-0.4,3-0.8c0,0-1.2,1.7-2.6,2.7c0.3,8.2-6.6,17.9-18.5,15.2c-1.5-0.3-2.9-1-4.5-1.9
		c1.7,0,4.4,0.3,7.7-2.2c-1.6-0.1-3.8-0.8-4.9-3.7c0.9,0.1,1.4,0.1,2.4-0.1c-1.8-0.4-4.2-2.2-4.1-5.2c0.5,0.3,1.6,0.6,2.3,0.6
		c-1-0.5-3.5-3.4-1.6-7C6,8.8,9.7,11.1,14.3,11.3z"/>
	</symbol>
</svg>

<!--end staticHeaderFooter.inc -->

