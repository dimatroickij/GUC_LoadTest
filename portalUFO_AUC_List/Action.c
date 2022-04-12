Action()
{
	int countListGraph = 0;
	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("guc2018.voskhod.ru", 
		"URL=https://guc2018.voskhod.ru/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/styles.48577afa67120b595a09.css", ENDITEM, 
		"Url=/runtime.26209474bfa8dc87a77c.js", ENDITEM, 
		"Url=/polyfills.879f6f182ad7647d76cf.js", ENDITEM, 
		"Url=/main.9ea38d1d007b1dd54150.js", ENDITEM, 
		"Url=/assets/img/main/Executes.png", ENDITEM, 
		"Url=/assets/img/main/Accepts.png", ENDITEM, 
		"Url=/assets/img/main/Provides.png", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Origin", 
		"https://guc2018.voskhod.ru");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_custom_request("siteDynamicData", 
		"URL=https://guc2018.voskhod.ru/app/scc/portal/api/v1/portal/constants/siteDynamicData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://guc2018.voskhod.ru/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=", 
		EXTRARES, 
		"Url=/assets/svg/Coat_of_Arms_of_the_Russian_Federation_background.svg", "Referer=https://guc2018.voskhod.ru/styles.48577afa67120b595a09.css", ENDITEM, 
		"Url=/open-iconic.3cf97837524dd7445e9d.woff", "Referer=https://guc2018.voskhod.ru/styles.48577afa67120b595a09.css", ENDITEM, 
		LAST);

	web_url("dictionaries", 
		"URL=https://guc2018.voskhod.ru/app/scc/portal/api/v1/portal/ca/dictionaries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://guc2018.voskhod.ru/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://guc2018.voskhod.ru");
	
	web_reg_save_param("listCA","LB=","RB=","Search=Body",LAST);
	
	web_custom_request("list", 
		"URL=https://guc2018.voskhod.ru/app/scc/portal/api/v1/portal/ca/list", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://guc2018.voskhod.ru/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"page\":1,\"orderBy\":\"availabilityRank\",\"ascending\":false,\"recordsOnPage\":100,\"searchString\":null,\"cities\":null,\"software\":null,\"cryptToolClasses\":null,\"statuses\":null}", 
		LAST);
	
	
	

	web_url("5167746159785", 
		"URL=https://guc2018.voskhod.ru/app/scc/portal/api/v1/portal/ca/get/5167746159785", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://guc2018.voskhod.ru/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param("listGraph","LB=","RB=","Search=Body",LAST);
	
	web_url("5167746159785_2", 
		"URL=https://guc2018.voskhod.ru/app/scc/portal/api/v1/portal/ca/getStats/5167746159785", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://guc2018.voskhod.ru/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	
	
	
	
	
	lr_eval_json("Buffer={listGraph}",
                 "JsonObject=json_listGraph", LAST);    
	
	countListGraph = lr_json_get_values("JsonObject=json_listGraph",
                       "ValueParam=title",
                     "QueryString=$.[*].date",
                       "SelectAll=Yes",
                       LAST);
	
	lr_output_message("Value is %i", countListGraph);
	
	lr_eval_json("Buffer={listCA}",
                 "JsonObject=json_listCA", LAST);  
	
	lr_json_get_values("JsonObject=json_listCA",
                       "ValueParam=CA",
                       "QueryString=$.[*]",
                       "SelectAll=Yes",
                       LAST);
	
	return 0;
}