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

**STOPPED AT Handle the easy libcurl for today**
