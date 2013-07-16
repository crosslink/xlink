/*
 * listen on the onclick event
 */
//if (tab.url.indexOf("chrome-devtools://") == -1) {
	chrome.browserAction.onClicked.addListener(
			function(tab) {
//				chrome.tabs.executeScript(null, {file: "events.js", allFrames: false });
//				 chrome.tabs.executeScript(null, {file: "wikifyme.js"}, function() {
//					var port = chrome.tabs.connect(tab.id);
					 chrome.tabs.sendMessage(tab.id, {
		                     'action': 'AlertMe',
		                     'data'  : tab.url
		             }, function(response) {});
//				 });
					 chrome.tabs.executeScript(null, {file: "wikifyme.js"}, function () {}
				 chrome.tabs.executeScript(null, {file: "wikifyme.js"});
			}
//				 chrome.tabs.executeScript(null, {code: "AlertMe"});
			}
	);
//}
