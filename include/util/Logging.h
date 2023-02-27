#ifndef DEV_LOGGING_H
#define DEV_LOGGING_H

#include <stdio.h>

#if DEV_DEBUG == 1
#define LOG(X) _Generic((X), \
                int: log_int,  \
                float: log_flt, \
                default: log_str  \
              )(X)
#else
#define LOG(x)
#endif

void log_int(int x);

void log_flt(float x);

void log_str(const char* x);

#endif // DEV_LOGGING_H
