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

    va_list ap;
    int index = 0;
    int (*routing)(va_list, char *, int);

    va_start(ap, format);

    char buffer[1024];

    int i;
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
