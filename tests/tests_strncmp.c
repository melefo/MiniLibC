/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strncmp
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strncmp, basic, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strncmp(str, str2, strlen(str)), asm_strncmp(str, str2, asm_strlen(str)));
}

Test(strncmp, okey, .init = init_tests)
{
    char *str = "Hello world!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strncmp(str, str2, strlen(str)), asm_strncmp(str, str2, asm_strlen(str)));
}

Test(strncmp, empty, .init = init_tests)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(strncmp(str, str2, strlen(str)), asm_strncmp(str, str2, asm_strlen(str)));
}

Test(strncmp, basic_middle, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strncmp(str, str2, 5), asm_strncmp(str, str2, 5));
}

Test(strncmp, okey_more, .init = init_tests)
{
    char *str = "Hello world!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strncmp(str, str2, strlen(str) + 10), asm_strncmp(str, str2, asm_strlen(str) + 10));
}

Test(strncmp, zero, .init = init_tests)
{
    char *str = "Hello world!\n";
    char *str2 = "Hello world!\n";

    cr_assert_eq(strncmp(str, str2, 0), asm_strncmp(str, str2, 0));
}

Test(strncmp, a_lot_bigger, .init = init_tests)
{
    char *str = "Hello";
    char *str2 = "Hello";

    cr_assert_eq(strncmp(str, str2, 10000000), asm_strncmp(str, str2, 10000000));
}

Test(strncmp, negativ, .init = init_tests)
{
    char *str = "Hello";
    char *str2 = "Hello";

    cr_assert_eq(strncmp(str, str2, (size_t)-1), asm_strncmp(str, str2, (size_t)-1));
}

Test(strncmp, different_on_stop, .init = init_tests)
{
    char *str = "Hello";
    char *str2 = "Hello";

    cr_assert_eq(strncmp(str, str2, 1), asm_strncmp(str, str2, 1));
}