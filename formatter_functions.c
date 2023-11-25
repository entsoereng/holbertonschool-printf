#ifndef FORMATTER_FUNCTIONS_H
#define FORMATTER_FUNCTIONS_H

#include <stdarg.h>

int buffer_string(va_list ap, char *buffer, int index);
int buffer_char(va_list ap, char *buffer, int index);
int buffer_int(va_list ap, char *buffer, int index);
int buffer_int_b(va_list ap, char *buffer, int index);

#endif /* FORMATTER_FUNCTIONS_H */
