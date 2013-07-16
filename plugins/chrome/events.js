function ListeningEvent(request, sender, response)
{
  if (request.action == 'AlertMe')
	  AlertMe(request.data);
}
 
chrome.extension.onMessage.addListener(ListeningEvent);