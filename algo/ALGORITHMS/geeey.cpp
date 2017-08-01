/* Program to demonstrate time taken by function fun() */
#include <stdio.h>
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
void fun()
{
    printf("fun() starts \n");
    printf("Press enter to stop fun \n");
    while(1)
    {
        if (getchar())
            break;
    }
    printf("fun() ends \n");
}
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
 
// The main program calls fun() and measures time taken by fun()
int main()
{int i,key,l,r,d;
    for(i=0;i<67;i++)
    s[i]=rand()%500;
    key=rand()%500;
    l=0;r=66;
    quicksort(s,0,66);
    clock_t t;
    t = clock();
    search(s,l,r,key,d);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf(" took %f seconds to execute \n", sizeof(clock_t));
    return 0;
}
