#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifndef NUMBER_OF_CODERS
#define NUMBER_OF_CODERS "75"
#endif

#ifndef TIME_TO_BURNOUT
#define TIME_TO_BURNOUT "350"
#endif

#ifndef TIME_TO_COMPILE
#define TIME_TO_COMPILE "150"
#endif

#ifndef TIME_TO_DEBUG
#define TIME_TO_DEBUG "450"
#endif

#ifndef TIME_TO_REFACTOR
#define TIME_TO_REFACTOR "300"
#endif

#ifndef NUMBER_OF_COMPILES_REQUIRED
#define NUMBER_OF_COMPILES_REQUIRED "12"
#endif

#ifndef DONGLE_COOLDOWN
#define DONGLE_COOLDOWN "10"
#endif

#ifndef SCHEDULER
#define SCHEDULER "Iniciando teste 1.2.3..."
#endif



typedef struct arguments
{
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    char* scheduler;
} t_args;

t_args ft_parser(int argc, char** argv);
#endif