#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - prints anything
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    int i;
    int index = 0;
    int (*routing)(va_list, char *, int);

    char buffer[1024];
    va_list ap;

    va_start(ap, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[index] = format[i];
            index++;
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
                buffer[index] = '%';
                index++;
            }
        }
    }

    va_end(ap);

    write(1, buffer, index);
    return index;
}
