#include <stdio.h>
#include <stdlib.h>
int  nsearch(int*,int,int,int,int);
int compare(const void *p, const void *q)// for qsort
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    int ret;
    if (x == y)
      ret = 0;
    else
      ret = (x < y) ? -1 : 1;

    return ret;
}
void sort(int *a, int n)
{
    qsort(a, n, sizeof(int), compare);
}

int main() {
      int a[10]={5,6,3,9,7,1,2,4,8,10};
      int search;
      int k,d,i;
      printf("enter no to be searched :");
      scanf("%d",&k);
      printf("Enter d:\t");
      scanf("%d",&d);
      sort(a,10);
      for(i=0;i<10;i++)
        printf("%d ",a[i]);

      search=nsearch(a,0,9,k,d);
      printf("\n\n%d",search);
      return 0;
}

int nsearch(int *data, int left, int right, int value,int d){
    int i,k,j;
    int arr[d];


     if(right>=left)
 {   i= (right - left)/d;
    for(k=0;k<=d-1;k++)
    {arr[k] = i*(k) + left ;}

    for(k=0;j<=d-1;k++)
    {if(data[arr[k]]==value)
       return arr[k];
    else
    if(data[arr[k]]>value)
         return nsearch(data,arr[k-1], arr[k]-1, value,d);
    }
    return nsearch(arr,arr[d-1]+1,right,value,d);
} return -1;
}
