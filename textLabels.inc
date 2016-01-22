<!-- BUTTONS Text Labels -->

<% IF Industry = "MOB" THEN %><% CombinedLabel = "List of Tenants" %>
<% ELSEIF Industry = "Healthcare" THEN %><% CombinedLabel = "List of Departments" %>
<% ELSEIF Industry = "Education" THEN %><% CombinedLabel = "List of Departments" %>
<% ELSEIF Industry = "Government" THEN %><% CombinedLabel = "List of Departments" %>
<% ELSEIF Industry = "Company HQ" THEN %><% CombinedLabel = "Staff Listings" %>
<% ELSEIF Industry = "Commercial Office" THEN %><% CombinedLabel = "List of Tenants" %>
<%ELSE%><% CombinedLabel = "List of Tenants" %>
<%END IF%>

<% IF qContent("CombinedButLabel") > "" THEN CombinedLabel = qContent("CombinedButLabel") %>

<% IF Industry = "MOB" THEN %><%CompaniesLabel = "List of Practices" %>
<% ELSEIF Industry = "Healthcare" THEN %><%CompaniesLabel = "List of Departments" %>
<% ELSEIF Industry = "Education" THEN %><%CompaniesLabel = "List of Departments" %>
<% ELSEIF Industry = "Government" THEN %><%CompaniesLabel = "List of Departments" %>
<% ELSEIF Industry = "Company HQ" THEN %><%CompaniesLabel = "List of Departments" %>
<% ELSEIF Industry = "Commercial Office" THEN %><%CompaniesLabel = "List of Companies" %>
<%ELSE%><% CompaniesLabel = "List of Companies" %>
<%END IF%>

<% IF qContent("CompButLabel") > "" THEN CompaniesLabel = qContent("CompButLabel") %>

<% IF Industry = "MOB" THEN %><%IndivsLabel = "List of Physicians" %>
<% ELSEIF Industry = "Healthcare" THEN %><%IndivsLabel = "List of Physicians" %>
<% ELSEIF Industry = "Education" THEN %><%IndivsLabel = "List of Individuals" %>
<% ELSEIF Industry = "Government" THEN %><%IndivsLabel = "List of Individuals" %>
<% ELSEIF Industry = "Company HQ" THEN %><%IndivsLabel = "List of Individuals" %>
<% ELSEIF Industry = "Commercial Office" THEN %><%IndivsLabel = "List of Individuals" %>
<%ELSE%><% IndivsLabel = "List of Individuals" %>
<%END IF%>

<% IF qContent("IndButLabel") > "" THEN IndivsLabel = qContent("IndButLabel") %>


<% IF qContent("LeaseButLabel") > "" THEN SpaceLabel = qContent("LeaseButLabel") ELSE SpaceLabel = "Space Available" %>
<% IF qContent("AmenButLabel") > "" THEN BldgAmenLabel = qContent("AmenButLabel") ELSE BldgAmenLabel = "Building Amenities" %>
<% IF qContent("AnnounceButLabel") > "" THEN AnnLabel = qContent("AnnounceButLabel") ELSE AnnLabel = "List of Events" %>
<% IF qContent("L12ButLabel") > "" THEN List12Label = qContent("L12ButLabel") ELSE List12Label = "Search Listings" %>
<% IF qContent("PropButLabel") > "" THEN BuildingInfoButtonLabel = qContent("PropButLabel") ELSE BuildingInfoButtonLabel = "Building Info" %>
<% IF qContent("PDFUploadLabel") > "" THEN PDFLabel = qContent("PDFUploadLabel") ELSE PDFLabel = "PDF Information" %>
<% IF qContent("PDF2Label") > "" THEN PDF2Label = qContent("PDF2Label") ELSE PDF2Label = "PDF Info 2" %>
<% IF qContent("PDF3Label") > "" THEN PDF3Label = qContent("PDF3Label") ELSE PDF3Label = "PDF Info 3" %>
<% IF qContent("PDF4Label") > "" THEN PDF4Label = qContent("PDF4Label") ELSE PDF4Label = "PDF Info 4" %>


<% TSLiveTrafButtonLabel = "Local Traffic" %>
<% TSLiveAmenButtonLabel = "Area Amenities" %>
<% TSLiveTransitButtonLabel = "Transit Information" %>

<% URLLabel = "Web Site" %>
<% URL2Label = "Web Site 2" %>

<!-- Button Icons for PDFs  -->
<% GreenText = "Green" %>
<% LEEDText = "LEED" %>
<% MapText = "Map" %>
<% PDFBtnIcon = "svgPDF" %>
<% PDFBtn2Icon = "svgPDF" %>
<% PDFBtn3Icon = "svgPDF" %>
<% PDFBtn4Icon = "svgPDF" %>
<% IF (inStr(PDFLabel, GreenText) > 0) OR (inStr(PDFLabel, LEEDText) > 0) THEN PDFBtnIcon = "svgPDFLeed"%>
<% IF (inStr(PDF2Label, GreenText) > 0) OR (inStr(PDF2Label, LEEDText) > 0) THEN PDFBtn2Icon = "svgPDFLeed"%>
<% IF (inStr(PDF3Label, GreenText) > 0) OR (inStr(PDF3Label, LEEDText) > 0) THEN PDFBtn3Icon = "svgPDFLeed"%>
<% IF (inStr(PDF4Label, GreenText) > 0) OR (inStr(PDF4Label, LEEDText) > 0) THEN PDFBtn4Icon = "svgPDFLeed"%>
<% IF (inStr(PDFLabel, MapText) > 0) THEN PDFBtnIcon = "svgPDFMap"%>
<% IF (inStr(PDF2Label, MapText) > 0) THEN PDFBtn2Icon = "svgPDFMap"%>
<% IF (inStr(PDF3Label, MapText) > 0) THEN PDFBtn3Icon = "svgPDFMap"%>
<% IF (inStr(PDF4Label, MapText) > 0) THEN PDFBtn4Icon = "svgPDFMap"%>


<!-- Column Header, etc., Labels - some gotten from the Users table in DB -->
<% IF Industry = "MOB" THEN %><%CombinedHeader = "Tenant" %>
<% ELSEIF Industry = "Healthcare" THEN %><%CombinedHeader = "Department" %>
<% ELSEIF Industry = "Education" THEN %><%CombinedHeader = "Department" %>
<% ELSEIF Industry = "Government" THEN %><%CombinedHeader = "Department" %>
<% ELSEIF Industry = "Company HQ" THEN %><%CombinedHeader = "Name" %>
<% ELSEIF Industry = "Commercial Office" THEN %><%CombinedHeader = "Tenant" %>
<%ELSE%><%CombinedHeader = "Tenant" %>
<%END IF%>

<% IF Industry = "MOB" THEN %><%SuiteHeader = "Suite" %>
<% ELSEIF Industry = "Healthcare" THEN %><%SuiteHeader = "Room" %>
<% ELSEIF Industry = "Education" THEN %><%SuiteHeader = "Room" %>
<% ELSEIF Industry = "Government" THEN %><%SuiteHeader = "Room" %>
<% ELSEIF Industry = "Company HQ" THEN %><%SuiteHeader = "Suite" %>
<% ELSEIF Industry = "Commercial Office" THEN %><%SuiteHeader = "Suite" %>
<%ELSE%><% SuiteHeader = "Suite" %>
<%END IF%>

<% CompaniesHeader = qContent("CompNameLabel") %>
<% IndivsHeader = qContent("IndNameLabel") %>
<% BldgAmenHeader = qContent("AmenNameLabel") %>
<% List12Header = qContent("L12TExtLabel1") %>
<% AnnHeader = "Event" %>

<% ManagementHeader = "Managed by:" %>
<% LeasingHeader = "Leased by:" %>

<% TouchSourceLabel = "TouchSource<br>www.TouchSource.com" %>