/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** float_to_str
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

void float_to_str(float num, char* str, int32_t precision)
{
    int32_t int_part = (int32_t) num;
    int32_t int_len = int_to_str(int_part, str);

    str[int_len++] = '.';

    float float_part = num - int_part;
    for (int32_t i = 0; i < precision; i++) {
        float_part *= 10;
        int digit = (int) float_part;
        str[int_len++] = digit + '0';
        float_part -= digit;
    }
    str[int_len] = '\0';
}
