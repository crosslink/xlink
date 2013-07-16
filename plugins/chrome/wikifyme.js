//if (tab.url.indexOf("chrome-devtools://") == -1) {
	chrome.browserAction.onClicked.addListener(
			function(tab) {
				chrome.tabs.executeScript(null, {file: "events.js"});
			}
	);
//}
