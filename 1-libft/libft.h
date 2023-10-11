#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long size_t;

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char* s);
int ft_toupper(int c);
int ft_tolower(int c);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
void ft_bzero(void *s, size_t n);


#endif