#include <stdio.h>
#include <curl/curl.h>

#define URL "http://sis.saminray.com:8020"


void http_get_request(){
  
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL,URL);

    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        printf("OK!\n ");
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    }

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }

}


void http_post_request(){
  
  CURL *curl;
  CURLcode res;

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    curl_easy_setopt(curl, CURLOPT_URL, "http://postit.example.com/moo.cgi");
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();

}


int main(void)
{
    http_get_request();
    return 0;
}
