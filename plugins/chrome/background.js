/******************************************************************************
 * This file is part of the XLINK - The Link Discovery Toolkit.
 * (c) Copyright 2013 Queensland University of Technology
 *
 * This file may be distributed and/or modified under the terms of the
 * BSD 3-cause LICENSE appearing in the file BSD.txt included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *******************************************************************************
 *
 * @author				Eric Tang
 *
 *******************************************************************************/

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
						 chrome.tabs.executeScript(tab.id, {file: "ajax.js", file: "wikifyme.js"});
					 });
			}
//				 chrome.tabs.executeScript(null, {code: "AlertMe"});
//			}
	);
//}
