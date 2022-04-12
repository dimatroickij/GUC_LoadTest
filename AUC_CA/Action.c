Action()
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
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/assets/settings.js", ENDITEM, 
		"Url=/styles.48577afa67120b595a09.css", ENDITEM, 
		"Url=/runtime.26209474bfa8dc87a77c.js", ENDITEM, 
		"Url=/polyfills.879f6f182ad7647d76cf.js", ENDITEM, 
		"Url=/main.9ea38d1d007b1dd54150.js", ENDITEM, 
		"Url=/assets/img/main/Executes.png", ENDITEM, 
		"Url=/assets/img/main/Accepts.png", ENDITEM, 
		"Url=/assets/img/main/Provides.png", ENDITEM, 
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
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=/assets/svg/Coat_of_Arms_of_the_Russian_Federation_background.svg", "Referer={URL}/styles.48577afa67120b595a09.css", ENDITEM, 
		"Url=/open-iconic.3cf97837524dd7445e9d.woff", "Referer={URL}/styles.48577afa67120b595a09.css", ENDITEM, 
		LAST);

	web_url("dictionaries", 
		"URL={URL}app/scc/portal/api/v1/portal/ca/dictionaries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", lr_eval_string("{URL}"));

	web_reg_save_param("listCA","LB=","RB=","Search=Body",LAST);
	
	web_custom_request("list", 
		"URL={URL}app/scc/portal/api/v1/portal/ca/list", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"page\":1,\"orderBy\":\"id\",\"ascending\":false,\"recordsOnPage\":100,\"searchString\":null,\"cities\":null,\"software\":null,\"cryptToolClasses\":null,\"statuses\":null}", 
		LAST);
	
	lr_eval_json("Buffer={listCA}",
                 "JsonObject=json_listCA", LAST);
	
	srand(time(NULL));
	indexOGRN = rand() % 100;
	
	lr_save_int(indexOGRN,"index");
	
	lr_json_get_values("JsonObject=json_listCA",
                       "ValueParam=CA",
                       "QueryString=$.data.[{index}].ОГРН",
                       LAST);
	
	web_url("getCA", 
		"URL={URL}app/scc/portal/api/v1/portal/ca/get/{CA}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param("dataCA","LB=","RB=","Search=Body",LAST);
	web_url("getCA_2",
		"URL={URL}app/scc/portal/api/v1/portal/ca/getStats/{CA}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}