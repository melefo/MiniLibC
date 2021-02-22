/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strcmp
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strcmp, basic, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strcmp(str, str2), asm_strcmp(str, str2));
}

Test(strcmp, okey, .init = init_tests)
{
    char *str = "Hello world!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strcmp(str, str2), asm_strcmp(str, str2));
}

Test(strcmp, empty, .init = init_tests)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(strcmp(str, str2), asm_strcmp(str, str2));
}