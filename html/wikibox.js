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

function loadXMLDoc(url)
{
	var xmlhttp;
	if (window.XMLHttpRequest) // code for IE7+, Firefox, Chrome, Opera, Safari, 
	{
		xmlhttp=new XMLHttpRequest();
	}
	else // code for IE6, IE5
	{
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	
	xmlhttp.onreadystatechange = function()
	{
	    var text;
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200)
		{
			text = xmlhttp.responseText;
		}
		else
		{
		    text = "Error in retrieving the abstract";
		}
		document.getElementById("wikiabstract").innerHTML= text;
	}
	xmlhttp.open("GET", url, true);
	xmlhttp.send();
}

function showWikiBox(lang, id, anchor, others) {
	wikiboxHtml = '<div id="wikibox"><div id="wikititle"><h3>' + anchor + '</h3><hr></div><div id="wikiabstract"><img src="ajaxload.gif" /> Fetching Abstract...</div>';
	if (others) {
		var links = createSeeAlsoLinks(others);
		wikiboxHtml = wikiboxHtml.concat('<div class="seealso"><h3>See Also</h3><hr><br>' + links + '</div>');
	}
	wikiboxHtml = wikiboxHtml.concat('</div>');
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
	
	loadXMLDoc('/get?pageid=' + id + '&lang=' + lang);
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
		var temp = '<a  class="wikibox" href=&quot;http://' + lang +'.wikipedia.org/w/index.php?curid=' + id + '&quot;>' + anchor +	'</a>';
		if (i > 0)
			links_html = links_html.concat('<br>');
		links_html = links_html.concat(temp);
	}
	return links_html;
//	links_html.concat('</div>');
}