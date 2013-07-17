/*
 * listen on the onclick event
 */
//if (tab.url.indexOf("chrome-devtools://") == -1) {
	chrome.browserAction.onClicked.addListener(
			function(tab) {
//				chrome.tabs.executeScript(null, {file: "events.js", allFrames: false });
//				 chrome.tabs.executeScript(null, {file: "wikifyme.js"}, function() {
//					var port = chrome.tabs.connect(tab.id);
//					 chrome.tabs.sendMessage(tab.id, {
//		                     'action': 'AlertMe',
//		                     'data'  : tab.url
//		             }, function(response) {});
//				 });
					 chrome.tabs.executeScript(tab.id, {code: "var url_to_wikify = " + JSON.stringify(tab.url)}, function () {
						 chrome.tabs.executeScript(tab.id, {file: "wikifyme.js"});
					 });
			}
//				 chrome.tabs.executeScript(null, {code: "AlertMe"});
//			}
	);
//}
