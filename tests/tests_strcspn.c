/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strcspn
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strcspn, basic, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *list = "!?.,;:";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}

Test(strcspn, none, .init = init_tests)
{
    char *str = "Hello World\n";
    char *list = "!?.,;:";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}

Test(strcspn, basic2, .init = init_tests)
{
    char *str = "Hello;World!\n";
    char *list = "!?.,;:";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}

Test(strcspn, empty, .init = init_tests)
{
    char *str = "";
    char *list = "!?.,;:";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}

Test(strcspn, empty2, .init = init_tests)
{
    char *str = "Hello World!\n";
    char *list = "";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}

Test(strcspn, empty3, .init = init_tests)
{
    char *str = "";
    char *list = "";

    cr_assert_eq(strcspn(str, list), asm_strcspn(str, list));
}