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

function getContentByUrl(url, callback)
{
	var httpRequest;
	if (window.XMLHttpRequest) // for IE7+, Firefox, Chrome, Opera, Safari, 
	{
		httpRequest = new  XMLHttpRequest();
	}
	else // for IE6, IE5
	{
		httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
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
		callback(text);
	}
	httpRequest.open("GET", url, true);
	httpRequest.send();
}