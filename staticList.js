// ============ PAGE INITIALIZATION ==================
$(document).ready(function(){
	$('.weatherContainer').delay(1500).animate({
		opacity: 1
	});
}); 

// Do this after page loads
$(window).load(function(){
	prep();
});


// ========================= SCROLLING MESSAGE ==============================
var setScrollMsgWidth = 1080; // default width for page
var setScrollMsgLeft = 0; // default


// ============================ STATIC LISTINGS ==================================
var col1 = $('.col1');
var col1List = $('.col1Listings');
var col2;
var col2List = $('.col2Listings');
var col3;
var col3List = $('.col3Listings');
// var col4;
// var col4List = $('.col4Listings');
// var col5;
// var col5List = $('.col5Listings');
var item = $('.col0 .companyListing'); // these are the listings
var itemHeight = 0;
var totalItemHeight = 0;
var col1Height = $('.col1').height();
var col1ListHeight;
var col2Height;
var col2ListHeight;
var col3Height;
var col3ListHeight;
// var col4Height;
// var col4ListHeight;
// var col5Height;
// var col5ListHeight;
var currentFontSize = 0;
var count = item.length;

function rebuild() { // Rebuild columns - reset to defaults, shrink font size and cycle through again
	activeCol = 1;
	activeCount = 0;
	itemHeight = 0;
	totalItemHeight = 0;
	$('.cont2').remove(); // remove continued elements
	$('.cont3').remove();
	// $('.cont4').remove();
	// $('.cont5').remove();
	// $('.directoryContainer').find('span').remove();
	$('.staticHeader').remove();
	$('.staticListingLine').remove();
	lineCount = 0;
	doOnceCol3 = true;
	// col5List.children().prependTo('.col0'); // send listings back to original container
	// col4List.children().prependTo('.col0');
	col3List.children().prependTo('.col0');
	col2List.children().prependTo('.col0');
	col1List.children().prependTo('.col0');
	header1 = true;
	header2 = true;
	header3 = true;
	// header4 = true;
	// header5 = true;
	if (actualFontSize >= 6) {
		prep();
	}
}


var activeCol = 1; // active column to place listings in
var indCodeOn = false; // set to true to use continued from company - ASP needs to be tweaked to accomodate this feature
var reduceFontCount = 0; // number of times font has been reduced in size
var actualFontSize = parseFloat($('#listings').css('fontSize')); // get initial font size from container, remove px from string
var activeCount = 0; // current number of listings processed

var addLines = true; //  ============== set true to add lines =======================================
var addLinesEvery = 2; // ============= add listing lines after this many listings ===========================
var staticDebug = false; // ============ set true to see detailed info ==================================
var headerOn = false; //  ============= show column headers if true ==================================

var headerContent = $('.listHeader').html(); // get content from original ASP header before its removed
var header1, header2, header3, header4, header5;
var lineCount = 0;
var addLineMargins = 0;
var addLineHeight = 1;

function addListingLines(column) { // adds horizontal lines
	if ((addLines === true) && (!$('.companyContainer').hasClass('noLines'))) {
		lineCount++;
		if (lineCount % addLinesEvery === 0) { // calculate when to add a line
			$('.staticListingLine').css('marginBottom', addLineMargins).css('marginTop', addLineMargins); // set line margins - increases with autoBalance function
			if (staticDebug === true) {
				totalItemHeight += addLineHeight; // add the lines height == debug only now
				$('<div class="staticListingLine"><span>'  + lineCount + "-" + addLineHeight + "-" + totalItemHeight +  '</span></div>').appendTo(column);
			} else {
				$('<div class="staticListingLine"></div>').appendTo(column); // create line
			}
		}
	}
}


function prep() {
	var numContainers = $('.container').length; // calculate number of containers
	// var contWidth = Math.floor(100 / numContainers) + '%'; // calculate their widths
	var companyName;
	if (numContainers == 2) { // accounts for a single 1px vertical line and 2 columns
		$('.col1').css('width', 540);
		$('.col2').css('width', 539);
	} else if (numContainers == 3) { // accounts for two 1px vertical lines and 3 columns
		$('.col1').css('width', 353);
		$('.col2').css('width', 352);
		$('.col3').css('width', 353);
	}
	item.each(function() {  // cycle through each col0 listing and put in new columns
		// ======================== Column 1 =============================
		if (activeCol == 1) {
			if ((headerOn === true) && (header1 !== false)) { // add header 1 if switched on
				col1List.prepend('<div class="staticHeader clearfix">' + headerContent + '</div>'); // create header
				header1 = false; // now false so we dont come back
				if (staticDebug === true) {
					totalItemHeight += $('.col1 .staticHeader').height(); // debug - total height
					$('.col1 .staticHeader').append('<span>' + $('.col1 .staticHeader').height() + "-" + totalItemHeight + '</span>'); // debug - print to item
				}
			}
			$(this).appendTo(col1List); // move this item to column 1
			if (staticDebug === true) {
				itemHeight = $(this).outerHeight(true); // debug - get this items height
				totalItemHeight += itemHeight; // debug - add items height to total height
				// $(this).append('<span>' + lineCount + '</span>'); // debug - show how many counted listings
				$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // debug - show single item and total height calculations
			}
			addListingLines(col1List);
			activeCount +=1; // count the number of listings cycled though
			col1ListHeight = $('.col1Listings').height();
			if (col1ListHeight > col1Height) { // do this when height is taller than parent
				if (($('.col2').length === 0) && (reduceFontCount === 0)) { // try to reduce font size first
					actualFontSize -= 1; // keep track of actual font size with counter
					reduceFontCount += 1; // keep track of how many times the font has been reduced
					$('#listings').css('fontSize', '-=1'); // reduce font size by one
					rebuild(); // rebuild with smaller font
					return false; // stop the prep function
				} else if ($('.col2').length === 0) { // if col2 does not exist then we need to create it
					$('#listings').append('<div class="lineVert"></div><div class="container col2"><div class="col2Listings"></div></div>'); // create vert line and col2
					col2 = $('.col2'); // set variable
					col2Height = col2.height(); // set variable
					col2List = $('.col2Listings'); // set variable
					rebuild(); // start over now that we have two columns
					return false;
				} else { // if font reduced and col2 exists already, start building list for col2
					activeCol = 2; // now add listings to col2
					if (staticDebug === true) {
						totalItemHeight = 0;  // debug - reset height total now that we are adding to the new column 2
					}
					lineCount = 0;
					if ((headerOn === true) && (header2 !== false)) { // add HEADER 2 if switched on =======
						col2List.prepend('<div class="staticHeader clearfix">' + headerContent + '</div>'); // create header for col2
						header2 = false; // now false so we dont come back
						if (staticDebug === true) {
							totalItemHeight += $('.col2 .staticHeader').height();
							$('.col2 .staticHeader').append('<span>' + $('.col2 .staticHeader').height() + "-" + totalItemHeight + '</span>');
						}
					}
					if ( $(this).attr('data-type') == 'Ind' && indCodeOn === true) { // if this is an individual we need continued from company message
						companyName = $(this).attr('data-comp'); // get company name
						col2List.append('<div class="cont2">' + companyName + ' (Continued)</div>'); // add the company name continued to col2
						$(this).appendTo(col2List).find('span').remove(); // add this individual listing to col2, remove spans if active
						if (staticDebug === true) {
							totalItemHeight += $('.cont2').height(); // debug - add continued div height to total 
							totalItemHeight += $(this).height(); // debug - add this individual listing height to total
						}
					} else {
						$(this).appendTo(col2List).find('span').remove(); // move this item from column 1 to column 2
						lineCount++;
						if (staticDebug === true) {
							totalItemHeight += $(this).height();
						}
					}
				} 
				if (staticDebug === true) {
					// $(this).append('<span>' + lineCount + '</span>'); // count listings
					$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
				}
			}
		}
		// ======================== Column 2 =============================
		else if (activeCol === 2) {
			$(this).appendTo(col2List); // start putting items in col 2
			if (staticDebug === true) {
				itemHeight = $(this).outerHeight(true);
				totalItemHeight += itemHeight;
				// $(this).append('<span>' + lineCount + '</span>'); // count listings
				$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
			}
			addListingLines(col2List);
			activeCount +=1; // count the number of listings cycled though
			col2ListHeight = $('.col2Listings').height();
			if (col2ListHeight > col2Height) {
				if (($('.col3').length === 0) && (reduceFontCount == 1)) {
					actualFontSize -= 1; // actual font size counter
					reduceFontCount += 1; // font size counter
					$('#listings').css('fontSize', '-=1'); // reduce font size by one
					rebuild();
					return false;
				} else if ($('.col3').length === 0) {
					$('#listings').append('<div class="lineVert"></div><div class="container col3"><div class="col3Listings"></div></div>');
					col3 = $('.col3');
					col3Height = col3.height();
					col3List = $('.col3Listings');
					rebuild();
					return false;
				} else {
					activeCol = 3; // now add listings to col3
					if (staticDebug === true) {
						totalItemHeight = 0;
					}
					lineCount = 0;
					if ((headerOn === true) && (header3 !== false)) { // add HEADER 3 if switched on =======
						col3List.prepend('<div class="staticHeader clearfix">' + headerContent + '</div>');
						header3 = false; // now false so we dont come back
						if (staticDebug === true) {
							totalItemHeight += $('.col3 .staticHeader').height();
							$('.col3 .staticHeader').append('<span>' + $('.col3 .staticHeader').height() + "-" + totalItemHeight + '</span>');
						}
					}
					if ( $(this).attr('data-type') == 'Ind' && indCodeOn === true ) {
						companyName = $(this).attr('data-comp');
						col3List.append('<div class="cont2">' + companyName + ' (Continued)</div>');
						$(this).appendTo(col3List).find('span').remove();
						if (staticDebug === true) {
							totalItemHeight += $('.cont3').height();
							totalItemHeight += $(this).height();
						}
					} else {
						$(this).appendTo(col3List).find('span').remove();
						lineCount++;
						if (staticDebug === true) {
							totalItemHeight += $(this).height();
						}
					}
				}
				if (staticDebug === true) {
					// $(this).append('<span>' + lineCount + '</span>'); // count listings
					$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
				}
			}
		}
		// ======================== Column 3 =============================
		// else if (activeCol === 3) {
		// 	$(this).appendTo(col3List);
		// 	if (staticDebug === true) {
		// 		itemHeight = $(this).outerHeight(true);
		// 		totalItemHeight += itemHeight;
				// $(this).append('<span>' + lineCount + '</span>'); // count listings
			// 	$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
			// }
			// addListingLines(col3List);
			// activeCount +=1; // count the number of listings cycled though
			// col3ListHeight = $('.col3Listings').height();
			// if (col3ListHeight > col3Height) { // need to reduce font once and rebuild before adding another column
			// 	if (($('.col4').length === 0) && (reduceFontCount === 2)) {
			// 		actualFontSize -= 1; // actual font size counter
			// 		reduceFontCount += 1; // font size counter
			// 		$('#listings').css('fontSize', '-=1'); // reduce font size by one
			// 		rebuild();
			// 		return false;
			// 	} else if ($('.col4').length === 0) {
			// 		$('#listings').append('<div class="lineVert"></div><div class="container col4"><div class="col4Listings"></div></div>');
			// 		col4 = $('.col4');
			// 		col4Height = col4.height();
			// 		col4List = $('.col4Listings');
			// 		rebuild();
			// 		return false;
			// 	} else {
			// 		activeCol = 4; // now add listings to col4
			// 		if (staticDebug === true) {
			// 			totalItemHeight = 0;
			// 		}
			// 		lineCount = 0;
			// 		if ((headerOn === true) && (header4 !== false)) { // add HEADER 4 if switched on =======
			// 			col4List.prepend('<div class="staticHeader clearfix">' + headerContent + '</div>');
			// 			header4 = false;
			// 			if (staticDebug === true) {
			// 				totalItemHeight += $('.col4 .staticHeader').height();
			// 				$('.col4 .staticHeader').append('<span>' + $('.col4 .staticHeader').height() + "-" + totalItemHeight + '</span>');
			// 			}
			// 		}
			// 		if ( $(this).attr('data-type') == 'Ind' && indCodeOn === true ) {
			// 			companyName = $(this).attr('data-comp');
			// 			col4List.append('<div class="cont2">' + companyName + ' (Continued)</div>');
			// 			$(this).appendTo(col4List).find('span').remove();
			// 			if (staticDebug === true) {
			// 				totalItemHeight += $('.cont4').height();
			// 				totalItemHeight += $(this).height();
			// 			}
			// 		} else {
			// 			$(this).appendTo(col4List).find('span').remove();
			// 			lineCount++;
			// 			if (staticDebug === true) {
			// 				totalItemHeight += $(this).height();
			// 			}
			// 		}
			// 	}
			// 	if (staticDebug === true) {
					// $(this).append('<span>' + lineCount + '</span>'); // count listings
					// $(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
		// 		}
		// 	}
		// }
		// ======================== Column 4 =============================
		// else if (activeCol === 4) {
		// 	$(this).appendTo(col4List);
		// 	if (staticDebug === true) {
		// 		itemHeight = $(this).outerHeight(true);
		// 		totalItemHeight += itemHeight;
				// $(this).append('<span>' + lineCount + '</span>'); // count listings
		// 		$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
		// 	}
		// 	addListingLines(col4List);
		// 	activeCount +=1; // count the number of listings cycled though
		// 	col4ListHeight = $('.col4Listings').height();
		// 	if (col4ListHeight > col4Height) {
		// 		if (($('.col5').length === 0) && ((reduceFontCount >= 3) && (reduceFontCount <= 5))) {
		// 			actualFontSize -= 1; // actual font size counter
		// 			reduceFontCount += 1; // font size counter
		// 			$('#listings').css('fontSize', '-=1'); // reduce font size by one
		// 			console.debug('Col4 - Size: ' + actualFontSize + ' - Count: ' + reduceFontCount + ' - How many left: ' + (count - activeCount));
		// 			rebuild();
		// 			return false;
		// 		} else if ($('.col5').length === 0) {
		// 			$('#listings').append('<div class="lineVert"></div><div class="container col5"><div class="col5Listings"></div></div>');
		// 			col5 = $('.col5');
		// 			col5Height = col5.height();
		// 			col5List = $('.col5Listings');
		// 			rebuild();
		// 			return false;
		// 		} else {
		// 			activeCol = 5; // now add listings to col5
		// 			if (staticDebug === true) {
		// 				totalItemHeight = 0;
		// 			}
		// 			lineCount = 0; 
		// 			if ((headerOn === true) && (header5 !== false)) { // add HEADER 5 if switched on =======
		// 				col5List.prepend('<div class="staticHeader clearfix">' + headerContent + '</div>');
		// 				header5 = false;
		// 				if (staticDebug === true) {
		// 					totalItemHeight += $('.col5 .staticHeader').height();
		// 					$('.col5 .staticHeader').append('<span>' + $('.col5 .staticHeader').height() + "-" + totalItemHeight + '</span>');
		// 				}
		// 			}
		// 			if ( $(this).attr('data-type') == 'Ind' && indCodeOn === true ) {
		// 				companyName = $(this).attr('data-comp');
		// 				col5List.append('<div class="cont2">' + companyName + ' (Continued)</div>');
		// 				$(this).appendTo(col5List).find('span').remove();
		// 				if (staticDebug === true) {
		// 					totalItemHeight += $('.cont5').height();
		// 					totalItemHeight += $(this).height();
		// 				}
		// 			} else {
		// 				$(this).appendTo(col5List).find('span').remove();
		// 				lineCount++;
		// 				if (staticDebug === true) {
		// 					totalItemHeight += $(this).height();
		// 				}
		// 			}
		// 		}
		// 		if (staticDebug === true) {
		// 			$(this).append('<span>' + lineCount + '</span>'); // count listings
		// 			$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
		// 		}
		// 	}
		// }
		// ======================== Column 3 =============================
		else if (activeCol === 3) {
			$(this).appendTo(col3List);
			if (staticDebug === true) {
				itemHeight = $(this).outerHeight(true);
				totalItemHeight += itemHeight;
				// $(this).append('<span>' + lineCount + '</span>'); // count listings
				$(this).append('<span>' + itemHeight + "-" + totalItemHeight + '</span>'); // show height calculations
			}
			addListingLines(col3List);
			activeCount +=1; // count the number of listings cycled though
			if (doOnceCol3 === true) { // runs once after a rebuild cycle
				lineCount = 2; // one listing has already been populated, start at 2 now
				doOnceCol3 = false;
			}
			col3ListHeight = $('.col3Listings').height();
			if (col3ListHeight > col3Height) {
				actualFontSize -= 1; // actual font size counter
				reduceFontCount += 1; // font size counter
				$('#listings').css('fontSize', '-=1'); // reduce font size by one
				rebuild();
				return false;
			}
			if (staticDebug === true) {
				console.debug('Col3 - Size: ' + actualFontSize + ' - Count: ' + reduceFontCount + ' - How many left: ' + (count - activeCount));
			}
		}
		if (activeCount == count) {
			autoBalance();
			$('.col0').remove();
			$('.removeHeader').remove();
			$('#pleaseWait').fadeOut(1000, function() {
				$('#listings').animate({
					opacity: 1,
				}, 1000);
			});
			console.debug('List building complete - ' + count + ' Total Listings');
		}
	}); // end cycling through each listing
} // end prep function

var autoBalanceCount = 0;
var activeListHeightCol;
function autoBalance() { // rebuild listings with increased padding until last column is filled to at least 75%
	activeListHeightCol = $('.col' + activeCol + 'Listings');
	var containerPerc;

	if (activeCol === 1) {
		containerPerc = $('.container:last-child').height() * 0.95; 
	} else {
		containerPerc = $('.container:last-child').height() * 0.85; 
	} 
	if (count >= 6) {
		if (($('.container:last-child .companyListing').length === 0) || (activeListHeightCol.height() < containerPerc)) {
			$('.companyListing .setOne0').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			$('.companyListing .setOne1').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			$('.companyListing .setOne2').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			$('.companyListing .setOne3').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			$('.companyListing .setOne4').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			$('.companyListing .setOne5').css('paddingBottom', '+=.15').css('paddingTop', '+=.15');
			addLineMargins += 0.1; //add height to line margins
			addLineHeight = 1 + (addLineMargins * 2);
			autoBalanceCount += 1; // keep track of how many times autobalance runs
			console.error('AutoBalance ' + autoBalanceCount + 'x - ' + activeListHeightCol.height() + ' < ' + containerPerc);
			rebuild();
		} else {
			lineCleanUp();
		}
	} else {
		$('.companyListing .setOne0').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.companyListing .setOne1').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.companyListing .setOne2').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.companyListing .setOne3').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.companyListing .setOne4').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.companyListing .setOne5').css('paddingBottom', '30px').css('paddingTop', '30px');
		$('.staticListingLine').css('marginBottom', '10px').css('marginTop', '10px');
		lineCleanUp();
	}
}
function lineCleanUp() { // remove the last listing lines of each column
	$('.container .staticListingLine:last-of-type').remove();
}


function wrapCol() { // print total heights and color backgrounds
	col1ListHeight = $('.col1Listings').height();
	col1List.append('<span class="debugHeight">' + col1ListHeight + '</div>');

	col2ListHeight = $('.col2Listings').height();
	col2List.append('<span class="debugHeight">' + col2ListHeight + '</div>');

	col3ListHeight = $('.col3Listings').height();
	col3List.append('<span class="debugHeight">' + col3ListHeight + '</div>');

	// col4ListHeight = $('.col4Listings').height();
	// col4List.append('<span class="debugHeight">' + col4ListHeight + '</div>');

	// col5ListHeight = $('.col5Listings').height();
	// col5List.append('<span class="debugHeight">' + col5ListHeight + '</div>');

	$('.companyListing').css('background', 'green');
	$('.companyListing:nth-child(2n)').css('background', 'magenta');
}

$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.addressCont' ,function() { // click building title to turn on
	if (staticDebug === true) {
		wrapCol();
	}
});

// ==================== ADD HYPHEN IN FRONT OF INDIVIDUAL LISTINGS ======================
var hyphenInd = $(".companyListing[data-type='Ind'] .setOne1");
hyphenInd.prepend('- ');

// ==================== HEADER BREAK STRING INTO TWO LINES============================
// headerBreakText();
// function headerBreakText() {
// 	var buildingTitle = $('.addressText').html();
// 	console.debug(buildingTitle);
// 	var titleArray = buildingTitle.split("<br>");
// 	$('.addressText').empty().append('<div class="buildingName">'+titleArray[0]+'</div><div class="buildingAddress">'+titleArray[1]+'</div>');
// }



 // ==================== HEADER BREAK STRING INTO TWO LINES============================
headerBreakText();
function headerBreakText() {
	var buildingTitle = $('.addressCont').html();
	var titleArray;
	if ($('.mainLogoOnly').length === 0) {
		console.debug('==============>' + buildingTitle + '<==================');
		titleArray = buildingTitle.split("<br>");
		if (titleArray[1] !== undefined) {
			$('.addressCont').empty().append('<div class="buildingName">'+titleArray[0]+'</div><div class="buildingAddress">'+titleArray[1]+'</div>');
			
			if ($('.addressCont').hasClass('addressResize')) {
				var fontSize = parseInt($('.addressCont').attr('data-fontsize')); // get data
				var fontSize2 = parseInt(fontSize) - 15;
				$('.buildingName').css('font-size', fontSize);
				$('.buildingAddress').css('font-size', fontSize2);
			} 
		}
	}
	$('.addressCont').delay(1000).animate({ opacity:1 });
}


// ====================== TWITTER ================================
var stateWeatherLow = false;



// ====================== TIME AND DATE ================================
function showTimeDate() {
    var today=new Date();
    var h=today.getHours();
    var m=today.getMinutes();
    var s=today.getSeconds();
    var ap = "AM";
     if (h   > 11) { ap = "PM"; }
    if (h   > 12) { h = h - 12; }
    if (h   == 0) { h = 12; }
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('currentTime').innerHTML = h+":"+m+" "+ap;
    var t = setTimeout(function(){showTimeDate()},500);
    var date = new Date();
    var currDate = date.getDate();
    var monthName = getMonthName(date.getMonth());
    var dayName = getDayName(date.getDay());    
    var year = date.getFullYear();
    document.getElementById('currentDate').innerHTML = dayName + ', ' + monthName + ' ' + currDate + ', ' + year;
}

function checkTime(i) {
    if (i<10) {i = "0" + i};  // add zero in front of numbers < 10
    return i;
}

function getMonthName(month) {
    var ar = new Array("Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec");
    return ar[month];
}

function getDayName(day) {
    var ar1 = new Array("Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat");
    return ar1[day];
}


// ================================== PDF VIEWER =======================================
var pdfActive = false;
// $(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.mapURL' ,function(event){
$('.mapURL').click(function(event) {
	event.preventDefault();
	pdfActive = true;
	var pdfDoc = $(this).attr('href');
	
	$('#pdfMask').delay(500).fadeIn(300, function() {
		$('.closePDF').fadeIn(300);
	});
	$( '#pdfWindow' ).attr( 'src', pdfDoc).delay(500).fadeIn(300);

});

function closePDFViewer() {
	pdfActive = false;
	$('#pdfMask, .closePDF').fadeOut(300);
	$('#pdfWindow').fadeOut(300, function() {
		$( '#pdfWindow' ).attr( 'src', 'index.html' ); // clear out URL so page fit work on iframe reload
	});
}
$('#pdfMask, .closePDF').click(function() {
	closePDFViewer();
});