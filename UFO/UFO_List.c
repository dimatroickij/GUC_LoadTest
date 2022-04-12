UFO_List()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("site", 
		"URL={URL}",
		"Resource=0", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", lr_eval_string("{URL}"));

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_custom_request("siteDynamicData", 
		"URL={URL}app/scc/portal/api/v1/portal/constants/siteDynamicData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);
	
	//Открытие главной страницы "Сертификаты УФО"

	web_url("issuers", 
		"URL={URL}app/scc/portal/api/v1/portal/ufoCertificates/issuers", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", lr_eval_string("{URL}"));

	web_custom_request("list", 
		"URL={URL}app/scc/portal/api/v1/portal/ufoCertificates/list", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"page\":1,\"orderBy\":\"certInfo.subject\",\"ascending\":true,\"recordsOnPage\":10,\"searchString\":null,\"issuers\":null,\"statuses\":null}", 
		LAST);

	return 0;
}