Action()
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
		"Snapshot=t14.inf", 
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
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);
	
	lr_think_time(4);
	
	lr_start_transaction("loadAUCList");

	web_url("dictionaries", 
		"URL={URL}app/scc/portal/api/v1/portal/ca/dictionaries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={URL}", 
		"Snapshot=t16.inf", 
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
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"page\":1,\"orderBy\":\"availabilityRank\",\"ascending\":false,\"recordsOnPage\":10,\"searchString\":null,\"cities\":null,\"software\":null,\"cryptToolClasses\":null,\"statuses\":null}", 
		LAST);
	
	lr_end_transaction("loadAUCList", LR_AUTO);
	
	return 0;
}