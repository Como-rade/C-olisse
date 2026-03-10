## Libcurl Tutorial

Will be refering to [libcurl-tutorial](https://curl.se/libcurl/c/libcurl-tutorial.html)

README will be used to take notes in this case.

#### curl-config [OPTION]
- Tool that is very helpful.
- **curl-config --libs** will display which flag is need when compiling
- **curl-config --feature** will display all the supported SSL libraries

#### Initialize
- Use **curl_global_init(long flags);** CODE IN BETWEEN **curl_global_cleanup();**
- Default flags: CURL_GLOBAL_ALL or CURL_GLOBAL_DEFAULT which are nearly the same
- CURLcode is a struct which returns a code where 0 = okay. More [info](https://github.com/curl/curl/blob/70ec11358c3aac5fbae24b02f0c1c671741838dd/include/curl/curl.h#L648)

#### Info
- curl_version_info_data \*curl_version_info(CURLversion age);
- Use flag CURLVERSION_NOW to have the most recent info.

#### easy libcurl
- To start a so called handle session **CURL\* curl = curl_easy_init();** [doc](https://curl.se/libcurl/c/curl_easy_init.html)
- Don't forget to close the session with **curl_easy_cleanup(curl);** (assuming curl is the variable name here)
- To set an option use **curl_easy_setopt(CURL\* handle, CURLoption option, parameter);** [doc](https://curl.se/libcurl/c/curl_easy_setopt.html)
- Generally speaking, the first setopt should be **curl_easy_setopt(handle, CURLOPT_URL, "https://example.com/");** which we initialize the website we want to work on
- In my case, to create a custom header check [CURLOPT_HTTPHEADER explained](https://curl.se/libcurl/c/CURLOPT_HTTPHEADER.html)
- By default, an internal callback is set where the result will appear in stdout. To save the data elsewhere in the program, refer to [CURLOPT_WRITEFUNCTION explained](https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html) and [CURLOPT_WRITEDATA explained](https://curl.se/libcurl/c/CURLOPT_WRITEDATA.html)
- Meaning of [void\* and how to use it](https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it#:~:text=A%20pointer%20to%20void%20is,It%20gets%20called%20like%20so:)
- Callback is defined as: a function passed as an argument into another function, designed to be executed ("called back") after the first function completes a specific task or event
- To connect to the site and execute any given option **CURLcode curl_easy_perform(CURL\* easy_handle);** is used. It is synchronous. [doc](https://curl.se/libcurl/c/curl_easy_perform.html)
- In CURLOPT **CURLOPT_ERRORBUFFER** can be used to have human readable errors
- **CURLOPT_HEADER** will include the header in the response. Setonff to 1
- Got a little sidetracked but here: xdg-open to open anytype of file, got firefox as well (firefox to open it)

#### Upload data to a remote site
- This one was a headache and a half
- **curl_easy_setopt(cinit, CURLOPT_POST, 1L);** by default (I think) it is set to GET, this (1L) will set it to http POST. [doc](https://curl.se/libcurl/c/CURLOPT_POST.html)
- **curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);** generally PUT is used to upload, 1L is the proper flag
- **curl_easy_setopt(cinit, CURLOPT_READFUNCTION, read_callback);** pointer to the callback function(how the data is READ before transfer) [doc](https://curl.se/libcurl/c/CURLOPT_READFUNCTION.html)
- **curl_easy_setopt(cinit, CURLOPT_READDATA, (void\* )f_ptr);** fourth argument of the CUROPT_READFUNCTION [doc](https://curl.se/libcurl/c/CURLOPT_READDATA.html)
- For good practice always set the file size to be uploaded using **curl_easy_setopt(CURL\* handle, CURLOPT_INFILESIZE_LARGE, curl_off_t filesize);** [doc](https://curl.se/libcurl/c/CURLOPT_INFILESIZE_LARGE.html) filesize has to be the EXACT file size of the file otherwise it won't work
- [10minapi](https://10minapi.com/) let's you create a temporary api endpoint to test your calls (pretty neat)
- Read through Passwords, Http authentication and part of Http posting

#### MISC
- **MIME** is an extension to the email protocols. It supports text, images, video, audio and files. Uses base64 to encode. It is used to format the emails. SMTP is a protocol that is used to send and receive emails (one of many).[Video explaning it](https://www.youtube.com/watch?v=qvFFS_OFV9g)
- Setting CURLOPT_POSTFIELDS to "" or NULL does not stop libcurl from doing a POST. It makes it POST without any data to send!  **curl_easy_setopt(handle, CURLOPT_HTTPGET, 1L);** should be called to reset to GET. Do not forget that curl_easy_perform is sticky which means it retains all options until you change it.
- **curl_easy_setopt(CURL\* handle, CURLOPT_CUSTOMREQUEST, char\* method);** can be used for any protocol to send a custom request (exemple PUT, DELETE, ect.). Better to use the built in to avoid errors 
- libcurl speaks HTTP 1.1 by default, to change it say to HTTP 1.0 use **curl_easy_setopt(handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);**


#### Showing progress
- **curl_easy_setopt(CURL/* handle, CURLOPT_NOPROGRESS, long onoff);** will show a progress bar. Is always set to, change it to 0L to show the progress bar
- **curl_easy_setopt(CURL\* handle, CURLOPT_XFERINFOFUNCTION, progress_callback);** to create your own progress bar.CURLOPT_NOPROGRESS must be set to 0 to make this function actually get called. 
- **curl_easy_setopt(CURL\* handle, CURLOPT_XFERINFODATA, void\* pointer);** to fill the struct with some info.

#### NOTE
- Although I read through the whole thing, since most of the protocols and concept are new and not sure how to test them, it would be preferable to revist them when I get a better understanding and can actually run a few test.
