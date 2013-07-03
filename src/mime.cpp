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
 * mime.cpp
 *
 *  Created on: 03/07/2013
 */

#include "mime.h"

#include <string.h>

namespace QLINK {

/*
 * http://webdesign.about.com/od/multimedia/a/mime-types-by-file-extension.htm
 */
std::map<std::string, const char *> mime::MIME_TYPE;
int mime::TYPE_COUNT = 0; //sizeof(MIME_TYPE) / sizeof(MIME_TYPE[0]);

mime::mime() {
	if (MIME_TYPE.size() == 0) {
		MIME_TYPE["*"] = "application/octet-stream";
		MIME_TYPE["323"] = "text/h323";
		MIME_TYPE["acx"] = "application/internet-property-stream";
		MIME_TYPE["ai"] = "application/postscript";
		MIME_TYPE["aif"] = "audio/x-aiff";
		MIME_TYPE["aifc"] = "audio/x-aiff";
		MIME_TYPE["aiff"] = "audio/x-aiff";
		MIME_TYPE["asf"] = "video/x-ms-asf";
		MIME_TYPE["asr"] = "video/x-ms-asf";
		MIME_TYPE["asx"] = "video/x-ms-asf";
		MIME_TYPE["au"] = "audio/basic";
		MIME_TYPE["avi"] = "video/x-msvideo";
		MIME_TYPE["axs"] = "application/olescript";
		MIME_TYPE["bas"] = "text/plain";
		MIME_TYPE["bcpio"] = "application/x-bcpio";
		MIME_TYPE["bin"] = "application/octet-stream";
		MIME_TYPE["bmp"] = "image/bmp";
		MIME_TYPE["c"] = "text/plain";
		MIME_TYPE["cat"] = "application/vnd.ms-pkiseccat";
		MIME_TYPE["cdf"] = "application/x-cdf";
		MIME_TYPE["cdf"] = "application/x-netcdf";
		MIME_TYPE["cer"] = "application/x-x509-ca-cert";
		MIME_TYPE["class"] = "application/octet-stream";
		MIME_TYPE["clp"] = "application/x-msclip";
		MIME_TYPE["cmx"] = "image/x-cmx";
		MIME_TYPE["cod"] = "image/cis-cod";
		MIME_TYPE["cpio"] = "application/x-cpio";
		MIME_TYPE["crd"] = "application/x-mscardfile";
		MIME_TYPE["crl"] = "application/pkix-crl";
		MIME_TYPE["crt"] = "application/x-x509-ca-cert";
		MIME_TYPE["csh"] = "application/x-csh";
		MIME_TYPE["css"] = "text/css";
		MIME_TYPE["dcr"] = "application/x-director";
		MIME_TYPE["der"] = "application/x-x509-ca-cert";
		MIME_TYPE["dir"] = "application/x-director";
		MIME_TYPE["dll"] = "application/x-msdownload";
		MIME_TYPE["dms"] = "application/octet-stream";
		MIME_TYPE["doc"] = "application/msword";
		MIME_TYPE["dot"] = "application/msword";
		MIME_TYPE["dvi"] = "application/x-dvi";
		MIME_TYPE["dxr"] = "application/x-director";
		MIME_TYPE["eps"] = "application/postscript";
		MIME_TYPE["etx"] = "text/x-setext";
		MIME_TYPE["evy"] = "application/envoy";
		MIME_TYPE["exe"] = "application/octet-stream";
		MIME_TYPE["fif"] = "application/fractals";
		MIME_TYPE["flr"] = "x-world/x-vrml";
		MIME_TYPE["gif"] = "image/gif";
		MIME_TYPE["gtar"] = "application/x-gtar";
		MIME_TYPE["gz"] = "application/x-gzip";
		MIME_TYPE["h"] = "text/plain";
		MIME_TYPE["hdf"] = "application/x-hdf";
		MIME_TYPE["hlp"] = "application/winhlp";
		MIME_TYPE["hqx"] = "application/mac-binhex40";
		MIME_TYPE["hta"] = "application/hta";
		MIME_TYPE["htc"] = "text/x-component";
		MIME_TYPE["htm"] = "text/html";
		MIME_TYPE["html"] = "text/html";
		MIME_TYPE["htt"] = "text/webviewhtml";
		MIME_TYPE["ico"] = "image/x-icon";
		MIME_TYPE["ief"] = "image/ief";
		MIME_TYPE["iii"] = "application/x-iphone";
		MIME_TYPE["ins"] = "application/x-internet-signup";
		MIME_TYPE["isp"] = "application/x-internet-signup";
		MIME_TYPE["jfif"] = "image/pipeg";
		MIME_TYPE["jpe"] = "image/jpeg";
		MIME_TYPE["jpeg"] = "image/jpeg";
		MIME_TYPE["jpg"] = "image/jpeg";
		MIME_TYPE["js"] = "application/x-javascript";
		MIME_TYPE["latex"] = "application/x-latex";
		MIME_TYPE["lha"] = "application/octet-stream";
		MIME_TYPE["lsf"] = "video/x-la-asf";
		MIME_TYPE["lsx"] = "video/x-la-asf";
		MIME_TYPE["lzh"] = "application/octet-stream";
		MIME_TYPE["m13"] = "application/x-msmediaview";
		MIME_TYPE["m14"] = "application/x-msmediaview";
		MIME_TYPE["m3u"] = "audio/x-mpegurl";
		MIME_TYPE["man"] = "application/x-troff-man";
		MIME_TYPE["mdb"] = "application/x-msaccess";
		MIME_TYPE["me"] = "application/x-troff-me";
		MIME_TYPE["mht"] = "message/rfc822";
		MIME_TYPE["mhtml"] = "message/rfc822";
		MIME_TYPE["mid"] = "audio/mid";
		MIME_TYPE["mny"] = "application/x-msmoney";
		MIME_TYPE["mov"] = "video/quicktime";
		MIME_TYPE["movie"] = "video/x-sgi-movie";
		MIME_TYPE["mp2"] = "video/mpeg";
		MIME_TYPE["mp3"] = "audio/mpeg";
		MIME_TYPE["mpa"] = "video/mpeg";
		MIME_TYPE["mpe"] = "video/mpeg";
		MIME_TYPE["mpeg"] = "video/mpeg";
		MIME_TYPE["mpg"] = "video/mpeg";
		MIME_TYPE["mpp"] = "application/vnd.ms-project";
		MIME_TYPE["mpv2"] = "video/mpeg";
		MIME_TYPE["ms"] = "application/x-troff-ms";
		MIME_TYPE["msg"] = "application/vnd.ms-outlook";
		MIME_TYPE["mvb"] = "application/x-msmediaview";
		MIME_TYPE["nc"] = "application/x-netcdf";
		MIME_TYPE["nws"] = "message/rfc822";
		MIME_TYPE["oda"] = "application/oda";
		MIME_TYPE["p10"] = "application/pkcs10";
		MIME_TYPE["p12"] = "application/x-pkcs12";
		MIME_TYPE["p7b"] = "application/x-pkcs7-certificates";
		MIME_TYPE["p7c"] = "application/x-pkcs7-mime";
		MIME_TYPE["p7m"] = "application/x-pkcs7-mime";
		MIME_TYPE["p7r"] = "application/x-pkcs7-certreqresp";
		MIME_TYPE["p7s"] = "application/x-pkcs7-signature";
		MIME_TYPE["pbm"] = "image/x-portable-bitmap";
		MIME_TYPE["pdf"] = "application/pdf";
		MIME_TYPE["pfx"] = "application/x-pkcs12";
		MIME_TYPE["pgm"] = "image/x-portable-graymap";
		MIME_TYPE["pko"] = "application/ynd.ms-pkipko";
		MIME_TYPE["pma"] = "application/x-perfmon";
		MIME_TYPE["pmc"] = "application/x-perfmon";
		MIME_TYPE["pml"] = "application/x-perfmon";
		MIME_TYPE["pmr"] = "application/x-perfmon";
		MIME_TYPE["pmw"] = "application/x-perfmon";
		MIME_TYPE["pnm"] = "image/x-portable-anymap";
		MIME_TYPE["pot"] = "application/vnd.ms-powerpoint";
		MIME_TYPE["ppm"] = "image/x-portable-pixmap";
		MIME_TYPE["pps"] = "application/vnd.ms-powerpoint";
		MIME_TYPE["ppt"] = "application/vnd.ms-powerpoint";
		MIME_TYPE["prf"] = "application/pics-rules";
		MIME_TYPE["ps"] = "application/postscript";
		MIME_TYPE["pub"] = "application/x-mspublisher";
		MIME_TYPE["qt"] = "video/quicktime";
		MIME_TYPE["ra"] = "audio/x-pn-realaudio";
		MIME_TYPE["ram"] = "audio/x-pn-realaudio";
		MIME_TYPE["ras"] = "image/x-cmu-raster";
		MIME_TYPE["rgb"] = "image/x-rgb";
		MIME_TYPE["rmi"] = "audio/mid";
		MIME_TYPE["roff"] = "application/x-troff";
		MIME_TYPE["rtf"] = "application/rtf";
		MIME_TYPE["rtx"] = "text/richtext";
		MIME_TYPE["scd"] = "application/x-msschedule";
		MIME_TYPE["sct"] = "text/scriptlet";
		MIME_TYPE["setpay"] = "application/set-payment-initiation";
		MIME_TYPE["setreg"] = "application/set-registration-initiation";
		MIME_TYPE["sh"] = "application/x-sh";
		MIME_TYPE["shar"] = "application/x-shar";
		MIME_TYPE["sit"] = "application/x-stuffit";
		MIME_TYPE["snd"] = "audio/basic";
		MIME_TYPE["spc"] = "application/x-pkcs7-certificates";
		MIME_TYPE["spl"] = "application/futuresplash";
		MIME_TYPE["src"] = "application/x-wais-source";
		MIME_TYPE["sst"] = "application/vnd.ms-pkicertstore";
		MIME_TYPE["stl"] = "application/vnd.ms-pkistl";
		MIME_TYPE["stm"] = "text/html";
		MIME_TYPE["sv4cpio"] = "application/x-sv4cpio";
		MIME_TYPE["sv4crc"] = "application/x-sv4crc";
		MIME_TYPE["svg"] = "image/svg+xml";
		MIME_TYPE["swf"] = "application/x-shockwave-flash";
		MIME_TYPE["t"] = "application/x-troff";
		MIME_TYPE["tar"] = "application/x-tar";
		MIME_TYPE["tcl"] = "application/x-tcl";
		MIME_TYPE["tex"] = "application/x-tex";
		MIME_TYPE["texi"] = "application/x-texinfo";
		MIME_TYPE["texinfo"] = "application/x-texinfo";
		MIME_TYPE["tgz"] = "application/x-compressed";
		MIME_TYPE["tif"] = "image/tiff";
		MIME_TYPE["tiff"] = "image/tiff";
		MIME_TYPE["tr"] = "application/x-troff";
		MIME_TYPE["trm"] = "application/x-msterminal";
		MIME_TYPE["tsv"] = "text/tab-separated-values";
		MIME_TYPE["txt"] = "text/plain";
		MIME_TYPE["uls"] = "text/iuls";
		MIME_TYPE["ustar"] = "application/x-ustar";
		MIME_TYPE["vcf"] = "text/x-vcard";
		MIME_TYPE["vrml"] = "x-world/x-vrml";
		MIME_TYPE["wav"] = "audio/x-wav";
		MIME_TYPE["wcm"] = "application/vnd.ms-works";
		MIME_TYPE["wdb"] = "application/vnd.ms-works";
		MIME_TYPE["wks"] = "application/vnd.ms-works";
		MIME_TYPE["wmf"] = "application/x-msmetafile";
		MIME_TYPE["wps"] = "application/vnd.ms-works";
		MIME_TYPE["wri"] = "application/x-mswrite";
		MIME_TYPE["wrl"] = "x-world/x-vrml";
		MIME_TYPE["wrz"] = "x-world/x-vrml";
		MIME_TYPE["xaf"] = "x-world/x-vrml";
		MIME_TYPE["xbm"] = "image/x-xbitmap";
		MIME_TYPE["xla"] = "application/vnd.ms-excel";
		MIME_TYPE["xlc"] = "application/vnd.ms-excel";
		MIME_TYPE["xlm"] = "application/vnd.ms-excel";
		MIME_TYPE["xls"] = "application/vnd.ms-excel";
		MIME_TYPE["xlt"] = "application/vnd.ms-excel";
		MIME_TYPE["xlw"] = "application/vnd.ms-excel";
		MIME_TYPE["xof"] = "x-world/x-vrml";
		MIME_TYPE["xpm"] = "image/x-xpixmap";
		MIME_TYPE["xwd"] = "image/x-xwindowdump";
		MIME_TYPE["z"] = "application/x-compress";
		MIME_TYPE["zip"] = "application/zip";

		TYPE_COUNT = MIME_TYPE.size();
	}

}

mime::~mime() {

}

const char* mime::get_mime_type(const char* filename) {
	const char *mime_type = MIME_TYPE["*"];  // unknown type

	char *ext = strchr((char *)filename, '.');
	if (ext) {
		++ext;
		if (*ext != '\0') {
			mime_type = MIME_TYPE[ext];
		}
	}
	return mime_type;
}

mime mime_instance;
} /* namespace QLINK */
