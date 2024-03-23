#include <stdio.h>

        // "Pure" C code using Reference Parameter! (aka pointers) 
        void 
        doit( int * x ) 
        { 
            *x = 5; 
        } 
        // 
        // Test code for passing by a variable by reference 
        // Note the use of the & (ampersand) in the function call. 
        // 
        int 
        main() 
        { 
          int z = 27; 
          doit( & z ); 
          printf("z is now %d\n", z); 
 
          return 0; 
        } 