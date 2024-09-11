#include "philosophers.h"

void ft_sleep(long sleep_time_ms)
{
    usleep(sleep_time_ms * 1000);
}

long get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}