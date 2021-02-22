/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strcasecmp
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strcasecmp, basic, .init = init_tests)
{
    char *str1 = "Hello World!\n";
    char *str2 = "Hello World!\n";

    cr_assert_eq(strcasecmp(str1, str2), asm_strcasecmp(str1, str2));
}


Test(strcasecmp, basic_case, .init = init_tests)
{
    char *str1 = "Hello World!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strcasecmp(str1, str2), asm_strcasecmp(str1, str2));
}

Test(strcasecmp, found, .init = init_tests)
{
    char *str1 = "HeLlO bye!\n";
    char *str2 = "HElLo world!\n";

    cr_assert_eq(strcasecmp(str1, str2), asm_strcasecmp(str1, str2));
}

Test(strcasecmp, empty, .init = init_tests)
{
    char *str1 = "";
    char *str2 = "";

    cr_assert_eq(strcasecmp(str1, str2), asm_strcasecmp(str1, str2));
}