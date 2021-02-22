/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_memset
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(memset, basic, .init = init_tests)
{
    char *str1 = strdup("Hello World!\n");
    char *str2 = strdup("Hello World!\n");

    memset(str1, 'a', strlen(str1));
    asm_memset(str2, 'a', asm_strlen(str2));

    for (size_t i = 0; i < strlen(str1); i++)
        cr_assert_eq(str1[i], str2[i]);
}