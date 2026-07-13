#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#ifndef NUMBER_OF_CODERS
#define NUMBER_OF_CODERS 12
#endif

#ifndef TIME_TO_BURNOUT
#define TIME_TO_BURNOUT 350
#endif

#ifndef TIME_TO_COMPILE
#define TIME_TO_COMPILE 150
#endif

#ifndef TIME_TO_DEBUG
#define TIME_TO_DEBUG 450
#endif

#ifndef TIME_TO_REFACTOR
#define TIME_TO_REFACTOR 300
#endif

#ifndef NUMBER_OF_COMPILES_REQUIRED
#define NUMBER_OF_COMPILES_REQUIRED 12
#endif

#ifndef DONGLE_COOLDOWN
#define DONGLE_COOLDOWN 10
#endif

#ifndef SCHEDULER
#define SCHEDULER "edf"
#endif

typedef struct dongle t_dongle;

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


typedef struct coder
{
    int number;
    struct coder* next;
    struct coder* previous;
    char* action;
    t_dongle* right_dongle;
    t_dongle* left_dongle;
} t_coder;


typedef struct circle
{
    t_coder* first_coder;
    int number_of_coders;
    int nb_dongles;
} t_circle;

struct dongle
{
    t_coder* actual_coder;
    struct dongle* next;
    char name;
};


t_args ft_parser(void);
void ft_add_next_coder(t_coder* current_coder, t_coder* next_coder);
void ft_add_previous_coder(t_coder* current_coder, t_coder* previous_coder);
t_coder* ft_create_coder(int nb);
t_circle* ft_handle_circle(t_args args);
void ft_print_args(t_args args);
void ft_print_circle(t_coder* first_coder);
t_circle* ft_create_circle(t_coder* coder, t_args args);
void* ft_create_dongles(t_circle* circle);
void ft_print_dongles(t_circle* circle);
void ft_add_dongle_right(t_coder* coder, t_dongle* dongle);
void ft_add_dongle_left(t_coder* coder, t_dongle* dongle);
void ft_print_all_dongles(t_dongle* first_dongle, t_dongle* last_dongle, t_circle* circle);


#endif