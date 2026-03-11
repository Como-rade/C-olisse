# Header files & libraries

#### [Video](https://www.youtube.com/watch?v=5UMHbzZGQuE) by Kevin Lynch
- Explains the basic on .h which includes: include guards(to avoid duplication), function prototype, the related .c file and how to compile. Check for the comments in every file for more details.
##### For the next section we will be referring to the video from 4:57 to the end
- A header file can call another header file (exemple: general.h can be called in helper1.h and helper2.h)
- The way they compile is (in what we did in the repository): the rad2volume.c, since it calls rad2volume.h theyt will be both compiled into rad2volume.o, same for main.c which calls rad2volume.h, they will be both compiled into main.o
- They're then Linked to make the program. THIS IS AN OVERVIEW AND SIMPLIFICATION OF THE WHOLE PROCESS but you get the idea
- In the header files do not include: **private** function prototypes, constants, macros (as good practice). In our program, it would be the **cuber(double x)** function. We don't want it availble outside of the scope of this file.
- Avoid adding global variable in the header file. May cause problems at compilation.
- What should go in a header file: include guard, other include files, new data types, **public** function prototype, constants and macros.
- extern global variable (ex: extern int global), compared to the other one, we do not allocate space for this variable, we're declaring it but not defining it or allocating the space for it.

#### Other tips [Video](https://www.youtube.com/watch?v=8KyZedtkEhk)
- use flag -H when compiling to check if there's multiple copy of the same header
- Idempotent: Has an effect carried out once (no duplicates) That is why the macro symbols #ifndef...#endif are important
- <header.h> tells the compiler to look into *system include paths* run: `echo "" | gcc -E -Wp, -v -` will show all the paths to include
- "header.h" tells the compiler to look into our main directory
- When changing something in one file, instead of recompiling use the following method:
    - Compile to object using: gcc -Wall -Wextra(both of them will check for errors) -c(flag to make an object file) prog.c
    - This will create object file, to link them use: gcc obj1.o obj.o -o name 


#### Static vs Dynamic [Link](https://www.reddit.com/r/C_Programming/comments/19733rv/static_or_dynamic/)
- In general (english) "static" means "unchanging", and "dynamic" means "changing". Dynamic means it will/can change when the program runs, during the execution, after the compilation. Static means it won't/can't change while the program is running.
- C is statically typed, which means the type of a variable must be known when the program is being compiled, before it runs. To a certain point because there are such things as void * therefore it is weakly static
- static int some_global_variable = 10; static void some_function(void) { do_something(); } In these cases, "static" is limiting the scope of the variable "some_global_variable" and the function "some_function" to just the file that they appear in. They cannot be referenced or called directly from another compilation unit (c file, or object file). (Technically, if the code in the other file got ahold of a pointer to these static objects, they could access them, but barring that, they cannot.)
- If the static key is within a function, the value will persist at each call.


