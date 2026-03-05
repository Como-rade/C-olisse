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
- curl_version_info_data `*`curl_version_info(CURLversion age);
- Use flag CURLVERSION_NOW to have the most recent info.

#### easy libcurl
- To start a so called handle session ** CURL \*curl = curl_easy_init(); ** [doc](https://curl.se/libcurl/c/curl_easy_init.html)
- Don't forget to close the session with curl_easy_cleanup(curl); (assuming curl is variable name here)
- To set an option use curl_easy_setopt(CURL `*`handle, CURLoption option, parameter);[doc](https://curl.se/libcurl/c/curl_easy_setopt.html)
- Generally speaking, the first setopt should be curl_easy_setopt(handle, CURLOPT_URL, "https://example.com/"); which we initialize the website we want to work on
- In my case, to create a custom header check [CURLOPT_HTTPHEADER explained](https://curl.se/libcurl/c/CURLOPT_HTTPHEADER.html)
- By default, an internal callback is set where the result will appear in stdout. To save the data elsewhere in the program, refer to [CURLOPT_WRITEFUNCTION explained](https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html) and [CURLOPT_WRITEDATA explained](https://curl.se/libcurl/c/CURLOPT_WRITEDATA.html)
- Meaning of [void`*` and how to use it](https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it#:~:text=A%20pointer%20to%20void%20is,It%20gets%20called%20like%20so:)
- Callback is defined as: a function passed as an argument into another function, designed to be executed ("called back") after the first function completes a specific task or event

**STOPPED AT success = curl_easy_perform(handle); for today**
