#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int  nsearch(int *,int ,int ,int ,int );
int nsearch(int *data, int left, int right, int value,int d){
    int i,k,j;
    int arr[d];

    if(left>right)
       return -1;

    i= (right - left)/d;
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
}

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

int main()
{  long long int d,n,i,j,k;
   for(d=2;d<=11;d++)   // dividing factor d
   {
       for(n=50;n<=500;n+=50);  //number of elements in arr
       {  double sum=0,avg;int arr[n];
          start = clock();
           for(k=1;k<=500000;k++)   // average number of times
           {  time_t t;
              srand((unsigned) time(&t));
               for(i=0;i<n;i++)
               {
                   arr[i]=rand()%10000;
               }
               int key=rand()%n;

               sort(arr,n);
              clock_t start, stop;
               double duration;


               nsearch(arr,0,n-1,key,d);
               stop = clock();
               duration = (double)(stop)-(double)( start );
               sum+=duration;
           }

        printf("%f\n",sum);
       }
   }
    return 0;
}


