/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(strlen, basic, .init = init_tests)
{
    cr_assert_eq(asm_strlen("Hello World!"), strlen("Hello World!"));
}

Test(strlen, empty, .init = init_tests)
{
    cr_assert_eq(asm_strlen(""), strlen(""));
}