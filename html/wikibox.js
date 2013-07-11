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

function getContentByUrl(url)
{
	var httpRequest;
	if (window.httpRequestRequest) // for IE7+, Firefox, Chrome, Opera, Safari, 
	{
		httpRequest = new httpRequestRequest();
	}
	else // for IE6, IE5
	{
		httpRequest = new ActiveXObject("Microsoft.httpRequest");
	}
	
	httpRequest.onreadystatechange = function()
	{
	    var text;
		if (httpRequest.readyState == 4 && httpRequest.status == 200)
		{
			text = httpRequest.responseText;
		}
		else
		{
		    text = "Error in retrieving the abstract";
		}
		setInfo(text);
	}
	httpRequest.open("GET", url, true);
	httpRequest.send();
}

function setInfo(text) {
	document.getElementById("wikiabstract").innerHTML= text;
}

function displayProgress(info) {
	var loadingInfo = '<img src="ajaxload.gif" /> Fetching Abstract';
	
	if (info)
		loadingInfo = loadingInfo.concat(' for ' + info);
	loadingInfo = loadingInfo.concat('...');
	setInfo(loadingInfo);
}

function loadAbstract(id, lang, anchor) {
	displayProgress(anchor);
	getContentByUrl('/get?pageid=' + id + '&lang=' + lang);
}

function showWikiBox(lang, id, anchor, others) {
	wikiboxHtml = '<div id="wikibox"><div id="wikititle"><h3>' + anchor + '</h3><hr></div><div id="wikiabstract"></div>';
	if (others) {
		var links = createSeeAlsoLinks(others);
		wikiboxHtml = wikiboxHtml.concat('<div id="wikiseealso" class="seealso"><h3>See Also</h3><hr><br>' + links + '</div>');
	}
	wikiboxHtml = wikiboxHtml.concat('</div>');
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
	
	loadAbstract(id, lang, anchor);
}

function createSeeAlsoLinks(others) {
	var links_array = others.split(";");
	var links_html = ""; 
	//'<div id="wikilinks">';

	for (var i = 0; i < links_array.length; i++) {
		var id_anchor = links_array[i].split(":");
		var lang = id_anchor[0];
		var id = id_anchor[1];
		var anchor = id_anchor[2];
		var temp = '<a  class="wikibox" href=&quot;http://' + lang +'.wikipedia.org/w/index.php?curid=' + id + '&quot; onmouseover=&quot;loadAbstract(' + id +', ' + lang + ', ' + anchor + ')&quot;>' + anchor +	'</a>';
		if (i > 0)
			links_html = links_html.concat('<br>');
		links_html = links_html.concat(temp);
	}
	return links_html;
//	links_html.concat('</div>');
}