#include <stdio.h>
        // C function using pass by value. (Notice no &) 
        void 
        doit( int x ) 
        { 
             x = 5; 
        }
        // Test function for passing by value (i.e., making a copy) 
        int 
        main() 
        { 
          int z = 27; 
          doit( z ); 
          printf("z is now %d\n", z); 
 
          return 0; 
        } 