
<!-- TSLIVE ELEMENTS DISPLAY: TRAFFIC AND AMENITY URLS HIDDEN UNTIL BUTTON IS TOUCHED - TSLIVE PROGRAM -->


	<!-- Traffic Container 
	<% IF TSLiveTrafButtonOn THEN %>
	<div class="trafficCont">
		<iframe class="iframeSpecs" src="http://ts4.touchsource.com/TouchSourceWeb/traffic/ts4?lat=<%response.write (latitude)%>&lon=<%response.write (longitude)%>&zl=<%response.write (TrafficZoom)%>" frameborder="0" scrolling="no"></iframe>
	</div>
	<% END IF %>-->

	<!-- Transit Container 
	<% IF TSLiveTransitButtonOn THEN %>
	<div class="transitCont">
		<iframe class="iframeSpecs" src="<%response.write (TransitURL)%>" frameborder="0" scrolling="no"></iframe>
	</div>
	<% END IF %>-->


<!-- TSLIVE ELEMENTS DISPLAY:  WEATHER AND NEWS VISIBLE IN TSLIVE PROGRAM -->

	<!-- News/Stocks Container -->
<!-- 	<% IF TSLiveNewsOn And TSLiveStocksOn THEN %>
		<iframe class="newsContainer activeNews" src="http://tslive.touchsource.com/TSLive/Templates/TS41V/index.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe>
	<% ELSEIF TSLiveNewsOn THEN%>
		<iframe class="newsContainer activeNews" src="http://tslive.touchsource.com/TSLive/Templates/TS41-Static-News/index.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe>
	<% END IF %> -->

	 <!-- Weather  Container  -->
	<% IF TSLiveWeatherOn THEN %>
		<!-- <iframe class="weatherContainer" src="http://tslive.touchsource.com/TSLive/Templates/TS41-Static-NewsStocks/weather.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe> -->
	<% END IF %>

		<!-- Weather - Single Day Container -->
<!-- 	<% IF TSLiveAllOn = 0 AND ZipPostal > "" THEN%>
		<div class="weatherContainerSingleWrapper">
			<iframe class="weatherContainerSingle" src="http://tslive.touchsource.com/TSLive/Templates/TS4-42H-single-day/weather.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe>
		</div> -->
	<% END IF %>


<div class="tsLiveImage"><img src="weatherClear240x96.png" border="0"></div>