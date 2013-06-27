function showWikiBox() {
	wikiboxHtml = '<a href=&quot;http://en.wikipedia.org&quot;>Wikipedia</a><div id="wikibox"><hr><br><div style="font-style:italic" id="wikiabstract"><img src="ajaxload.gif" /> Fetching Abstract...</div></div>',
	
	Tip(wikiboxHtml, DELAY, 1000, STICKY, true);
}