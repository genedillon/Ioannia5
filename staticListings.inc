<div class="directoryContainer activeFull<% IF TSLiveAllOn = 0 THEN %> directoryContainerNoTSL<% END IF %><% IF SlideshowOn THEN %> directoryContainerSlideshow<% END IF %>">
	<% IF CombinedOn THEN %>
		<div class="companyContainer combinedList activeLeft">
			<div class="listHeader removeHeader">
				<div class="setOne0"></div>
				<div class="setOne1"><%response.write (CombinedHeader)%></div>
				<div class="setOne2"><%response.write (SuiteHeader)%></div>
				<div class="setOne3"></div>
				<div class="setOne4"></div>
				<div class="setOne5"></div>
			</div>
			<div class="col0">
				<% do until qCombList.EOF%>
					<div class="companyListing clearfix" data-listing="<%response.write(qCombList("ListingID"))%>" data-comp="<%response.write(qCombList("CompanyName"))%>" data-type="<%response.write(qCombList("Type"))%>">
						<div class="setOne0">MAP</div>
						<div class="setOne1"><%response.write (qCombList("ListingName"))%></div>
						<div class="setOne2"><%response.write (qCombList("Suite"))%></div>
						<div class="setOne3"></div>
						<div class="setOne4"></div>
						<div class="setOne5"></div>
					</div><!-- end tenant listing -->
				<% qCombList.movenext
				loop %>
			</div><!-- end listings -->
			<!-- <div id="listings" class="listingsContainer<% IF TSLiveAllOn = 0 THEN %> listingsNoTSL<% END IF %><% IF SlideshowOn = 0 THEN %> listingsNoSlide<% END IF %>"> -->
			<div id="listings" class="listingsContainer">
				<div class="col1 container"><div class="col1Listings"></div></div>
			</div>
		</div><!-- end tenant container -->

		<%ELSE%>


		<div class="companyContainer combinedList activeLeft noLines indentedInd">
<!-- 			<div class="listHeader removeHeader">
				<div class="setOne0"></div>
				<div class="setOne1"><%response.write (CombinedHeader)%></div>
				<div class="setOne2"><%response.write (SuiteHeader)%></div>
				<div class="setOne3"></div>
				<div class="setOne4"></div>
				<div class="setOne5"></div>
			</div> -->
			<div class="col0">
				<% do until qStaticIndentedList.EOF%>
					<div class="companyListing clearfix" data-listing="<%response.write(qStaticIndentedList("ListingID"))%>" data-comp="<%response.write(qStaticIndentedList("CompanyName"))%>" data-type="<%response.write(qStaticIndentedList("Type"))%>">

						<div class="setOne0">

				<!-- 		<a class="mapURL" href="animatedmap.asp?ID=<%response.write (qStaticIndentedList("CompanyID"))%>&CODE=1-<%response.write (qStaticIndentedList("Building"))%>"> -->

<a class="wayfinder" href="#" target="_top" data-company="<%response.write(qStaticIndentedList("CompanyID"))%>">
				MAP
			</a>


<!-- 						MAP

						</a> -->

						</div>


						<div class="setOne1"><%response.write (qStaticIndentedList("ListingName"))%></div>
						<div class="setOne2"><%response.write (qStaticIndentedList("Suite"))%></div>
						<div class="setOne3"></div>
						<div class="setOne4"></div>
						<div class="setOne5"></div>
					</div><!-- end tenant listing -->
				<% qStaticIndentedList.movenext
				loop %>
			</div><!-- end listings -->
			<div id="listings" class="listingsContainer<% IF TSLiveAllOn = 0 THEN %> listingsNoTSL<% END IF %><% IF SlideshowOn = 0 THEN %> listingsNoSlide<% END IF %>">
				<div class="col1 container"><div class="col1Listings"></div></div>
			</div>
		</div><!-- end tenant container -->




	<%END IF%>

</div><!-- end directoryContainer -->
	
<div id="pleaseWait">Loading Directory Listings.<br>Please Wait...</div>


