#include <stdio.h>
    int main()
    {
    int input;

    printf( "4. Play game\n" );      //i have re-edited the question and shortened the code and included what I additionally tried as per the advice, to focus on the question more, w/o changing the main question .
    printf( "Selection: " );
    scanf( "%d", &input );
    switch ( input ) 
    {
        case 4:
            printf( "Thanks for playing! Taaaa\n" );
            break;
        default: 
            while(input!=4)          //just a sample condition, and i know that it doesnt check for letters or characters as input, but that is not the point. I just want to see if a solution on similar thought/methodology exists.
           {   
            printf( "no u have to give a correct input\n" );
            scanf("%d", &input);
            continue;                // I tried a Goto and return; in this loop as well only to realize that it will not jump me out of this loop and back into the program.
           }
    }
    return 0;
    }