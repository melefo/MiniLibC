/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strpbrk
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strpbrk, basic, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *list = "!?.,;:";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}

Test(strpbrk, none, .init = init_tests)
{
    char *str = "Hello World\n";
    char *list = "!?.,;:";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}

Test(strpbrk, basic2, .init = init_tests)
{
    char *str = "Hello;World!\n";
    char *list = "!?.,;:";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}

Test(strpbrk, empty, .init = init_tests)
{
    char *str = "";
    char *list = "!?.,;:";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}

Test(strpbrk, empty2, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *list = "";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}

Test(strpbrk, empty3, .init = init_tests)
{
    char *str = "";
    char *list = "";

    cr_assert_eq(strpbrk(str, list), asm_strpbrk(str, list));
}