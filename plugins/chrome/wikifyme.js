debugger;

var wikification_server = "centos6.qut.edu.au:8888";
var wikification_request_url = "http://" + wikification_server + "/?page=";

function AlertMe(url) {
	alert("I am running on " + url);
}

function UpdateDocument(newHtml) {
	if (newHtml)
		document.write(newHtml);
}

if (url_to_wikify) {
//	AlertMe(url_to_wikify);
	console.log("receiving request for wikifying url: " + url_to_wikify);
	getContentByUrl(wikification_request_url + url_to_wikify, UpdateDocument);
}

