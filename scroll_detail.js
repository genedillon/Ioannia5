var w = window,
d = document,
e = d.documentElement,
g = d.getElementsByTagName('body')[0],
viewHeight = w.innerHeight|| e.clientHeight|| g.clientHeight;
// var windowHeight = 550  // use to hard code the height of parent window


var scrolling = false;
var activeListWindow = $('.companyContainer .list-window'); // set as default
var activeTblWrapper = $('.companyContainer .tbl_wrapper'); // set as default
var canScroll; // detect if scrolling conditions are met

// =========== SCROLL BUTTONS ============
$(".scrollUpBtn").on("mousedown touchstart pointerdown MSPointerDown", function(event) {
		scrolling = true;
		scrollContentDir("up", activeListWindow, activeTblWrapper);
		if (canScroll == true) {
		$('.scrollUpBtn').css('opacity', '.3');
		}
	}).on("mouseup mouseleave touchend pointerup MSPointerUp", function(event) {
		scrolling = false;
		if (canScroll == true) {
		$('.scrollUpBtn').css('opacity', '1');
		}
		canScroll = false;
});
$(".scrollDownBtn").on("mousedown touchstart pointerdown MSPointerDown", function(event) {	
		scrolling = true;
		scrollContentDir("down", activeListWindow, activeTblWrapper);
		if (canScroll == true) {
		$('.scrollDownBtn').css('opacity', '.3');
		}
	}).on("mouseup mouseleave touchend pointerup MSPointerUp", function(event) {
		scrolling = false;
		if (canScroll == true) {
		$('.scrollDownBtn').css('opacity', '1');
		}
		canScroll = false;
});


// ================= COMMON SCROLLING FUNCTION ===================
function scrollContentDir(direction, listWindow, tableWrapper) {
	var amount = (direction === "up" ? "+=6px" : "-=6px"); // inline if-then statement
	var windowHeight = listWindow.innerHeight();  // parameter sent from button
	// var fullHeight = tableWrapper.height();  // parameter sent from button
	var fullHeight = tableWrapper.innerHeight();  // parameter sent from button
	var currentMargin = parseFloat(tableWrapper.css('marginTop'));
	var currDiff = fullHeight - Math.abs(currentMargin);
	var adaOffset = parseFloat(windowHeight) - 60;
	var testVarNew = -(fullHeight - windowHeight) + 12;

	// console.log('CurrMar=['+currentMargin+'] NewVar =['+testVarNew+'] CurrDiff=['+currDiff+'] WinH =['+windowHeight+']');
	
	// ======== DOWN ARROW ========
	if ( (currentMargin < windowHeight) && (currentMargin > testVarNew) && (direction === 'down') && (adaValue == true) ) {
		// console.log('Down' + tableWrapper.css('marginTop'));
		canScroll = true;
		tableWrapper.animate({
			marginTop:amount
		}, 1, function() {
			if (scrolling) {
				scrollContentDir(direction, listWindow, tableWrapper);
			}
		});
	} else if ( (currDiff > windowHeight) && (direction === 'down') && (adaValue == false) ) {
		// console.log('Down' + tableWrapper.css('marginTop'));
		canScroll = true;
		tableWrapper.animate({
			marginTop:amount
		}, 1, function() {
			if (scrolling) {
				scrollContentDir(direction, listWindow, tableWrapper);
			}
		});
	} 
	// ======= UP ARROW =========
	if ( (currentMargin < adaOffset) && (direction === 'up') && (adaValue == true) ) {
		// console.debug('Up' + tableWrapper.css('marginTop'));
		canScroll = true;
		tableWrapper.animate({
			marginTop:amount
		}, 1, function() {
			if (scrolling) {
				scrollContentDir(direction, listWindow, tableWrapper);
			}
		});
	}  else if ( (currentMargin < 0) && (direction === 'up') && (adaValue == false) ) {
		// console.error('Up' + tableWrapper.css('marginTop'));
		canScroll = true;
		tableWrapper.animate({
			marginTop:amount
		}, 1, function() {
			if (scrolling) {
				scrollContentDir(direction, listWindow, tableWrapper);
			}
		});
	} 
}; // end scrollContentdDir


function disableScroll(directionNew, listWindowNew, tableWrapperNew) {
	$('.scrollSpaceDownBtn, .scrollSpaceUpBtn').off('mousedown', scrollContentDir(directionNew, listWindowNew, tableWrapperNew) );
};
function enableScroll(directionNew, listWindowNew, tableWrapperNew) {
	$('.scrollSpaceDownBtn, .scrollSpaceUpBtn').on('mousedown', scrollContentDir(directionNew, listWindowNew, tableWrapperNew) );
};