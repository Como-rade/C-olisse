#include <stdio.h>
#include <curl/curl.h>

int main(void){

    CURLcode initi =  curl_global_init(CURL_GLOBAL_ALL);
    
    printf("%d\n", initi);

    curl_version_info_data *data = curl_version_info(CURLVERSION_NOW);

    printf("%s\n",data->version);

    curl_global_cleanup();

    return 0;
}
