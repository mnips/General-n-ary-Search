#include <time.h>
#include <stdio.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    char s[32];

    start = clock();

    printf("\nSleeping 3 seconds...\n\n");
   // sleep(3);

    end = clock();

    cpu_time_used = ((double)(end - start)) / ((double)CLOCKS_PER_SEC);

    printf("start = %.20f\nend   = %.20f\n", start, end);
    printf("delta = %.20f\n", ((double) (end - start)));
    printf("cpu_time_used  = %.15f\n", cpu_time_used);
    printf("CLOCKS_PER_SEC = %i\n\n", CLOCKS_PER_SEC);

    return 0;
}
