<div class="btnContWrapper">
<div class="btnContainer"> 
	<!--<% IF BuildingInfoDisplayOn THEN %>btnContainerShort<% ELSE %>btnContainerTall<% END IF %>-->
	<div class="btnCol1 clearfix">
		<% IF CombinedOn THEN %>
			<div id="tenantsBtn" class="button button1">
				<svg class="svgNavIcon iconTenant"><use xlink:href="#svgTenants" /></svg>
				<div class="btnText"><%response.write (CombinedLabel)%></div>
			</div>
		<% END IF %>
		<% IF CompaniesOn THEN %>
			<div id="compsBtn" class="button button1">
				<svg class="svgNavIcon iconComp"><use xlink:href="#svgTenants" /></svg>
				<div class="btnText"><%response.write (CompaniesLabel)%></div>
			</div>
		<% END IF %>
		<% IF IndivsOn THEN %>
			<div id="indivsBtn" class="button button1">
				<svg class="svgNavIcon iconURL"><use xlink:href="#svgIndiv" /></svg>
				<div class="btnText"><%response.write (IndivsLabel)%></div>
			</div>
		<% END IF %>
		<% IF BuildingInfoButtonOn THEN %>
			<div id="bldginfoBtn" class="button button1">
				<svg class="svgNavIcon iconBldgInfo"><use xlink:href="#svgPDF" /></svg>
				<div class="btnText"><%response.write (BuildingInfoButtonLabel)%></div>
			</div>
		<% END IF %>	
		<% IF SpaceOn THEN %>
			<div id="spaceBtn" class="button button1">
				<svg class="svgNavIcon iconSpace"><use xlink:href="#svgSpace" /></svg>
				<div class="btnText"><%response.write (SpaceLabel)%></div>
			</div>
		<% END IF %>	
		<% IF BldgAmenOn THEN %>
			<div id="bldgAmenBtn" class="button button1">
				<svg class="svgNavIcon iconBldgAmen"><use xlink:href="#svgBldgAmen" /></svg>
				<!-- <svg class="svgNavIcon iconBldgAmen"><use xlink:href="#confRoom" /></svg> -->
				<div class="btnText"><%response.write (BldgAmenLabel)%></div>
			</div>
		<% END IF %>	
		<% IF AnnOn THEN %>
			<div id="annBtn" class="button button1">
				<svg class="svgNavIcon iconAnn"><use xlink:href="#svgAnn" /></svg>
				<div class="btnText"><%response.write (AnnLabel)%></div>
			</div>
		<% END IF %>
		<% IF List12On THEN %>
			<div id="list12Btn" class="button button1">
				<svg class="svgNavIcon iconList12"><use xlink:href="#svgTenants" /></svg>
				<div class="btnText"><%response.write (List12Label)%></div>
			</div>
		<% END IF %>
		<% IF PDFOn THEN %>
			<div id="pdfBtn1" class="button button1 pdfParent ">
				<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write (qProperty("PDFName"))%>">
				<svg class="svgNavIcon iconPDF"><use xlink:href="#<%response.write(PDFBtnIcon)%>" /></svg>
					<div class="btnText"><%response.write (PDFLabel)%></div>
				</a>
			</div>
		<% END IF %>	
		<% IF PDF2On THEN %>
			<div id="pdfBtn2" class="button button1 pdfParent ">
				<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write (qProperty("PDF2Name"))%>">
				<svg class="svgNavIcon iconPDF"><use xlink:href="#<%response.write(PDFBtn2Icon)%>" /></svg>
					<div class="btnText"><%response.write (PDF2Label)%></div>
				</a>
			</div>
		<% END IF %>	
		<% IF PDF3On THEN %>
			<div id="pdfBtn3" class="button button1 pdfParent ">
				<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write (qProperty("PDF3Name"))%>">
				<svg class="svgNavIcon iconPDF"><use xlink:href="#<%response.write(PDFBtn3Icon)%>" /></svg>
					<div class="btnText"><%response.write (PDF3Label)%></div>
				</a>
			</div>
		<% END IF %>	
		<% IF PDF4On THEN %>
			<div id="pdfBtn4" class="button button1 pdfParent ">
				<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write (qProperty("PDF4Name"))%>">
				<svg class="svgNavIcon iconPDF"><use xlink:href="#<%response.write(PDFBtn4Icon)%>" /></svg>
					<div class="btnText"><%response.write (PDF4Label)%></div>
				</a>
			</div>
		<% END IF %>	


		<!-- ============ List12 BUTTON FOR URLs or Videos ==================
		UNDER CONSTRUCTION -->

		<% IF List12URLOn THEN %>
			<div id="List12URLBtn" class="button button1">
				<svg class="svgNavIcon iconList12"><use xlink:href="#svgWeb" /></svg>
				<div class="btnText">Web Links</div>
			</div>
		<% END IF %>

		<% IF List12VideoOn THEN %>
			<div id="List12VideoBtn" class="button button1">
				<svg class="svgNavIcon iconList12"><use xlink:href="#svgMovie" /></svg>
				<div class="btnText">Videos</div>
			</div>
		<% END IF %>


		<!-- ============ HARD CODED BUTTON FOR URLs ================== -->
		<% IF URLOn THEN %>
			<div id="urlBtn" class="button button1 webModal" data-url="http://www.touchsource.com">
				<svg class="svgNavIcon iconURL"><use xlink:href="#svgWeb" /></svg>
				<div class="btnText"><%response.write (URLLabel)%></div>
			</div>
		<% END IF %>	
		<% IF URL2On THEN %>
			<div id="urlBtn2" class="button button1 webModal" data-url="http://cnn.com">
				<svg class="svgNavIcon iconURL"><use xlink:href="#svgWeb" /></svg>
				<div class="btnText"><%response.write (URL2Label)%></div>
			</div>
		<% END IF %>

		<!-- ============ HARD CODED BUTTON FOR VIDEO ================== -->
		<% IF VideoOn THEN %>
		<div id="videoBtn1" class="button button1 videoBtn"  data-video="https://www.youtube.com/embed/qvWxhhi0_yk?iv_load_policy=3&controls=0&autoplay=1&disablekb=1&modestbranding=1&fs=0&rel=0&showinfo=0&autohide=0&color=white">
			<svg class="svgNavIcon iconURL"><use xlink:href="#svgMovie" /></svg>
			<div class="btnText">Video</div>
		</div>
		<% END IF %>	
		<% IF Video2On THEN %>
		<div id="videoBtn2" class="button button1 videoBtn"  data-video="https://www.youtube.com/embed/461zVqa99dg?iv_load_policy=3&controls=0&autoplay=1&disablekb=1&modestbranding=1&fs=0&rel=0&showinfo=0&autohide=0&color=white">
			<svg class="svgNavIcon iconURL"><use xlink:href="#svgMovie" /></svg>
			<div class="btnText">Video 2</div>
		</div>
		<% END IF %>


	</div>
	<!-- end .btnCol1 -->


	<!-- TSLive Button Container -->
	<% IF TSLiveButtonNumber > 0 THEN %>
		<div class="contTSLiveBtns"><!-- button wrapper -->
	<% END IF %>	
		<% IF TSLiveAmenButtonOn THEN %>
			<div id="amenityBtn" class="buttonTSLive">
				<svg class="svgNavIconTSLive iconAreaAmen"><use xlink:href="#svgAreaAmen" /></svg>
				<div class="btnTextTSLive"><%response.write (TSLiveAmenButtonLabel)%></div>
			</div>
		<% END IF %>	
		<% IF TSLiveTrafButtonOn THEN %>
			<div id="trafficBtn" class="buttonTSLive">
				<svg class="svgNavIconTSLive iconTraffic"><use xlink:href="#svgTraffic" /></svg>
				<div class="btnTextTSLive"><%response.write (TSLiveTrafButtonLabel)%></div>
			</div>
		<% END IF %>	
		<% IF TSLiveTransitButtonOn THEN %>
			<div id="transitBtn" class="buttonTSLive">
				<svg class="svgNavIconTSLive iconTransit"><use xlink:href="#svgTransit" /></svg>
				<div class="btnTextTSLive"><%response.write (TSLiveTransitButtonLabel)%></div>
			</div>
		<% END IF %>	
	<% IF TSLiveButtonNumber > 0 THEN %>
		</div><!-- end button wrapper -->
	<% END IF %>

</div><!-- end btnContainer -->
</div><!-- end btnContWrapper -->


<!-- ============================= BEGIN SVG ICON CODE ================================ -->
<svg xmlns="http://www.w3.org/2000/svg" style="display:none">
	<symbol id="svgSpace" viewBox="0 0 72 72">
		<path d="M59,28V9H8v31.7h28V65h19.9V53H65V28H59z M61,49h-9v11.8H40.4V36H12V13h42.6v19.3H61V49z"/>
		<polygon points="19.8,18.9 12,24.1 19.8,29.3 19.8,25.6 46.8,25.6 46.8,29.3 54.6,24.1 46.8,18.9 46.8,22.6 19.8,22.6 "/>
		<polygon points="16.6,56.9 21.8,64.7 27,56.9 23.3,56.8 23.3,48.4 27,48.4 21.8,40.7 16.6,48.4 20.3,48.4 20.3,56.8 "/>
		
		<!-- <path d="M31.3,24.6c-1.3,0-2.1,1.2-2.1,2.9c0,1.7,0.8,2.8,2.1,2.8c1.3,0,2-1.2,2-2.9C33.4,25.9,32.6,24.6,31.3,24.6z"/> -->
		<!-- <path d="M31.4,35.9L31.4,35.9c-0.2,0.5-0.3,1.1-0.4,1.6l-0.5,1.8h1.9l-0.5-1.8C31.7,37.1,31.6,36.4,31.4,35.9z"/> -->
		<!-- <path d="M56.9,3.1v5.2H8.4v4.3h11.2v1.9c-0.8,0.5-1.4,1.5-1.5,2.6h-3.8c-2.4,0-4.4,2-4.4,4.4v23.3c0,2.4,2,4.4,4.4,4.4h35.1
			c2.4,0,4.4-2,4.4-4.4V21.6c0-2.4-2-4.4-4.4-4.4h-5.1c-0.1-1.1-0.7-2.1-1.5-2.6v-1.9h8.1c2.1,0.4,3.6,0.9,4.5,1.8
			c1,1,1.4,2.5,1.6,4.8v50.4h3.6V3.1H56.9z M43.9,34.5h5.3v1.6h-3.3v1.8h3.1v1.6h-3.1v2h3.5V43h-5.4V34.5z M22.4,12.6H40v1.9
			c-0.8,0.5-1.4,1.5-1.5,2.6H23.9c-0.1-1.1-0.7-2.1-1.5-2.6V12.6z M19.8,43h-5.3v-8.5h1.9v6.9h3.4V43z M20.7,23.2h5.2v1.6h-3.3v1.9
			h3.1v1.6h-3.1v3.4h-1.9V23.2z M26.7,43h-5.4v-8.5h5.3v1.6h-3.3v1.8h3.1v1.6h-3.1v2h3.5V43z M33.3,43l-0.7-2.2h-2.4L29.6,43h-2
			l2.6-8.5h2.5l2.6,8.5H33.3z M31.2,31.8c-2.5,0-4-1.9-4-4.3c0-2.6,1.6-4.5,4.1-4.5c2.6,0,4,2,4,4.3C35.4,30.1,33.7,31.8,31.2,31.8z
			 M38.9,43.1c-1,0-1.9-0.3-2.4-0.5l0.4-1.6c0.5,0.3,1.3,0.5,2.1,0.5c0.9,0,1.4-0.4,1.4-0.9c0-0.5-0.4-0.8-1.4-1.2
			c-1.4-0.5-2.3-1.3-2.3-2.5c0-1.5,1.2-2.6,3.2-2.6c1,0,1.7,0.2,2.2,0.4l-0.4,1.6c-0.3-0.2-0.9-0.4-1.8-0.4c-0.8,0-1.2,0.4-1.2,0.8
			c0,0.5,0.5,0.8,1.6,1.2c1.5,0.6,2.2,1.3,2.2,2.5C42.3,41.9,41.2,43.1,38.9,43.1z M41.4,31.7c-0.1-0.2-0.3-0.9-0.6-2
			c-0.2-1.1-0.6-1.4-1.4-1.4h-0.6v3.4h-1.9v-8.4c0.6-0.1,1.5-0.2,2.6-0.2c1.3,0,2.1,0.2,2.8,0.7c0.5,0.4,0.8,1,0.8,1.8
			c0,1.1-0.8,1.8-1.5,2.1v0c0.6,0.2,0.9,0.8,1.1,1.6c0.3,1,0.5,2.1,0.7,2.4H41.4z"/>
		<path d="M39.7,24.5c-0.5,0-0.7,0-0.9,0.1v2.4h0.8c1,0,1.5-0.5,1.5-1.2C41.1,24.9,40.6,24.5,39.7,24.5z"/> -->
	</symbol>
	<symbol id="svgTenants" viewBox="0 0 72 72">
		<path d="M46.5,5.3c-11.1,0-20.1,9-20.1,20.1c0,4.5,1.5,8.7,4,12C19.9,44.5,1,56.8,5.8,64.9c4.8,8.1,22-8.7,28.3-23.6
			c3.4,2.7,7.7,4.3,12.4,4.3c11.1,0,20.1-9,20.1-20.1S57.6,5.3,46.5,5.3z M46.5,42.2c-9.3,0-16.8-7.5-16.8-16.8S37.2,8.7,46.5,8.7
			s16.8,7.5,16.8,16.8S55.8,42.2,46.5,42.2z"/>
		<circle cx="46.3" cy="18.4" r="5.5"/>
		<path d="M46.3,25.3c-4.7,0-8.8,4.2-10.5,10.2c2.7,2.8,6.5,4.6,10.7,4.6c4,0,7.7-1.6,10.3-4.3C55.2,29.7,51.1,25.3,46.3,25.3z"/>
	</symbol>
	<symbol id="svgTenants" viewBox="0 0 72 72">
		<path d="M46.5,5.3c-11.1,0-20.1,9-20.1,20.1c0,4.5,1.5,8.7,4,12C19.9,44.5,1,56.8,5.8,64.9c4.8,8.1,22-8.7,28.3-23.6
			c3.4,2.7,7.7,4.3,12.4,4.3c11.1,0,20.1-9,20.1-20.1S57.6,5.3,46.5,5.3z M46.5,42.2c-9.3,0-16.8-7.5-16.8-16.8S37.2,8.7,46.5,8.7
			s16.8,7.5,16.8,16.8S55.8,42.2,46.5,42.2z"/>
		<circle cx="46.3" cy="18.4" r="5.5"/>
		<path d="M46.3,25.3c-4.7,0-8.8,4.2-10.5,10.2c2.7,2.8,6.5,4.6,10.7,4.6c4,0,7.7-1.6,10.3-4.3C55.2,29.7,51.1,25.3,46.3,25.3z"/>
	</symbol>
	<symbol id="confRoom" viewBox="0 0 72 72">
		<path d="M3.1,58.4c0,0,0.5-19.7,9.8-19.7c4.7,0,6.3,3.8,7.1,6.8c-2.6,4.6-7.1,12.9-7.1,12.9H3.1z"/>
		<polygon points="15.8,58.4 23.8,43.5 48.7,43.5 56.6,58.4 	"/>
		<ellipse cx="12.8" cy="29.9" rx="5.5" ry="6.7"/>
		<ellipse cx="59.5" cy="29.9" rx="5.5" ry="6.7"/>
		<ellipse cx="35.7" cy="18.9" rx="5.5" ry="6.7"/>
		<path d="M26.8,41.2c0-3.2,0.9-13.6,9-13.6s9.7,11.3,9.7,13.6C43,41.2,28.3,41.2,26.8,41.2z"/>
		<path d="M69.4,58.4c0,0-0.5-19.7-9.8-19.7c-4.7,0-6.3,3.8-7.1,6.8c2.6,4.6,7.1,12.9,7.1,12.9H69.4z"/>
	</symbol>
	<symbol id="svgAnn" viewBox="0 0 72 72">
		<path d="M43.3,15.1c-2.9-3.9-6.3-5.6-9.4-5c-2.4,0.5-4.3,2.4-5.5,5.4c-0.3,0.2-0.6,0.5-0.8,0.9c-0.4,0.9-0.7,1.7-1,2.5
			c-1.7,4.6-2.6,7.1-9.1,8.4c-0.6,0.1-1.3,0.3-2.2,0.4c-4.9,0.9-9.4,1.8-11.3,2.8c-3,1.5-3.7,5.6-2.9,8.9c0.8,3.3,3,5.5,5.8,6
			c0.2,0.1,0.5,0.2,0.8,0.3c3.6,0.6,3.9,1.6,3.9,1.6c0.9,3.6,1.4,6.4,1.8,8.6c0.8,4.2,1.2,6.3,2.9,7.4c0.7,0.5,1.5,0.6,2.4,0.6
			c0.9,0,2-0.2,3.1-0.4c0.5-0.1,0.9-0.2,1.2-0.3c1.9-0.4,3.3-0.7,4.1-1.9c0.8-1.2,0.5-2.8,0.2-4.4c-0.5-2.1-1.9-2.5-2.6-2.8
			c0,0,0,0,0,0c-0.2-1.2-0.6-2.9-1-4.6c-0.5-2.1-1.4-5.6-1.3-6.8c0.8-0.2,1.6-0.3,2.3-0.3c3.8,0,7.4,4,8.7,5.5
			c0.2,0.2,0.3,0.4,0.4,0.5c0.3,0.4,0.8,0.5,1.3,0.5c2.2,2.4,4.6,3.7,6.9,3.7c0.4,0,0.9,0,1.3-0.1c3.1-0.7,5.4-3.7,6.4-8.4
			c0.9-4.3,0.8-9.7-0.4-15.1C48,23.5,45.9,18.6,43.3,15.1z M31.2,32.9c-0.4-1.7-0.6-3.4-0.8-5.1l3.5-0.7c0.3-0.1,0.6-0.1,0.9-0.1
			c0.9,0,1.9,0.3,2.7,0.9c1.1,0.8,1.8,2,2,3.3c0.2,1.4,0,2.7-0.8,3.9c-0.7,1.1-1.8,1.9-3,2.2l-3,0.6C32.1,36.3,31.6,34.7,31.2,32.9z
			 M4.6,38.5c-0.5-2.1,0-4.4,1.1-5c1.7-0.8,7.2-1.9,10.3-2.5c-0.7,1.3-1.1,2.9-0.9,4.4c0.2,2,1.3,3.6,3,4.8c-2.7,0.8-5.8,1.6-10,1.7
			c0,0,0,0-0.1,0C5.6,41.9,4.8,39.3,4.6,38.5z M23.7,57.4c0.1,0,0.1,0,0.2,0.1c0,0,0,0.1,0,0.1c0.2,1.1,0.3,1.6,0.3,1.8
			c-0.3,0.1-1.1,0.3-1.8,0.4c-0.4,0.1-0.8,0.2-1.3,0.3c-2,0.4-2.7,0.4-2.8,0.3c-0.5-0.3-0.9-2.8-1.4-5.2c-0.4-2.2-1-5.1-1.8-8.8
			c-0.1-0.6-0.4-1.1-0.8-1.6c0.9-0.2,1.8-0.4,2.9-0.7c0.6-0.1,1.2-0.3,1.8-0.4c0.2,1.7,0.7,4,1.4,6.6c0.4,1.7,0.8,3.3,1,4.4
			C21.6,56.8,23.1,57.3,23.7,57.4z M21.7,43.1l-0.1-0.3c0.2,0,0.4-0.1,0.6-0.1C22.1,42.9,22,43,21.7,43.1z M24.6,39
			c-1.2,0-2.4,0.2-3.6,0.5c-2.3-0.9-3.6-2.3-3.9-4.3c-0.2-1.8,0.6-3.6,1.9-4.8c3.9-0.9,6.2-2.4,7.7-4.2c0.2,5.6,1.5,10.5,2.9,14.2
			C28.1,39.5,26.4,39,24.6,39z M46.3,43.3c-0.7,3.3-2.1,5.4-3.8,5.8c-1.7,0.4-3.8-1-5.9-3.7c-1.2-1.6-2.3-3.5-3.2-5.6l2.6-0.5
			c1.7-0.4,3.3-1.4,4.3-3c1-1.6,1.4-3.5,1.1-5.4c-0.7-3.9-4.2-6.5-7.8-5.8l-3.3,0.7c-0.1-2.4,0.1-4.6,0.5-6.5
			c0.7-3.3,2.1-5.4,3.8-5.8c0.2,0,0.4-0.1,0.6-0.1c1.6,0,3.5,1.3,5.3,3.7c2.4,3.1,4.3,7.6,5.4,12.6C47,34.7,47.1,39.5,46.3,43.3z"/>
		<rect x="54.9" y="41.1" transform="matrix(-0.9609 -0.2768 0.2768 -0.9609 111.8165 100.0561)" width="16.2" height="2.1"/>
		<rect x="55.3" y="25.1" transform="matrix(-0.9706 0.2407 -0.2407 -0.9706 131.3276 36.3106)" width="16.2" height="2.1"/>
		<rect x="47.8" y="11.1" transform="matrix(0.7202 -0.6938 0.6938 0.7202 7.2273 42.1564)" width="16.2" height="2.1"/>
	</symbol>
	<symbol id="svgPDF" viewBox="0 0 72 72">
		<path d="M43.4,9H15.6v53.8h42.7v-39L43.4,9z M55,59.5H18.9V12.3H42l0.1,0.1v12.7h12.8l0.1,0.1V59.5z"/>
		<rect x="22.1" y="30.6" width="20.1" height="2.6"/>
		<rect x="22.1" y="37.8" width="29.7" height="2.6"/>
		<rect x="22.1" y="46.1" width="29.7" height="2.6"/>
	</symbol>
	<symbol id="svgPDFMap" viewBox="0 0 72 72">
		<path d="M36,10c-9.6,0-17.3,7.8-17.3,17.3c0,9.6,16.5,37.5,17.3,37.5s17.3-28,17.3-37.5C53.3,17.8,45.6,10,36,10z M36,34.5
		c-4,0-7.2-3.2-7.2-7.2s3.2-7.2,7.2-7.2s7.2,3.2,7.2,7.2S40,34.5,36,34.5z"/>
	</symbol>
	<symbol id="svgPDFLeed" viewBox="0 0 72 72">
		<path d="M9.5,57.3c0.9,3.4,2.9,3.8,3.8,3.4c5.3-2.1,24.4-10,34.9-33.3c0,0,0.4,11.1-16.8,26.3C41,64,51.7,55.6,54.8,51.6
		c3.1-4,6.8-17.2-1.7-42.9c-1.9,2.6-4.8,5.4-10.5,7.1c-7.9,2.3-18.1,3.9-24.5,15.1C15.2,37,17.7,46.8,26,50
		C24.4,53.1,9,55.3,9.5,57.3z"/>
	</symbol>
	<symbol id="svgWeb" viewBox="0 0 72 72">
		<path d="M36.3,7.9C20.6,7.9,7.9,20.6,7.9,36.2s12.7,28.3,28.3,28.3s28.3-12.7,28.3-28.3S51.9,7.9,36.3,7.9z M11.2,37.8h9.6
		c0.1,3.1,0.4,6,1,8.8h-8.4C12.1,43.9,11.3,40.9,11.2,37.8z M37.8,21.7V11.3c3.4,0.9,6.5,4.9,8.5,10.4H37.8z M47.3,24.9
		c0.8,3,1.2,6.3,1.4,9.8H37.8v-9.8H47.3z M34.7,11.3v10.4h-8.5C28.2,16.2,31.2,12.2,34.7,11.3z M34.7,24.9v9.8H23.9
		c0.1-3.5,0.6-6.8,1.4-9.8H34.7z M20.8,34.6h-9.6c0.2-3.5,1.2-6.8,2.7-9.8H22C21.3,27.9,20.9,31.2,20.8,34.6z M23.9,37.8h10.8v8.8
		H25C24.4,43.9,24,40.9,23.9,37.8z M34.7,49.7v11.4c-3.6-1-6.8-5.4-8.8-11.4H34.7z M37.8,61.2V49.7h8.8
		C44.7,55.8,41.5,60.2,37.8,61.2z M37.8,46.6v-8.8h10.8c-0.1,3.1-0.5,6-1.1,8.8H37.8z M51.8,37.8h9.6c-0.2,3.1-1,6.1-2.2,8.8h-8.4
		C51.3,43.8,51.7,40.9,51.8,37.8z M51.8,34.6c-0.1-3.5-0.5-6.8-1.2-9.8h8.2c1.5,3,2.4,6.3,2.7,9.8H51.8z M56.8,21.7h-7.1
		c-1.2-3.7-2.8-6.8-4.7-9.1C49.8,14.4,53.9,17.6,56.8,21.7z M27.6,12.6c-1.9,2.3-3.5,5.4-4.7,9.1h-7.1
		C18.6,17.6,22.8,14.4,27.6,12.6z M15,49.7h7.5c1.2,4.1,2.9,7.6,5,10.1C22.4,57.9,18,54.3,15,49.7z M44.9,59.9c2.1-2.6,3.8-6,5-10.1
		h7.5C54.5,54.3,50.2,57.9,44.9,59.9z"/>
	</symbol>
	<symbol id="svgBldgAmen" viewBox="0 0 72 72">
		<path d="M50.1,49.1c0.8-1.2,1.4-2.6,1.8-4c2.6-0.3,5.5-1.7,7.9-4.1c4.5-4.5,5.6-10.7,2.4-13.8
		c-2.2-2.2-6-2.3-9.6-0.6c-0.5-2.3-5.2-4.3-11.7-5.1c1.5-4.5,0-12.6-4.2-14.8c-0.7,0.3,2.8,5.3,0.6,8.6c-1.4,2.2-1.9,4.2-1.8,5.8
		c-0.4,0-0.8,0-1.2,0c0-1.6,0.3-3.4,0.9-5.6c1.6-5.5,1.1-9.3-4.9-12.6c3.3,7.3-4.2,7.4-4.2,17.3c0,0.5,0,1,0.1,1.5
		c-6.2,1-10.5,3-10.5,5.3h0V40c0,3.4,1,6.6,2.8,9.3c-6.6,1.6-10.8,4.1-10.8,6.9c0,4.8,12.2,8.7,27.2,8.7c15,0,27.2-3.9,27.2-8.7
		C62,53.3,57.3,50.6,50.1,49.1z M52.7,40v-9.4c2.2-1.3,4.6-1.4,6,0c1.8,1.8,1.2,5.2-1.4,7.8c-1.4,1.4-3.1,2.2-4.7,2.3
		C52.6,40.5,52.7,40.3,52.7,40z M26.2,21.8c1,5.7,6.9,6.2,9,4.8c-0.5-1.4-1-3.2-0.9-5.6c0.4,0,0.8,0,1.2,0c0.1,3,2.3,4.5,4.1,2.7
		c0.5-0.5,0.9-1.3,1.3-2.1c4,0.7,6.8,2.1,6.8,3.7c0,2.4-6,4.3-13.5,4.3s-13.5-1.9-13.5-4.3C20.7,23.9,22.9,22.6,26.2,21.8z
		 M34.8,59.3c-9.3,0-16.9-2.4-16.9-5.4c0-0.9,0.7-1.8,2-2.6c3.2,3.7,7.8,6,13,6h2.4c5.4,0,10.3-2.5,13.4-6.5c1.8,0.9,2.9,1.9,2.9,3
		C51.7,56.9,44.1,59.3,34.8,59.3z"/>
	</symbol>
	<symbol id="svgTraffic" viewBox="0 0 72 72">
		<path d="M48.3,32.8c3.6,0,3.6-6.9,3.6-6.9h-8v-5c1.4-1,0.8-3.9,4.4-3.9c3.6,0,3.6-6.9,3.6-6.9h-8V8.9c0-1.5-1.2-2.7-2.7-2.7h-4.5
			c-0.5-0.8-1.3-1.3-2.3-1.3h-0.3c-1,0-1.8,0.5-2.3,1.3h-4.5c-1.5,0-2.7,1.2-2.7,2.7v1.2h-7.9c0,0-0.1,6.9,3.6,6.9
			c3.5,0,3,2.7,4.3,3.8v5.1h-7.9c0,0-0.1,6.9,3.6,6.9c3.5,0,3,2.7,4.3,3.8v4.8h-7.9c0,0-0.1,6.9,3.6,6.9c3.5,0,3,2.7,4.3,3.8v1.8
			c0,1.5,1.2,2.7,2.7,2.7h1c0,0.1,0,0.2,0,0.3v7c0,1.5,1.2,2.7,2.7,2.7h6.6c1.5,0,2.7-1.2,2.7-2.7v-7c0-0.1,0-0.2,0-0.3h1
			c1.5,0,2.7-1.2,2.7-2.7v-1.7c1.4-1,0.8-3.9,4.4-3.9c3.6,0,3.6-6.9,3.6-6.9h-8v-4.7C45.3,35.7,44.7,32.8,48.3,32.8z M42.3,46.3
			c0,4.6-3.6,8.3-8,8.3s-8-3.7-8-8.3V16.5c0-4.6,3.6-8.3,8-8.3s8,3.7,8,8.3V46.3z"/>
		<circle cx="34.3" cy="17" r="5.6"/>
		<circle cx="34.3" cy="31.5" r="5.6"/>
		<circle cx="34.3" cy="46" r="5.6"/>
	</symbol>
	<symbol id="svgIndiv" viewBox="0 0 72 72">
		<path d="M46.5,5.3c-11.1,0-20.2,9-20.2,20.2c0,4.5,1.5,8.7,4,12.1C19.9,44.5,1,56.9,5.8,65c4.8,8.1,22.1-8.7,28.4-23.6
			c3.4,2.7,7.7,4.3,12.4,4.3c11.1,0,20.2-9,20.2-20.2S57.7,5.3,46.5,5.3z M46.5,42.3c-9.3,0-16.8-7.5-16.8-16.8S37.3,8.7,46.5,8.7
			s16.8,7.5,16.8,16.8S55.8,42.3,46.5,42.3z"/>
		<path d="M46.6,28.5c2.3,0,4.2-1.7,4.2-4c0-2.3-1.9-4.2-4.2-4.2c-2.3,0-4.2,1.7-4.2,4C42.4,26.6,44.3,28.5,46.6,28.5z"/>
		<path d="M46.4,29.6c-3.6,0-6.7,3.5-8,8.1c2.2,1.5,5,2.6,8.2,2.6c3.1,0,5-0.5,7.9-2.3C53.3,33.3,50.1,29.6,46.4,29.6z"/>
		<path d="M38.8,22.1c2.3,0,4.2-1.7,4.2-4c0-2.3-1.9-4.2-4.2-4.2c-2.3,0-4.2,1.7-4.2,4C34.6,20.2,36.5,22.1,38.8,22.1z"/>
		<path d="M40.5,23.5c-5.5,0-7,3.9-8.3,7.4c1.4,1.6,3.1,3,5.3,3.7c1.1-1.9,2.2-3.7,5.1-5.5C41,27.2,40.6,25.7,40.5,23.5z"/>
		<path d="M52.5,23.5c5.5,0,7.2,3.5,8.4,7.4c-1.6,2.1-3.1,3.3-5.2,3.9c-1.1-1.9-2-3.8-5-5.6C52.2,27.3,52.6,26,52.5,23.5z"/>
		<path d="M54.7,22.3c2.3,0,4.2-1.7,4.2-4c0-2.3-1.9-4.2-4.2-4.2c-2.3,0-4.2,1.7-4.2,4C50.5,20.4,52.4,22.3,54.7,22.3z"/>
	</symbol>

	<symbol id="svgAreaAmen" viewBox="0 0 72 72">
		<path d="M35.8,47.6l0.5,0.5l0,0l1.4,1.4l4,3.9c-3,1.2-6.3,1.5-9.6,0.7l-2.4,3.6c9.2,2.8,19.2-1.3,23.8-9.8L49.2,47
			c-1.8,2.9-4.5,5.1-7.5,6.3l0.1-5.6l0-2.1l0,0l0-0.7l7.6,1.7l12.5,2.8l-10.7-7l-6.7-4.4l0.5-0.5l0,0l1.4-1.5l4.1-4.1l-5.8-0.1
			l-1.2,0l0,0l-0.6,0l3.2-12.6l3.7-14.4l-7.8,12.7L35,28.6l-0.5-0.4l0,0l-1.1-1.1l-4-3.9c2.8-1.1,5.9-1.4,9-0.9l2.3-3.7
			c-9-2.4-18.6,1.7-23,10l4.2,0.9c1.8-2.9,4.5-5.1,7.5-6.3l-0.1,5.6l-0.1,2.8l-7.6-1.7L9.1,27.1l10.7,7l6.5,4.2l-2,2l-3.9,4
			c-1.2-3.1-1.5-6.5-0.7-9.8l-3.6-2.3c-2.9,9.2,1.1,19.2,9.5,23.9l1-4.2c-2.8-1.8-4.9-4.4-6.1-7.4l5.6,0.1l1.9,0l0,0l0.7,0l-2,8.8
			l-2.8,12.5l7-10.7L35.8,47.6z M32.5,37c0.7-1.7,2.6-2.4,4.3-1.7c1.7,0.7,2.4,2.6,1.7,4.3c-0.7,1.7-2.6,2.4-4.3,1.7
			C32.6,40.6,31.8,38.7,32.5,37z"/>
		<path d="M57.9,46.4l2.8,1.8c5.1-13-0.6-27.7-12.9-34L47,17.4C57.2,23,61.9,35.3,57.9,46.4z"/>
		<path d="M27.7,60.7l-1.8,2.8c13.3,5.1,28.3-1,34.3-14l-3.2-0.7C51.6,59.6,39,64.7,27.7,60.7z"/>
		<path d="M42.6,15.5l1.7-2.8c-13.1-4.5-27.6,1.6-33.4,14.3l3.2,0.7C19.3,17.2,31.5,12.1,42.6,15.5z"/>
		<path d="M13.2,30.2l-2.8-1.8c-5.2,13.3,0.8,28.4,13.7,34.4l0.7-3.2C14.1,54.1,9.1,41.5,13.2,30.2z"/>
		<path d="M46.1,20.9L45,25c5.3,3.8,7.9,10.6,6.3,17l3.6,2.3C57.8,35.4,54.1,25.7,46.1,20.9z"/>
	</symbol>
	<symbol id="svgTransit" viewBox="0 0 72 72">
		<path d="M42.9,6.8H30.4c-7.5,0-13.7,6.2-13.7,13.7v27.1c0,1.9,1.5,3.4,3.4,3.4h31.7c1.9,0,3.4-1.5,3.4-3.4V19.2
			C55.3,12.4,49.7,6.8,42.9,6.8z M23.6,44.2c-1.6,0-2.9-1.3-2.9-2.9c0-1.6,1.3-2.9,2.9-2.9c1.6,0,2.9,1.3,2.9,2.9
			C26.5,43,25.2,44.2,23.6,44.2z M48.5,44.2c-1.6,0-2.9-1.3-2.9-2.9c0-1.6,1.3-2.9,2.9-2.9c1.6,0,2.9,1.3,2.9,2.9
			C51.4,43,50.1,44.2,48.5,44.2z M51.3,25.9c0,2.5-2,4.5-4.5,4.5H25.2c-2.5,0-4.5-2-4.5-4.5v-6.5c0-2.5,2-4.5,4.5-4.5h21.6
			c2.5,0,4.5,2,4.5,4.5V25.9z"/>
		<polygon points="29.5,52.6 23.2,52.6 14.2,66 20.5,66 	"/>
		<polygon points="48.8,52.6 42.5,52.6 51.5,66 57.8,66 	"/>
	</symbol>
	<symbol id="svgInfo" viewBox="0 0 72 72">
		<path d="M39.5,19c3.8,0,6.8-3.1,6.8-6.9c0-3.4-2.2-5.8-5.4-5.8c-1.9,0-3.5,0.7-4.8,2c-1.3,1.4-2.1,3.3-2,5.1
			C34.1,16.8,36.3,19,39.5,19z"/>
		<path d="M41.6,52.1c-2,1.8-3.8,2.9-4.6,3.3c0-0.3,0.1-0.9,0.4-1.8l5.3-21.4c1-3.9,0.9-6.6-0.2-8c-0.6-0.7-1.3-1.1-2.3-1.1
			c-3.4,0-9.8,3.8-15.2,9l-0.5,0.5l2.2,4.3l1-0.8c1.8-1.5,3.4-2.5,4.2-2.9c0,0.3-0.1,0.7-0.3,1.4l-4.9,20.6
			c-1.1,4.4-1.1,7.2,0.1,8.8c0.7,0.9,1.6,1.3,2.9,1.3c3.5,0,10.3-4.2,14.8-9.2l0.5-0.6l-2.5-4L41.6,52.1z"/>
	</symbol>
	<symbol id="svgMovie" viewBox="0 0 72 72">
		<path display="none" d="M49,41c0,4.1-23.5,16-25,16s-3-1.3-3-3V29c0-1.7,1.4-3,3-3S49,36.9,49,41z"/>
		<path d="M29.5,27.3l21.4,12.4c1.4,0.8,1.4,2.9,0,3.7L29.5,55.7c-1.4,0.8-3.2-0.2-3.2-1.9V29.1C26.3,27.5,28.1,26.4,29.5,27.3z"/>
		<path d="M58,8H16c-4.4,0-8,3.6-8,8v39.7C8,61.3,12.7,66,18.4,66h37.3C61.3,66,66,61.3,66,55.6V16C66,11.6,62.4,8,58,8z M50,12.2
			c0-0.7,0.5-1.2,1.2-1.2h6.6c0.7,0,1.2,0.5,1.2,1.2v3.6c0,0.7-0.5,1.2-1.2,1.2h-6.6c-0.7,0-1.2-0.5-1.2-1.2V12.2z M38,12.2
			c0-0.7,0.5-1.2,1.2-1.2h6.6c0.7,0,1.2,0.5,1.2,1.2v3.6c0,0.7-0.5,1.2-1.2,1.2h-6.6c-0.7,0-1.2-0.5-1.2-1.2V12.2z M26,12.2
			c0-0.7,0.5-1.2,1.2-1.2h6.6c0.7,0,1.2,0.5,1.2,1.2v3.6c0,0.7-0.5,1.2-1.2,1.2h-6.6c-0.7,0-1.2-0.5-1.2-1.2V12.2z M14,12.2
			c0-0.7,0.5-1.2,1.2-1.2h6.6c0.7,0,1.2,0.5,1.2,1.2v3.6c0,0.7-0.5,1.2-1.2,1.2h-6.6c-0.7,0-1.2-0.5-1.2-1.2V12.2z M64,55.3
			c0,4.8-3.9,8.7-8.7,8.7H18.7c-4.8,0-8.7-3.9-8.7-8.7V24c0-2.2,1.8-4,4-4h46c2.2,0,4,1.8,4,4V55.3z"/>
	</symbol>
	<symbol id="svgCompFilter" viewBox="0 0 30 30">
		<rect x="6" y="9" width="3" height="3"/>
		<rect x="11" y="9" width="3" height="3"/>
		<rect x="6" y="13" width="3" height="3"/>
		<rect x="11" y="13" width="3" height="3"/>
		<rect x="6" y="17" width="3" height="3"/>
		<rect x="11" y="17" width="3" height="3"/>
		<path d="M11.3,4H8.8C5.7,4,3,6.6,3,9.7V26h14V9.7C17,6.6,14.4,4,11.3,4z M15,24h-3v-3H8v3H5V11.2
			C5,8,6.6,6.9,9.8,6.9h0.6c3.1,0,4.6,1.2,4.6,4.3V24z"/>
		<path d="M19,26h8V14.7c0-3.1-2.6-5.7-5.7-5.7H18v2.9h2.3c3.1,0,4.6,1.2,4.6,4.3V24h-3v-2h-3V26z"/>
		<rect x="19" y="15" width="2" height="2"/>
		<rect x="22" y="15" width="2" height="2"/>
		<rect x="19" y="18" width="2" height="2"/>
		<rect x="22" y="18" width="2" height="2"/>
	</symbol>
	<symbol id="svgIndFilter" viewBox="0 0 30 30">
		<circle  cx="14.5" cy="10.6" r="5.5"/>
		<path d="M14.5,18.7c-2.5,0-4-0.8-5.7-2.5C5.6,17.9,4,21.2,4,26c5,0,16.2,0,21,0c0-4.8-1.6-8.1-4.8-9.7
			C18.5,17.9,17.1,18.7,14.5,18.7z"/>
	</symbol>
	<symbol id="scrollUpArrowSVG" viewBox="0 0 30 30">
		<path d="M3,16L14.5,2L26,16h-6c0,0,0,10.4,0,12c-4-3-7-3-11,0c0-8,0-12,0-12H3z"/>
	</symbol>
	<symbol id="scrollDownArrowSVG" viewBox="0 0 30 30">
		<path d="M26,14L14.5,28L3,14h6C9,14,9,3.6,9,2c4,3,7,3,11,0c0,8,0,12,0,12H26z"/>
	</symbol>
	<symbol id="scrollUpPDFSVG" viewBox="0 0 38 38">
		<polygon points="32.7,23.6 19,9.9 5.3,23.6 8.7,27.1 19,16.9 29.2,27.1 "/>
	</symbol>
	<symbol id="scrollDownPDFSVG" viewBox="0 0 38 38">
		<polygon display="inline" points="5.3,15.4 19,29.1 32.7,15.4 29.2,11.9 19,22.1 8.7,11.9 "/>
	</symbol>
	<symbol id="pageUpPDFSVG" viewBox="0 0 38 38">
		<path display="inline" d="M11,7l-4,4v24h22V3H15L11,7z M28,34H8V11l7,0l0-7h13V34z"/>
		<polygon display="inline" points="26.7,25 18,16.3 9.3,25 11.5,27.2 18,20.7 24.5,27.2 "/>
	</symbol>
	<symbol id="pageDownPDFSVG" viewBox="0 0 38 38">
		<path display="inline" d="M11,7l-4,4v24h22V3H15L11,7z M28,34H8V11l7,0l0-7h13V34z"/>
		<polygon display="inline" points="9.3,18.5 18,27.2 26.7,18.5 24.5,16.3 18,22.8 11.5,16.3 	"/>
	</symbol>
	<symbol id="zoomOutPDFSVG" viewBox="0 0 38 38">
		<path display="inline" d="M18.5,5C12.1,5,7,10.1,7,16.5C7,22.9,12.1,28,18.5,28S30,22.9,30,16.5
			C30,10.1,24.9,5,18.5,5z M18.5,24c-4.1,0-7.5-3.4-7.5-7.5S14.4,9,18.5,9s7.5,3.4,7.5,7.5S22.6,24,18.5,24z"/>
		<path display="inline" d="M33.9,10h-1.4c-0.6,0-1.1-0.5-1.1-1.1V2.1c0-0.6,0.5-1.1,1.1-1.1h1.4
			C34.5,1,35,1.5,35,2.1v6.8C35,9.5,34.5,10,33.9,10z"/>
		<path display="inline" d="M31.3,30.9l-0.5,0.5c-0.7,0.7-1.9,0.7-2.6,0l-4.8-4.8c-0.7-0.7-0.7-1.9,0-2.6l0.5-0.5
			c0.7-0.7,1.9-0.7,2.6,0l4.8,4.8C32,29,32,30.2,31.3,30.9z"/>
		<path display="inline" d="M22.9,18h-8.8c-0.6,0-1.1-0.5-1.1-1.1v-0.8c0-0.6,0.5-1.1,1.1-1.1h8.8
			c0.6,0,1.1,0.5,1.1,1.1v0.8C24,17.5,23.5,18,22.9,18z"/>
	</symbol>
	<symbol id="zoomInPDFSVG" viewBox="0 0 38 38">
		<path display="inline" d="M18.5,5C12.1,5,7,10.1,7,16.5C7,22.9,12.1,28,18.5,28S30,22.9,30,16.5
			C30,10.1,24.9,5,18.5,5z M18.5,24c-4.1,0-7.5-3.4-7.5-7.5S14.4,9,18.5,9s7.5,3.4,7.5,7.5S22.6,24,18.5,24z"/>
		<path display="inline" d="M31.3,30.9l-0.5,0.5c-0.7,0.7-1.9,0.7-2.6,0l-4.8-4.8c-0.7-0.7-0.7-1.9,0-2.6l0.5-0.5
			c0.7-0.7,1.9-0.7,2.6,0l4.8,4.8C32,29,32,30.2,31.3,30.9z"/>
		<path display="inline" d="M22.9,18h-8.8c-0.6,0-1.1-0.5-1.1-1.1v-0.8c0-0.6,0.5-1.1,1.1-1.1h8.8
			c0.6,0,1.1,0.5,1.1,1.1v0.8C24,17.5,23.5,18,22.9,18z"/>
		<path display="inline" d="M17,20.9v-8.8c0-0.6,0.5-1.1,1.1-1.1h0.8c0.6,0,1.1,0.5,1.1,1.1v8.8
			c0,0.6-0.5,1.1-1.1,1.1h-0.8C17.5,22,17,21.5,17,20.9z"/>
	</symbol>
	<symbol id="clearSearchSVG" viewBox="0 0 38 38">
		<path d="M13,9l-9,9l9,9h18V9H13z M29,25H14l-7.4-7l7.4-7h15V25z"/>
		<path d="M21.5,17.9l3.6-3.6c0.4-0.4,0.4-1,0-1.4c-0.4-0.4-1-0.4-1.4,0l-3.6,3.6l-3.6-3.6c-0.4-0.4-1-0.4-1.4,0
		c-0.4,0.4-0.4,1,0,1.4l3.6,3.6l-3.6,3.6c-0.4,0.4-0.4,1,0,1.4c0.4,0.4,1,0.4,1.4,0l3.6-3.6l3.6,3.6c0.4,0.4,1,0.4,1.4,0
		c0.4-0.4,0.4-1,0-1.4L21.5,17.9z"/>
	</symbol>
	<symbol id="twitterSVG" viewBox="0 0 30 30">
		<path d="M14.3,11.3c-0.1-0.5-0.6-2.5,1.2-4.7c1.1-1.4,4.8-3,7.8,0c0.8-0.2,1.6-0.4,3.3-1.3
		c-0.6,1.9-2.3,2.8-2.3,2.8c1,0,2-0.4,3-0.8c0,0-1.2,1.7-2.6,2.7c0.3,8.2-6.6,17.9-18.5,15.2c-1.5-0.3-2.9-1-4.5-1.9
		c1.7,0,4.4,0.3,7.7-2.2c-1.6-0.1-3.8-0.8-4.9-3.7c0.9,0.1,1.4,0.1,2.4-0.1c-1.8-0.4-4.2-2.2-4.1-5.2c0.5,0.3,1.6,0.6,2.3,0.6
		c-1-0.5-3.5-3.4-1.6-7C6,8.8,9.7,11.1,14.3,11.3z"/>
	</symbol>
	<symbol id="twitterSVG" viewBox="0 0 30 30">
		<path d="M14.3,11.3c-0.1-0.5-0.6-2.5,1.2-4.7c1.1-1.4,4.8-3,7.8,0c0.8-0.2,1.6-0.4,3.3-1.3
		c-0.6,1.9-2.3,2.8-2.3,2.8c1,0,2-0.4,3-0.8c0,0-1.2,1.7-2.6,2.7c0.3,8.2-6.6,17.9-18.5,15.2c-1.5-0.3-2.9-1-4.5-1.9
		c1.7,0,4.4,0.3,7.7-2.2c-1.6-0.1-3.8-0.8-4.9-3.7c0.9,0.1,1.4,0.1,2.4-0.1c-1.8-0.4-4.2-2.2-4.1-5.2c0.5,0.3,1.6,0.6,2.3,0.6
		c-1-0.5-3.5-3.4-1.6-7C6,8.8,9.7,11.1,14.3,11.3z"/>
	</symbol>
</svg>