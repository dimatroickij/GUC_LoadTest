UFO_Details()
{
	int indexOGRN = 0;

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
		"Snapshot=t1.inf", 
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
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);
	
	//Открытие главной страницы "Сертификаты УФО"

	web_url("issuers", 
		"URL={URL}app/scc/portal/api/v1/portal/ufoCertificates/issuers", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", lr_eval_string("{URL}"));

	web_reg_save_param("listUFO","LB=","RB=","Search=Body",LAST);
	
	web_custom_request("list", 
		"URL={URL}app/scc/portal/api/v1/portal/ufoCertificates/list", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"page\":1,\"orderBy\":\"certInfo.subject\",\"ascending\":true,\"recordsOnPage\":10,\"searchString\":null,\"issuers\":null,\"statuses\":null}", 
		LAST);
	
	// Открытие карточки сертификата УФО
	lr_eval_json("Buffer={listUFO}",
                 "JsonObject=json_listUFO", LAST);
	
	srand(time(NULL));
	indexOGRN = rand() % 100;
	
	lr_save_int(indexOGRN,"index");
	
	//lr_json_get_values("JsonObject=json_listUFO",
    //                   "ValueParam=CA",
    //                   "QueryString=$.data.[{index}].РћР“Р Рќ",
    //                   LAST);

	web_url("sert_UFO",
		"URL={URL}app/scc/portal/api/v1/portal/ca/get/1047796526546", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("sert_UFO_2", 
		"URL={URL}app/scc/portal/api/v1/portal/ca/getStats/1047796526546", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}