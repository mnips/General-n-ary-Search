/* Program to demonstrate time taken by function fun() */
#include <stdio.h>
#include <time.h>
 
// A function that terminates when enter key is pressed
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
{
    
    clock_t t;
    t = clock();
    search(s,l,r,key,d);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
