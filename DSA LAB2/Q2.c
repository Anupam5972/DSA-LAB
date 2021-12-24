#include <stdio.h>

struct Distance
{
    int Km;
    float m;
} d1, d2, result;

int main()
{
    // take first distance input
    printf("Enter 1st distance\n");
    printf("Enter Km: ");
    scanf("%d", &d1.Km);
    printf("Enter m: ");
    scanf("%f", &d1.m);

    // take second distance input
    printf("\nEnter 2nd distance\n");
    printf("Enter Km: ");
    scanf("%d", &d2.Km);
    printf("Enter m: ");
    scanf("%f", &d2.m);

    // adding distances
    result.Km = d1.Km + d2.Km;
    result.m = d1.m + d2.m;

    // convert mes to Km if greater than 1000
    while (result.m >= 1000.0)
    {
        result.m = result.m - 1000.0;
        ++result.Km;
    }
    printf("\nSum of distances = %d Km - %.1f m", result.Km, result.m);
    return 0;
}