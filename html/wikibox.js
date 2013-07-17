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

function setInfo(text) {
	var wikiAbstractElem = document.getElementById("wikiabstract");
	if (text)
		wikiAbstractElem.innerHTML= text;
	else
		wikiAbstractElem.innerHTML= "Error in retrieving the abstract";
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
	getContentByUrl('/get?pageid=' + id + '&lang=' + lang, setInfo);
}

function showWikiBox(lang, id, anchor, others) {
	
	wikiboxHtml = '<div id="wikibox"><div id="wikititle"><h3>' + anchor + '</h3><hr></div><div id="wikiabstract"></div>';
//	if (others) {
//		var links = createSeeAlsoLinks(others);
// 		' + links + '
		wikiboxHtml = wikiboxHtml.concat('<br><div id="wikiseealso" class="seealso"><h3>See Also</h3><hr><div id="wiki-see-also-links"></div></div>');
//	}
	wikiboxHtml = wikiboxHtml.concat('</div>');
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
	
	createSeeAlsoLinks(others);
	
	loadAbstract(id, lang, anchor);
}

function updateAbstract() {
	var id_lang = this.title.split(":");
	var anchor = this.innerHTML;
	var lang = id_lang[0];
	var id = id_lang[1];
		
	loadAbstract(id, lang, anchor); 
}

function createSeeAlsoLinks(others) {
	var otherLinksDiv = document.getElementById("wiki-see-also-links");
	var links_array = others.split(";");
	var links_html = ""; 
	//'<div id="wikilinks">';

	if (otherLinksDiv) {	
		while (otherLinksDiv.hasChildNodes()) {
			otherLinksDiv.removeChild(otherLinksDiv.lastChild);
		}
		for (var i = 0; i < links_array.length; i++) {
			var id_anchor = links_array[i].split(":");
			var lang = id_anchor[0];
			var id = id_anchor[1];
			var anchor = id_anchor[2];
			
			var a = document.createElement('a');
			var anchorText = document.createTextNode(anchor);
			a.appendChild(anchorText);
			a.title = lang + ':' + id;
			a.href = 'http://' + lang +'.wikipedia.org/w/index.php?curid=' + id;
			var onEvent = "loadAbstract('" + id +"', '" + lang + "', '" + anchor + "');";
			a.onmouseover =updateAbstract
//			a.hover = onEvent;
			otherLinksDiv.appendChild(a);
			
	//		var temp = '<a  class="wikibox" href="http://' + lang +'.wikipedia.org/w/index.php?curid=' + id + '" onmouseover="loadAbstract(&quote;' + id +'&quote;, &quote;' + lang + '&quote;, &quote;' + anchor + '&quote;)">' + anchor +	'</a>';
			if (links_array.length > (i + 1)) {
	//			links_html = links_html.concat('<br>');
				var lineBreak = document.createElement('br');
				otherLinksDiv.appendChild(lineBreak);
			}
	//		links_html = links_html.concat(temp);
		}
	}
//	return links_html;
//	links_html.concat('</div>');
}