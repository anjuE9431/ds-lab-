#include <stdio.h>
int main()
{
    int n1,n2,n3,i,j,temp;            
    int a[10000], b[10000], c[20000];
    printf("Enter the size of first array: ");
    scanf("%d",&n1);
    printf("Enter the  first array elements: ");
    for(int i = 0; i < n1; i++)      
       scanf("%d", &a[i]);
for(i=0;i<n1;i++){
   for(j=i+1;j<n1-1;j++){
      if(a[i]>a[j]){
         temp=a[i]; 
         a[i]=a[j];
         a[j]=temp;
      }
   }
}
printf("the sorted first array:");
for(i=0;i<n1;i++)
printf("%d ",a[i]);
    printf("\nEnter the size of second array: ");
        scanf("%d",&n2);
    printf("Enter the  second array elements: ");
    for(int i = 0; i < n2; i++)      
       scanf("%d", &b[i]);
for(i=0;i<n2;i++){
   for(j=i+1;j<n2-1;j++){
      if(b[i]>b[j]){
         temp=b[i]; 
         b[i]=b[j];
         b[j]=temp;
      }
   }
}
printf("the sorted second  array:");
for(i=0; i<n2 ;i++)
printf( "%d " ,b[i]);
    n3 = n1 + n2;
    for(int i = 0; i < n1; i++)
       c[i] = a[i];
    for(int i = 0; i < n2; i++)     
        c[i + n1] = b[i];
        
    printf("\nThe merged array: ");
    for(int i = 0; i < n3; i++)
        printf("%d ", c[i]);        
    
    printf("\nFinal array after sorting: ");
    for(int i = 0; i < n3; i++){
        int temp;
        for(int j = i + 1; j < n3; j++) {
            if(c[i] > c[j]) {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }   
    for(int i = 0; i < n3 ; i++)       
        printf(" %d ",c[i]);
    return 0;   
}
