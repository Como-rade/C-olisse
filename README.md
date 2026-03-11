# C-olisse pt. 1

This tutorial will follow the following 
[tutorial from Bro Code](https://www.youtube.com/watch?v=xND0t1pr3KY)

#### tutorial/day-one timestamp -> 0:00 to 35:05

#### tutorial/day-two timestamp -> 35:05 to 1:06:53
##### IMPORTANT: 
User inputs has a lot of interations with the buffers.
Check [the following link](https://security.stackexchange.com/questions/95245/security-implications-of-neglecting-the-extra-byte-for-null-termination-in-c-c) for: null terminator, strlen & sizeof.

#### tutorial/day-three timestamp -> 1:06:53 to 1:25:25

#### tutorial/day-four timestamp -> 1:25:25 to 1:36:43

#### tutorial/day-five timestamp -> 1:36:43 to 2:10:27
##### IMPORTANT:
- Explains [getchar()](https://www.reddit.com/r/C_Programming/comments/18rygdt/cant_get_my_head_around_with_getchar_function/#:~:text=In%20second%20case%2C%20you%20do,%2C%20l%2C%20l%2C%20o.&text=ohkk%20got%20it%20getchar(),is%20happening%20behind%20the%20scene?)
- Explains [sleep in a loop](https://stackoverflow.com/questions/25627535/printf-and-sleep-inside-for-loop)
- Explains [the use of fflush(stdin)](https://stackoverflow.com/questions/39738163/usage-of-getchar-and-fflushstdin) and [also](https://stackoverflow.com/questions/4023643/second-scanf-is-not-working)
- FIND SOMETHING ABOUT THE BUFFERS CUZ SHIT IS CRAZY

#### tutorial/day-six timestamp -> 2:10:27 to 3:00:04
- Explains when to use [fflush, getchar and the "right alternatives"](
         https://c-faq.com/stdio/gets_flush1.html)
- Convert string into long int with [strtol](https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm)

#### tutorial/day-seven timestamp -> 3:00:04 to 5:13:50
- Check theory/ and practice/ for every subject seen
- Code to clean [buffer](https://stackoverflow.com/questions/28056284/is-this-the-best-way-to-clear-input-buff-in-c)

#### tutorial/day-eight timestamp -> 5:13:50 to END
- Check theory/ for every subject seen
- [Escape Sequences](https://en.wikipedia.org/wiki/Escape_sequences_in_C)
- [memset basics](https://stackoverflow.com/questions/1735919/whats-the-best-way-to-reset-a-char-in-c)
- [Reference for any function](cplusplus.com)_ find it little clearer than man sometimes

___

### Libcurl tutorial
- Every note will be in the tutorial/curl README
- Day One stopped at: Handle the easy libcurl
- Day Two stopped at: success = curl_easy_perform(handle);
- Day Three REREAD: Upload data to a remote site(need to implement it)
- Day Four stopped at: MIME API
- Day Five: Finished reading, check the last note in the README of tutorial/curl
___

### Header files in C
- Check README in branch tutorial/headerfiles-libraries for all the necessary information 
