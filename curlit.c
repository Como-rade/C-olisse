#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct memory {
  char *response;
  size_t size;
};

void get_key(char *key);
static size_t cb(char *data, size_t size, size_t nmemb, void *clientp);

int main(void){

    char key[1024] = {0};
    get_key(key);
    //printf("key is :%s\n", key);

    struct curl_slist *list = NULL;//for the header
    list = curl_slist_append(list, key);
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
                "https://api.themoviedb.org/3/search/movie?query=spaceball");
        curl_easy_setopt(cinit, CURLOPT_HTTPHEADER, list);
        curl_easy_setopt(cinit, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(cinit, CURLOPT_WRITEDATA, (void *)&chunk);
        
        result = curl_easy_perform(cinit);

        /*
        CURLOPT_HEADER 1 will include the header in the response
        curl_easy_setopt(cinit, CURLOPT_URL, 
                "https://wordcounter.net/character-count");
        curl_easy_setopt(cinit, CURLOPT_HEADER, 1);
        curl_easy_setopt(cinit, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(cinit, CURLOPT_WRITEDATA, (void *)&chunk);
        result = curl_easy_perform(cinit);
        printf("%d\n", result);
        printf("%s\n", chunk.response);*/
        
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

void get_key(char *key){
    FILE *p_file = fopen("key.txt", "r");
    char buffer[1024] = {0};

    if(p_file == NULL){
        printf("Could not open file\n");
        exit(1);
    }

    fgets(buffer ,sizeof(buffer) , p_file);
    printf("%ld\n", strlen(buffer));
    printf("%s\n", buffer);
    buffer[strlen(buffer)-1] = '\0'; /*usually, in a case where it ends with
                                       a newline is  considered
                                       a char therefore to add a null pointer
                                       length-1
                                      */
    printf("length : %ld\n"
            "KEY : %s\n", strlen(buffer), buffer);

    strncpy(key, buffer, strlen(buffer));
    fclose(p_file);
}
