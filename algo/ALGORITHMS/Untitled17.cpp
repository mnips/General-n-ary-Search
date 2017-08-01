/* Program to demonstrate time taken by function fun() */
#include <stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include <time.h>
#include<ctime>
#include<iostream>
#include<cstdlib>
 int s[1001];
// A function that terminates when enter key is pressed
void quicksort(int array[], int firstIndex, int lastIndex)
{
    int pivotIndex, temp, index1, index2;

    if(firstIndex < lastIndex)
    {
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;
         while(index1 < index2)
        {
            while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
                index1++;
            
            while(array[index2]>array[pivotIndex])
            index2--;

            if(index1<index2)
            { temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        } temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2] = temp;
         quicksort(array, firstIndex, index2-1);
        quicksort(array, index2+1, lastIndex);
    }
}

int search(int arr[], int l, int r, int x,int d,int sis)
{  int i;
   if (r >= l)
   {
        int mid = l + (r - l)/d;
    for(i=1;i<d;i++)
    { //hello
     if (arr[i*mid] == x)  
		return mid;
	}
	for(i=1;i<d;i++)
	{
		
	}
		for(i=1;i<d;i++)
		{//helllll
        if (arr[i*mid] > x) 
		return search(arr, l,i*mid-1, x,d,sis);
        return search(arr,i*mid+1, r, x,d,sis);}
       }
       for(i=1;i<d;i++)
	{
		
	}
     return -1;
} 
 

int main(int argc,char *argv[])
{	
int i,key,l,r,d,n,nik,k;
   for(d=2;d<11;d++)
   {
   	for(n=50;n<500;n++)
   	{
	   for(k=1;k<1000;k++)
	   {
	   
	   //clock_t t;
   //	srand(time(NULL));
   	             	for(i=0;i<n;i++)
	               s[i]=rand()%5000;
	               quicksort(s,0,n-1);
	   
	                key=rand()%5000;
	             	l=0;r=n;  
					 	
    
	  // t = clock();
	  time_t se = time(0);
  search(s,l,r,key,d,n);

   // t=clock()-t;
   // double time_taken = ((double)t)/CLOCKS_PER_SEC; 
//printf("fun() took %f seconds to execute \n", time_taken);
printf("That took %f seconds.\n", (double)difftime(se, time(0))/CLOCKS_PER_SEC);
    
    

	}}
    
}
return 0;}
