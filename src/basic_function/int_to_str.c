/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-clement-antoine.xavier
** File description:
** int_to_str
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

static void reverse_str(char* str, int32_t len)
{
    int32_t j = len - 1;
    char temp = 0;
    for (int32_t i = 0; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int int_to_str(int32_t num, char* str)
{
    int32_t i = 0;
    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    reverse_str(str, i);
    str[i] = '\0';
    return i;
}
