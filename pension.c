// #include<stdio.h>
// int main()
// {
//     char name[30];
//     int age;
//     printf("enter your name and age\n");
//     scanf("%s %d",&name,&age);
//     if(age>60 && age<=70)
//     {
//         printf("their pension will be 10000");
//     }
//     if(age>70 && age<=80)
//     {
//         printf("their PENSION WILL BE 20000");
//     }
//     if(age>80 && age<=85)
//     {
//         printf("their pension will be 30000");
//     }
//     if(age>85)
//     {
//         printf("their pension will be 50000");
//     }
//     return 0;
// }
#include<stdio.h>
int main()
{
    char name[30];
    int age,pension;
    printf("enter your name and age\n");
    scanf("%s %d",&name,&age);
    if(age>60 && age<=70)
    {
        pension=10000;
    }
    else if(age>70 && age<=80)
    {
        pension=20000;
    }
    else if(age>80 && age<=85)
    {
        pension=30000;
    }
    else if (age>85)
    {
        pension=50000;
    }
    else 
    {
        pension=0;
    }
    printf("Mr/Mrs %s, your pension is Rs.%d\n",name,pension);
    return 0;
}