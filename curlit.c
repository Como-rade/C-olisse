#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct memory {
  char *response;
  size_t size;
};

static size_t cb(char *data, size_t size, size_t nmemb, void *clientp);

int main(void){
    struct curl_slist *list = NULL;
    list = curl_slist_append(list, "Authorization: Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI2MzlmNmUzNDNkMzI5YzYyNTdkOTdkMzM1Njk4MzhiMiIsIm5iZiI6MTc3MjU3Mzk1MS4xMTgsInN1YiI6IjY5YTc1NGZmMjIxNjMzZjUwNDA5NzVjNCIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.uLtZM52bRfhhwE2Reja-dVs_rsWwKp9nFX5rSaaMZdc");

    struct memory chunk = { 0 };

    CURLcode initi =  curl_global_init(CURL_GLOBAL_ALL);
    
    printf("%d\n", initi);

    curl_version_info_data *data = curl_version_info(CURLVERSION_NOW);

    printf("%s\n",data->version);

    CURL *cinit  = curl_easy_init();

    printf("%p\n", cinit);
    
    if(cinit){
        printf("IM HERE\n");
        CURLcode result;
        curl_easy_setopt(cinit, CURLOPT_URL, 
                "https://api.themoviedb.org/3/movie/11");
        curl_easy_setopt(cinit, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(cinit, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(cinit, CURLOPT_WRITEDATA, (void *)&chunk);
        result = curl_easy_perform(cinit);
       // printf("%d\n", result);
        //printf("%s\n", chunk.response);
        free(chunk.response);
        curl_easy_cleanup(cinit);
    }

    curl_slist_free_all(list);

    curl_global_cleanup();

    return 0;
}

static size_t cb(char *data, size_t size, size_t nmemb, void *clientp)
{
  size_t realsize = nmemb;
  struct memory *mem = (struct memory *)clientp;

  char *ptr = realloc(mem->response, mem->size + realsize + 1);
  if(!ptr)
    return 0;  /* out of memory */

  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;

  FILE *p_file = fopen("output.txt", "w");
  if(p_file == NULL){ //couldnt open the file
        printf("Error opening a file\n");
        return 1; // 0 = success; 1 = failure
    }

  int written = fprintf(p_file,"%s", mem->response ); //to write in file
    if(written >= 0){
        printf("File was written successfully\n");
    }else{
        printf("Error has occured while writing in the file.\n");
    }

    fclose(p_file);

  return realsize;
}
