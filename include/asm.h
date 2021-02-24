/*
** EPITECH PROJECT, 2021
** B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include <stddef.h>

void init_tests(void);
extern size_t (*asm_strlen)(const char *);
extern char *(*asm_strchr)(const char *s, int c);
extern void *(* asm_memset)(void *s, int c, size_t n);
extern void *(* asm_memcpy)(void *dest, const void *src, size_t n);
extern int (* asm_strcmp)(const char *s1, const char *s2);
extern void *(* asm_memmove)(void *dest, const void *src, size_t n);
extern int (* asm_strncmp)(const char *s1, const char *s2, size_t n);
extern int (* asm_strcasecmp)(const char *s1, const char *s2);
extern char *(* asm_rindex)(const char *s, int c);

#endif /* !ASM_H_ */