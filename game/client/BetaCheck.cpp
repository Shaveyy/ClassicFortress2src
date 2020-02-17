#include "typeinfo"
#include "cbase.h"
#include "dbg.h"
#include "BetaCheck.h"
#include "curl/curl.h"

// Called when curl receives data from the server
static size_t rcvData(void* ptr, size_t size, size_t nmemb, void* userdata)
{
	Msg((char*)ptr); // up to 989 characters each time
	return size * nmemb;
}

void PrintPage()
{
	CURL* curl;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "developer.valvesoftware.com");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, rcvData);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

ConCommand print_page("print_page", PrintPage);