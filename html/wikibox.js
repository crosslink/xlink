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
	xmlhttp.onreadystatechange=function()
	  {
	  if (xmlhttp.readyState==4 && xmlhttp.status==200)
	    {
	    document.getElementById("wikiabstract").innerHTML=xmlhttp.responseText;
	    }
	  }
	xmlhttp.open("GET", url, true);
	xmlhttp.send();
}

function showWikiBox() {
	wikiboxHtml = '<div id="wikibox"><div id="wikilinks"><a href=&quot;http://en.wikipedia.org&quot;>Wikipedia</a></div><br><hr><div style="font-style:italic" id="wikiabstract"><img src="ajaxload.gif" /> Fetching Abstract...</div></div>',
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
	
	loadXMLDoc("http://localhost");
//	var wikiAbstract = document.getElementById("wikiabstract");
	
/*	if (wikiAbstract) {
		setTimeout(function() {
//			$("#wikiabstract").load("abstract_test.txt");
	//		tt_aElt[0].innerHTML = "Crazy me";
			wikiAbstract.innerHTML = "Crazy me";
			
	    }, 2000);
	}*/
}