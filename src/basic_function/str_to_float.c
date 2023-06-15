/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** str_to_float
*/
#include "lib.h"

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/GPUPreference.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/OpenGL.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

void point_processing(char *str, float *result, int32_t *digits_after_dot)
{
    while (char_isdigit(*str)) {
        (*result) = (*result) * 10 + ((*str) - '0');
        (*digits_after_dot)++;
        str++;
    }
    return;
}

void digit_processing(char *str, float *result)
{
    while (char_isdigit(*str)) {
        (*result) = (*result) * 10 + ((*str) - '0');
        str++;
    }
    return;
}

float str_to_float(char *str)
{
    float result = 0.0; float divisor = 1.0;
    int32_t sign = 1; int32_t point_dot = 0; int32_t digits_after_dot = 0;
    while (char_isspace(*str))
        str++;
    (*str == '-' ? sign = -1, str++ : 0);
    (*str == '+' ? str++ : 0);
    digit_processing(str, &result);
    if (*str == '.') {
        point_dot = 1;
        str++;
        point_processing(str, &result, &digits_after_dot);
        for (int i = 0; i < digits_after_dot; i++)
            divisor *= 10;
    }
    if (point_dot)
        result /= divisor;
    result *= sign;
    return result;
}
