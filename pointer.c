#include<stdio.h>
int main()
{
int num=43;
int *ptr=&num;
printf("the value of variable is %d",num);
printf("the value of variable num though the pointer variable ptr is  %d",*ptr);

return 0;
}

