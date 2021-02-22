/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_memmove
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(memmove, basic, .init = init_tests)
{
    char *src = "Hello World!\n";
    char *dest1 = malloc(sizeof(char) * 14);
    char *dest2 = malloc(sizeof(char) * 14);

    memmove(dest1, src, strlen(src));
    asm_memmove(dest2, src, asm_strlen(src));
    for (size_t i = 0; i < strlen(dest1); i++)
        cr_assert_eq(dest1[i], dest2[i]);
}

Test(memmove, empty, .init = init_tests)
{
    char *src = "";
    char *dest1 = malloc(sizeof(char) * 14);
    char *dest2 = malloc(sizeof(char) * 14);

    memmove(dest1, src, strlen(src));
    asm_memmove(dest2, src, asm_strlen(src));
    for (size_t i = 0; i < strlen(dest1); i++)
        cr_assert_eq(dest1[i], dest2[i]);
}

Test(memmove, overlap, .init = init_tests)
{
    char *src1 = strdup("Hello World!");
    char *src2 = strdup("Hello World!");

    memmove(&src1[6], src1, 6);
    asm_memmove(&src2[6], src2, 6);
    for (size_t i = 0; i < strlen(src1); i++)
        cr_assert_eq(src1[i], src2[i]);
}