/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strchr
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strchr, basic, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(strchr(str, 'W'), asm_strchr(str, 'W'));
}

Test(strchr, first, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(strchr(str, 'H'), asm_strchr(str, 'H'));
}

Test(strchr, last, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(strchr(str, '\n'), asm_strchr(str, '\n'));
}

Test(strchr, zero, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(strchr(str, '\0'), asm_strchr(str, '\0'));
}

Test(strchr, not, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(strchr(str, 'c'), asm_strchr(str, 'c'));
}

Test(strchr, empty, .init = init_tests)
{
    char *str = "";

    cr_assert_eq(strchr(str, ' '), asm_strchr(str, ' '));
}