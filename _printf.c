#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"print_

/**
* router - selects the appropriate function to perform the operation
* @c: format specifier
*
* Return: pointer to the function that corresponds to the format specifier
*/
int (*router(char c))(va_list, char *, int)
{
print_t ops[] = {
{'%', print_percent},
{'c', print_char},
{'s', print_string},
{'d', print_int},
{'i', print_int},
/* Add more format specifiers as needed */
{0, NULL}
};
int i = 0;

while (ops[i].c)
{
if (ops[i].c == c)
return (ops[i].f);
i++;
}

return (NULL);
}

/**
* _printf - prints anything
* @format: format string
*
* Return: number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int i;
int index = 0;
int (*routing)(va_list, char *, int);

char buffer[1024];
va_list ap;

if (format == NULL)
return (-1);

va_start(ap, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[index] = format[i];
index++;
}
else if (format[i + 1] == '%')
{
buffer[index] = '%';
index++;
i++;
}
else if (format[i + 1] != '\0')
{
routing = router(format[i + 1]);
if (routing != NULL)
{
index = routing(ap, buffer, index);
i++;
}
else
{
buffer[index] = format[i];
index++;
}
}
}

va_end(ap);

write(1, buffer, index);
return (index);
}
