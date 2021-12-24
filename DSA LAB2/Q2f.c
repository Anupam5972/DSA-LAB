#include <stdio.h>

struct dist
{
  int km;
  int m;
};
void addition(struct dist, struct dist, struct dist *);

void main()
{
  struct dist d1, d2, d3;
  printf("Enter km and m for 1st system: ");
  scanf("%d %d", &d1.km, &d1.m);
  printf("\nEnter km and m for 2nd system: ");
  scanf("%d %d", &d2.km, &d2.m);
  addition(d1, d2, &d3);
  printf("\nAddition of two systems is %d km %d m", d3.km, d3.m);
}

void addition(struct dist d1, struct dist d2, struct dist *d3)
{
  (*d3).km = d1.km + d2.km;
  (*d3).m = d1.m + d2.m;
  if ((*d3).m >= 1000)
  {
    (*d3).km++;
    (*d3).m -= 1000;
  }
}