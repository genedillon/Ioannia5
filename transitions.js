// ============ PAGE INITIALIZATION ==================
$(document).ready(function(){
	$('.detailListing').fadeOut();
	setListingDefaults();
	calculateButtons();
	calculateTSLiveButtons();
	calculateBuilding();
	calculateTSLiveWeather();
	calculateTSLiveNews();
	calculateSlideshow();
	calculateScrollOrTwitter();
	prepKeyboard(activeTblWrapper, activeListWindow);
	prepBldgInfo();
	prepAnn();
	buttonStyle2(); // enable new button styles
	configurePageElements();
	prepareAdaBtns();
	$('.btnContainer').delay(800).animate({
		opacity: 1
	});
 
	$('.directoryContainer').delay(800).animate({
		opacity: 1
	});
	$('#scrollSearch').delay(800).animate({
		opacity: 1
	});
});

// === Load function after everything loads ===	
$(window).load(function(){
	$('.slideWrapper').delay(1500).animate({
		opacity: 1
	});
	// $('.slideWrapper').css('opacity', 1);
	$('.amenityCont').fadeOut(10, function() { // needs to be visible when page loads, then hide
		$('.amenityCont').css('opacity', '1');
	});
	$('.trafficCont').fadeOut(10, function() { // needs to be visible when page loads, then hide
		$('.trafficCont').css('opacity', '1');
	});
	$('.transitCont').fadeOut(10, function() { // needs to be visible when page loads, then hide
		$('.transitCont').css('opacity', '1');
	});
	if ((slideShowSize == 'fullTSLiveOn') || (slideShowSize == 'fullTSLiveOff')) { // adjust heights if no slideshow
		$('#tsSlideshow').fadeOut();
	}
	countEmUp();
	// SMART BOXES: Used to set automatic box calculation on and off, and to turn text lined listings on and off
	// toggle smart boxes on or off / fixed height value for boxes (first value false) / lined on or off (override) / parent container object / listing object
	smartBoxes(true, 200, false, $('.spaceContainer'), $('.spaceListing'));
	smartBoxes(true, 200, false, $('.list12Container'), $('.list12Listing'));
	smartBoxes(true, 200, false, $('.bldgAmenContainer'), $('.bldgAmenListing'));
	smartBoxes(null, 200, false, $('.annContainer'), $('.annListing')); // null value to avoid resizing of announcement listings, they work as is - full width and auto height
});

// =================  PRINT NUMBER OF LISTINGS =====================
function countEmUp() {
	var numComps = $('.companyContainer .companyListing').length;
	var numIndivs = $('.individualsContainer .indivListing').length;
	console.debug('Num Companies=' + numComps + ', Num Individuals=' +numIndivs);
}


// ============= NAVIGATION BUTTONS - Set Style =============
var btnStyle = 1;
function buttonStyle1() {
	btnStyle = 1;
	$('.button2 .btnIcon2').removeClass('btnIcon2').addClass('btnIcon');
	$('.button2').removeClass('button2').addClass('button1');
	$('.btnText2').removeClass('btnText2').addClass('btnText');
}
function buttonStyle2() {
	btnStyle = 2;
	$('.button .btnIcon').removeClass('btnIcon').addClass('btnIcon2');
	$('.button1').removeClass('button1').addClass('button2');
	$('.btnText').removeClass('btnText').addClass('btnText2');
}

// ======== DISABLE RIGHT CLICK MENU IN CHROME ==========
(function () {
	var blockContextMenu, myElement;
	blockContextMenu = function (evt) {
		evt.preventDefault();
	};
	myElement = document.querySelector('html');
	myElement.addEventListener('contextmenu', blockContextMenu);
})();
 

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

			// var dataFontSize = $('.addressCont').attr('data-fontsize'); // get data
			// var fontSize;
			// var fontSize2;
			// SHOULD WORK IF PropNameFont could take a data input like 50-35 (currently numbers only)			
			// var fontArrray = dataFontSize.split("-"); // split data
			// if (fontArrray[1] === undefined && $('.addressCont').hasClass('addressResize')) { // if font size data but second array item is empty 
			// 	console.debug(dataFontSize);
			// 	fontSize = fontArrray[0];
			// 	fontSize2 = parseInt(fontSize) - 15;
			// 	$('.buildingName').css('font-size', fontSize);
			// 	$('.buildingAddress').css('font-size', fontSize2);
			// } else if ($('.addressCont').hasClass('addressResize')) { // if font size data with hyphen 
			// 	console.debug(dataFontSize);
			// 	fontSize = fontArrray[0];
			// 	fontSize2 = fontArrray[0];
			// 	$('.buildingName').css('font-size', fontSize);
			// 	$('.buildingAddress').css('font-size', fontSize2);
			// }
		}
	}
	$('.addressCont').delay(1000).animate({ opacity:1 });
}

// ===================== BOX OR LISTING STYLE - SET AT TOP DURING PAGE INITIALIZATION ======================
function smartBoxes(smartOn, boxHeight, linedOn, container, listing) { // equalize box heights then fade out space container
	var listingCount = 0;
	var tallestBoxListing = 0;
	if (linedOn === true) {
		container.find('.boxListings').removeClass('boxListings').addClass('linedListings');
		container.find('.iconInfo').attr('class', 'iconInfo'); // removes the offsetIconInfo class from SVG info icon, removeClass wont work on SVG
		container.fadeOut(function() { // fade out space container
			container.css('opacity', '1');
		});
	} else if (smartOn === true) {
		listing.each(function() { // cycle through all listings - find tallest space box and set all others to be that height
			var totalListing = listing.length; // total number of listings
			var listingBoxHeight = $(this).height(); // this listings height
			listingCount += 1; // how many listing so far
			
			if (listingBoxHeight > tallestBoxListing) { // if current box is taller than all others
				tallestBoxListing = listingBoxHeight; // store the tallest value
			}
			if (totalListing === listingCount) { // when the last listing is reached
				if (tallestBoxListing > 300) {
					listing.css('width', '96%').css('marginLeft', '2%'); // make listing full width with no set height
					container.fadeOut(function() { // fade out space container
						container.css('opacity', '1');
					});
				} else {
					// alert('test');
					listing.height(tallestBoxListing); // set all boxes to be equal to the tallest box
					container.fadeOut(function() { // fade out space container
						container.css('opacity', '1');
					});
				}
				console.debug(container + ' - ' + tallestBoxListing + ' - ' + listingCount + ' - ' + totalListing);
			}
		});
	} else if (smartOn === false) {
		listing.css('height', boxHeight); // set all boxes to be this height
		container.fadeOut(function() { // fade out space container
			container.css('opacity', '1');
		});
	}
	getSpaceScrolls = $('.spaceContainer .tbl_wrapper').height(); //scrolls if too much content
	getSpaceContainer = $('.spaceContainer .list-window').innerHeight(); //container fixed height

	getList12Scrolls = $('.list12Container .tbl_wrapper').height(); //scrolls if too much content
	getList12Container = $('.list12Container .list-window').innerHeight(); //container fixed height

	getBldgAmenScrolls = $('.bldgAmenContainer .tbl_wrapper').height(); //scrolls if too much content
	getBldgAmenContainer = $('.bldgAmenContainer .list-window').innerHeight(); //container fixed height
}


// ============================= NAVIGATION FUNCTIONS ====================================

// Remove the no listings with 'selected letter' message
function noListing() {
	$('.noListing').remove();
}

// === Combined List Functions ===
function showTenants() {
	activeListWindow = $('.companyContainer .list-window');
	activeTblWrapper = $('.companyContainer .tbl_wrapper');
	stateActiveWindow = 'comb';
	noListing();
	listAll();
	$('.activeCompDetail').removeClass('activeCompDetail');
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 900);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.companyContainer').hasClass('activeLeft')) {
				$('#scrollSearch').delay(900).fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.companyContainer').hasClass('activeLeft')) {
		$('.companyContainer').delay(300).fadeIn();
		console.debug('Tenants Button - Combined is Active already');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Tenants Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				$('.companyContainer').delay(300).fadeIn().toggleClass('activeLeft');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				if (adaValue === false) {
					$('#scrollSearch').delay(300).fadeIn();
				}
			});
		}
		if ((!$('.companyContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if comb list not active
			console.debug('Tenants Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.companyContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Companies List Functions ===
function showCompanies() {
	activeListWindow = $('.companyContainer .list-window');
	activeTblWrapper = $('.companyContainer .tbl_wrapper');
	stateActiveWindow = 'comp';
	noListing();
	listAll();
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 900);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.companyContainer').hasClass('activeLeft')) {
				$('#scrollSearch').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.companyContainer').hasClass('activeLeft')) {
		$('.companyContainer').delay(300).fadeIn();
		console.debug('Companies Button - Companies is Active already');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Companies Button - 1 - Map was Active');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				$('.companyContainer').delay(300).fadeIn().toggleClass('activeLeft');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				if (adaValue === false) {
					$('#scrollSearch').delay(300).fadeIn();
				}
			});
		}
		if ((!$('.companyContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if comp list not active
			console.debug('Companies Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.companyContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Individuals List Functions ===
function showIndividuals() {
	activeListWindow = $('.individualsContainer .list-window');
	activeTblWrapper = $('.individualsContainer .tbl_wrapper');
	stateActiveWindow = 'indiv';
	noListing();
	listAll();
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 900);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === INDIVIDUALS FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.individualsContainer').hasClass('activeLeft')) {
				$('#scrollSearch').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.individualsContainer').hasClass('activeLeft')) {
		$('.individualsContainer').delay(300).fadeIn();
		console.debug('Individuals Button - Individuals is Active already');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Individuals Button - 1 - Map was Active');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				$('.individualsContainer').delay(300).fadeIn().toggleClass('activeLeft');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				if (adaValue === false) {
					$('#scrollSearch').delay(300).fadeIn();
				}
			});
		}
		if ((!$('.individualsContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if ind list not active
			console.debug('Individuals Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.individualsContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}


// === Building Info Functions ===
function prepBldgInfo() {
	$('.bldgInfoContainer').fadeOut(function() { // after page loads, get values then hide container
		$('.bldgInfoContainer').css('opacity', '1');
	});
	getBldgInfoScrolls = $('.bldgInfoContainer .tbl_wrapper').height(); //scrolls if too much content
	getBldgInfoContainer = $('.bldgInfoContainer .list-window').innerHeight(); //container fixed height
}
var getBldgInfoScrolls = 0;
var getBldgInfoContainer = 0;

function showBldgInfo() {
	activeListWindow = $('.bldgInfoContainer .list-window');
	activeTblWrapper = $('.bldgInfoContainer .tbl_wrapper');
	stateActiveWindow = 'bldgInfo';
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 700);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.bldgInfoContainer').hasClass('activeLeft')) {
				$('#scrollSpace').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.bldgInfoContainer').hasClass('activeLeft')) {
		console.debug('Building Info Button - Building Info Already Active');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Building Info Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				$('.bldgInfoContainer').delay(300).fadeIn().toggleClass('activeLeft');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
			});
		}
		if ((!$('.bldgInfoContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if bldg info not active
			console.debug('Building Info Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.bldgInfoContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Space Available Functions ===
var getSpaceScrolls = 0;
var getSpaceContainer = 0;

function showSpace() {
	activeListWindow = $('.spaceContainer .list-window');
	activeTblWrapper = $('.spaceContainer .tbl_wrapper');
	stateActiveWindow = 'space';
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 700);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.spaceContainer').hasClass('activeLeft')) {
				$('#scrollSpace').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.spaceContainer').hasClass('activeLeft')) { // if space is already active
		console.debug('Show Space Button - Show Space Already Active');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Show Space Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				$('.spaceContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
		if ((!$('.spaceContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if space list not active
			console.debug('Show Space Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.spaceContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Building Amenities Functions ===
var getBldgAmenScrolls = 0;
var getBldgAmenContainer = 0;

function showBldgAmenities() {
	activeListWindow = $('.bldgAmenContainer .list-window');
	activeTblWrapper = $('.bldgAmenContainer .tbl_wrapper');
	stateActiveWindow = 'bldgAmen';
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 700);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.bldgAmenContainer').hasClass('activeLeft')) {
				$('#scrollSpace').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.bldgAmenContainer').hasClass('activeLeft')) { // if amenities is already active
		console.debug('Bldg Amen Button - Bldg Amen Already Active');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Bldg Amen Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				$('.bldgAmenContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
		if ((!$('.bldgAmenContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if bldg amen not active
			console.debug('Bldg Amen Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.bldgAmenContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Announcement Functions ===
function prepAnn() {
	$('.annContainer').fadeOut(function() { // after page loads, get values then hide container
		$('.annContainer').css('opacity', '1');
	});
	getAnnScrolls = $('.annContainer .tbl_wrapper').height(); //scrolls if too much content
	getAnnContainer = $('.annContainer .list-window').innerHeight(); //container fixed height
}
var getAnnScrolls = 0;
var getAnnContainer = 0;

function showAnn() {
	activeListWindow = $('.annContainer .list-window');
	activeTblWrapper = $('.annContainer .tbl_wrapper');
	stateActiveWindow = 'ann';
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 700);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.annContainer').hasClass('activeLeft')) {
				$('#scrollSpace').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.annContainer').hasClass('activeLeft')) { // if amenities is already active
		console.debug('Announcements Button - Announcements Already Active');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('Announcements Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				$('.annContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
		if ((!$('.annContainer').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if announcements list not active
			console.debug('Announcements Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.annContainer').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === List 12 Functions ===
var getList12Scrolls = 0;
var getList12Container = 0;

function showList12() {
	activeListWindow = $('.list12Container .list-window');
	activeTblWrapper = $('.list12Container .tbl_wrapper');
	stateActiveWindow = 'list12';
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 700);
	if ((stateSlideShow === true) && (slideShowSize != 'standard')) { // runs if Tenants button is clicked while full slideshow is running
		console.debug('SLIDESHOW IS TRUE === COMPANY FUNCTION ==========================');
		stateSlideShow = false; // prevents idle timer 'active' cycle from running
		directoryTextHide();
		$('#tsSlideshow').fadeOut(300, function() {
			$('.directoryContainer').fadeIn(300);
			if ($('.list12Container').hasClass('activeLeft')) {
				$('#scrollSpace').fadeIn(300).addClass('controlOn');
			}
		});
	}
	if ($('.list12Container').hasClass('activeLeft')) { // if amenities is already active
		console.debug('List 12 Button - List 12 Already Active');
	} else {
		if (!$('.directoryContainer').hasClass('activeFull') ) { // if Map is active
			console.debug('List 12 Button - 1');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.directoryContainer').delay(300).fadeIn().toggleClass('activeFull');
				if (slideShowSize == 'standard') {
					$('#tsSlideshow').delay(300).fadeIn();
				}
				$('.list12Container').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
		if ((!$('.list12Container').hasClass('activeLeft') ) && ($('.directoryContainer').hasClass('activeFull') )) { // if list12 not active
			console.debug('List 12 Button - 2 - Return from Other Lists');
			$('.activeLeft').toggleClass('activeLeft').fadeOut( function(){
				$('.list12Container').delay(300).fadeIn().toggleClass('activeLeft');
			});
		}
	}
}

// === Amenities Map Functions ===
function showAmenities() {
	stateActiveWindow = 'amenMap';
	if ($('.amenityCont').hasClass('activeFull')) { // if amenities is already active
		console.debug('Amenities Map Button - Amenities Map Already Active');
	} else { 
		if ($('.directoryContainer').hasClass('activeFull') ) {
			console.debug('Amenity Map Button - 1');
			$('.activeLeft').fadeOut().toggleClass('activeLeft');
			if (adaValue === false) {
				$('#tsSlideshow').fadeOut();
			}
			$('.controlOn').fadeOut();
			$('.directoryContainer').toggleClass('activeFull').fadeOut(function() {
				$('.amenityCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		} else {
			console.debug('Amenity Map Button - 2');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.amenityCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		}
	}
}

// === Traffic Map Functions ===
function showTraffic() {
	stateActiveWindow = 'trafficMap';
	if ($('.trafficCont').hasClass('activeFull')) {
		console.debug('Traffic Map Button - Traffic Map Already Active');
	} else {
		if ($('.directoryContainer').hasClass('activeFull') ) {
			console.debug('Traffic Map Button - 1');
			$('.activeLeft').fadeOut().toggleClass('activeLeft');
			if (adaValue === false) {
				$('#tsSlideshow').fadeOut();
			}
			$('.controlOn').fadeOut();
			$('.directoryContainer').toggleClass('activeFull').fadeOut(function() {
				$('.trafficCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		} else {
			console.debug('Traffic Map Button - 2');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.trafficCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		}
	}
}

// === Transit Info Functions ===
function showTransit() {
	stateActiveWindow = 'transit';
	if ($('.transitCont').hasClass('activeFull')) {
		console.debug('Transit Map Button - Transit Map Already Active');
	} else {
		if ($('.directoryContainer').hasClass('activeFull') ) {
			console.debug('Transit Map Button - 1');
			$('.activeLeft').fadeOut().toggleClass('activeLeft');
			if (adaValue === false) {
				$('#tsSlideshow').fadeOut();
			}
			$('.controlOn').fadeOut();
			$('.directoryContainer').toggleClass('activeFull').fadeOut(function() {
				$('.transitCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		} else {
			console.debug('Transit Map Button - 2');
			$('.activeFull').toggleClass('activeFull').fadeOut(function() {
				$('.transitCont').delay(300).toggleClass('activeFull').fadeIn();
			});
		}
	}
}


// ========================= ANIMATED OPACITY FOR ALL NAVIGATION BUTTONS ========================
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.button, .buttonTSLive, .adaBtnWrapper, .alphaBtn, .listBtn, .clearField, .searchKeyboard' ,function(){ 
	$(this).animate({ opacity: 0.3 }, 100, function() {
		$(this).animate({ opacity: 1 }, 300);
	});
});


// =============================== NAVIGATION BUTTONS ==================================
function disableBtns() {	
	$('.button, .buttonTSLive, .adaBtnWrapper').addClass('disableBtns');
	setTimeout(function() {
		$('.button, .buttonTSLive, .adaBtnWrapper').removeClass('disableBtns');
	}, 1000);
}
// Disable buttons temporarily
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.button, .button2, .buttonTSLive, .adaBtnWrapper' ,function(){ 
	disableBtns();
});


// Tenants Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#tenantsBtn' ,function(){
	showTenants();
	if ( (adaValue === true) || !$('.companyContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSearch')); 
	} else if ( $('#keyboard').hasClass('controlOn') ) {
		hideKeyboard($('#scrollSearch')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#tenantsBtnAda' ,function(){
	showTenants();
	openClearSearch();
});

// Companies Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#compsBtn' ,function(){
	showCompanies();
	if ( (adaValue === true) || !$('.companyContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSearch')); 
	} else if ( $('#keyboard').hasClass('controlOn') ) {
		hideKeyboard($('#scrollSearch')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#compsBtnAda' ,function(){
	showCompanies();
	openClearSearch();
});

// Individuals Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#indivsBtn' ,function(){
	showIndividuals();
	if ( (adaValue === true) || !$('.individualsContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSearch')); 
	} else if ( $('#keyboard').hasClass('controlOn') ) {
		hideKeyboard($('#scrollSearch')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#indivsBtnAda' ,function(){
	showIndividuals();
	openClearSearch();
});

// Building Info Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#bldginfoBtn' ,function(){
	showBldgInfo();
	if ( (adaValue === true) || !$('.bldgInfoContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSpace')); 
	} 
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#bldginfoBtnAda' ,function(){
	showBldgInfo();
	closeClearSearch();
});

// Space Available Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#spaceBtn' ,function(){
	showSpace();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
	if ( (adaValue === true) || !$('.spaceContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSpace')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#spaceBtnAda' ,function(){
	showSpace();
	closeClearSearch();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});

// Building Amenities Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#bldgAmenBtn' ,function(){
	showBldgAmenities();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
	if ( (adaValue === true) || !$('.bldgAmenContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSpace')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#bldgAmenBtnAda' ,function(){
	showBldgAmenities();
	closeClearSearch();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});

// Announcements Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#annBtn' ,function(){
	showAnn();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
	if ( (adaValue === true) || !$('.annContainer').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSpace')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#annBtnAda' ,function(){
	showAnn();
	closeClearSearch();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});

// List 12 Button
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#list12Btn' ,function(){
	showList12();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
	if ( (adaValue === true) || !$('.list12Container').hasClass('activeLeft') ) {
		hideKeyboard($('#scrollSpace')); 
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#list12BtnAda' ,function(){
	showList12();
	closeClearSearch();
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});

// TSLive Buttons
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#amenityBtn, #amenityBtnAda' ,function(){
	showAmenities();
	closeClearSearch();
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#trafficBtn, #trafficBtnAda' ,function(){
	showTraffic();
	closeClearSearch();
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#transitBtn, #transitBtnAda' ,function(){
	showTransit();
	closeClearSearch();
});


// ========================= SHOW COMPANY DETAILS =============================
$( ".companyLink" ).click(function( event ) {
	event.preventDefault();
});

var stateCompDetails = false;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.companyContainer .companyLink' ,function(){
	var $this = $(this);
	
	function fillCompIndivCont() {
		compIndivCont.addClass('activeIndCont'); // add class to target and empty later
		var numCompInd = 0;
		companyIndividuals.each(function() { // cycle through each comp ind
			var thisPerson = $(this).text(); // get comp ind text
			numCompInd += 1;
			compIndivCont.append(thisPerson + '<br/>'); // put into div and add break
		});

		if ( numCompInd === 0 ) {
			compIndTitle.toggleClass('emptyCont');
			console.debug(numCompInd + ' = Hide title'); //hide Individuals title if none exist
		} else if ( numCompInd >= 1 ) {
			console.debug(numCompInd + ' Individuals');
		}
	}

	if ($('.companyContainer .companyLink').hasClass('disableBtns')) { // prevents double clicking if class is on button
		console.debug('NO DOUBLE CLICKING'); // do nothing is class is active
	} else { // run regualr function on the fist click
		$this.addClass('disableBtns'); // add disableBtn class to prevent double click bug
		setTimeout(function() {
			$this.removeClass('disableBtns'); // remove disable after half second
		}, 500);

		stateCompDetails = true;
		var companyIDhref = $(this).attr('href'); // get the href value from the link
		var companyID = companyIDhref.slice(3); // slice off from the string 'ID=' leaving just the number

		var companySelected = $(".companyListing[data-type='Comp'][data-comp='" + companyID + "']" );
		var compSelectedSub = $(".companyListing[data-type='Comp'][data-comp='" + companyID + "'] div[class^='set'] " );
		var compDetailInfo = $(".companyListing[data-type='Comp'][data-comp='" + companyID + "'] .compDetailInfo" );
		var compIndivCont = $(".companyListing[data-type='Comp'][data-comp='" + companyID + "'] .compIndivCont" );
		var compIndTitle = $(".companyListing[data-type='Comp'][data-comp='" + companyID + "'] .listOfInd" );
		var companyIndividuals = $(".companyListing[data-type='Ind'][data-comp='" + companyID + "'] .setOne1" );

		$('.companyContainer .companyListing').fadeOut(200); // hide each listing
		$('.companyContainer .listHeader').fadeOut(200, function() { // hide company header
			$('.companyContainer .listDetailsHeader').fadeIn(200); // show tenant header
		}); 
		compSelectedSub.fadeOut().addClass('hiddenChildren'); // hide other comp info
		$('.companyContainer .listings').fadeOut(200, function() { // hide container
			$('.companyContainer .listings').fadeIn(); // show container
			companySelected.delay(50).fadeIn(); // show selected company - just one
			compDetailInfo.delay(50).fadeIn().addClass('activeCompDetail'); // show detail info container - name, suite, etc
			$('.companyContainer .tbl_wrapper').css('marginTop', '0'); // scroll to top of container
			fillCompIndivCont(); // populate individuals into their container
			setTimeout(function() {
				prepKeyboard(activeTblWrapper, activeListWindow);
			}, 500);
		});
		$('#textEntry').empty();
		searchString = false;

		console.debug('compID = ' + companyID);
	}
});


// ========================= SHOW INDIVIDUAL DETAILS =============================
var stateIndDetails = false;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.showIndividuals .companyLink' ,function(){
	stateIndDetails = true;
	var indListing = $(this).parent().parent(); 
	var indListingDetails = indListing.find('.compDetailInfo').text();
	var indSelectedSub = indListing.children('[class^="setTwo"]').fadeOut();
	var compDetailInfo = indListing.children('.compDetailInfo');

	
	function fillIndivDetailCont() {
		compIndivCont.addClass('activeIndCont'); // add class to target and empty later
		var numCompInd = 0;
		companyIndividuals.each(function() { // cycle through each comp ind
			var thisPerson = $(this).text(); // get comp ind text
			numCompInd += 1;
			compIndivCont.append(thisPerson + '<br/>'); // put into div and add break
		});

		if ( numCompInd === 0 ) {
			compIndTitle.toggleClass('emptyCont');
			console.debug(numCompInd + ' = Hide title'); //hide Individuals title if none exist
		} else if ( numCompInd >= 1 ) {
			console.debug(numCompInd + ' Individuals');
		}
	}

	$('.individualsContainer .indivListing').fadeOut(200); // hide each listing
	$('.individualsContainer .listHeader').fadeOut(200, function() { // hide company header
		$('.individualsContainer .listDetailsHeader').fadeIn(200); // show tenant header
	}); 
	indSelectedSub.fadeOut().addClass('hiddenChildren'); // hide other comp info
	$('.individualsContainer .listings').fadeOut(200, function() { // hide container
		$('.individualsContainer .listings').fadeIn(); // show container
		indListing.delay(50).fadeIn(); // show selected company - just one
		compDetailInfo.delay(50).fadeIn().addClass('activeCompDetail'); // show detail info container - name, suite, etc
		$('.individualsContainer .tbl_wrapper').css('marginTop', '0'); // scroll to top of container
		setTimeout(function() {
			prepKeyboard(activeTblWrapper, activeListWindow);
		}, 500);
	});
	$('#textEntry').empty();
	searchString = false;
});


// ========================= FILTER BY COMPANY OR INDIVIDUAL ================================
$('#compFilter').click(function() {
	clearCompIndDetails();
	$('.companyListing[data-type="Comp"]').delay(10).fadeIn(1, function() {
		setTimeout(function() {
			prepKeyboard(activeTblWrapper, activeListWindow);
		}, 500);
	});
	$('.companyListing[data-type="Ind"]').fadeOut(1);
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});
$('#indFilter').click(function() {
	clearCompIndDetails();
	$('.companyListing[data-type="Ind"]').delay(10).fadeIn(1, function() {
		setTimeout(function() {
			prepKeyboard(activeTblWrapper, activeListWindow);
		}, 500);
	});
	$('.companyListing[data-type="Comp"]').fadeOut(1);
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
});



// ================================ KEYBOARD ======================================
function clearCompIndDetails() {
	if ( stateCompDetails === true ) {
		stateCompDetails = false;
		$('.activeIndCont').empty().removeClass('activeIndCont');
		$('.activeCompDetail').hide();
		$('.hiddenChildren').show().removeClass('hiddenChildren');
		$('.emptyCont').toggleClass('emptyCont');
		$('.companyContainer .listDetailsHeader').delay(200).fadeOut(200, function() {
			$('.companyContainer .listHeader').fadeIn(200);
		});
		console.debug('clear Details Info');
	}
	if ( stateIndDetails === true ) {
		stateIndDetails = false;
		$('.compDetailInfo').hide();
		$('.hiddenChildren').show().removeClass('hiddenChildren');
		$('.individualsContainer .listDetailsHeader').fadeOut(200, function() {
			$('.individualsContainer .listHeader').fadeIn(200);
		});
	}
}
function listAll() {
	clearCompIndDetails();
	
	if (stateActiveWindow == 'comb') {
		$('.companyListing').show();
	} else if (stateActiveWindow == 'comp') {
		$('.companyListing[data-type="Comp"]').show();
	} else  if (stateActiveWindow == 'indiv') {
		$('.indivListing').show();
	}
	$(".tbl_wrapper").animate({ marginTop: 0 }, "slow");
	
}

$(".alphaBtn, .listBtn").mousedown(function() {
	$('.list-window').toggleClass('list-window-fix'); // Chrome rendering bug fix for list-window
});

var searchString = false; // multi letter search

$( ".alphaBtn" ).mousedown(function() { // ====== Search by Key Entry ========
	clearCompIndDetails();
	noListing();
	$('.companyListing').removeClass('markedListing');
	$('.indivListing').removeClass('markedListing');
	listAll();

	// Multi Letter Search
	var btnText = $(this).text().toLowerCase(); // key pressed
	if (searchString === false) {
		searchString = btnText; // first letter
	} else {
		searchString += btnText; // second letter and on
	}
	var searchLength = searchString.length; // search query is this long
	var numberOfMatches = 0;
	$('#textEntry').html(searchString.toUpperCase()); // enter uppercase text into search field

	function filterNames() {
		if (stateActiveWindow == 'comb') {
			$('.companyListing .setOne1').each(function() {
				var alphaName = $(this).text().slice(0,searchLength).toLowerCase(); // query each listing to certain  length
				
				if (alphaName != searchString) {
					$(this).parent().hide(); // hide if listing does not match search entered
				}
				if (alphaName == searchString) {
					$(this).parent().addClass('markedListing'); // mark matched listing
					numberOfMatches += 1; // count total number of matched listings
				} 
			});
		} else if (stateActiveWindow == 'comp') { 
			$('.companyListing[data-type="Comp"] .setOne1').each(function() {
				var alphaName = $(this).text().slice(0,searchLength).toLowerCase(); // query each listing to certain  length
				
				if (alphaName != searchString) {
					$(this).parent().hide(); // hide if listing does not match search entered
				}
				if (alphaName == searchString) {
					$(this).parent().addClass('markedListing'); // mark matched listing
					numberOfMatches += 1; // count total number of matched listings
				} 

			});
		} else {
			$('.indivListing .setTwo1').each(function() {
				var alphaName = $(this).text().slice(0,searchLength).toLowerCase(); // query each listing to certain  length
				
				if (alphaName != searchString) {
					$(this).parent().hide(); // hide if listing does not match search entered
				}
				if (alphaName == searchString) {
					$(this).parent().addClass('markedListing'); // mark matched listing
					numberOfMatches += 1; // count total number of matched listings
				} 
			});
		}
	}
	$.when(filterNames()).then(function() {
		if (isClearSearchOn === false) {
			prepKeyboard(activeTblWrapper, activeListWindow);
		} else if (isClearSearchOn === true) {
			clearKeyboardSearch(); // use for clearing of entered search criteria after a set timeout duration
		}
	});
	console.debug('Alpha Button "' + btnText + '" Number Of Matches = ' + numberOfMatches);
	if (numberOfMatches === 0) { // no matches found message
		if ( (stateActiveWindow == 'comb') || (stateActiveWindow == 'comp') ) {
			$('.companyContainer .listings').prepend('<div class="noListing">There are no listings beginning with " ' + searchString.toUpperCase() + ' " </div>');
		} else {
			$('.individualsContainer .listings').prepend('<div class="noListing">There are no listings beginning with " ' + searchString.toUpperCase() + ' " </div>');
		}
	}
});

// =============== Search by Keyboard Entry Clear =====================
var isClearSearchOn = false; // true will enable clearing of entered search criteria after a set timeout duration
var timeoutClearSearch;
var timerSearchState = false; // is search field timer on

function clearKeyboardSearch() {  // clear entry in search field after
	if (timerSearchState === false) { // initial run
		initialSearchTimer();
	} else if (timerSearchState === true) { // if ralready running
		clearTimeout(timeoutClearSearch); // stop timer
		initialSearchTimer();
	}
	prepKeyboard(activeTblWrapper, activeListWindow); 
	
	function initialSearchTimer() {
		timerSearchState = true; 
		timeoutClearSearch = window.setTimeout(function() {
			noListing();
			listAll();
			if (searchString !== false) { // if entry then clear
				$('#textEntry').empty();
				searchString = false;
			}
			prepKeyboard(activeTblWrapper, activeListWindow);
			timerSearchState = false;
		},7000);
	}
}


$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.clearField' ,function(){
	noListing();
	listAll();
	if (searchString !== false) {
		$('#textEntry').empty();
		searchString = false;
	}
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 200);
});

$( ".listBtn" ).mousedown(function() {
	noListing();
	listAll();
	console.debug('List All Button');
	if (searchString !== false) {
		$('#textEntry').empty();
		searchString = false;
	}
	setTimeout(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	}, 200);
});


function showKeyboard() { 
	if (disableSearchKeyboard === false) {
		$('#searchField').delay(400).fadeIn();
		$('.controlOn').fadeOut().removeClass('controlOn');
		$('.list-window').animate({
			height: listWinKeyOn
		}, function() {
			$('#keyboard').fadeIn().addClass('controlOn');
		});
	}
}

$('.searchKeyboard').click(function(e) {
	showKeyboard();
	searchString = false;
	console.debug('Search Button');
});


var calcDiff = 0; 
var disableSearchKeyboard = false;
var disableListAllBtn = false;

function prepKeyboard(insideHeight, wrapperHeight) { // Check to see which buttons should be active or disabled
	calcDiff = insideHeight.innerHeight() - wrapperHeight.height(); // table - list
	if (adaValue === false) {
		if ((stateActiveWindow == 'comb') || (stateActiveWindow == 'comp') || (stateActiveWindow == 'indiv')) {
			if ( calcDiff > 0 ) { // plenty of listings - lets scroll baby
				$('.scrollUpBtn').css('opacity', '1');
				$('.scrollDownBtn').css('opacity', '1');
				if ((stateCompDetails === false) && (stateIndDetails === false)) {
					$('.searchKeyboard').css('opacity', '1');
					$('.listBtn').css('opacity', '1');
					disableSearchKeyboard = false;
					disableListAllBtn = false;
				}
				if ( (stateCompDetails === true) || (stateIndDetails === true) ) {
					$('.listBtn').css('opacity', '1');
					disableListAllBtn = false;
				}
			} else { // not enough listings - no scrolling needed
				$('#scrollSearch .scrollUpBtn').css('opacity', '.18');
				$('#scrollSearch .scrollDownBtn').css('opacity', '.18');
				$('#scrollSpace .scrollUpBtn').css('opacity', '.18');
				$('#scrollSpace .scrollDownBtn').css('opacity', '.18');
				$('#keyboard .scrollUpBtn').css('opacity', '.18');
				$('#keyboard .scrollDownBtn').css('opacity', '.18');
				if ((stateCompDetails === false) && (stateIndDetails === false)) {
					$('.searchKeyboard').css('opacity', '.18');
					disableSearchKeyboard = true;
					if (!$('#keyboard').hasClass('controlOn')) {
						if (stateActiveWindow !== 'comb') {
							$('#scrollSearch .listBtn').css('opacity', '.18');
							$('#scrollSpace .listBtn').css('opacity', '.18');
							$('#keyboard .listBtn').css('opacity', '.18');
						}
						disableListAllBtn = true;
					}
				}
				if ( (stateCompDetails === true) || (stateIndDetails === true) ) {
					$('.listBtn').css('opacity', '1');
					disableListAllBtn = false;
				}
			}
		} else { // check active non keyboard windows
			if (calcDiff > 0) {
				$('.scrollUpBtn').css('opacity', '1');
				$('.scrollDownBtn').css('opacity', '1');
			} else {
				$('#scrollSearch .scrollUpBtn').css('opacity', '.18');
				$('#scrollSearch .scrollDownBtn').css('opacity', '.18');
				$('#scrollSpace .scrollUpBtn').css('opacity', '.18');
				$('#scrollSpace .scrollDownBtn').css('opacity', '.18');
				$('#keyboard .scrollUpBtn').css('opacity', '.18');
				$('#keyboard .scrollDownBtn').css('opacity', '.18');
			}
		} 
	} else if (adaValue === true) { // if ADA is on then all buttons active
		disableSearchKeyboard = false;
		disableListAllBtn = false;
	}
}

function hideKeyboard(showKeyboardType) { // hide active and show passed variable
	$('.controlOn').removeClass('controlOn').fadeOut(250, function() {
		showKeyboardType.delay(800).fadeIn().addClass('controlOn');
		$('.list-window').animate({
			height: listWinKeyOff 
		});
	});
	closeClearSearch();
}

function closeClearSearch() {
	if ($('#searchField').is(":visible")) {
		$('#searchField').fadeOut();
		$('#textEntry').empty();
		searchString = false;
	} else {
		$('#textEntry').empty();
		searchString = false;
	}
}
function openClearSearch() {
	if ($('#searchField').is(":visible")) {
		$('#textEntry').empty();
		searchString = false;
	} else {
		$('#searchField').fadeIn();
		$('#textEntry').empty();
		searchString = false;
	}
}

// Disable anchor link (space and comp pdf)
$('.disableLink').click(function(event) {
	event.preventDefault();
});


// ================================== URL MODAL =======================================
var urlModalActive;
var iframeURL;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.webModal' ,function() {
	urlModalActive = true;
	iframeURL = $(this).attr('data-url');
	$('#urlModal').append('<iframe id="iframeURLContainer" sandbox="allow-same-origin allow-scripts" class="iframeWindow" src="' + iframeURL + '"></iframe>');
	$('#urlMask').delay(500).fadeIn(300, function() {
		$('.closeURL').fadeIn(300);
		$('.backURL').fadeIn(300);
	});
	$('#urlModal').fadeIn(300);

	$('#urlMask').addClass('disableURL');
	$('.closeURL').addClass('disableURL');
	$('.backURL').addClass('disableURL');
	setTimeout(function() {
		$('#urlMask').removeClass('disableURL');
		$('.closeURL').removeClass('disableURL');
		$('.backURL').removeClass('disableURL');
	}, 1700);
});

function closeURL() {
	urlModalActive = false;
	$('#urlMask, .closeURL, .backURL').fadeOut(300);
	$('#urlModal').fadeOut(300, function() {
		$('#iframeURLContainer').remove();
	});
}
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#urlMask, .closeURL' ,function(){
	if ( !$('#urlMask').hasClass('disableURL') || !$('.closeURL').hasClass('disableURL') ) {
	closeURL();
	}
});

function backURL() {
	$.when($('#iframeURLContainer').remove()).then(function() {
		$('#urlModal').append('<iframe id="iframeURLContainer" sandbox="allow-same-origin allow-scripts" class="iframeWindow" src="' + iframeURL + '"></iframe>');
	});
}
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.backURL' ,function(){
	if (!$('.backURL').hasClass('disableURL')) {
	backURL();
	}
});


// ================================== VIDEO MODAL =======================================
var videoModalActive;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.videoBtn' ,function() {
	videoModalActive = true;
	if (adaValue === true) {
		$('#videoModal').addClass('videoModalADA');
		$('.closeVideo').addClass('closeVideoADA');
	}
	var iframeVideo = $(this).attr('data-video');
	$('#videoModal').append('<iframe id="iframeVideoContainer" sandbox="allow-same-origin allow-scripts" class="iframeWindow" src="' + iframeVideo + '"></iframe>');
	$('#videoMask').delay(500).fadeIn(300, function() {
		$('.closeVideo').fadeIn(300);
	});
	$('#videoModal').fadeIn(300);
});

function closeVideo() {
	videoModalActive = false;
	$('#videoMask, .closeVideo').fadeOut(300);
	$('#videoModal').fadeOut(300, function() {
		$('#iframeVideoContainer').remove();
		if (adaValue === true) {
			$('#videoModal').removeClass('videoModalADA');
			$('.closeVideo').removeClass('closeVideoADA');
		}
	});
}
$('#videoMask, .closeVideo').click(function() {
	closeVideo();
});


// ================================== PDF VIEWER =======================================
var pdfActive = false;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.pdfParent' ,function(){
	event.preventDefault();
	pdfActive = true;
	var pdfDoc = $(this).find('a').attr('href');
	var  zoomLevel = '#zoom=page-fit'; // page-height, page-width, page-fit, or use a number

	if (adaValue === true) {
		$('#pdfWindow').css('top', pdfContTopADA); 
		$('.closePDF').css('top', pdfCloseTopADA);
	} else {
		$('#pdfWindow').css('top', pdfContTop);
		$('.closePDF').css({
			top: pdfCloseTop,
			// left: 100,
		});
	}

	$('#pdfMask').delay(500).fadeIn(300, function() {
		$('.closePDF').fadeIn(300);
	});
	$( '#pdfWindow' ).attr( 'src', pdfDoc + zoomLevel ).delay(500).fadeIn(300);
	$('#textEntry').empty();
	searchString = false;
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

// move close button to line up with other PDF viewer buttons
// var pdfWindow = $('#pdfWindow');
// var pdfWinHeight = pdfWindow.height();
// var pdfTopPosition = parseInt(pdfWindow.css('top'));
// var pdfCloseBtnHeight = 41; //height of button, plus borders and bottom space
// var setPDFBtn = (pdfWinHeight + pdfTopPosition) - pdfCloseBtnHeight;
// $('.closePDF').css('top', setPDFBtn); // move close button 


// =============================== IMAGE VIEWER =======================================
var jpgActive = false;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.jpgParent' ,function(){
	event.preventDefault();
	jpgActive = true;
	var jpgDoc = $(this).find('img.jpgImg').attr('src');
	
	$('#jpgMask').fadeIn(300);
	$( '#jpgWindow .jpgImg' ).attr( 'src', jpgDoc ).delay(500).fadeIn(300);
});

function closeJPGViewer() {
	jpgActive = false;
	$('#jpgMask').fadeOut(300);
}
$('.jpgWrapper').on('mousedown touchstart pointerdown MSPointerDown', function(event) {
	closeJPGViewer();
});


// ================================= ADA MENU ========================================
var adaValue = false; //switch used for scrolling

function closeADA() {
	console.debug('Close ADA Menu');
	if ($('#searchField').is(':visible')) {
		$('#searchField').fadeOut(100, function() {
			$('#searchField').css('top', searchFieldTop);
			$('#searchField').css('left', '756px');
		});
	} else {
		$('#searchField').css('top', searchFieldTop);
		$('#searchField').css('left', '756px');
	}
	$('.adaNav').animate({top: 101}, 300, 'easeInQuart', function() {
		adaValue = false;
		$('.adaOff').delay(400).fadeIn(200);
		$('.btnContWrapper').delay(600).fadeIn(250, 'easeInQuart');
		scrollTwitter.delay(400).fadeIn(200);
		$('#textEntry').empty();
		searchString = false;
		if (stateWeatherLow === true) {
			$('.weatherContainer').delay(400).fadeIn(200, 'easeInQuart');
		}
		if (stateNews === true) {
			$('.newsContainer').delay(400).fadeIn(200, 'easeInQuart');
		}
		if ( ($('.companyContainer').hasClass('activeLeft')) || ($('.individualsContainer').hasClass('activeLeft')) ) {
			if ( $('#keyboard').hasClass('controlOn') ) { // from Comp click Search, go to ADA and then close ADA
				console.debug('============ADA1============');
				$('#keyboard').fadeOut().removeClass('controlOn');
				$('#scrollSearch').addClass('controlOn').delay(700).fadeIn(250, 'easeInQuart');
			} else if ( $('#scrollSpace').hasClass('controlOn') ) { // from bldg/lease/space, go to ADA, click on Comp and then close ADA
				console.debug('============ADA2============');
				$('#scrollSpace').fadeOut().removeClass('controlOn');
				$('#scrollSearch').addClass('controlOn').delay(700).fadeIn(250, 'easeInQuart');
			} else {// from Comp, go to ADA and then close ADA
				console.debug('============ADA3============'); 
				if (stateSlideShow === false) {
					$('.controlOn').delay(700).fadeIn(250, 'easeInQuart');
				}
			}
		} else if ( ($('.spaceContainer').hasClass('activeLeft')) || ($('.bldgAmenContainer').hasClass('activeLeft')) || ($('.annContainer').hasClass('activeLeft')) || ($('.list12Container').hasClass('activeLeft')) || ($('.bldgInfoContainer').hasClass('activeLeft'))  ) {
			if ( $('#keyboard').hasClass('controlOn') ) {
				console.debug('============ADA4============');
				$('#keyboard').fadeOut().removeClass('controlOn');
				$('#scrollSpace').addClass('controlOn').delay(700).fadeIn(250, 'easeInQuart');
			} else if ( $('#scrollSearch').hasClass('controlOn') ) { // from Comp list, go to ADA, click on bldg/lease/space then close ADA 
				console.debug('============ADA5============');
				if (stateSlideShow === false) {
					$('#scrollSearch').fadeOut().removeClass('controlOn');
					$('#scrollSpace').addClass('controlOn').delay(700).fadeIn(250, 'easeInQuart');
				}
			} else { // from bldg/lease/space, go to ADA and then close ADA
				console.debug('============ADA6============'); 
				$('.controlOn').delay(700).fadeIn(250, 'easeInQuart');
			}
		}
	});

	if (stateActiveWindow == 'amenMap' && stateSlideShow === false) {
		$('.amenityCont').animate({ // animate amenity map if active
			height: amenContHeight,
			top: amenContTop
		});
		$('#tsSlideshow').fadeOut(30); // bring back standard slidshow
	} else {
		$('.amenityCont').css('height', amenContHeight).css('top', amenContTop); // otherwise just set amenity map css
	}
	if (stateActiveWindow == 'trafficMap' && stateSlideShow === false) {
		$('.trafficCont').animate({ // animate traffic if active
			height: trafficContHeight,
			top: trafficContTop
		});
		$('#tsSlideshow').fadeOut(30); // bring back standard slidshow
	} else {
		$('.trafficCont').css('height', trafficContHeight).css('top', trafficContTop); // otherwise just set traffic css
	}
	if (stateActiveWindow == 'transit' && stateSlideShow === false) {
		$('.transitCont').animate({ // animate transit if active
			height: transitContHeight,
			top: transitContTop
		});
		$('#tsSlideshow').fadeOut(30); // bring back standard slidshow
	} else {
		$('.transitCont').css('height', transitContHeight).css('top', transitContTop); // otherwise just set traffic css
	}
	$('#urlModal').css('height', webContHeight).css('top', webContTop); // set web URL window size

	$.when($('.list-window').animate({
		height: listWinKeyOff,
	}, 500, 'easeInQuart')).then(function() {
		prepKeyboard(activeTblWrapper, activeListWindow);
	});
}

function openADA() {
	console.debug('Open ADA Menu');
	adaValue = true;
	$('.adaOff').fadeOut(250, 'easeInQuart');
	$('.btnContWrapper').fadeOut(250, 'easeInQuart');
	$('.controlOn').fadeOut(250, 'easeInQuart'); // hide keyboard
	scrollTwitter.fadeOut(250, function(){
		$('.adaNav').delay(200).animate({
			top: 0
		}, 200, 'easeInQuart');
		$('.list-window').delay(200).animate({
			height: listWinADA,
		}, 350, 'easeInQuart');
	});
	if (stateWeatherLow === true) {
		$('.weatherContainer').fadeOut(200, 'easeInQuart');
	}
	if (stateNews === true) {
		$('.newsContainer').fadeOut(200, 'easeInQuart');
	}
	$('#searchField').fadeOut(100, function() {
		if ( ($('.directoryContainer').hasClass('activeFull')) && ((stateActiveWindow == 'comb') || (stateActiveWindow == 'comp') || (stateActiveWindow == 'indiv')) ) {
			$('#searchField').css('top', searchFieldTopADA).css('left', '470px').delay(1000).fadeIn(200);
		} else {
			$('#searchField').css('top', searchFieldTopADA).css('left', '470px');
		}
	});
	$('#textEntry').empty();
	searchString = false;
	if (stateActiveWindow == 'amenMap') { // animate amenity map if visible
		$('.amenityCont').animate({
			height: amenContHeightADA,
			top: amenContTopADA
		});
		if (slideShowSize == 'standard') {
			$('#tsSlideshow').delay(600).fadeIn(300);
		}
	} else { // otherwise just set amenity map css
		$('.amenityCont').css('height', amenContHeightADA).css('top', amenContTopADA);
	}
	if (stateActiveWindow == 'trafficMap') { // animate traffic if visible
		$('.trafficCont').animate({
			height: trafficContHeightADA,
			top: trafficContTopADA
		});
		if (slideShowSize == 'standard') {
			$('#tsSlideshow').delay(600).fadeIn(300);
		}
	} else { // otherwise just set traffic css
		$('.trafficCont').css('height', trafficContHeightADA).css('top', trafficContTopADA);
	}
	if (stateActiveWindow == 'transit') { // animate traffic if visible
		$('.transitCont').animate({
			height: transitContHeightADA,
			top: transitContTopADA
		});
		if (slideShowSize == 'standard') {
			$('#tsSlideshow').delay(600).fadeIn(300);
		}
	} else { // otherwise just set traffic css
		$('.transitCont').css('height', transitContHeightADA).css('top', transitContTopADA);
	}
	$('#urlModal').css('height', webContHeightADA).css('top', webContTopADA); // set web URL window size
}

$('.adaMenu').click(function() {
	if ($(this).hasClass('adaOff')) {
		openADA();
		listAll();
		noListing();
	}
	if ($(this).hasClass('adaOn')) {
		listAll();
		noListing();
		closeADA();
	}
});


function prepareAdaBtns() {
	$('.btnContainer .button').each(function(){ // cycle through main nav buttons
		var createAdaBtnName;
		if (btnStyle == 1) {
			createAdaBtnName = $(this).find('.btnText').text(); // get button name
		} else if (btnStyle == 2) {
			createAdaBtnName = $(this).find('.btnText2').text(); // get button name
		}
		var createAdaId = $(this).attr('ID'); // get button ID
		var setAdaId = ' id="'+createAdaId+'Ada"'; // add Ada to button ID
		var createUrlLink = $(this).attr('data-url'); // get the url
		var setUrlLink = ' data-url=" '+createUrlLink+' " '; // create hook and URL to use
		var createVideoUrl = $(this).attr('data-video'); // get the url
		var setVideoUrl = ' data-video=" '+createVideoUrl+' " '; // create hook and URL to use

		if ( $(this).hasClass('pdfParent') ) {  // if pdfParent copy class over and link for pdf
			var adaPdfLink = $(this).find('a').attr('href');
			console.debug('Found PDF Link: ' + adaPdfLink);
			$('.adaBtnCont').append('<div class="adaBtnWrapper pdfParent"'+setAdaId+'><div class="adaBtn">'+createAdaBtnName+'</div><a href="'+adaPdfLink+'"></a></div>');
		} else if ( $(this).hasClass('webModal') ) {  // if webModal copy class over
			$('.adaBtnCont').append('<div class="adaBtnWrapper webModal"'+setAdaId+setUrlLink+'><div class="adaBtn">'+createAdaBtnName+'</div></div>');
		} else if ( $(this).hasClass('videoBtn') ) {
			$('.adaBtnCont').append('<div class="adaBtnWrapper videoBtn"'+setAdaId+setVideoUrl+'><div class="adaBtn">'+createAdaBtnName+'</div></div>');
		} else {  // create non-PDF ADA button
			$('.adaBtnCont').append('<div class="adaBtnWrapper"'+setAdaId+'><div class="adaBtn">'+createAdaBtnName+'</div></div>');
		}
	});
	if ($('.contTSLiveBtns')) {
		$('.buttonTSLive').each(function(){ // cycle though each TSLive main nav button
			var createAdaTSLiveBtnName = $(this).find('.btnTextTSLive').text(); // get button name
			var createAdaTSLiveId = $(this).attr('ID'); // get button ID
			var setAdaTSLiveId = ' id="'+createAdaTSLiveId+'Ada"'; // add Ada to button ID
			$('.adaBtnCont').append('<div class="adaBtnWrapper"'+setAdaTSLiveId+'><div class="adaBtn">'+createAdaTSLiveBtnName+'</div></div>');
		});
	}

	// Count buttons, resize if needed and center onto ADA menu
	var totalButtonsWidth = 0; 
	if ((numFullButtons + tsliveButtonDetect) == 11) {
		totalButtonsWidth =  (numFullButtons + tsliveButtonDetect) * 92;
		$('.adaBtn').css('fontSize', '12px').css('width', '76px'); // resize for many buttons
	} else if ((numFullButtons + tsliveButtonDetect) == 10) {
		totalButtonsWidth = (numFullButtons + tsliveButtonDetect) * 101;
		$('.adaBtn').css('fontSize', '12px').css('width', '86px'); // resize for many buttons
	} else if ((numFullButtons + tsliveButtonDetect) == 9) {
		totalButtonsWidth = (numFullButtons + tsliveButtonDetect) * 113;
		$('.adaBtn').css('fontSize', '12px').css('width', '98px'); // resize for many buttons
	} else if ((numFullButtons + tsliveButtonDetect) == 8) {
		totalButtonsWidth = (numFullButtons + tsliveButtonDetect) * 126;
		$('.adaBtn').css('fontSize', '12px').css('width', '111px'); // resize for many buttons
	} else {
		totalButtonsWidth = (numFullButtons + tsliveButtonDetect) * 145; // 145 is width of .adaBtnWrapper
	}
	var adaBtnContMar = Math.floor(((1080 - 56) - totalButtonsWidth) / 2); // usable  page width minus ada button
	$('.adaBtnCont').css('marginLeft', adaBtnContMar);  // center ada buttons using left margin
}



// =============================== SCREENSAVER SLIDESHOW ========================================
function endScreenSaver() {
	stateSlideShow = false;
	$('#tsSlideshow').fadeOut(50, function() {
		// if (slideShowSize == 'wideTSLiveOff') {
			$('.directoryTextCont').fadeOut();
		// } else if (slideShowSize == 'wideTSLiveOn') {
		// }
	});
}
// function startScreenSaver() {
// 	if ( !$('.directoryContainer').hasClass('activeFull') ) { // if gamen or gtraffic is visible
// 		$('.activeFull').removeClass('activeFull').fadeOut(1); // hide maps iframe
// 		$('.directoryContainer').addClass('activeFull').fadeIn(100); 
// 		$('.companyContainer').addClass('activeLeft');
// 		if (!$('#tsSlideshow').is(':visible')) { // if slideshow is not visible then show it
// 			$('#tsSlideshow').fadeIn();
// 		}
// 	}
// }


// ============================ TIMEOUT - NEED MORE TIME PROMPT =================================
var stateSlideShow = false;
function defaultState() { // set page elements back to the intial state
	$('#moreTime').fadeOut();
	$('.moreTimeMask').fadeOut();
	window.clearTimeout(timeoutUsePrompt); // clear prompt timer
	clearInterval(timerCountdown);
	
	stateSlideShow = true;

	if (adaValue === true) {
		closeADA();
	}
	if (pdfActive === true) {
		closePDFViewer();
	}
	if (jpgActive === true) {
		closeJPGViewer();
	}
	if (urlModalActive === true) {
		closeURL();
	}
	if (videoModalActive === true) {
		closeVideo();
	}


	if (slideShowSize == 'standard') {
		hideKeyboard($('#scrollSearch')); 
		// startScreenSaver(); // if maps visible then hide and start slideshow

		if (stateCombinedList === true) {
			showTenants();
		} else if (stateCompanies === true) {
			showCompanies();
		} else {
			showIndividuals();
		}
	} else { // if full slide show is active, then set directory to active and hide it
		$('.controlOn').removeClass('controlOn').fadeOut(250, function() {
			$('#scrollSearch').addClass('controlOn');
			// $('.list-window').animate({
			// 	height: listWinKeyOff 
			// });
		});
		closeClearSearch();

		if ( !$('.directoryContainer').hasClass('activeFull') ) { // if gamen or gtraffic is visible
			$('.activeFull').removeClass('activeFull').fadeOut(10); // hide the active iframe map
			$('.directoryContainer').addClass('activeFull'); 
			$('.companyContainer').addClass('activeLeft');
		}
		$('.directoryContainer').fadeOut(10, function() {
			$('.list-window').css('height', listWinKeyOff);
			$('#tsSlideshow').fadeIn(10);
		});
		directoryTextShow();
	}
}

function directoryTextShow() {
	if (numFullButtons <= 4 && calculateTSLiveButtons() === false) {
		$('.directoryTextCont').fadeIn();
		$('.directoryText').fadeIn();
		$('.touchText').fadeIn();
	} else if (calculateTSLiveButtons() === false) {
		$('.directoryTextCont').fadeIn();
		$('.directoryText').fadeIn();
	} else if (numFullButtons <= 4) {
		$('.directoryTextCont').fadeIn();
		$('.touchText').fadeIn();
	}
}
function directoryTextHide() {
	$('.directoryTextCont').fadeOut();
	$('.directoryText').fadeOut();
	$('.touchText').fadeOut();
}

var timeoutUsePrompt;
var isPromptActive = false;
function usePrompt() {  // open prompt - does user need more time?
	isPromptActive = true;
	$('#moreTime').fadeIn();
	$('.moreTimeMask').fadeIn();
	countdownSeconds = 10; // add more time to countdown timer - one second more than timeout
	timerCountdown = setInterval(countDown,1000); // start countdown interval time
	countDown(); // start countdown timer
	timeoutUsePrompt = window.setTimeout(function() {
		defaultState();
	},9000);
}
var countdownSeconds;
var timerCountdown;

function countDown(){  // count down that shows on prompt window
	countdownSeconds--; // count down one sec
	if (countdownSeconds === 0){
		clearInterval(timerCountdown); // reset when at zero
	}
	$('#timeLeft').html(countdownSeconds); // print out time left
}

$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '#moreTime, .moreTimeMask' ,function(){ // clear prompt if user clicks screen
	userNeedsMoreTime();
});
function userNeedsMoreTime() { // clear out prompt and timer
	$('#moreTime').fadeOut();
	$('.moreTimeMask').fadeOut();
	window.clearTimeout(timeoutUsePrompt);
	clearInterval(timerCountdown);
}


// =============================== SECRET SLIDESHOW =====================================
var stateSecretSlideShow;
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.forceSlideshow1' ,function(){
	if ((slideShowSize != 'standard') && (stateSlideShow === false)) {
		stateSecretSlideShow = true;
		secretSlideshow();
	}
});
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.forceSlideMask' ,function(){
	stateSecretSlideShow = false;
	secretSlideshow();
});

function secretSlideshow() {
	if (stateSecretSlideShow === true) {
		defaultState();
		$('.forceSlideMask').fadeIn();
		$('.forceSlideshow1').fadeOut(10);
	} else {
		$.when( endScreenSaver() ).then(function() { // end screen saver and show default listing type
			$('.forceSlideMask').fadeOut();
			$('.forceSlideshow1').fadeIn(10);
			$('#scrollSearch').delay(900).fadeIn(300).addClass('controlOn');
			$('.directoryContainer').delay(300).fadeIn();
			if (stateCombinedList === true) {
				showTenants();
			} else if (stateCompanies === true) {
				showCompanies();
			} else {
				showIndividuals();
			}
		});
	}
}


// ===== ADA overlay button - work around to prevent direct clicking of ADA button while full screen slideshow is running ======
$(document.body).on('mousedown touchstart pointerdown MSPointerDown', '.adaFix' ,function(){ 
	openADA();
	$('.controlOn').css('visibility', 'hidden'); // hide buttons that are in fading in
	setTimeout(function() { // wait half a second for other functions using fade to finish
		$('.controlOn').fadeOut( function() {  // fade controls out
			$('.controlOn').css('visibility', 'visible'); // set visibility back to original state
			if ((stateActiveWindow == 'comb') || (stateActiveWindow == 'comp') || (stateActiveWindow == 'indiv')) {
				$('#searchField').fadeIn(); // show search box if needed
			}
		});
	}, 500);
});

// ================================ TIMEOUT - IDLE TIMER  =====================================
var stateInUse = true; // used for page refresh

// ==== INACTIVE TIMER - no touch or mouse events detected =======
$(document).idleTimer( 120000 );  // time before actions
$(document).on("idle.idleTimer", function () {
	console.debug('Idle Timer Inactive');
	stateInUse = false;

	if (slideShowSize != 'standard') {
		$('.adaFix').fadeIn(1);
	}
	if (stateSecretSlideShow === true) {
		$('.forceSlideMask').fadeOut();
		$('.forceSlideshow1').fadeIn(10);
	}
	if ($('#pdfWindow').is(':visible') || $('#iframeURLContainer').is(':visible') || $('#iframeVideoContainer').is(':visible') || stateActiveWindow == 'amenMap' || stateActiveWindow == 'trafficMap' || stateActiveWindow == 'transit') {
		usePrompt(); // prompt only if iframe related content is active
	} else {
		defaultState(); // otherwise set back to default state
	}
});

// ==== ACTIVE TIMER - mouse or touch events detected ========
$(document).on("active.idleTimer", function () {
	console.debug('Idle Timer Active');
	stateInUse = true;

	if (isPromptActive === true) { // clear prompt if user moves mouse while prompt is visible
		userNeedsMoreTime();
	}

	if ((stateSlideShow === true) && ((slideShowSize == 'fullTSLiveOn') || (slideShowSize == 'fullTSLiveOff'))) { // only when full screen slideshow is running 
		$('#tsSlideshow').fadeOut(function() {
			$('.directoryContainer').fadeIn();
			$('.controlOn').fadeIn();
		});
		directoryTextHide();
		if (stateCombinedList === true) {
			showTenants();
		} else if (stateCompanies === true) {
			showCompanies();
		} else {
			showIndividuals();
		}
		setTimeout(function() {
			$('.adaFix').fadeOut(1);
		}, 100);
		
	}
});


// =========================== DETECT CONFIGURATION AND BUTTONS ===============================
var numButtons = 0; // regular buttons and TSLive button
var numFullButtons = 0; // regular buttons only
var tsliveButtonDetect = 0;
var stateNews = false; //used by ADA button
var stateWeather = false; //used by ADA button

function calculateButtons() { // detect how many non-TSLive buttons
	numButtons = $('.button').length; 
	numFullButtons = $('.button').length; 
	var numTSLiveButtons = $('.buttonTSLive').length;
	if (numTSLiveButtons > 0) {
		$('.contTSLiveBtns').height(80);
		numButtons +=1;
		$('.contTSLiveBtns').width(numTSLiveButtons * 158);
	}
}
function calculateTSLiveButtons() { // detect how many TSLive buttons
	tsliveButtonDetect = $('.buttonTSLive').length;
	if (tsliveButtonDetect) {
		return true;
	} else if (tsliveButtonDetect === 0) {
		return false;
	}
}
function calculateBuilding() { // is there building info section in the header
	var bldgInfoDetect = $('.bldgInfo').length;
	if (bldgInfoDetect) {
		return true;
	} else if (bldgInfoDetect === 0) {
		return false;
	}
}
function calculateTSLiveNews() { // is news active
	var tsliveNewsDetect = $('.newsContainer').length;
	if (tsliveNewsDetect) {
		stateNews = true;
		return true;
	} else if (tsliveNewsDetect === 0) {
		stateNews = false;
		return false;
	}
}
function calculateTSLiveWeather() { // is weather active
	var tsliveWeatherDetect = $('.weatherContainer').length;
	if (tsliveWeatherDetect) {
		stateWeather = true;
		return true;
	} else if (tsliveWeatherDetect === 0) {
		stateWeather = false;
		return false;
	}
}
function calculateTSLiveFinance() { // is financial market active - NOT USED - set with ASP
	var tsliveFinanceDetect = $('.financeContainer').length;
	if (tsliveFinanceDetect) {
		return true;
	} else if (tsliveFinanceDetect === 0) {
		return false;
	}
}

var slideShowSize;
function calculateSlideshow() { // determine which slideshow size to use
	if ($('#tsSlideshow').hasClass('pics3')) { 
		slideShowSize = 'fullTSLiveOff';
	} else if ($('#tsSlideshow').hasClass('pics2')) {
		slideShowSize = 'fullTSLiveOn';
	} else {
		slideShowSize = 'standard';
	}

	var slideshowDetect = $('#tsSlideshow').length;
	if (slideshowDetect) {
		return true;
	} else if (slideshowDetect === 0) {
		return false;
	}
}

var scrollTwitter;
var scrollMsgDetect;
function calculateScrollOrTwitter() {
	var twitterDetect = $('#tweetsCont').length;
	scrollMsgDetect = $('#scrollingMessage').length;
	if (scrollMsgDetect !== 0) {
		scrollTwitter = $('#scrollingMessage');
	} else if (twitterDetect !== 0) {
		scrollTwitter = $('#tweetsCont');
	}
}

function ifNewsOff() {  // if news off then drop down keyboard and listings window elelemts
	if (stateNews === false) {
		$('#scrollSpace').css('top', '893px');
		$('#scrollSearch').css('top', '893px');
		$('#keyboard').css('top', '833px');
		
		listWinKeyOn +=100;
		listWinKeyOff +=100;
	}
}


// ============================ TWO ROW CONFIGURATION =================================
function navTwoRows() { // Arrange Nav buttons in two columns and scale down
	
	var $navBtns = $('.btnCol1').children(); // Count children

	if (numFullButtons % 2 === 0) { // if number of buttons are even
		var half = $navBtns.length/2; 
		var btnContWidth = half * 265;
		$('.btnCol1').css('width', btnContWidth); // btn parent container width

		$navBtns.filter(function(i){  // put half children in top row
			return i < half; 
		}).wrapAll('<div id="btnRow1" class="leftColumn">');
		
		$navBtns.filter(function(i){   // put half children in bottom row
			return i >= half; 
		}).wrapAll('<div id="btnRow2" class="rightColumn">');
	} else { // if number of buttons are odd
		var firstHalf = Math.ceil($navBtns.length/2); 
		var secondHalf = Math.floor($navBtns.length/2); 
		var row1Width = firstHalf * 265;  // should these width be auto calculated????????????????????????????????????????????????
		var row2Width = secondHalf * 265;

		console.debug('First: ' + firstHalf + ' Second: ' + secondHalf);
		$navBtns.filter(function(i){  // put half children plus one in top row
			return i < firstHalf; 
		}).wrapAll('<div id="firstRow" class="twoRow1">');
		
		$navBtns.filter(function(i){   // put remainder of children in bottom row
			return i >= firstHalf; 
		}).wrapAll('<div id="secondRow" class="twoRow2">');

		$('.btnCol1').css('width', row1Width); // btn parent container width
		$('#firstRow').css('width', row1Width);
		$('#secondRow').css('width', row2Width);
	}
}

// ================ MOVE WEATHER DOWN - SHORTEN SCROLLING MESSAGE AND MOVE RIGHT ==================
var setScrollMsgLeft = 0; // default
var setScrollMsgWidth = 1080; // default width for page
var stateWeatherLow = false; //used by ADA open/close
// function weatherScrollMsg() { 
// 	stateWeatherLow = true; 
// 	$('.weatherContainer').css('top', '+=80');
// 	setScrollMsgLeft = 570; // message aligns with right side of news when lowered
// 	setScrollMsgWidth = 1350; // used to change message width when message script loads
// }


// ================================= DEFAULT LISTING TYPE =========================================
var stateCombinedList = false; // combined listings are on?
var stateCompanies = false; // company listings are on?
var stateIndividuals = false; // individual listings are on?
var stateActiveWindow = 'comb'; // comb, comp, ind - currently active listing types

function setListingDefaults() { // detect and set default listing type - reverts to one of these after timeout
	if ( $('.combinedList').length == 1) { 
		stateCombinedList = true; 
		stateActiveWindow = 'comb';
	} else if ( $('.companyContainer').hasClass('onlyCompanies') ) {
		stateCompanies = true;
		stateCombinedList = false;
		stateActiveWindow = 'comp';
		$('.companyContainer .companyListing[data-type="Ind"]').hide(); //hide individuals
	} else {
		$('.individualsContainer').addClass('activeLeft').fadeIn(1);
		stateActiveWindow = 'indiv';
		activeListWindow = $('.individualsContainer .list-window');
		activeTblWrapper = $('.individualsContainer .tbl_wrapper');
	}
	if ( $('.showIndividuals').length == 1) { 
		stateIndividuals = true; 
	}
	if (stateCombinedList === false) { // adjust keyboard
		$('#compFilter').hide();
		$('#indFilter').hide();
		$('#scrollSearch').css('left', '+=40');
	}
}


// ========================CALCULATE  HEIGHTS AND VERTICAL POSITIONS=================================
var listWinKeyOff = $('.list-window').height(); // list-window height default is 768
var listWinKeyOn = listWinKeyOff - 42; // list-window height with keyboard visible 726
var listWinADA = 1096; // list-window height to ADA   
var searchFieldTop = parseFloat($('#searchField').css('top')); //get start position  
var searchFieldTopADA = 1768;  
var scrollSearchTop = parseFloat($('#scrollSearch').css('top')); //get start position 
var scrollSpaceTop = parseFloat($('#scrollSpace').css('top')); //get start position 
var keyboardTop = parseFloat($('#keyboard').css('top')); //get start position 	

var amenContHeight = $('.amenityCont').height(); //  height for amen 
var amenContTop = parseFloat($('.amenityCont').css('top')); //  top for amen 
var amenContHeightADA = 1070; // ada height for amen 	
var amenContTopADA = 710; //  ada top for amen 	

var trafficContHeight = $('.trafficCont').height(); //  height for traffic 
var trafficContTop = parseFloat($('.trafficCont').css('top')); //  top for traffic
var trafficContHeightADA = 1070; // ada height for traffic 	
var trafficContTopADA = 710; //  ada top for traffic	

var transitContHeight = $('.transitCont').height(); //  height for traffic 
var transitContTop = parseFloat($('.transitCont').css('top')); //  top for traffic 	
var transitContHeightADA = 1070; // ada height for traffic 	
var transitContTopADA = 710; //  ada top for traffic	

var webContHeight = $('#urlModal').height(); //  height for web url 
var webContTop = $('#urlModal').css('top'); //  top for web url 
var webContHeightADA = 900; // ada height web url 
var webContTopADA = 870; //  ada top for web url 

var pdfContTop = $('#pdfWindow').css('top'); //  top for pdf window 
var pdfContTopADA = 452; //  ada top for pdf window 
var pdfCloseTop = $('.closePDF').css('top'); //  top for pdf close button 	
var pdfCloseTopADA = 1821; //  ada top for pdf close button 

function tallHeader(moveDown) { // adjust page elements variable down to accomodate a taller header
	var newAddressHeight = 98 + moveDown; // 98 needs to match .addressCont height from css
	$('.pageHeader').css('height', '+=' + moveDown);
	$('.addressCont').css('height', newAddressHeight); 
	// console.debug($('.addressCont').css('height'));
	$('#tsSlideshow').css('top', '+=' + moveDown);
	$('.directoryContainer').css('top', '+=' + moveDown);
	listWinKeyOn -=moveDown;
	listWinKeyOff -=moveDown;
	listWinADA -=moveDown;
	amenContHeight -=moveDown;
	amenContTop +=moveDown;
	trafficContHeight -=moveDown;
	trafficContTop +=moveDown;
	transitContHeight -=moveDown;
	transitContTop +=moveDown;
	amenContHeightADA -=moveDown;
	amenContTopADA +=moveDown;
	trafficContHeightADA -=moveDown;
	trafficContTopADA +=moveDown;
	transitContHeightADA -=moveDown;
	transitContTopADA +=moveDown;
}
function noSlideshow() { // adjust page elements variables to accomodate no slideshow
	$('.directoryContainer').css('top', '-=582'); // -579 is slideshow height diff -3 to account for border removal (-582)
	$('.pageHeader').css('borderBottom', 'none');
	listWinKeyOn +=579;
	listWinKeyOff +=579;
	listWinADA +=579;
}
function setVerticalElements() { // execute all changes in heights and positions
	$('.list-window').css('height', listWinKeyOff);
	$('#searchField').css('top', searchFieldTop);
	$('#scrollSearch').css('top', scrollSearchTop);
	$('#scrollSpace').css('top', scrollSpaceTop);
	$('#keyboard').css('top', keyboardTop);
	$('.amenityCont').css({'height': amenContHeight, 'top': amenContTop});
	$('.trafficCont').css({'height': trafficContHeight, 'top': trafficContTop});
	$('.transitCont').css({'height': transitContHeight, 'top': transitContTop});
}
function configureVerticalElements(vertPosition) { // adjust elements heights and positions from
	if (vertPosition < 0) { // negative numbers do this
		var positiveValue = Math.abs(vertPosition); // convert negative to positive number
		$('.btnContWrapper').css('top', '-=' + positiveValue);
		listWinKeyOn -=positiveValue;
		listWinKeyOff -=positiveValue;
		searchFieldTop -=positiveValue;
		scrollSearchTop -=positiveValue;
		scrollSpaceTop -=positiveValue;
		keyboardTop -=positiveValue;
		amenContHeight -=positiveValue;
		trafficContHeight -=positiveValue;
		transitContHeight -=positiveValue;
	} else if (vertPosition > 0) { // positive numbers do this
		$('.btnContWrapper').css('top', '+=' + vertPosition);
		listWinKeyOn +=vertPosition;
		listWinKeyOff +=vertPosition;
		searchFieldTop +=vertPosition;
		scrollSearchTop +=vertPosition;
		scrollSpaceTop +=vertPosition;
		keyboardTop +=vertPosition;
		amenContHeight +=vertPosition;
		trafficContHeight +=vertPosition;
		transitContHeight +=vertPosition;
	}
	setVerticalElements(); // reconfigure elements now
}



// =================== MOVE BUTTONS AND PAGE ELEMENTS TO ACCOMMODATE NAVIGATION =========================
function configurePageElements() {
	var btnContHeight;
	var btnContTop;
	var btnCol1Width;

	tallHeader(40); // amount header increases in height and page elements get pushed down - this can be adjusted

	if ((calculateSlideshow() === false) || (slideShowSize == 'fullTSLiveOn') || (slideShowSize == 'fullTSLiveOff')) { // adjust heights if no slideshow
		noSlideshow();
		trafficContTopADA = 148;
		trafficContHeightADA = 1640;
		amenContTopADA = 148;
		amenContHeightADA = 1640;
		transitContTopADA = 148;
		transitContHeightADA = 1640;
	}

	if ((calculateTSLiveNews() === false) && (calculateTSLiveButtons() === false)) {
		if (numFullButtons >= 9) {
			// not designed for 9 or more buttons
		} else if (numFullButtons >= 5) {
			navTwoRows();
			configureVerticalElements(130);
		} else if (numFullButtons <=4) {
			$('.btnCol1').css('width', (numFullButtons * 265));
			configureVerticalElements(210);
		}

	} else if ((calculateTSLiveNews() === true) && (calculateTSLiveButtons() === true)) {
		if (numFullButtons >= 9) {
			// not designed for 9 or more buttons
		} else if (numFullButtons >= 5) {
			navTwoRows();
			configureVerticalElements(-70);
		} else if (numFullButtons <=4) {
			$('.btnCol1').css('width', (numFullButtons * 265));
			configureVerticalElements(0);
		}

	} else if ((calculateTSLiveNews() === true) && (calculateTSLiveButtons() === false)) { 
		if (numFullButtons >= 9) {
			// not designed for 9 or more buttons
		} else if (numFullButtons >= 5) {
			navTwoRows();
			configureVerticalElements(0);
		} else if (numFullButtons <=4) {
			$('.btnCol1').css('width', (numFullButtons * 265));
			configureVerticalElements(70);
		}

	} else if ((calculateBuilding() === false) && (calculateTSLiveNews() === false) && (calculateTSLiveButtons() === true)) { // CONFIGURATION NOT POSSIBLE
		// not possible to turn on TSLive and remove the news/weather/stock bar

	}  // end button permutations
} // end configurePageElements


// ======================== TIME AND DATE ==============================
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
    document.getElementById('currentDate').innerHTML = dayName + ', ' + monthName + ' ' + currDate;
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


//===================== TOOLS =========================
// === Tell me what div I click on ===
// $('div').click(function(){
// 	console.error(this)
// })
