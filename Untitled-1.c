// program1.l

%{
#include<stdio.h>
int id=0,op=0,v=0,flag=0;
%}

Regex:

[...] -> search string for given pattern
[a-z] -> rICHU
A-Z
0-9

a* -> { ; , a, aa, aaa, aaaa..} - zero or more
a+ -> { a, aa, aaa, aaaa} - one or more

[a-z]* -> RICHU -> match found

[a-zA-Z]+

5+3
5+3*
5-

5+3 -> id = 2, op = 1
7+2+5*9 -> id = 4, op = 3
11/2+3*2-5 -> id = 5, op = 4

valid expr -> id = op + 1

Xmax1 + Xmin2
a

+, *, -, = -> special characters
[a-z]*

\ -> delimiter

(5+2) - (3)
v = 0;

( -> v++;
) -> v--;

valid expr -> ( == ) -> v=0

a = 5 + 3 

.|\n {return 0;}

. -> any character except newline
newline -> \n, ENTER
\n -> newline character

| -> pipe -> connects two character / rules

.|\n -> a + b - c * d / e = 3


%%
[a-zA-Z]+[0-9A-Za-z]* {id++;}
[0-9]+ {id++;}
[\+\-\*/\=] {op++;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {return 0;}
%%

int main()
{
printf("Enter the expression\n");
yylex();
if((op+1)==id &&v==0 && flag==0)
{
printf("The expression is valid\n");
printf("The number of identifiers=%d\n",id);
printf("The number of operators=%d\n",op);
}
else
{
printf("The expression is invalid\n");
}
return 0;
}


-----------------------------------------------------------------------
// p1b.l


5
5

string input = "5+2";
"5" -> 5 integer
parseDouble()

char* input = "5+2";
			      |
+ -> character
; -> empty action / skip / epsilon

65 + 4 valid 

65 + 4 + 2 - 8 $ \n

. -> any character except new line


5+3+5+1+65+544+8+6545
// used to denote whether input is exhausted / copmleted / ENTER CLICKED
1 - > exhausted
0 - > not exhausted
-> < > -> predefined
-> " " -> user defined

%{
#include "y.tab.h"
#include<stdlib.h> 
void yyerror(char *);
%}

%%
[0-9]+ { yylval=atoi(yytext); return INTEGER;}
[\+ \- \* \/ \n] return *yytext;
[\t] ;
. yyerror("Invalid");
%%

int yywrap(void) 
{
return 1;
}

//prog1b.y
%{
#include<stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INTEGER

%%
program: program expr '\n' { printf("%d\n", $2);}
|
;
expr:
INTEGER {$$=$1;}
| expr '+' expr {$$=$1+$3;}
| expr '-' expr {$$=$1-$3;}
| expr '*' expr {$$=$1*$3;}
| expr '/' expr {$$=$1/$3;}
;
%%

void yyerror(char *s)
{
fprintf(stderr, "%s\n",s);
}
int main(void)
{
printf("Enter the expression\n");
yyparse();
return 0;
}

a*b

//prog2a.l
%{
#include "y.tab.h"
#include<stdlib.h>
void yyerror(char *);
%}

%%
a {return A;}
b {return B;}
[\n] return '\n';
%%

int yywrap(void)
{
return 1;
}



//prog2a.y
%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *);
%}

%token A B

%%
program: expr '\n' { printf("Success\n"); exit(0);}
expr: A s1 B | B
s1: ;|A s1
%%

n a's end with b

ab -> AcB, c-> epsilon/empty -> AB
aaa...b -> AcB, c->Ac -> AAcB

S -> A c B / B

aab

AcB -> AAcB -> AAB -> AAAcB
B

c -> epsilon / A c

str = "vivek"

*str ->v
str++
*str-> i

void yyerror(char *s)
{
fprintf(stderr, "%s\n",s);
}
int main(void)
{
printf("Enter the expression\n");
yyparse();
//return 0;
}


//sr.c
#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],sk[15],act[10];
void check();

void main()
{
	puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
	puts("enter input string ");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT->");
	puts("stack \t input \t action");
	for(k=0,i=0; j<c; k++,i++,j++)
	{
		

				a = "     " j=8
		a[j] = i -> ' '
		a[j+1] = d -> ' '

		s[0] = i -> E 				-> E
		s[1] = d -> \0 -> + 		-> \0 -> 
		s[2] = \0 -> \0 -> i -> E 	-> \0 -> 
		s[3] = d -> \0 -> 
		s[4] = \0

		j = 3, i = 0

		if(a[j]=='i' && a[j+1]=='d')
		{
			sk[i]=a[j];
			sk[i+1]=a[j+1];
			sk[i+2]='\0';
			a[j]=' ';
			a[j+1]=' ';
			printf("\n$%s\t%s$\t%sid",sk,a,act);
			check();
		}
		else
		{
			sk[i]=a[j];
			sk[i+1]='\0';
			a[j]=' ';
			printf("\n$%s\t%s$\t%ssymbols",sk,a,act);
			check();
		}
	}
}
void check()
{
	
	strcpy(ac,"REDUCE TO E");
	for(z=0; z<c; z++)
		if(sk[z]=='i' && sk[z+1]=='d')
		{
			sk[z]='E';
			sk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",sk,a,ac);
			j++;
		}


	for(z=0; z<c; z++)
		if(sk[z]=='E' && sk[z+1]=='+' && sk[z+2]=='E')
		{
			sk[z]='E';
			sk[z+1]='\0';
			sk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",sk,a,ac);
			i=i-2;
		}
	for(z=0; z<c; z++)
		if(sk[z]=='E' && sk[z+1]=='*' && sk[z+2]=='E')
		{
			sk[z]='E';
			sk[z+1]='\0';
			sk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",sk,a,ac);
			i=i-2;
		}
	for(z=0; z<c; z++)
		if(sk[z]=='(' && sk[z+1]=='E' && sk[z+2]==')')
		{
			sk[z]='E';
			sk[z+1]='\0';
			sk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",sk,a,ac);
			i=i-2;
		}
}


 read write execute
rwx---rr--w
!feof(fp1)
feof -> file end of

//prog5.c
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void main()
{
	char arg1[5], arg2[5], op[2], result[5];
	FILE *fp1,*fp2;
	fp1=fopen("infile.txt","r");
	fp2=fopen("outfile.txt","w");
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s", result, arg1,op,arg2);
		if(strcmp(op,"+")==0)
		{
			fprintf(fp2,"\n mov R0,%s",arg1);
			fprintf(fp2,"\n add R0,%s",arg2);
			fprintf(fp2,"\n mov %s,R0",result);
		}
		if(strcmp(op,"-")==0)
		{
			fprintf(fp2,"\n mov R0,%s",arg1);
			fprintf(fp2,"\n sub R0,%s",arg2);
			fprintf(fp2,"\n mov %s,R0",result);
		}
		if(strcmp(op,"*")==0)
		{
			fprintf(fp2,"\n mov R0,%s",arg1);
			fprintf(fp2,"\n mul R0,%s",arg2);
			fprintf(fp2,"\n mov %s,R0",result);
		}
		if(strcmp(op,"/")==0)
		{
			fprintf(fp2,"\n mov R0,%s",arg1);
			fprintf(fp2,"\n div R0,%s",arg2);
			fprintf(fp2,"\n mov %s,R0",result);
		}
		if(strcmp(op,"=")==0)
		{
			fprintf(fp2,"\n mov R0,%s",arg1);
			fprintf(fp2,"\n mov %s,R0",result);
		}
	}
}
















#include <GL/glut.h>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#define gameName "Fighting Game Mini Project"

#define font_bitmap_small GLUT_BITMAP_8_BY_13
#define font_bitmap_large GLUT_BITMAP_9_BY_15

#define font_small GLUT_BITMAP_HELVETICA_12
#define font_large GLUT_BITMAP_HELVETICA_18

#define font_huge GLUT_BITMAP_TIMES_ROMAN_24
    
int menuWindowID;
int gameWindowID;

int windowHeight;
int windowWidth;

bool isInGame = false;
bool mainMenuActive = false; // Flag to control the display of "Hello World"

// Function to display the game
void displayGame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw game scene and other game-specific code here

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display instructions page
void instructions() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Draw the first set of big texts
    const char* line1 = "SPACEBAR - To make the player JUMP";
    int line1Length = strlen(line1);

    const char* line2 = "LEFT ARROW KEY - To make the player go left";
    int line2Length = strlen(line2);

    const char* line3 = "RIGHT ARROW KEY - To make the player go right";
    int line3Length = strlen(line3);

    // Calculate horizontal positions for the first set of texts
    int line1X = (windowWidth - line1Length * 8) / 2;
    int line2X = (windowWidth - line2Length * 8) / 2;
    int line3X = (windowWidth - line3Length * 8) / 2;

    // Calculate vertical positions for the first set of texts
    int line1Y = windowHeight / 2 + 120;
    int line2Y = windowHeight / 2 + 70;
    int line3Y = windowHeight / 2 + 20;

    // Draw the first set of texts
    glRasterPos2f(line1X, line1Y);
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line1[i]);
    }

    glRasterPos2f(line2X, line2Y);
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line2[i]);
    }

    glRasterPos2f(line3X, line3Y);
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line3[i]);
    }

    // Draw the second set of smaller texts
    const char* line4 = "Player has a total of 100 health points (100HP)";
    int line4Length = strlen(line4);

    const char* line5 = "If you get hit by the enemy, you lose 10HP";
    int line5Length = strlen(line5);

    const char* line6 = "If you hit the enemy, it loses 50HP";
    int line6Length = strlen(line6);

    const char* line7 = "The enemy has 1000HP";
    int line7Length = strlen(line7);

    const char* line8 = "Press ENTER key to go back to the main menu";
    int line8Length = strlen(line8);

    // Calculate horizontal positions for the second set of texts
    int line4X = (windowWidth - line4Length * 6) / 2;
    int line5X = (windowWidth - line5Length * 6) / 2;
    int line6X = (windowWidth - line6Length * 6) / 2;
    int line7X = (windowWidth - line7Length * 6) / 2;
    int line8X = (windowWidth - line8Length * 6) / 2;

    // Calculate vertical positions for the second set of texts
    int line4Y = windowHeight / 2 - 20;
    int line5Y = windowHeight / 2 - 70;
    int line6Y = windowHeight / 2 - 120;
    int line7Y = windowHeight / 2 - 170;
    int line8Y = windowHeight / 2 - 250;

    // Draw the second set of texts
    glRasterPos2f(line4X, line4Y);
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line4[i]);
    }

    glRasterPos2f(line5X, line5Y);
    for (int i = 0; i < line5Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line5[i]);
    }

    glRasterPos2f(line6X, line6Y);
    for (int i = 0; i < line6Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line6[i]);
    }

    glRasterPos2f(line7X, line7Y);
    for (int i = 0; i < line7Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line7[i]);
    }

    glRasterPos2f(line8X, line8Y);
    for (int i = 0; i < line8Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line8[i]);
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display main menu
void mainMenu() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    const char* line1 = "START GAME";
    int line1Length = strlen(line1);
    int line1Width = glutBitmapLength(font_huge, (const unsigned char*)line1);

    const char* line2 = "INSTRUCTIONS";
    int line2Length = strlen(line2);
    int line2Width = glutBitmapLength(font_huge, (const unsigned char*)line2);

    const char* line3 = "CREDITS";
    int line3Length = strlen(line3);
    int line3Width = glutBitmapLength(font_huge, (const unsigned char*)line3);

    const char* line4 = "EXIT";
    int line4Length = strlen(line4);
    int line4Width = glutBitmapLength(font_huge, (const unsigned char*)line4);

    // Calculate vertical positions
    int line1Y = windowHeight / 2 + 100;
    int line2Y = windowHeight / 2 + 50;
    int line3Y = windowHeight / 2;
    int line4Y = windowHeight / 2 - 50;

    // Calculate horizontal positions
    int line1X = (windowWidth - line1Width) / 2;
    int line2X = (windowWidth - line2Width) / 2;
    int line3X = (windowWidth - line3Width) / 2;
    int line4X = (windowWidth - line4Width) / 2;

    // Draw the text lines
    glRasterPos2f(line1X, line1Y);
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line1[i]);
    }

    glRasterPos2f(line2X, line2Y);
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line2[i]);
    }

    glRasterPos2f(line3X, line3Y);
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line3[i]);
    }

    glRasterPos2f(line4X, line4Y);
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line4[i]);
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display project info
void mainInfo() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    const char* line1 = "VIVEKANANDA INSTITUTE OF TECHNOLOGY";
    int line1Length = strlen(line1);
    int line1Width = glutBitmapLength(font_large, (const unsigned char*)line1);

    const char* line2 = "DEPARTMENT OF COMPUTER SCIENCE";
    int line2Length = strlen(line2);
    int line2Width = glutBitmapLength(font_small, (const unsigned char*)line2);

    const char* line3 = "A MINI PROJECT ON";
    int line3Length = strlen(line3);
    int line3Width = glutBitmapLength(font_small, (const unsigned char*)line3);

    const char* line4 = "FIGHTING GAME";
    int line4Length = strlen(line4);
    int line4Width = glutBitmapLength(font_large, (const unsigned char*)line4);

    const char* line5 = "Created by";
    int line5Length = strlen(line5);
    int line5Width = glutBitmapLength(font_small, (const unsigned char*)line5);

    const char* line6 = "STUDENT NAMES";
    int line6Length = strlen(line6);
    int line6Width = glutBitmapLength(font_small, (const unsigned char*)line6);

    const char* line7 = "ADIB UL HUQ KHAN (1VK20CS005)";
    int line7Length = strlen(line7);
    int line7Width = glutBitmapLength(font_small, (const unsigned char*)line7);

    const char* line8 = "RISHABH RANJAN (1VK20CS067)";
    int line8Length = strlen(line8);
    int line8Width = glutBitmapLength(font_small, (const unsigned char*)line8);

    const char* line9 = "Under the Guidance of";
    int line9Length = strlen(line9);
    int line9Width = glutBitmapLength(font_small, (const unsigned char*)line9);

    const char* line10 = "Dr. Dinesh S";
    int line10Length = strlen(line10);
    int line10Width = glutBitmapLength(font_small, (const unsigned char*)line10);

    const char* line11 = "ACADEMIC YEAR 2022-23";
    int line11Length = strlen(line11);
    int line11Width = glutBitmapLength(font_small, (const unsigned char*)line11);

    const char* line12 = "Press ENTER to go to the Main Menu";
    int line12Length = strlen(line12);
    int line12Width = glutBitmapLength(font_small, (const unsigned char*)line12);

    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    // Calculate vertical and horizontal offsets for centering
    int line1X = (windowWidth - line1Width) / 2;
    int line1Y = windowHeight - 100;

    int line2X = (windowWidth - line2Width) / 2;
    int line2Y = line1Y - 50;

    int line3X = (windowWidth - line3Width) / 2;
    int line3Y = line2Y - 50;

    int line4X = (windowWidth - line4Width) / 2;
    int line4Y = line3Y - 50;

    int line5X = (windowWidth - line5Width) / 2;
    int line5Y = line4Y - 50;

    int line6X = 100;
    int line6Y = line5Y - 100;

    int line7X = line6X;
    int line7Y = line6Y - 50;

    int line8X = line6X;
    int line8Y = line7Y - 50;

    int line9X = windowWidth - line9Width - 100;
    int line9Y = line5Y - 100;

    int line10X = line9X;
    int line10Y = line9Y - 50;

    int line11X = (windowWidth - line9Width) / 2;
    int line11Y = line10Y - 50;

    int line12X = ((windowWidth - line10Width) / 2 ) - 50;
    int line12Y = line11Y - 50;

    glRasterPos2f(line1X, line1Y); // Set the position for the first line
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(font_large, line1[i]);
    }

    glRasterPos2f(line2X, line2Y); // Set the position for the second line
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(font_small, line2[i]);
    }

    glRasterPos2f(line3X, line3Y); // Set the position for the third line
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(font_small, line3[i]);
    }

    glRasterPos2f(line4X, line4Y); // Set the position for the fourth line
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(font_large, line4[i]);
    }

    glRasterPos2f(line5X, line5Y); // Set the position for the fifth line
    for (int i = 0; i < line5Length; i++) {
        glutBitmapCharacter(font_small, line5[i]);
    }

    glRasterPos2f(line6X, line6Y); // Set the position for the sixth line
    for (int i = 0; i < line6Length; i++) {
        glutBitmapCharacter(font_small, line6[i]);
    }

    glRasterPos2f(line7X, line7Y); // Set the position for the seventh line
    for (int i = 0; i < line7Length; i++) {
        glutBitmapCharacter(font_small, line7[i]);
    }

    glRasterPos2f(line8X, line8Y); // Set the position for the eighth line
    for (int i = 0; i < line8Length; i++) {
        glutBitmapCharacter(font_small, line8[i]);
    }

    glRasterPos2f(line9X, line9Y); // Set the position for the ninth line
    for (int i = 0; i < line9Length; i++) {
        glutBitmapCharacter(font_small, line9[i]);
    }

    glRasterPos2f(line10X, line10Y); // Set the position for the tenth line
    for (int i = 0; i < line10Length; i++) {
        glutBitmapCharacter(font_small, line10[i]);
    }

    glRasterPos2f(line11X, line11Y); // Set the position for the ninth line
    for (int i = 0; i < line11Length; i++) {
        glutBitmapCharacter(font_small, line11[i]);
    }

    glRasterPos2f(line12X, line12Y); // Set the position for the tenth line
    for (int i = 0; i < line12Length; i++) {
        glutBitmapCharacter(font_small, line12[i]);
    }

    if (mainMenuActive) {
        mainMenu();
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to handle the display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // Draw your OpenGL scene here
    mainInfo();

    glFlush();  // Ensure all drawing commands are executed
}

// Function to handle the window reshape callback
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // Set the viewport

    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
}

// Function to handle keyboard callback
void keyboard(unsigned char key, int x, int y) {
    if (key == 13) { // Check for Enter key press
        printf("ENTER clicked\n");
        mainMenuActive = true; // Set the flag to display "Hello World"
        glutPostRedisplay(); // Trigger a redisplay to show the updated screen
    }
    else if (key == 27) {
        if (isInGame) {
            isInGame = false;
            glutDestroyWindow(gameWindowID);
            glutSetWindow(menuWindowID);
            glutPostRedisplay();
        }
    }
}

// Function to handle mouse callback
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to OpenGL coordinates
        int oglX = x;
        int oglY = windowHeight - y;

        // Check if the mouse click is within the bounds of a button
        if (oglX >= (windowWidth - 200) / 2 && oglX <= (windowWidth + 200) / 2) {
            if (oglY >= windowHeight / 2 + 100 && oglY <= windowHeight / 2 + 120) {
                // START GAME button clicked
                // Perform action here
                printf("START GAME clicked\n");
                if (!isInGame) {
                    isInGame = true;
                    gameWindowID = glutCreateWindow(gameName);
                    glutDisplayFunc(displayGame);
                    glutReshapeFunc(reshape);
                    glutKeyboardFunc(keyboard);
                }
            }
            else if (oglY >= windowHeight / 2 + 50 && oglY <= windowHeight / 2 + 70) {
                // INSTRUCTIONS button clicked
                // Perform action here
                printf("INSTRUCTIONS clicked\n");
                instructions();
            }
            else if (oglY >= windowHeight / 2 && oglY <= windowHeight / 2 + 20) {
                // CREDITS button clicked
                // Perform action here
                printf("CREDITS clicked\n");
                mainMenuActive = false;
                mainInfo();
            }
            else if (oglY >= windowHeight / 2 - 50 && oglY <= windowHeight / 2 - 30) {
                // EXIT button clicked
                // Perform action here
                printf("EXIT clicked\n");
                exit(0); // Close the program
            }
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode

    glutInitWindowSize(1280, 720);  // Set window size
    menuWindowID = glutCreateWindow(gameName);  // Create a window

    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    glutDisplayFunc(display);  // Register display callback
    glutReshapeFunc(reshape);  // Register reshape callback
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutMouseFunc(mouse); // Register mouse callback

    glutMainLoop();  // Enter the main loop

    return 0;
}



int squareX = 0;
int squareY = 0;
int squareSize = 100;
int jumpHeight = 100;
bool isJumping = false;
bool isFalling = false;
int jumpDuration = 500; // Jump duration in milliseconds
int jumpStartTime = 0;
bool isMovingLeft = false;
bool isMovingRight = false;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, windowWidth, 0, windowHeight, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange

    glTranslatef(squareX, squareY, 0); // Translate square based on squareX and squareY positions

    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(squareSize, 0);
    glVertex2f(squareSize, squareSize);
    glVertex2f(0, squareSize);
    glEnd();

    glFlush(); // Ensure all drawing commands are executed
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, windowWidth, windowHeight);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // ESC key
        exit(0);
        break;
    case 32: // Spacebar
        if (!isJumping && !isFalling) {
            isJumping = true;
            jumpStartTime = glutGet(GLUT_ELAPSED_TIME);
        }
        break;
    }
}

void specialKeyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        if (squareX > 0) {
            isMovingLeft = true;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (squareX < windowWidth - squareSize) {
            isMovingRight = true;
        }
        break;
    }
}

void specialKeyboardUp(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isMovingLeft = false;
        break;
    case GLUT_KEY_RIGHT:
        isMovingRight = false;
        break;
    }
}

void update(int value) {
    if (isJumping) {
        int elapsed = glutGet(GLUT_ELAPSED_TIME) - jumpStartTime;
        if (elapsed >= jumpDuration) {
            isJumping = false;
            isFalling = true;
        }
        else {
            // Calculate the vertical position during the jump
            float t = (float)elapsed / jumpDuration;
            squareY = jumpHeight * (1 - (t - 0.5) * (t - 0.5));
        }
    }
    else if (isFalling) {
        int elapsed = glutGet(GLUT_ELAPSED_TIME) - jumpStartTime;
        if (elapsed >= jumpDuration) {
            isFalling = false;
            squareY = 0; // Reset squareY to the ground level
        }
        else {
            // Calculate the vertical position during the fall
            float t = (float)elapsed / jumpDuration;
            squareY = jumpHeight * (t - 0.5) * (t - 0.5);
        }
    }

    if (isMovingLeft) {
        if (squareX > 0) {
            squareX -= 5; // Move the square left by 5 units
        }
    }
    if (isMovingRight) {
        if (squareX < windowWidth - squareSize) {
            squareX += 5; // Move the square right by 5 units
        }
    }

    glutTimerFunc(16, update, 0); // Update at approximately 60 frames per second
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(windowWidth, windowHeight); // Set window size
    glutCreateWindow("Move Square Example"); // Create a window

    glutDisplayFunc(display); // Register display callback
    glutReshapeFunc(reshape); // Register reshape callback
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutSpecialFunc(specialKeyboard); // Register special keyboard callback
    glutSpecialUpFunc(specialKeyboardUp); // Register special keyboard release callback

    glutTimerFunc(0, update, 0); // Start the update timer

    glutMainLoop(); // Enter the main loop

    return 0;
}


#include <GL/glut.h>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#define gameName "Fighting Game Mini Project"

#define font_bitmap_small GLUT_BITMAP_8_BY_13
#define font_bitmap_large GLUT_BITMAP_9_BY_15

#define font_small GLUT_BITMAP_HELVETICA_12
#define font_large GLUT_BITMAP_HELVETICA_18

#define font_huge GLUT_BITMAP_TIMES_ROMAN_24
    
int menuWindowID;
int gameWindowID;

int windowHeight;
int windowWidth;

int squareX = 0;
int squareY = 0;
int squareSize = 100;
int jumpHeight = 100;

bool isJumping = false;
bool isFalling = false;

int jumpDuration = 500; // Jump duration in milliseconds
int jumpStartTime = 0;

bool isMovingLeft = false;
bool isMovingRight = false;

bool isInGame = false;
bool mainMenuActive = false; // Flag to control the display of "Hello World"


void keyboardGame(unsigned char key, int x, int y);

void specialKeyboardGame(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        if (squareX > 0) {
            isMovingLeft = true;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (squareX < windowWidth - squareSize) {
            isMovingRight = true;
        }
        break;
    }
}

void specialKeyboardUpGame(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        isMovingLeft = false;
        break;
    case GLUT_KEY_RIGHT:
        isMovingRight = false;
        break;
    }
}

void update(int value) {
    if (isJumping) {
        int elapsed = glutGet(GLUT_ELAPSED_TIME) - jumpStartTime;
        if (elapsed >= jumpDuration) {
            isJumping = false;
            isFalling = true;
        }
        else {
            // Calculate the vertical position during the jump
            float t = (float)elapsed / jumpDuration;
            squareY = jumpHeight * (1 - (t - 0.5) * (t - 0.5));
        }
    }
    else if (isFalling) {
        int elapsed = glutGet(GLUT_ELAPSED_TIME) - jumpStartTime;
        if (elapsed >= jumpDuration) {
            isFalling = false;
            squareY = 0; // Reset squareY to the ground level
        }
        else {
            // Calculate the vertical position during the fall
            float t = (float)elapsed / jumpDuration;
            squareY = jumpHeight * (t - 0.5) * (t - 0.5);
        }
    }

    if (isMovingLeft) {
        if (squareX > 0) {
            squareX -= 5; // Move the square left by 5 units
        }
    }
    if (isMovingRight) {
        if (squareX < windowWidth - squareSize) {
            squareX += 5; // Move the square right by 5 units
        }
    }

    glutTimerFunc(16, update, 0); // Update at approximately 60 frames per second
    glutPostRedisplay();
}

// Function to display the game
void displayGame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, windowWidth, 0, windowHeight, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange

    glTranslatef(squareX, squareY, 0); // Translate square based on squareX and squareY positions

    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(squareSize, 0);
    glVertex2f(squareSize, squareSize);
    glVertex2f(0, squareSize);
    glEnd();

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display instructions page
void instructions() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    // Draw the first set of big texts
    const char* line1 = "SPACEBAR - To make the player JUMP";
    int line1Length = strlen(line1);

    const char* line2 = "LEFT ARROW KEY - To make the player go left";
    int line2Length = strlen(line2);

    const char* line3 = "RIGHT ARROW KEY - To make the player go right";
    int line3Length = strlen(line3);

    // Calculate horizontal positions for the first set of texts
    int line1X = (windowWidth - line1Length * 8) / 2;
    int line2X = (windowWidth - line2Length * 8) / 2;
    int line3X = (windowWidth - line3Length * 8) / 2;

    // Calculate vertical positions for the first set of texts
    int line1Y = windowHeight / 2 + 120;
    int line2Y = windowHeight / 2 + 70;
    int line3Y = windowHeight / 2 + 20;

    // Draw the first set of texts
    glRasterPos2f(line1X, line1Y);
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line1[i]);
    }

    glRasterPos2f(line2X, line2Y);
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line2[i]);
    }

    glRasterPos2f(line3X, line3Y);
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(font_bitmap_large, line3[i]);
    }

    // Draw the second set of smaller texts
    const char* line4 = "Player has a total of 100 health points (100HP)";
    int line4Length = strlen(line4);

    const char* line5 = "If you get hit by the enemy, you lose 10HP";
    int line5Length = strlen(line5);

    const char* line6 = "If you hit the enemy, it loses 50HP";
    int line6Length = strlen(line6);

    const char* line7 = "The enemy has 1000HP";
    int line7Length = strlen(line7);

    const char* line8 = "Press ENTER key to go back to the main menu";
    int line8Length = strlen(line8);

    // Calculate horizontal positions for the second set of texts
    int line4X = (windowWidth - line4Length * 6) / 2;
    int line5X = (windowWidth - line5Length * 6) / 2;
    int line6X = (windowWidth - line6Length * 6) / 2;
    int line7X = (windowWidth - line7Length * 6) / 2;
    int line8X = (windowWidth - line8Length * 6) / 2;

    // Calculate vertical positions for the second set of texts
    int line4Y = windowHeight / 2 - 20;
    int line5Y = windowHeight / 2 - 70;
    int line6Y = windowHeight / 2 - 120;
    int line7Y = windowHeight / 2 - 170;
    int line8Y = windowHeight / 2 - 250;

    // Draw the second set of texts
    glRasterPos2f(line4X, line4Y);
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line4[i]);
    }

    glRasterPos2f(line5X, line5Y);
    for (int i = 0; i < line5Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line5[i]);
    }

    glRasterPos2f(line6X, line6Y);
    for (int i = 0; i < line6Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line6[i]);
    }

    glRasterPos2f(line7X, line7Y);
    for (int i = 0; i < line7Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line7[i]);
    }

    glRasterPos2f(line8X, line8Y);
    for (int i = 0; i < line8Length; i++) {
        glutBitmapCharacter(font_bitmap_small, line8[i]);
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display main menu
void mainMenu() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    const char* line1 = "START GAME";
    int line1Length = strlen(line1);
    int line1Width = glutBitmapLength(font_huge, (const unsigned char*)line1);

    const char* line2 = "INSTRUCTIONS";
    int line2Length = strlen(line2);
    int line2Width = glutBitmapLength(font_huge, (const unsigned char*)line2);

    const char* line3 = "CREDITS";
    int line3Length = strlen(line3);
    int line3Width = glutBitmapLength(font_huge, (const unsigned char*)line3);

    const char* line4 = "EXIT";
    int line4Length = strlen(line4);
    int line4Width = glutBitmapLength(font_huge, (const unsigned char*)line4);

    // Calculate vertical positions
    int line1Y = windowHeight / 2 + 100;
    int line2Y = windowHeight / 2 + 50;
    int line3Y = windowHeight / 2;
    int line4Y = windowHeight / 2 - 50;

    // Calculate horizontal positions
    int line1X = (windowWidth - line1Width) / 2;
    int line2X = (windowWidth - line2Width) / 2;
    int line3X = (windowWidth - line3Width) / 2;
    int line4X = (windowWidth - line4Width) / 2;

    // Draw the text lines
    glRasterPos2f(line1X, line1Y);
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line1[i]);
    }

    glRasterPos2f(line2X, line2Y);
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line2[i]);
    }

    glRasterPos2f(line3X, line3Y);
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line3[i]);
    }

    glRasterPos2f(line4X, line4Y);
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line4[i]);
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to display project info
void mainInfo() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    const char* line1 = "VIVEKANANDA INSTITUTE OF TECHNOLOGY";
    int line1Length = strlen(line1);
    int line1Width = glutBitmapLength(font_large, (const unsigned char*)line1);

    const char* line2 = "DEPARTMENT OF COMPUTER SCIENCE";
    int line2Length = strlen(line2);
    int line2Width = glutBitmapLength(font_small, (const unsigned char*)line2);

    const char* line3 = "A MINI PROJECT ON";
    int line3Length = strlen(line3);
    int line3Width = glutBitmapLength(font_small, (const unsigned char*)line3);

    const char* line4 = "FIGHTING GAME";
    int line4Length = strlen(line4);
    int line4Width = glutBitmapLength(font_large, (const unsigned char*)line4);

    const char* line5 = "Created by";
    int line5Length = strlen(line5);
    int line5Width = glutBitmapLength(font_small, (const unsigned char*)line5);

    const char* line6 = "STUDENT NAMES";
    int line6Length = strlen(line6);
    int line6Width = glutBitmapLength(font_small, (const unsigned char*)line6);

    const char* line7 = "ADIB UL HUQ KHAN (1VK20CS005)";
    int line7Length = strlen(line7);
    int line7Width = glutBitmapLength(font_small, (const unsigned char*)line7);

    const char* line8 = "RISHABH RANJAN (1VK20CS067)";
    int line8Length = strlen(line8);
    int line8Width = glutBitmapLength(font_small, (const unsigned char*)line8);

    const char* line9 = "Under the Guidance of";
    int line9Length = strlen(line9);
    int line9Width = glutBitmapLength(font_small, (const unsigned char*)line9);

    const char* line10 = "Dr. Dinesh S";
    int line10Length = strlen(line10);
    int line10Width = glutBitmapLength(font_small, (const unsigned char*)line10);

    const char* line11 = "ACADEMIC YEAR 2022-23";
    int line11Length = strlen(line11);
    int line11Width = glutBitmapLength(font_small, (const unsigned char*)line11);

    const char* line12 = "Press ENTER to go to the Main Menu";
    int line12Length = strlen(line12);
    int line12Width = glutBitmapLength(font_small, (const unsigned char*)line12);

    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    // Calculate vertical and horizontal offsets for centering
    int line1X = (windowWidth - line1Width) / 2;
    int line1Y = windowHeight - 100;

    int line2X = (windowWidth - line2Width) / 2;
    int line2Y = line1Y - 50;

    int line3X = (windowWidth - line3Width) / 2;
    int line3Y = line2Y - 50;

    int line4X = (windowWidth - line4Width) / 2;
    int line4Y = line3Y - 50;

    int line5X = (windowWidth - line5Width) / 2;
    int line5Y = line4Y - 50;

    int line6X = 100;
    int line6Y = line5Y - 100;

    int line7X = line6X;
    int line7Y = line6Y - 50;

    int line8X = line6X;
    int line8Y = line7Y - 50;

    int line9X = windowWidth - line9Width - 100;
    int line9Y = line5Y - 100;

    int line10X = line9X;
    int line10Y = line9Y - 50;

    int line11X = (windowWidth - line9Width) / 2;
    int line11Y = line10Y - 50;

    int line12X = ((windowWidth - line10Width) / 2 ) - 50;
    int line12Y = line11Y - 50;

    glRasterPos2f(line1X, line1Y); // Set the position for the first line
    for (int i = 0; i < line1Length; i++) {
        glutBitmapCharacter(font_large, line1[i]);
    }

    glRasterPos2f(line2X, line2Y); // Set the position for the second line
    for (int i = 0; i < line2Length; i++) {
        glutBitmapCharacter(font_small, line2[i]);
    }

    glRasterPos2f(line3X, line3Y); // Set the position for the third line
    for (int i = 0; i < line3Length; i++) {
        glutBitmapCharacter(font_small, line3[i]);
    }

    glRasterPos2f(line4X, line4Y); // Set the position for the fourth line
    for (int i = 0; i < line4Length; i++) {
        glutBitmapCharacter(font_large, line4[i]);
    }

    glRasterPos2f(line5X, line5Y); // Set the position for the fifth line
    for (int i = 0; i < line5Length; i++) {
        glutBitmapCharacter(font_small, line5[i]);
    }

    glRasterPos2f(line6X, line6Y); // Set the position for the sixth line
    for (int i = 0; i < line6Length; i++) {
        glutBitmapCharacter(font_small, line6[i]);
    }

    glRasterPos2f(line7X, line7Y); // Set the position for the seventh line
    for (int i = 0; i < line7Length; i++) {
        glutBitmapCharacter(font_small, line7[i]);
    }

    glRasterPos2f(line8X, line8Y); // Set the position for the eighth line
    for (int i = 0; i < line8Length; i++) {
        glutBitmapCharacter(font_small, line8[i]);
    }

    glRasterPos2f(line9X, line9Y); // Set the position for the ninth line
    for (int i = 0; i < line9Length; i++) {
        glutBitmapCharacter(font_small, line9[i]);
    }

    glRasterPos2f(line10X, line10Y); // Set the position for the tenth line
    for (int i = 0; i < line10Length; i++) {
        glutBitmapCharacter(font_small, line10[i]);
    }

    glRasterPos2f(line11X, line11Y); // Set the position for the ninth line
    for (int i = 0; i < line11Length; i++) {
        glutBitmapCharacter(font_small, line11[i]);
    }

    glRasterPos2f(line12X, line12Y); // Set the position for the tenth line
    for (int i = 0; i < line12Length; i++) {
        glutBitmapCharacter(font_small, line12[i]);
    }

    if (mainMenuActive) {
        mainMenu();
    }

    glFlush(); // Ensure all drawing commands are executed
}

// Function to handle the display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // Draw your OpenGL scene here
    mainInfo();

    glFlush();  // Ensure all drawing commands are executed
}

// Function to handle the window reshape callback
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // Set the viewport

    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
}

// Function to handle keyboard callback
void keyboard(unsigned char key, int x, int y) {
    if (key == 13) { // Check for Enter key press
        printf("ENTER clicked\n");
        mainMenuActive = true; // Set the flag to display "Hello World"
        glutPostRedisplay(); // Trigger a redisplay to show the updated screen
    }
}

// Function to handle mouse callback
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to OpenGL coordinates
        int oglX = x;
        int oglY = windowHeight - y;

        // Check if the mouse click is within the bounds of a button
        if (oglX >= (windowWidth - 200) / 2 && oglX <= (windowWidth + 200) / 2) {
            if (oglY >= windowHeight / 2 + 100 && oglY <= windowHeight / 2 + 120) {
                // START GAME button clicked
                // Perform action here
                printf("START GAME clicked\n");
                if (!isInGame) {
                    isInGame = true;
                    gameWindowID = glutCreateWindow(gameName);
                    glutDisplayFunc(displayGame);
                    glutReshapeFunc(reshape); // Register reshape callback
                    glutKeyboardFunc(keyboardGame); // Register keyboard callback
                    glutSpecialFunc(specialKeyboardGame); // Register special keyboard callback
                    glutSpecialUpFunc(specialKeyboardUpGame); // Register special keyboard release callback

                    glutTimerFunc(0, update, 0); // Start the update timer
                }
            }
            else if (oglY >= windowHeight / 2 + 50 && oglY <= windowHeight / 2 + 70) {
                // INSTRUCTIONS button clicked
                // Perform action here
                printf("INSTRUCTIONS clicked\n");
                instructions();
            }
            else if (oglY >= windowHeight / 2 && oglY <= windowHeight / 2 + 20) {
                // CREDITS button clicked
                // Perform action here
                printf("CREDITS clicked\n");
                mainMenuActive = false;
                mainInfo();
            }
            else if (oglY >= windowHeight / 2 - 50 && oglY <= windowHeight / 2 - 30) {
                // EXIT button clicked
                // Perform action here
                printf("EXIT clicked\n");
                exit(0); // Close the program
            }
        }
    }
}

void keyboardGame(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // ESC key
        if (isInGame) {
            isInGame = false;
            isFalling = false;
            isJumping = false;
            isMovingLeft = false;
            isMovingRight = false;
            mainMenuActive = true;
            glutDestroyWindow(gameWindowID);
            glutSetWindow(menuWindowID);
            glutDisplayFunc(display);  // Register display callback
            glutReshapeFunc(reshape);  // Register reshape callback
            glutKeyboardFunc(keyboard); // Register keyboard callback
            glutSpecialFunc(NULL); // Register special keyboard callback
            glutSpecialUpFunc(NULL); // Register special keyboard release callback
            glutMouseFunc(mouse); // Register mouse callback
            glutPostRedisplay();
            glutTimerFunc(20, NULL, 0);
        }
        break;
    case 32: // Spacebar
        if (!isJumping && !isFalling) {
            isJumping = true;
            jumpStartTime = glutGet(GLUT_ELAPSED_TIME);
        }
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode

    glutInitWindowSize(1280, 720);  // Set window size
    menuWindowID = glutCreateWindow(gameName);  // Create a window

    windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    windowWidth = glutGet(GLUT_WINDOW_WIDTH);

    glutDisplayFunc(display);  // Register display callback
    glutReshapeFunc(reshape);  // Register reshape callback
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutMouseFunc(mouse); // Register mouse callback

    glutMainLoop();  // Enter the main loop

    return 0;
}

A -> aBa
B -> bB | epsilon

abba

bb -> bB -> bbB -> bb

A -> aBa -> abBa -> abbBa -> abba

#include<stdio.h>
#include<string.h>
                         0 1 2 3 4 5    0 1 2 3 4 5
char production[3][10]={"A - > a B a", "B - > b B", "B->@"};
char stack[20], input[10];
int top=-1;
int k=0,i,l=0;
void push(int item)
{
    stack[++top]=item;
}
void pop()
{
    top=top-1;
}
void display()
{
    for(l=top;l>=0;l--)
        printf("%c",stack[l]);
    printf("\n");
}
void stackop(char val)
{
    if(val=='A')
    {
        pop();
        for(k=strlen(production[0])-1; k>=3;k--)
            push(production[0][k]);
    }
    if(val=='B')
    {
        pop();
        for(k=strlen(production[1])-1; k>=3;k--)
            push(production[1][k]);
    }
}
void main()
{
    int p=0,q=0;
    printf("Enter the input\n");
    scanf("%s",input);
    printf("The parse table\n");
    push('$');
    push('A');
    i=0;

    while(stack[top]!='$' && i!=strlen(input))
    {
        display();
        for(q=i;q<strlen(input);q++)
            printf("\t\t %c\t",input[q]);
        printf("\n");
        if(stack[top]=='A')
        {
            stackop('A');
        }
        else if(stack[top]=='B')
        {
            if(input[i]!='b')
            {
                pop();
            }
            else
            {
                stackop('B');
            }
        }
        else
        {
            if(stack[top]==input[i])
            {
                printf("match:%c",input[i]);
                pop();
                i++;
            }
            else
                break;
        }
    }

    if(stack[top]=='$' && input[i]=='$')
    {
        printf("The string is valid\n");
    }
    else
    {
        printf("The string is not valid\n");
    }
}




#include <GL/glut.h>

// Window size
const int WIDTH = 800;
const int HEIGHT = 600;

// Line position
float lineY = HEIGHT;

// OpenGL display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color to white
    glColor3f(1.0, 1.0, 1.0);

    // Draw the line
    glBegin(GL_LINES);
    glVertex2f(0, lineY);
    glVertex2f(WIDTH/2, lineY);
    glEnd();

    // Swap buffers to display the drawn frame
    glutSwapBuffers();
}

// OpenGL idle function
void idle()
{
    // Move the line upwards
    lineY -= 1.0;

    // Reset the line position if it goes  off the screen
    if (lineY < 0) {
        lineY = HEIGHT;
    }

    // Redraw the scene
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // Initialize OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Falling Line");

    // Set the display and idle functions
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    // Set the clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    // Start the main loop
    glutMainLoop();

    return 0;
}



