/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_memcpy
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(memcpy, basic, .init = init_tests)
{
    char *src = "Hello World!\n";
    char *dest1 = malloc(sizeof(char) * 14);
    char *dest2 = malloc(sizeof(char) * 14);

    memcpy(dest1, src, strlen(src));
    asm_memcpy(dest2, src, asm_strlen(src));

    for (size_t i = 0; i < strlen(dest1); i++)
        cr_assert_eq(dest1[i], dest2[i]);
}