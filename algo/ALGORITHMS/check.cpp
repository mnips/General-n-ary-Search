#include<stdio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<fstream>

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
{  
ofstream infile("graphnik.csv");
int i,nik,key,l,r,d,n,k,p;
	double sum;
	 double cpu_time_used;
	for(d=2;d<=4;d++)
	{      printf("*****%d******\n\n\n",d);
	    for(n=50;n<100;n++)
	    {   sum=0;
	       for(p=1;p<1000;p++)
	         {
	            for(i=0;i<n;i++)
	               s[i]=rand()%10000;
	               quicksort(s,0,n-1);
	              key=rand()%10000;
	             	l=0;r=n;  
				 clock_t start=0,end=0;
                start=clock();
                for(k=1;k<1000;k++)
                   search(s,l,r,key,d);
                   end=clock();
               double  time_taken = ((double)(end-start))/CLOCKS_PER_SEC; 
             time_taken=time_taken/(double)1000;
             sum=sum+time_taken;
             }
               sum=sum/(double)1000;
               
		     infile<<d<<","<< n << "," << sum << ","<<"\n";
			 }
		    
		    }infile.close();
}

