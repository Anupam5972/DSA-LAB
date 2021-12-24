#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int coeff;
  int pow;
  struct link *next;
} my_poly;

void create(my_poly **);
void display(my_poly *);
void add(my_poly **, my_poly *, my_poly *);

int main(void)
{
  int ch;
  do
  {
    my_poly *poly1, *poly2, *poly3;

    printf("\nCreate 1st expression\n");
    create(&poly1);
    printf("\nStored the 1st expression");
    display(poly1);

    printf("\nCreate 2nd expression\n");
    create(&poly2);
    printf("\nStored the 2nd expression");
    display(poly2);

    add(&poly3, poly1, poly2);
    display(poly3);

    printf("\nAdd two more expressions? (Y = 1/N = 0): ");
    scanf("%d", &ch);
  } while (ch);
  return 0;
}

void create(my_poly **node)
{
  int flag;
  int coeff, pow;
  my_poly *tmp;                             
  tmp = (my_poly *)malloc(sizeof(my_poly)); 
  *node = tmp;                              
  do
  {

    printf("\nEnter Coeff:");
    scanf("%d", &coeff);
    tmp->coeff = coeff;
    printf("\nEnter Pow:");
    scanf("%d", &pow);
    tmp->pow = pow;

    tmp->next = NULL;
    printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
    scanf("%d", &flag);
    if (flag)
    {
      tmp->next = (my_poly *)malloc(sizeof(my_poly));
      tmp = tmp->next;
      tmp->next = NULL;
    }
  } while (flag);
}

void display(my_poly *node)
{
  printf("\nThe polynomial expression is:\n");
  while (node != NULL)
  {
    printf("%dx^%d", node->coeff, node->pow);
    node = node->next;
    if (node != NULL)
      printf(" + ");
  }
}

void add(my_poly **result, my_poly *poly1, my_poly *poly2)
{
  my_poly *tmp;
  tmp = (my_poly *)malloc(sizeof(my_poly));
  tmp->next = NULL;
  *result = tmp;

  while (poly1 && poly2)
  {
    if (poly1->pow > poly2->pow)
    {
      tmp->pow = poly1->pow;
      tmp->coeff = poly1->coeff;
      poly1 = poly1->next;
    }
    else if (poly1->pow < poly2->pow)
    {
      tmp->pow = poly2->pow;
      tmp->coeff = poly2->coeff;
      poly2 = poly2->next;
    }
    else
    {
      tmp->pow = poly1->pow;
      tmp->coeff = poly1->coeff + poly2->coeff;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
    if (poly1 && poly2)
    {
      tmp->next = (my_poly *)malloc(sizeof(my_poly));
      tmp = tmp->next;
      tmp->next = NULL;
    }
  }
  while (poly1 || poly2)
  {
    tmp->next = (my_poly *)malloc(sizeof(my_poly));
    tmp = tmp->next;
    tmp->next = NULL;

    if (poly1)
    {
      tmp->pow = poly1->pow;
      tmp->coeff = poly1->coeff;
      poly1 = poly1->next;
    }
    if (poly2)
    {
      tmp->pow = poly2->pow;
      tmp->coeff = poly2->coeff;
      poly2 = poly2->next;
    }
  }
  printf("\nAddition Complete");
}