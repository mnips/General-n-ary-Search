#include<stdio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>

//using namespace std;
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

 int main()
{  int i,nik,key,l,r,d,n,k;
	double sum;
	
	for(d=2;d<11;d++)
	{ 
	    for(n=50;n<500;n++)
	    {   sum=0;
	       // for(k=1;k<1000;k++)
	         {
	            for(i=0;i<n;i++)
	               s[i]=rand()%500;
	               quicksort(s,0,n-1);
	   
	                key=rand()%500;
	             	l=0;r=n;  
					 clock_t t; 	 
                 t = clock();
                   search(s,l,r,key,d);
                    t = clock()-t;
             double  time_taken = ((double)t)/CLOCKS_PER_SEC; 
               printf("It took %f ---%fseconds to execute \n", time_taken,t);
               sum=sum+time_taken;
              }
			
             sum=sum/(double)1000;
            // printf("It took %f seconds to execute \n", time_taken);
        }
 
	
   }
}

