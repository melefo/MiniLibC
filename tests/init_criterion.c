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
void *(* asm_memset)(void *s, int c, unsigned long n);
void *(* asm_memcpy)(void *dest, const void *src, size_t n);
int (* asm_strcmp)(const char *s1, const char *s2);
void *(* asm_memmove)(void *dest, const void *src, size_t n);
int (* asm_strncmp)(const char *s1, const char *s2, size_t n);

void init_tests(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (handle == NULL)
        return;
    asm_strlen = dlsym(handle, "strlen");
    asm_strchr = dlsym(handle, "strchr");
    asm_memset = dlsym(handle, "memset");
    asm_memcpy = dlsym(handle, "memcpy");
    asm_strcmp = dlsym(handle, "strcmp");
    asm_memmove = dlsym(handle, "memmove");
    asm_strncmp = dlsym(handle, "strncmp");
}