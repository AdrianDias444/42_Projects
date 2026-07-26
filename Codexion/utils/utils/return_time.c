#include "../../header.h"


long ft_return_time_since_start(long start_ms)
{
    long duration;
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    duration = (tv.tv_sec*1000 + tv.tv_usec / 1000) - (start_ms);
    
    return (duration);
}


long ft_return_time_now()
{
    struct timeval tv;
    long time_now;
    
    
    gettimeofday(&tv, NULL);
    
    time_now = tv.tv_sec*1000 + tv.tv_usec / 1000;
    return (time_now);
}