#ifndef RAD2VOLUME_H
#define RAD2VOLUME_H /*These are called an 'include guard', it's a preprocessor 
                      command which says: if there is never (ifndef) been 
                      defined a constant called RAD2VOLUME_H, then go ahead an 
                      define it. Otherwise, it will skip everything from the
                      ifndef to the endif.
                      Reason: When we compile this code, we want to make sure
                      that we don't accidently include rad2volume.h twice during
                      the same compilation to object code. Otherwise, we might
                      have 2 definition of the function prototype. And that would
                      cause a compiler error.
                      */

#define LOL 10
#define MY_PI 3.1415926
double radius2volume(double r);

#endif
