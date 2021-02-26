/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_rindex
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(rindex, basic, .init = init_tests)
{
    char *str = "Hello World!\n";

    cr_assert_eq(rindex(str, 'W'), asm_rindex(str, 'W'));
}

Test(rindex, none, .init = init_tests)
{
    char *str = "Hello world!\n";

    cr_assert_eq(rindex(str, 'W'), asm_rindex(str, 'W'));
}

Test(rindex, multiple, .init = init_tests)
{
    char *str = "Wello World!\n";

    cr_assert_eq(rindex(str, 'W'), asm_rindex(str, 'W'));
}

Test(rindex, zero, .init = init_tests)
{
    char *str = "Wello World!\n";

    cr_assert_eq(rindex(str, '\0'), asm_rindex(str, '\0'));
}

Test(rindex, empty, .init = init_tests)
{
    char *str = "";

    cr_assert_eq(rindex(str, 'W'), asm_rindex(str, 'W'));
}

Test(rindex, empty_zero, .init = init_tests)
{
    char *str = "";

    cr_assert_eq(rindex(str, '\0'), asm_rindex(str, '\0'));
}