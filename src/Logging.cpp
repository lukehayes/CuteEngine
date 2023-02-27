#include "util/Logging.h"
#include <stdio.h>

void log_int(int x)
{
    printf("LOG: %i \n", x);
}

void log_flt(float x)
{
    printf("LOG: %f \n", x);
}

void log_str(const char* x)
{
    printf("LOG: %s \n", x);
}
