#include "../../include/philo.h"

long long get_time(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long current_time(long long initial_time)
{
    return (get_time() - initial_time);
}