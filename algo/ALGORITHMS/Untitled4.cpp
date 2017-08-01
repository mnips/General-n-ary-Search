#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
int search(int arr[], int l, int r, int x,int d)
{  int i;
   if (r >= l)
   {
        int mid = l + (r - l)/d;
    for(i=1;i<d;i++)
    {
     if (arr[i*mid] == x)  
		return mid;
	}
		for(i=1;i<d;i++)
		{
        if (arr[i*mid] > x) 
		return search(arr, l,i*mid-1, x,d);
        return search(arr,i*mid+1, r, x,d);}
       }
     return -1;
} 
main()
{  int i,nik,k,l,r,d;
	int s[10];
	cout<<"Bhar"<<endl;
	for(i=0;i<10;i++)
	scanf("%d",&s[i]);	
	printf("Enter the key to serch\n");
	scanf("%d",&k);
	printf("Enter the prtitions\n");
	scanf("%d",&d);
	l=0;r=9;
	clock_t begin, end;
	double time_spent;
	begin = clock();
/* here, do your time-consuming job */

 nik=search(s,l,r,k,d);
 if(nik==(-1))
 printf("Not found\n");
 else
 printf("Elemet found!!!\n");
 end = clock();
 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 cout<<"---"<<time_spent<<"--\n";
	
}

