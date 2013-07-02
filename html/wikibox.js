function loadXMLDoc(url)
{
	var xmlhttp;
	if (window.XMLHttpRequest)
	{// code for IE7+, Firefox, Chrome, Opera, Safari
		xmlhttp=new XMLHttpRequest();
	}
	else
	{// code for IE6, IE5
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	
	xmlhttp.onreadystatechange = function()
	{
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200)
		{
			var abs = processAbstract(xmlhttp.responseText);
			document.getElementById("wikiabstract").innerHTML= abs;
		}
	}
	xmlhttp.open("GET", url, true);
	xmlhttp.send();
}

function showWikiBox1() {
	Tip("test", DELAY, 1000, STICKY, true);
}

function showWikiBox(lang, id, anchor) {
	wikiboxHtml = '<div id="wikibox"><div id="wikilinks"><a href=&quot;' + 'http://' + lang +'.wikipedia.org/w/index.php?curid=' + id + '&quot;>' + anchor +	'</a></div><br><hr><div style="font-style:italic" id="wikiabstract"><img src="http://localhost/ajaxload.gif" /> Fetching Abstract...</div></div>';
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
	
	loadXMLDoc('/get?pageid=' + id);
//	var wikiAbstract = document.getElementById("wikiabstract");
	
/*	if (wikiAbstract) {
		setTimeout(function() {
//			$("#wikiabstract").load("abstract_test.txt");
	//		tt_aElt[0].innerHTML = "Crazy me";
			wikiAbstract.innerHTML = "Crazy me";
			
	}, 2000);
	}*/
}

function processAbstract (text) {
	return text
}
/*
function processAbstract(text) {
	return text;
}*/