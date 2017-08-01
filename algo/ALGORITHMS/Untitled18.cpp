#include <stdio.h>
#include <time.h>  /* required */

int main(void) {
    time_t s = time(0);

    //long_task();

    printf("That took %f seconds.\n", (double)difftime(s, time(0))/CLOCKS_PER_SEC);

    return 0;
}
