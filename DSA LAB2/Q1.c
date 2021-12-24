#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[30];
    char gender[30];
    char designation[30];
    int salary;
    int gsalary;
} Employee;

int main()
{
    int i, n = 2, hra, da;

    Employee employees[n];

    //Taking each employee detail as input

    printf("Enter %d Employee Details \n \n", n);
    for (i = 0; i < n; i++)
    {

        printf("Employee %d:- \n", i + 1);
        //Name
        printf("Name: ");
        scanf("%s", employees[i].name);

        //Gender
        printf("Gender: ");
        scanf("%s", employees[i].gender);

        //Designation
        printf("Designation: ");
        scanf("%s", employees[i].designation);

        //Salary
        printf("Salary: ");
        scanf("%d", &employees[i].salary);

        da = 0.75 * employees[i].salary;
        hra = 0.25 * employees[i].salary;
        employees[i].gsalary = employees[i].salary + da + hra;

        printf("\n");
    }
    //Displaying Employee details

    printf("-------------- All Employees Details ---------------\n");

    for (i = 0; i < n; i++)
    {

        printf("Name \t: ");
        printf("%s \n", employees[i].name);

        printf("Gender \t: ");
        printf("%s \n", employees[i].gender);

        printf("Designation \t: ");
        printf("%s \n", employees[i].designation);

        printf("Gross Salary \t: ");
        printf("%d \n", employees[i].gsalary);

        printf("\n");
    }

    return 0;
}