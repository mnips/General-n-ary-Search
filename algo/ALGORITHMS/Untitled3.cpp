// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
#include<stdio.h>
#include<iostream>
using namespace std;
int search(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/d;
  
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
  
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return search(arr, l, mid-1, x);
  
        // Else the element can only be present in right subarray
        return search(arr, mid+1, r, x);
   }
  
   // We reach here when element is not present in array
   return -1;
} 
main()
{  int i,nik,k,l,r;
	int s[9+1];
	cout<<"Bhar"<<endl;
	for(i=0;i<10;i++)
	{
		scanf("%d",&s[i]);
	}
	printf("Enter the key to serch\n");
	scanf("%d",&k);
	l=0;r=9;
 nik=search(s,l,r,k);
 if(nik==(-1))
 printf("Not found\n");
 else
 printf("Elemet found!!!\n");
	
}

