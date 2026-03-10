#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

struct MyData {
  void *custom;
};

struct progress {
  char *private;
  size_t size;
};

size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata);
int progress_callback(void *clientp,
                      curl_off_t dltotal,
                      curl_off_t dlnow,
                      curl_off_t ultotal,
                      curl_off_t ulnow);


int main(void){
    curl_off_t size_of = 15;
    printf("size of%ld\n", size_of);
    struct progress data;

    CURLcode initi =  curl_global_init(CURL_GLOBAL_ALL); //initialize curl

    CURL *cinit  = curl_easy_init();
    struct MyData this;

    FILE *f_ptr = fopen("hello.txt", "rb");
    if (f_ptr == NULL) {
       perror("Error opening file");
       return 1;
   }

    if(cinit){

        CURLcode result;
        printf("here\n");
        curl_easy_setopt(cinit, CURLOPT_URL, 
                "https://10minapi.com/api/kjjikki");
        printf("there\n");
        //curl_easy_setopt(cinit, CURLOPT_POST, 1L);
        curl_easy_setopt(cinit, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(cinit, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(cinit, CURLOPT_READDATA, (void *)f_ptr);
        curl_easy_setopt(cinit, CURLOPT_INFILESIZE_LARGE, (curl_off_t)size_of);
        printf("what\n");
        curl_easy_setopt(cinit, CURLOPT_XFERINFODATA, &data);
        curl_easy_setopt(cinit, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(cinit, CURLOPT_XFERINFOFUNCTION,
                          progress_callback);
        result = curl_easy_perform(cinit);
        printf("%d\n", result);
        
    }

    //fclose(f_ptr);
    curl_global_cleanup();


    return 0;
}

size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata){
    FILE *readhere = (FILE *)userdata;
    curl_off_t nread;

  /* copy as much data as possible into the 'ptr' buffer, but no more than
     'size' * 'nmemb' bytes. */
    size_t retcode = fread(buffer, size, nitems, readhere);

    nread = (curl_off_t)retcode;

    fprintf(stderr, "*** We read %" CURL_FORMAT_CURL_OFF_T
          " bytes from file\n", nread);
    return retcode;
}

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow,
                      curl_off_t ultotal, curl_off_t ulnow){
    //printf("download now: %ld\ndownload total%ld\n", dlnow, dltotal);
    //printf("upload now: %ld\nupload total%ld\n", ulnow, ultotal);
    struct progress *dataprogress = clientp;
    printf("size: %ld\n", dataprogress->size);
    return 0;
}
