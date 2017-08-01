#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int s[1001];
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
{  int i,nik,key,l,r,d,n,k;
	
	for(d=2;d<11;d++)
	{ 
	    for(n=50;n<500;n++)
	    {
	        for(k=1;k<1000;k++)
	         {
	            for(i=0;i<n;i++)
	               s[i]=rand();
	   // cout<<"Bhar"<<endl;
	     // for(i=0;i<6;i++)
	                key=rand();
	        //  scanf("%d",&s[i]);	
                //   	printf("Enter the key to serch\n");
                  //     	scanf("%d",&k);
	
                    	l=0;r=n;
                    	clock_t begin, end;
                       	double time_spent;
                       	begin=clock();
                    search(s,l,r,key,d);
             }
        }
 
	
   }
}

