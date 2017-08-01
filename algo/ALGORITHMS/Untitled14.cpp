#define ARRAY_SIZE 10000
 #include<stdio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
void swap(int *a, int *b)
{
    int tmp;
     
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void bubbleSort(int *array, int size)
{
    int swapped = 0;
    int x,tmp;    
    do
    {
        swapped = 0;
        for (x = 0; x < size-1;x++)
        {
            if (array[x]>array[x+1])
            {
                swap(&array[x], &array[x+1]);
                swapped = 1;
            }
        }
         
    } while (swapped);
}
 
int main(int argc, char *argv[])
{
    int array[ARRAY_SIZE];
    int i;
    clock_t start, end;
     
    /* initialize array with ARRAY_SIZE random numbers */
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand(); // random number between 0 and RAND_MAX
    }
    /* start the timer */
    start = clock();
    bubbleSort(array, ARRAY_SIZE);
    end = clock();
     
    /* Print out the difference */
    printf ( "The interval was: %f seconds\n", (double)( end - start ) / (double)CLOCKS_PER_SEC );
 
    getchar();
    return 0;
}
