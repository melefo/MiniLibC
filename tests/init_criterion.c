/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** init
*/

#include <dlfcn.h>
#include "asm.h"

size_t (*asm_strlen)(const char *);
char *(*asm_strchr)(const char *s, int c);

void init_tests(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (handle == NULL)
        return;
    asm_strlen = dlsym(handle, "strlen");
    asm_strchr = dlsym(handle, "strchr");
}