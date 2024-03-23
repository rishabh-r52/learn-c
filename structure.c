#include <stdio.h>
struct student
{
    char name[20];
    int rollno;
    int marks;
};
void main()
{
struct student s[20];
int n,i;
float total=0,avg_marks;
printf("Enter the number of students\n");
scanf("%d",&n);
printf("Enter the following details of students in the same column\n");
printf("Roll No \t Name \t Marks\n");
for(i=0;i<n;i++)
{
    scanf("%d %s %d",&s[i].rollno, s[i].name, &s[i].marks);
}
printf("\nStudent Details:\n");
printf("Roll No.\t Name\t\t Marks\n");
for(i=0;i<n;i++)
{
    printf("%d\t %s \t%d\n",s[i].rollno,s[i].name,s[i].marks);
}
for(i=0;i<n;i++)
{
    total=total+s[i].marks;
    avg_marks=total/n;
}
printf("The average marks:%f\n",avg_marks);
printf("The students Scored above the average marks\n");
printf("Name\t\t Marks \n");
for(i=0;i<n;i++)
{
    if(s[i].marks>avg_marks)
    printf("%s \t %d\n",s[i].name,s[i].marks);
}
printf("The students scored below the average marks\n");
printf("Name\t Marks\n");
for(i=0;i<n;i++)
{
    if(s[i].marks<avg_marks)
    printf("%s \t %d\n",s[i].name,s[i].marks);
}
}