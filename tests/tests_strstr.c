/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strstr
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strstr, basic, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *find = "World";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}

Test(strstr, fail, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *find = "world";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}

Test(strstr, empty, .init = init_tests)
{
    char *str = "";
    char *find = "World";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}

Test(strstr, empty2, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *find = "";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}

Test(strstr, empty3, .init = init_tests)
{
    char *str = "";
    char *find = "";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}

Test(strstr, not_full, .init = init_tests)
{
    char *str = "Hello Wor";
    char *find = "World";

    cr_assert_eq(strstr(str, find), asm_strstr(str, find));
}