#include <stdio.h>
#include <stdlib.h>
struct Employee
{
    char eid[10], ename[50];
    int eage;
    float esalary;
};
float highSal(struct Employee *E, int n)
{
    float max = E[0].esalary;
    for (int i = 1; i < n; i++)
    {
        if (max < E[i].esalary)
        {
            max = E[i].esalary;
        }
    }
    return max;
}
float avgSal(struct Employee *E, int n)
{
    float avg = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += E[i].esalary;
    }
    avg = sum / n;
    return avg;
}
int main()
{
    struct Employee *e;
    int n;
    printf("Enter the number of entries:\t");
    scanf("%d", &n);
    e = malloc(1000);
    for (int i = 0; i < n; i++)
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter Details of Employee %d\n", i + 1);
        printf("Enter Name:\t");
        scanf(" %[^\n]", &e[i].ename);
        printf("Enter ID:\t");
        scanf(" %[^\n]", &e[i].eid);
        printf("Enter Age:\t");
        scanf("%d", &e[i].eage);
        printf("Enter Salary:\t");
        scanf("%f", &e[i].esalary);
    }
    for (int i = 0; i < n; i++)
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Details of Employee %d\n", i + 1);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter Name:\t%s\n", e[i].ename);
        printf("Enter ID:\t%s\n", e[i].eid);
        printf("Enter Age:\t%d\n", e[i].eage);
        printf("Enter Salary:\t%.2f\n", e[i].esalary);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    float highestSal = highSal(e, n);
    printf("\nMaximum Salary is:%.2f", highestSal);
    float avgSalary = avgSal(e, n);
    printf("\nAverage Salary is:%.2f", avgSalary);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}