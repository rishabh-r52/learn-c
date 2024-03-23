// #include <stdio.h>
// int main()
// {
//     char name[20];
//     int age, roll_num;
//     printf("Enter name, roll no. & age respectively: ");
//     scanf("%s %d %d",name,&roll_num,&age);
//     printf("Name: %s\nRoll No.: %d\nAge: %d\n",name,roll_num,age);
//     return 0;
// }
#include <stdio.h>
struct student
{
    char name[20];
    int roll;
    int age;
};
int main()
{
    struct student s1,s2;
    printf("Student details:\n");
    printf("\nStudent1:\nName\tRoll\tAge\n");
    scanf("%s %d %d",s1.name,&s1.roll,&s1.age);
    printf("\nStudent2:\nName\tRoll\tAge\n");
    scanf("%s %d %d",s2.name,&s2.roll,&s2.age);
    printf("\nStudent details:\n");
    printf("\nRoll\tName\t\tAge\n");
    printf("%d\t%s\t\t%d",s1.roll,s1.name,s1.age);
    printf("\n%d\t%s\t\t%d",s2.roll,s2.name,s2.age);
    return 0;
}