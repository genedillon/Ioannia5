<div class="directoryContainer activeFull">

	<% IF CombinedOn THEN %>
		<div class="companyContainer combinedList activeLeft">
			<div class="listHeader">
				<div class="setOne0"></div>
				<div class="setOne1"><%response.write (CombinedHeader)%></div>
				<div class="setOne2"><%response.write (SuiteHeader)%></div>
				<div class="setOne3"></div>
				<div class="setOne4"></div>
				<div class="setOne5"></div>
			</div>
			<div class="listDetailsHeader"><%response.write (CombinedHeader)%> Details</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings">
						<% do until qCombList.EOF%>
									<% DIM CompImageName %>
									<% CompImageName = (qCombList("ListingImage"))%>
									<% DIM CompImageLast3 %>
									<% CompImageLast3 = right(CompImageName, 3) %>
									<%IF CompImageLast3 = "pdf" Then%>
							<div class="companyListing clearfix pdfParent" data-listing="<%response.write(qCombList("ListingID"))%>" data-comp="<%response.write(qCombList("CompanyID"))%>" data-type="<%response.write(qCombList("Type"))%>">
								<div class="setOne0">
									<div class="infoLink">
										<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(qCombList("ListingImage"))%>" target="_top">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</a>
									</div>
								</div>
									<%ELSE%>
							<div class="companyListing clearfix" data-listing="<%response.write(qCombList("ListingID"))%>" data-comp="<%response.write(qCombList("CompanyID"))%>" data-type="<%response.write(qCombList("Type"))%>">
								<div class="setOne0">
									<a class="companyLink" href="ID=<%response.write(qCombList("CompanyID"))%>" target="_top">
										<div class="infoLink">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png"> -->
												<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</a>
							</div>
							<%END IF%>
								<div class="setOne1"><%response.write (qCombList("ListingName"))%></div>
								<div class="setOne2"><%response.write (qCombList("Suite"))%></div>
								<div class="setOne3"></div>
								<div class="setOne4"></div>
								<div class="setOne5"></div>
							<div class="compDetailInfo">
								<%IF qCombList("Type") = "Comp" Then%>
									<% IF qCombList("ListingImage") > "" THEN %>
						  						<img src="<%response.write (CustomProgramPath)%><%response.write (qCombList("ListingImage"))%>"><BR><BR>
					 				<% END IF %>
									<% IF qCombList("Logo") > "" THEN %>
						  						<img src="<%response.write (CustomProgramPath)%><%response.write (qCombList("Logo"))%>"><BR><BR>
					 				<% END IF %>
									<div class="compDetailTitle"><%response.write (qCombList("CompanyName"))%></div>
									<% IF qCombList("Building") > "" THEN %>Building: <%response.write (qCombList("Building"))%><br><% END IF %>
									<%response.write (SuiteHeader)%>: <%response.write (qCombList("Suite"))%><br>
									<% IF qCombList("Phone") > "" THEN %>Phone: <%response.write (qCombList("Phone"))%><br><% END IF %>
									<% IF qCombList("Description") > "" THEN %><%response.write (qCombList("Description"))%><br><% END IF %>
									<% IF (qIndividuals.recordcount > 0) AND (qContent("Individuals") <> 0) THEN %>
										<div class="listOfInd"><%response.write (IndivsLabel)%></div>
										<div class="compIndivCont"></div><!-- insert individuals in here -->
									<%END IF%>
								<%END IF%>
							</div>
							</div><!-- end tenant listing -->
						<% qCombList.movenext
						loop %>
					</div><!-- end listings -->
				</div>
			</div>
		</div><!-- end tenant container -->
	<%END IF%>

	<% IF CombinedOn = 0 And CompaniesOn THEN %>
		<div class="companyContainer activeLeft onlyCompanies">
			<div class="listHeader">
				<div class="setOne0"></div>
				<div class="setOne1"><%response.write (CompaniesHeader)%></div>
				<div class="setOne2"><%response.write (SuiteHeader)%></div>
				<div class="setOne3"></div>
				<div class="setOne4"></div>
				<div class="setOne5"></div>
			</div>
			<div class="listDetailsHeader"><%response.write (CompaniesLabel)%> - Detail</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings">
						<% do until qCombList.EOF%>
							<% DIM CompanyImageName %>
							<% CompanyImageName = (qCombList("ListingImage"))%>
							<% DIM CompanyImageLast3 %>
							<% CompanyImageLast3 = right(CompanyImageName, 3) %>
							<%IF CompanyImageLast3 = "pdf" Then%>
							<div class="companyListing clearfix pdfParent" data-listing="<%response.write(qCombList("ListingID"))%>" data-comp="<%response.write(qCombList("CompanyID"))%>" data-type="<%response.write(qCombList("Type"))%>">
								<div class="setOne0">
									<div class="infoLink">
										<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(qCombList("ListingImage"))%>" target="_top">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</a>
									</div>
								</div>
							<%ELSE%>
							<div class="companyListing clearfix" data-listing="<%response.write(qCombList("ListingID"))%>" data-comp="<%response.write(qCombList("CompanyID"))%>" data-type="<%response.write(qCombList("Type"))%>">
								<div class="setOne0">
									<a class="companyLink" href="ID=<%response.write(qCombList("CompanyID"))%>" target="_top">
										<div class="infoLink">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png"> -->
												<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</a>
								</div>
							<%END IF%>
								<div class="setOne1"><%response.write (qCombList("ListingName"))%></div>
								<div class="setOne2"><%response.write (qCombList("Suite"))%></div>
								<div class="setOne3"></div>
								<div class="setOne4"></div>
								<div class="setOne5"></div>
								<div class="compDetailInfo">
									<% IF qCombList("ListingImage") > "" THEN %>
					  						<img src="<%response.write (CustomProgramPath)%><%response.write (qCombList("ListingImage"))%>"><BR><BR>
					 				<% END IF %>
									<% IF qCombList("Logo") > "" THEN %>
					  						<img src="<%response.write (CustomProgramPath)%><%response.write (qCombList("Logo"))%>"><BR><BR>
					 				<% END IF %>
									<div class="compDetailTitle"><%response.write (qCombList("CompanyName"))%></div>
									<% IF qCombList("Building") > "" THEN %>Building: <%response.write (qCombList("Building"))%><br><% END IF %>
									<% IF qCombList("Floor") > "" THEN %>Floor: <%response.write (qCombList("Floor"))%><br><% END IF %>
									<%response.write (SuiteHeader)%>: <%response.write (qCombList("Suite"))%><br>
									<% IF qCombList("Phone") > "" THEN %>Phone: <%response.write (qCombList("Phone"))%><br><% END IF %>
									<% IF qCombList("Description") > "" THEN %><%response.write (qCombList("Description"))%><br><% END IF %>
									<% IF (qIndividuals.recordcount > 0) AND (qContent("Individuals") <> 0) THEN %>
										<div class="listOfInd"><%response.write (IndivsLabel)%></div>
										<div class="compIndivCont"></div><!-- insert individuals in here -->
									<%END IF%>
								</div>
							</div><!-- end company listing -->
						<% qCombList.movenext
						loop %>
					</div><!-- end listings -->
				</div>
			</div>
		</div><!-- end company container -->
	<%END IF%>



	<% IF CombinedOn = 0 And IndivsOn THEN %>
		<div class="individualsContainer <% IF IndivsOn THEN %>showIndividuals<% END IF %>">
			<div class="listHeader">
				<div class="setTwo0"></div>
				<div class="setTwo1"><%response.write (IndivsHeader)%></div>
				<div class="setTwo2"><%response.write (SuiteHeader)%></div>
				<div class="setTwo3"></div>
				<div class="setTwo4"></div>
				<div class="setTwo5"></div>
			</div>
			<div class="listDetailsHeader"><%response.write (IndivsLabel)%> - Detail</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings">
						<% do until qIndividuals.EOF%>
							<% DIM IndividualImageName %>
							<% IndividualImageName = (qIndividuals("IndImage"))%>
							<% DIM IndividualImageLast3 %>
							<% IndividualImageLast3 = right(IndividualImageName, 3) %>
							<%IF IndividualImageLast3 = "pdf" Then%>
							<div class="indivListing clearfix pdfParent" data-comp="<%response.write(qIndividuals("CompanyID"))%>" data-type="<%response.write(qIndividuals("Type"))%>">
								<div class="setTwo0">
									<div class="infoLink">
										<a href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(qIndividuals("IndImage"))%>" target="_top">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</a>
									</div>
								</div>
							<%ELSE%>
							<div class="indivListing clearfix" data-comp="<%response.write(qIndividuals("CompanyID"))%>" data-type="<%response.write(qIndividuals("Type"))%>">
								<div class="setTwo0">
									<a class="companyLink" href="ID=<%response.write(qIndividuals("CompanyID"))%>" target="_top">
										<div class="infoLink">
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" border="0"> -->
											<svg class="iconInfo"><use xlink:href="#svgInfo" /></svg>
										</div>
										</div>
									</a>
								</div>
							<%END IF%>
								<div class="setTwo1"><%response.write (qIndividuals("IndividualName"))%></div>
								<div class="setTwo2"><%response.write (qIndividuals("Suite"))%></div>
								<div class="setTwo3"></div>
								<div class="setTwo4"></div>
								<div class="setTwo5"></div>
								<div class="compDetailInfo">
									<% IF qIndividuals("IndImage") > "" THEN %>
					  						<img src="<%response.write (CustomProgramPath)%><%response.write (qIndividuals("IndImage"))%>"><BR><BR>
					 				<% END IF %>
									<div class="indDetailTitle"><%response.write (qIndividuals("IndividualName"))%></div>
									<% IF qIndividuals("iBuilding") > "" THEN %>Building: <%response.write (qIndividuals("iBuilding"))%><br><% END IF %>
									<% IF qIndividuals("Floor") > "" THEN %>Floor: <%response.write (qIndividuals("Floor"))%><br><% END IF %>
									<%response.write (SuiteHeader)%>: <%response.write (qIndividuals("Suite"))%><br>
									<% IF qIndividuals("Phone") > "" THEN %>Phone: <%response.write (qIndividuals("Phone"))%><br><% END IF %>
								</div>
							</div><!-- end individual listing -->
						<% qIndividuals.movenext
						loop %>
					</div><!-- end listings -->
				</div>
			</div>
		</div><!-- end individuals container -->
	<%END IF%>


	<% IF BuildingInfoButtonOn THEN %>
		<div class="bldgInfoContainer">
			<div class="listHeader">
				<div class="bldgInfoHeader"><%response.write (BuildingInfoButtonLabel)%></div>
			</div>
			<div class="list-window">	
				<div class="tbl_wrapper">
					<div class="bldgInfoContents mgmtCont">
						<div class="mgmtInfo">
						<div class="infoHead"><%response.write (ManagementHeader)%></div>
							<% IF qProperty("ManagementContact") > "" THEN %><%response.write (qProperty("ManagementContact"))%><% END IF %>
							<% IF qProperty("ManagementCompany") > "" THEN %><BR><%response.write (qProperty("ManagementCompany"))%><% END IF %>
							<% IF qProperty("ManagementLocation") > "" THEN %><BR><%response.write (qProperty("ManagementLocation"))%><% END IF %>
							<% IF qProperty("ManagementPhone") > "" THEN %><BR><%response.write (qProperty("ManagementPhone"))%><% END IF %>
							<% IF qProperty("EmergencyContact") > "" THEN %><BR><%response.write (qProperty("EmergencyContact"))%><% END IF %>
							<% IF qProperty("Description") > "" THEN %><BR><%response.write (qProperty("Description"))%><% END IF%>
							<% IF qProperty("ManagementLogo") > "" THEN %><BR><BR><img src="<%response.write (CustomProgramPath)%><%response.write (qProperty("ManagementLogo"))%>" /><% END IF%>
						</div>
					</div>
					<div class="bldgInfoContents leaseCont">
						<div class="leaseInfo">
						<div class="infoHead"><%response.write (LeasingHeader)%></div>
							<% IF qProperty("LeasingContact") > "" THEN %><%response.write (qProperty("LeasingContact"))%><% END IF %>
							<% IF qProperty("LeasingCompany") > "" THEN %><BR><%response.write (qProperty("LeasingCompany"))%><% END IF %>
							<% IF qProperty("LeasingLocation") > "" THEN %><BR><%response.write (qProperty("LeasingLocation"))%><% END IF %>
							<% IF qProperty("LeasingPhone") > "" THEN %><BR><%response.write (qProperty("LeasingPhone"))%><% END IF %>
							<% IF qProperty("LeasingLine5") > "" THEN %><BR><%response.write (qProperty("LeasingLine5"))%><% END IF %>
							<% IF qProperty("LeasingLogo") > "" THEN %><BR><BR><img src="<%response.write (CustomProgramPath)%><%response.write (qProperty("LeasingLogo"))%>" /><% END IF%>
						</div>
					</div>
				</div>
			</div>
		</div><!-- end bldgInfoContainer  -->
	<%END IF%>


	<% IF SpaceOn THEN %>
		<div class="spaceContainer">
			<div class="listHeader">
				<div class="spaceTitle boxListings"><%response.write (SpaceLabel)%></div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until LeaseSpace.EOF%>
							<%IF LeaseSpace("Floorplan") > "" THEN%>
								<% DIM SpaceImageName %>
								<% SpaceImageName = (LeaseSpace("Floorplan"))%>
								<% DIM SpaceImageLast3 %>
								<% SpaceImageLast3 = right(SpaceImageName, 3) %>
								<%IF SpaceImageLast3 = "pdf" Then%>
								<div class="spaceListing boxListings pdfParent">
									<div class="setFour0">
										<div class="infoLink">
											<a class="disableLink" href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(LeaseSpace("Floorplan"))%>" target="_top">
												<div class="infoDiv">
													<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
													<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
												</div>
											</a>
										</div>
									</div>
								<%ELSEIF SpaceImageLast3 = "jpg" Then%>
								<div class="spaceListing boxListings jpgParent">
									<div class="setFour0">
										<div class="infoLink">
											<img class="jpgImg" src="<%response.write (CustomProgramPath)%><%response.write(LeaseSpace("Floorplan"))%>"></img>
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
								<%END IF%>
							<%ELSE%>
								<div class="spaceListing boxListings nothingHere">
									<div class="setFour0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
							<%END IF%>
									<div class="setFour1"><%response.write (LeaseSpace("Suite"))%></div>
									<div class="setFour2">
										<div><%response.write (LeaseSpace("SpaceSize"))%></div>
										<%IF LeaseSpace("Cost") > "" Then%>
											<div class="spaceSubset"><%response.write (LeaseSpace("Cost"))%></div>
										<%END IF%>
									</div>
									<div class="setFour3">
										<div>Available: <br><span class="spaceSubset"><%response.write (LeaseSpace("Availability"))%></span></div>
										<%IF LeaseSpace("Description") > "" Then%>
											<div class="spaceSubset"><%response.write (LeaseSpace("Description"))%></div>
										<%END IF%>
									</div>
									<div class="setFour4"></div>
									<div class="setFour5"></div>
								</div><!-- end spaceListing -->
						<% LeaseSpace.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end space container -->
	<%END IF%>

	<% IF BldgAmenOn THEN %>
		<div class="bldgAmenContainer">
			<div class="listHeader">
				<div class="bldgAmenTitle boxListings"><%response.write (BldgAmenLabel)%></div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until qAmenities.EOF%>
							<%IF qAmenities("PhotoFile") > "" THEN%>
								<% DIM BldgAmenImageName %>
								<% BldgAmenImageName = (qAmenities("PhotoFile"))%>
								<% DIM BldgAmenImageLast3 %>
								<% BldgAmenImageLast3 = right(BldgAmenImageName, 3) %>
								<%IF BldgAmenImageLast3 = "pdf" Then%>
								<div class="bldgAmenListing boxListings pdfParent">
									<div class="setThree0">
										<div class="infoLink">
											<a class="disableLink" href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(qAmenities("PhotoFile"))%>" target="_top">
												<div class="infoDiv">
													<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
													<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
												</div>
											</a>
										</div>
									</div>
								<%ELSEIF BldgAmenImageLast3 = "jpg" Then%>
								<div class="bldgAmenListing boxListings jpgParent"> <!-- add method to display JPEG -->
									<div class="setThree0">
										<div class="infoLink">
											<img class="jpgImg" src="<%response.write (CustomProgramPath)%><%response.write(qAmenities("PhotoFile"))%>"></img>
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
								<%END IF%>
							<%ELSE%>
								<div class="bldgAmenListing boxListings nothingHere">
									<div class="setThree0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
							<%END IF%>
									<div class="setThree1"><%response.write (qAmenities("AmenityName"))%></div>
									<div class="setThree2">
										<div><%response.write (qAmenities("Location"))%></div>
										<%IF qAmenities("Description") > "" Then%>
										<div class="bldgAmenSubset"><%response.write (qAmenities("Description"))%></div>
										<%END IF%>
									</div>
									<div class="setThree3"></div>
									<div class="setThree4"></div>
									<div class="setThree5"></div>
								</div><!-- close bldgAmenListing  -->
						<% qAmenities.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end bldgAmen container -->
	<%END IF%>
	

	<% IF List12On THEN %>
		<div class="list12Container">
			<div class="listHeader">
				<div class="list12Title boxListings"><%response.write (List12Label)%></div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until List12List.EOF%>
							<%IF List12List("ImageName") > "" Then%>
								<% DIM List12ImageName %>
								<% List12ImageName = (List12List("ImageName"))%>
								<% DIM List12ImageLast3 %>
								<% List12ImageLast3 = right(List12ImageName, 3) %>
								<%IF List12ImageLast3 = "pdf" Then%>
								<div class="list12Listing boxListings pdfParent">
									<div class="setSix0">
										<div class="infoLink">
											<a class="disableLink" href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(List12List("ImageName"))%>" target="_top">
												<div class="infoDiv">
													<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
													<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
												</div>
											</a>
										</div>
									</div>
								<%ELSEIF List12ImageLast3 = "jpg" Then%>
								<div class="list12Listing boxListings jpgParent"> <!-- add method to display JPEG -->
									<div class="setSix0">
										<div class="infoLink">
											<img class="jpgImg" src="<%response.write (CustomProgramPath)%><%response.write(List12List("ImageName"))%>"></img>
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
								<%END IF%>
							<%ELSE%>
								<div class="list12Listing boxListings nothingHere">
									<div class="setSix0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
							<%END IF%>
									<div class="setSix1"><%response.write (List12List("Text1"))%></div>
									<div class="setSix2"><%response.write (List12List("Text2"))%></div>
									<div class="setSix3"><%response.write (List12List("Text3"))%></div>
									<div class="setSix4"><%response.write (List12List("Text4"))%></div>
									<div class="setSix5"><%response.write (List12List("Text5"))%></div>
								</div><!-- close list12Listing -->
						<% List12List.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end list12 container -->
	<%END IF%>



<!--For future use creating listings of URLS in List12 by entering "URL" in the Text2 Label field on content maint page -->

	<% IF List12URLOn THEN %>
		<div class="list12Container">
			<div class="listHeader">
				<div class="list12Title boxListings">Web Links</div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until URLList.EOF%>
								<div class="list12Listing nothingHere">
									<div class="setSix0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
									<div class="setSix1"><%response.write (URLList("Text2"))%></div>
									<div class="setSix2"></div>
									<div class="setSix3"></div>
									<div class="setSix4"></div>
									<div class="setSix5"></div>
								</div><!-- close list12Listing -->
						<% URLList.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end list12 container -->
	<%END IF%>


<!--For future use creating listings of YouTube videos in List12 by entering "Video" in the Text3 Label field on content maint page, and entering their youtube URL codes -->

	<% IF List12VideoOn THEN %>
		<div class="list12Container">
			<div class="listHeader">
				<div class="list12Title boxListings">Videos</div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until VideoList.EOF%>
								<div class="list12Listing nothingHere">
									<div class="setSix0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
									<div class="setSix1"><%response.write (VideoList("Text3"))%></div>
									<div class="setSix2"></div>
									<div class="setSix3"></div>
									<div class="setSix4"></div>
									<div class="setSix5"></div>
								</div><!-- close list12Listing -->
						<% VideoList.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end list12 container -->
	<%END IF%>










	<% IF AnnOn THEN %>
		<div class="annContainer">
			<div class="listHeader">
				<div class="annTitle boxListings"><%response.write (AnnLabel)%></div>
			</div>
			<div class="list-window">
				<div class="tbl_wrapper">
					<div class="listings clearfix">
						<% do until qMeetings.EOF%>
							<%IF qMeetings("AnnounceImageName") > "" Then%>
								<% DIM AnnImageName %>
								<% AnnImageName = (qMeetings("AnnounceImageName"))%>
								<% DIM AnnImageLast3 %>
								<% AnnImageLast3 = right(AnnImageName, 3) %>
								<%IF AnnImageLast3 = "pdf" Then%>
								<div class="annListing boxListings pdfParent">
									<div class="setFive0">
										<div class="infoLink">
											<a class="disableLink" href="<%response.write (TS41FilePath)%>pdfjs/web/viewer.html?file=<%response.write (PDFPath)%><%response.write(qMeetings("AnnounceImageName"))%>" target="_top">
												<div class="infoDiv">
													<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
													<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
												</div>
											</a>
										</div>
									</div>
								<%ELSEIF AnnImageLast3 = "jpg" Then%>
								<div class="annListing boxListings jpgParent">
									<div class="setFive0">
										<div class="infoLink">
											<img class="jpgImg" src="<%response.write (CustomProgramPath)%><%response.write(qMeetings("AnnounceImageName"))%>"></img>
											<div class="infoDiv">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
								<%END IF%>
							<%ELSE%>
								<div class="annListing boxListings nothingHere">
									<div class="setFive0">
										<div class="infoLink">
											<div class="infoDiv noImage">
												<!-- <img src="<%response.write (TemplatePath)%>images/linkText.png" /> -->
												<svg class="iconInfo offsetIconInfo"><use xlink:href="#svgInfo" /></svg>
											</div>
										</div>
									</div>
							<%END IF%>
									<div class="setFive1">
										<div class="annName"><%response.write (qMeetings("Name"))%></div>
										<div><%response.write (qMeetings("Location"))%></div>
									</div>
									<div class="setFive2 annDate">
										<div>
											<%meetingStartDate = (qMeetings("StartDate"))%>
											<%meetingStartDateMod=Replace(meetingStartDate,"/201","/1") %>
											<%meetingEndDate = (qMeetings("EndDate"))%>
											<%meetingEndDateMod=Replace(meetingEndDate,"/201","/1") %>
											<%response.write (meetingStartDateMod)%>
											<% IF qMeetings("StartDate") <> qMeetings("EndDate") THEN %> - 
												<%response.write (meetingEndDateMod)%>
											<%END IF%>
										</div>
										<div class="annTime">
											<%response.write (mid(qMeetings("StartTime"),1,4))%>	
											<%response.write (mid(qMeetings("StartTime"),8,9))%>
											<%IF qMeetings("EndTime") > "" Then%> - 
												<%response.write (mid(qMeetings("EndTime"),1,4))%>
												<%response.write (mid(qMeetings("EndTime"),8,9))%>
											<%END IF%>
										</div>
									</div>
									<div class="setFive3">
										<%response.write (qMeetings("Description"))%>
									</div>
									<div class="setFive4"></div>
									<div class="setFive5"></div>
								</div><!-- close annListing -->
						<% qMeetings.movenext
						loop %>
					</div><!-- end listings -->
				</div><!-- end table wrapper -->
			</div><!-- end list window -->
		</div><!-- end Announcements container -->
	<%END IF%>



	<div class="fullHorizLine"></div>
</div><!-- end directoryContainer -->
	



<!-- KEYBOARD -->

<div id="scrollSearch" class="controlOn">
	<svg class="scrollUpBtn iconSVG"><use xlink:href="#scrollUpArrowSVG" /></svg>
	<svg class="scrollDownBtn iconSVG"><use xlink:href="#scrollDownArrowSVG" /></svg>
	<!-- <div class="scrollUpBtn" id="scroll_up"></div> -->
	<!-- <div class="scrollDownBtn" id="scroll_down"></div> -->
	<div class="searchKeyboard">Search</div>
	<div class="listBtn">List All</div>
	<div id="compFilter"><svg class="svgCompFilter iconSVG"><use xlink:href="#svgCompFilter" /></svg></div>
	<div id="indFilter"><svg class="svgIndFilter iconSVG"><use xlink:href="#svgIndFilter" /></svg></div>
</div>
<div id="scrollSpace" class="">
	<svg class="scrollSpaceUpBtn scrollUpBtn iconSVG" id="scrollSpace_up"><use xlink:href="#scrollUpArrowSVG" /></svg>
	<svg class="scrollSpaceDownBtn scrollDownBtn iconSVG" id="scrollSpace_down"><use xlink:href="#scrollDownArrowSVG" /></svg>
	<!-- <div class="scrollSpaceUpBtn scrollUpBtn" id="scrollSpace_up"></div> -->
	<!-- <div class="scrollSpaceDownBtn scrollDownBtn" id="scrollSpace_down"></div> -->
</div>
<div id="searchField">
	<div id="textEntry"></div>
	<div class="clearField">
		<svg class="clearSearchSVG iconSVG" id="scrollSpace_up"><use xlink:href="#clearSearchSVG" /></svg>
	</div>
</div>
<div id="keyboard" class="keyboard">
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
	<svg class="scrollUpBtn iconSVG" id="scroll_up"><use xlink:href="#scrollUpArrowSVG" /></svg>
	<!-- <div class="scrollUpBtn" id="scroll_up"></div> -->
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
	<svg class="scrollDownBtn iconSVG" id="scroll_down"><use xlink:href="#scrollDownArrowSVG" /></svg>
	<!-- <div class="scrollDownBtn" id="scroll_down"></div> -->
</div>
<div class="coverKeyboard"></div><!-- prevents button actions when detail is shown -->
<!-- end KEYBOARD -->


