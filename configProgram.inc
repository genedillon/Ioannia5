<!-- Program Configuration -->

<!-- Major logic, TSLive variables -->
<% IF (qContent("Static") <> 0) THEN StaticOn = 1 %>
<% IF (qContent("TSLive") <> 0) THEN TSLiveAllOn = 1 %>

<!-- CSS and Paths -->
	<% IF StaticOn THEN %> 
	<link rel="stylesheet" href="style_static.css">
	<%ELSE%>
	<link rel="stylesheet" href="style_ds.css">
	<%END IF%>

	<% IF (qContent("CustomStyle") <> 0) THEN %> 
	<% CustomProgramPath = "../Program/" %>
	<% TS41FilePath = "../../../../TS41/" %>
	<link rel="stylesheet" href="style_custom.css">
	<% ELSE %>
	<% CustomProgramPath = "../../asp/" & request.querystring("PropNum") & "/Common/Program/" %>
	<% TS41FilePath = "../" %>
	<% END IF %>

	<% PDFPath = "../../../asp/" & request.querystring("PropNum") & "/Common/Program/" %>
	
	<link rel="stylesheet" href="<%response.write (CustomProgramPath)%>override.css">


<% Industry = qContent("Industry") %>
<% ZipPostal = qContent("ZipPostal") %>
<% Latitude = qContent("Latitude") %>
<% Longitude = qContent("Longitude") %>
<% AmenityZoom = qContent("AmenityZoom") %>
<% IF (AmenityZoom < "1") OR (IsNull(AmenityZoom)) THEN AmenityZoom = "16" %>
<% TrafficZoom = qContent("TrafficZoom") %>
<% IF (TrafficZoom < "1") OR (IsNull(TrafficZoom)) THEN TrafficZoom = "12" %>
<% TransitURL = qContent("TransitURL") %>
<% Template = qContent("Template") %>
<% ScreenResPath = "" %>
<% ScreenResolution = qContent("ScreenResolution") %>
<% IF ScreenResolution > "" THEN %>
	<% IF ScreenResolution <> "1920x1080" THEN %>
		<% ScreenResPath = "-" & ScreenResolution %>
	<%END IF%>
<%END IF%>
<% TemplatePath = TS41FilePath & Template & ScreenResPath & "/" %>

<!-- Background Images -->
<% bgFileName = "bg_main.jpg" %>
<% bgFileName2 = TemplatePath & "images/bg_mainpage2.jpg" %>
<% bgListFileName = TemplatePath & "images/bg_directory.png" %>
<% bgWeatherFileName = TemplatePath & "images/bg_weather.png" %>
<% IF StaticOn THEN%>
	<% bgTSLiveFileName = TemplatePath & "images/bg_TSLiveStatic.png" %>
	<%ELSE%>
	<%bgTSLiveFileName = TemplatePath & "images/bg_TSLive.png" %>
<% END IF %>

<!-- Button Choices -->
<% IF (qContent("Combined") <> 0) THEN CombinedOn = 1 %>
<% IF ((CombinedOn = 0) AND (qContent("Companies") <> 0)) THEN CompaniesOn = 1 %>
<% IF ((CombinedOn = 0) AND (qContent("Individuals") <> 0)) THEN IndivsOn = 1 %>
<% IF qContent("Space") <> 0 THEN SpaceOn = 1 %>
<% IF qContent("Amenities") <> 0 THEN BldgAmenOn = 1 %>
<% IF qContent("Announcements") <> 0 THEN AnnOn = 1 %>
<% IF qContent("List12") <> 0 THEN List12On = 1 %>
<% BuildingInfoButtonOn = 0 %>
<!-- IU/TSLive Button Choices -->
<% IF qContent("PDFUpload") <> 0 THEN PDFOn = 1 %>
<% IF qContent("PDFUpload2") <> 0 THEN PDF2On = 1 %>
<% IF qContent("PDFUpload3") <> 0 THEN PDF3On = 1 %>
<% IF qContent("PDFUpload4") <> 0 THEN PDF4On = 1 %>
<% URLOn = 0 %>
<% URL2On = 0 %>
<% VideoOn = 0 %>
<% Video2On = 0 %>
<% IF TSLiveAllOn AND  qContent("AmenityDisplay") <> 0 THEN TSLiveAmenButtonOn = 1 %>
<% IF TSLiveAllOn AND  qContent("TrafficDisplay") <> 0 THEN TSLiveTrafButtonOn = 1 %>
<% IF TSLiveAllOn AND  (qContent("TransitDisplay") <> 0) AND  (qContent("TransitURL") > "") THEN TSLiveTransitButtonOn = 1 %>

<!-- Display TSLive Elements by Default, Without Touching a Button -->
<% IF TSLiveAllOn THEN TSLiveNewsOn = 1 %>
<% IF TSLiveAllOn THEN TSLiveWeatherOn = 1 %>
<% IF (qContent("Stocks") <> 0) THEN TSLiveStocksOn = 1 %>

<!-- Display Other TSLive Elements by Default, Without Touching a Button - rare usage, usually on static programs-->
<% TSLiveTrafficDisplayOn = 0 %>
<% TSLiveTransitDisplayOn = 0 %>

<!-- Display Standard Elements -->
<% IF (qContent("AttractImages") <> 0) THEN SlideshowOn = 1 %>
<% IF (qContent("SlideShowFull") <> 0) AND (StaticOn = 0) THEN SlideShowFull = 1 %><!-- ==changing this has no effect for VERT== -->

<% ScrollMsgOn = 0 %>
<% TouchSourceOn = 1 %>

<% IF SlideShowFull AND  TSLiveNewsOn THEN SlideShowType = "pics2" %><!-- ==changing this has no effect for VERT== -->
<% IF SlideShowFull AND  (TSLiveNewsOn = 0) THEN SlideShowType = "pics3" %><!-- ==only one size slideshow is being used== -->

<!-- AUTOMATIC LOGIC -->
<!-- If no records, set any number back to zero to turn off display of button -->
<% IF qCombList.recordcount = 0 THEN CombinedOn = 0 %>
<% IF qCompanies.recordcount = 0 THEN CompaniesOn = 0 %>
<% IF qIndividuals.recordcount = 0 THEN IndivsOn = 0 %>
<% IF LeaseSpace.recordcount = 0 THEN SpaceOn = 0 %>
<% IF qAmenities.recordcount = 0 THEN BldgAmenOn = 0 %>
<% IF qMeetings.recordcount = 0 THEN AnnOn = 0 %>
<% IF List12List.recordcount = 0 THEN List12On = 0 %>

<!-- Social Media / List12 - check -->
<% IF qContent("L12TextLabel1") = "Twitter" THEN %> 
	<% ScrollMsgOn = 0 %>
	<% List12On = 0 %>
	<% TwitterOn = 1 %>
<% END IF %>

<% IF qContent("L12TextLabel2") = "URL" THEN %> 
	<% List12URLOn = 1 %>
<% END IF %>

<% IF qContent("L12TextLabel3") = "Video" THEN %> 
	<% List12VideoOn = 1 %>
<% END IF %>




<!-- Display Building Info in Header IF it exists, otherwise no display, or no button shown -->
<% IF (qContent("Property") <> 0)  AND ((qProperty("ManagementContact") > "") OR (qProperty("LeasingContact") > "")) THEN %>
	<% IF (qContent("PropertyDisplay") = "Button")  THEN %>
		<% BuildingInfoButtonOn = 1 %>
	<% ELSE %>
		<% BuildingInfoDisplayOn = 1 %>
	<% END IF %>
<% END IF %>



<!-- To turn on Building Info header area for custom display of mainLogo.png, or text, etc. -->
<% IF (qContent("MainLogoDisplay") <> 0) THEN MainLogoDisplay = 1 %>

<% IF MainLogoDisplay = 1  THEN BuildingInfoDisplayOn = 1  %>
<% IF qProperty("BuildingLogo") > "" THEN BuildingLogo = qProperty("BuildingLogo")  %>

<% MainLogoType = qContent("MainLogoType") %>

<!-- Count Number of Directory Buttons -->
<% DirectoryButtonNumber = CombinedOn + CompaniesOn + IndivsOn + SpaceOn + BldgAmenOn + AnnOn + List12On + BuildingInfoButtonOn + PDFOn + PDF2On + PDF3On + PDF4On + URLOn + URL2On + VideoOn + Video2On %>

<!-- Count Number of TSLive Buttons -->
<% TSLiveButtonNumber = TSLiveAmenButtonOn + TSLiveTrafButtonOn + TSLiveTransitButtonOn %>

<!-- Count Total Number of Buttons -->
<% TotalButtonNumber = DirectoryButtonNumber + TSLiveButtonNumber %>

<!-- Get background image file names from config file, write into styles -->
<style type="text/css">
	.bgMain {
			background: url('<%response.write (bgFileName)%>') no-repeat, rgb(89, 126, 175);
	}
	.bgMain2 {
		background: url('<%response.write (bgFileName2)%>');
	}
	.weatherContainer {
		background: URL('<%response.write (bgWeatherFileName)%>');
	}
	.addressResize {
		font-size: <%response.write (qContent("PropNameFont"))%>px;
	}
</style>
