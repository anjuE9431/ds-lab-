#include <stdio.h>

int main() {

  double n1, n2, n3;

  printf("Enter three different numbers: ");
  scanf("%d,%d,%d", &n1, &n2, &n3);

 
  if (n1 >= n2 && n1 >= n3)
    printf(" the largest number.%d", n1);

  
  if (n2 >= n1 && n2 >= n3)
    printf("is the largest number.%d", n2);

 
  if (n3 >= n1 && n3 >= n2)
    printf(" is the largest number.%d", n3);

  return 0;
}


