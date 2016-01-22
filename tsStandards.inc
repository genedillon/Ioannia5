<!-- Slideshow, Scrolling Message and TS Info always visible -->
<% IF SlideshowOn THEN %>
	<div class="slideWrapper"><!-- for VERT pics, pics2, pics3 all have same styles applied -->
		<div id="tsSlideshow" class="clearfix cycle-slideshow <%response.write(SlideShowType)%>"
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
				<img src="<%response.write (TemplatePath)%>images/stock1<% IF SlideShowFull THEN%>W<%END IF%>.jpg">
				<img src="<%response.write (TemplatePath)%>images/stock2<% IF SlideShowFull THEN%>W<%END IF%>.jpg">
			<%END IF%>
		</div>	
	</div>
<% END IF %>
	
<!-- Test instagram - comment out slideshow above -->
<!-- <div id="tsSlideshow" class="instagramCont"></div> -->

<% IF ScrollMsgOn THEN %>
	<!-- Scrolling Message -->
	<div id="scrollingMessage">
		<ul id="tickerMessage" >
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
	<div class="tsInfo">
		<%response.write (TouchSourceLabel)%>
	</div>
<% END IF %>

<!-- Timeout - more time prompt -->
<div class="moreTimeMask"></div>
<div id="moreTime">Touch the Screen to Continue
	<div id="timeLeft"></div>
	<div class="timeYes">Yes</div>
	<div class="timeNo">No</div>
</div>

<!-- Directory Text Box -->
<div class="directoryTextCont">
	<div class="directoryText">DIRECTORY</div>
	<div class="touchText">Please Touch the Screen to Make a Selection</div>
</div>

<!-- PDF Modal -->
<iframe id="pdfWindow" src="" frameborder="0" scrolling="no"></iframe>
<div id="pdfMask"></div>
<div id="jpgMask">
	<div id="jpgWindow">
		<div class="jpgWrapper">
			<img class="jpgImg"></img>
		</div>
	</div>
</div>
<div class="closePDF">Close</div>

<!-- URL Modal -->
<div id="urlMask"></div>
<div id="urlModal"></div>
<div class="backURL">Reload</div>
<div class="closeURL">Close</div>

<!-- Video Modal -->
<div id="videoMask"></div>
<div id="videoModal"><div class="blockYouTube"></div></div>
<div class="closeVideo">Close</div>


<!-- ADA button / display -->
<div class="adaFix"></div>
<img class="adaMenu adaOff" src="<%response.write (TemplatePath)%>images/wheelchair.png">
<div class="adaWrapper">
	<div class="adaNav">
		<div class="adaBtnCont"></div>
		<div id="adaKeyboard">
			<svg class="scrollUpBtn iconSVG adaScrollUpBtn"><use xlink:href="#scrollUpArrowSVG" /></svg>
			<div class="alphaBtn">A</div>
			<div class="alphaBtn">B</div>
			<div class="alphaBtn">C</div>
			<div class="alphaBtn">D</div>
			<div class="alphaBtn">E</div>
			<div class="alphaBtn">F</div>
			<div class="alphaBtn">G</div>
			<div class="alphaBtn">H</div>
			<div class="alphaBtn">I</div>
			<div class="alphaBtn">J</div>
			<div class="alphaBtn">K</div>
			<div class="alphaBtn">L</div>
			<div class="alphaBtn">M</div>
			<div class="alphaBtn">N</div>
			<svg class="scrollDownBtn iconSVG adaScrollDownBtn"><use xlink:href="#scrollDownArrowSVG" /></svg>
			<div class="alphaBtn">O</div>
			<div class="alphaBtn">P</div>
			<div class="alphaBtn">Q</div>
			<div class="alphaBtn">R</div>
			<div class="alphaBtn">S</div>
			<div class="alphaBtn">T</div>
			<div class="alphaBtn">U</div>
			<div class="alphaBtn">V</div>
			<div class="alphaBtn">W</div>
			<div class="alphaBtn">X</div>
			<div class="alphaBtn">Y</div>
			<div class="alphaBtn">Z</div>
			<div class="listBtn">List All</div>
		</div>
		<img class="adaMenu adaOn" src="<%response.write (TemplatePath)%>images/wheelchair.png">
	</div>
</div>

<!-- <div class="directoryText">DIRECTORY</div> -->

<div class="forceSlideshow1"></div>
<div class="forceSlideMask"></div>

<div class="debugTest">
	<p id="numBtns">Num Buttons: </p>
	<p id="buildingOnOff">Building: </p>
	<p id="weatherOnOff">Weather: </p>
	<p id="tsliveOnOff">TSLive: </p>
</div>

