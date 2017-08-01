#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void quick_sort(long int *x,int first,int last){
    long int pivot,j,temp,i;

     if(first<last)
        {
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quick_sort(x,first,j-1);
         quick_sort(x,j+1,last);

    }
}

int n_ary_search(long int *arr,int beg,int end,int key,int d)
{
long int a[d];int i;
a[0]=beg;
if(beg>end)
{
    return -1;
}
for(i=1;i<=d-1;i++)
{
a[i]=beg+ i*(end-beg)/d;
}
for( i=1;i<=d-1;i++)
{
if(arr[a[i]]==key)
{
return 1;}
else if(key<arr[a[i]])
{
n_ary_search(arr,a[i-1],a[i]-1,key,d);
}
}
return n_ary_search(arr,a[d-1]+1,end,key,d);
return 0;
}
int main()
{
long int arr[5000],i,key,j,d,k,l,m,n,count=0;
clock_t start,stop;
FILE *fp;
fp=fopen("output1.csv","w");
for(n=50;n<=500;n+=50)
{
fprintf(fp,"%ld ,",n);
for(i=0;i<n;i++)
{arr[i]=rand()%10000;}


quick_sort(arr,0,n-1);


for(d=1;d<=11;d++)
{
start=clock();

for(k=0;k<5000;k++) // to take average
{
key=rand()%10000;
n_ary_search(arr,0,n-1,key,d);
count++;

}
stop=clock();
double ans=(double)stop-(double)start;
printf("\nN=%d and d=%d\n",n,d);
ans=ans/5000.0;
printf("%f\n",ans);// answer for 5000 calculations
fprintf(fp,"%f,",ans);
}
fprintf(fp,"\n");
}
fclose(fp);

}
