#ifndef _MAIN_H
#define _MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int (*specifier_handler)(va_list);

/**
 * struct handler - structure for print type handlers
 * @c: character to be compared
 * @handler_type: Pointer to print type handler.
*/
typedef struct handler
{
	char c;
	int (*handler_type)(va_list);
} handler;


int _printf (const char *input ,...);
int (*specifer_check(char))(va_list);
int handle_char(va_list args);
int handle_str(va_list args);
int handle_cent(va_list args);
int handle_dec(va_list args);
int handle_int(va_list args);

#endif
