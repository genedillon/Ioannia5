
<!-- TSLIVE ELEMENTS DISPLAY: TRAFFIC AND AMENITY URLS HIDDEN UNTIL BUTTON IS TOUCHED - TSLIVE PROGRAM -->

	<!-- Amenities Map Container -->
	<% IF TSLiveAmenButtonOn THEN %>
	<div class="amenityCont">
		<iframe class="iframeSpecs" src="http://ts4.touchsource.com/TouchSourceWeb/gmapamen/ts4?lat=<%response.write (latitude)%>&lon=<%response.write (longitude)%>&zoom=<%response.write (AmenityZoom)%>" frameborder="0" scrolling="no"></iframe>
	</div>
	<% END IF %>

	<!-- Traffic Container -->
	<% IF TSLiveTrafButtonOn THEN %>
	<div class="trafficCont">
		<iframe class="iframeSpecs" src="http://ts4.touchsource.com/TouchSourceWeb/traffic/ts4?lat=<%response.write (latitude)%>&lon=<%response.write (longitude)%>&zl=<%response.write (TrafficZoom)%>" frameborder="0" scrolling="no"></iframe>
	</div>
	<% END IF %>

	<!-- Transit Container -->
	<% IF TSLiveTransitButtonOn THEN %>
	<div class="transitCont">
		<iframe class="iframeSpecs" src="<%response.write (TransitURL)%>" frameborder="0" scrolling="no"></iframe>
	</div>
	<% END IF %>


<!-- TSLIVE ELEMENTS DISPLAY:  WEATHER AND NEWS VISIBLE IN TSLIVE PROGRAM -->

	<!-- News/Stocks Container -->
	<% IF TSLiveNewsOn And TSLiveStocksOn THEN %>
	<!-- <iframe class="newsContainer activeNews" src="http://tslive.touchsource.com/TSLive/Templates/TS4-B-NewsStocks/index.htm" frameborder="0" scrolling="no"></iframe> -->
	<% ELSEIF TSLiveNewsOn THEN%>
	<!-- <iframe class="newsContainer activeNews" src="http://tslive.touchsource.com/TSLive/Templates/TS4-B-News/index.htm" frameborder="0" scrolling="no"></iframe> -->
	<% END IF %>

	<!-- Weather and Single Day Containers -->
	<% IF TSLiveWeatherOn THEN %>
	<!-- <iframe class="weatherContainer" src="http://tslive.touchsource.com/TSLive/Templates/TS4-B-Weather/weather.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe> -->
	<% ELSEIF TSLiveAllOn = 0 AND ZipPostal > "" THEN%>
	<!-- <div class="weatherContainerSingleWrapper">
		<iframe class="weatherContainerSingle" src="http://tslive.touchsource.com/TSLive/Templates/TS4-42H-single-day-blue/weather.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe>
	</div> -->
	<% END IF %>


	<!-- Components above are now interegrated into a single container -->
	<% IF TSLiveAllOn THEN %>
		<iframe class="newsContainer activeNews" src="http://tslive.touchsource.com/TSLive/Templates/TS41V/index.htm?zip=<%response.write (ZipPostal)%>" frameborder="0" scrolling="no"></iframe>
	<% END IF %>
