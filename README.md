## C-olisse pt. 5
- Started statement (if and dabbled in a few others)
- NEED TO LEARN MORE ABOUT BUFFERS because of unclear behavior when using a
loop and adding in sleep with a output display.
- fflush(stdout): This is important when printing without a newline character 
(\n), as the output might be buffered and not display until the sleep finishes 
or a newline is encountered. The fflush(stdout) command ensures the output is 
printed to the console immediately.
- fflush(stdin): use after scanf so the buffer doesn't hold any unwanted char
or string(?)

