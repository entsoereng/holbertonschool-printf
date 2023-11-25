#include <stdarg.h>
#include "main.h"

/**
 * buffer_string - prints string
 * @ap: va_list
 * @buffer: character string
 * @index: position in string
 * Return: integer
 */
int buffer_string(va_list ap, char *buffer, int index)
{
    char *s = va_arg(ap, char *);

    if (s == NULL)
    {
        // Handle NULL string
        index = _strcpy(buffer, "(null)", index);
    }
    else
    {
        index = _strcpy(buffer, s, index);
    }

    return index;
}

/**
 * buffer_char - prints char
 * @ap: va_list
 * @buffer: character string
 * @index: position in string
 * Return: integer
 */
int buffer_char(va_list ap, char *buffer, int index)
{
    char s = va_arg(ap, int);
    buffer[index] = s;
    return index + 1;
}

/**
 * buffer_int - prints integer
 * @ap: va_list
 * @buffer: character string
 * @index: position in string
 * Return: integer
 */
int buffer_int(va_list ap, char *buffer, int index)
{
    int in = va_arg(ap, int);

    if (in < 0)
    {
        index = buffer_check(buffer, index);
        index = negative_copy(buffer, index);
        in = _abs(in);
    }

    char *s = int_string(in);
    index = _strcpy(buffer, s, index);

    return index;
}

/**
 * buffer_int_b - prints binary integer
 * @ap: va_list
 * @buffer: character string
 * @index: position in string
 * Return: integer
 */
int buffer_int_b(va_list ap, char *buffer, int index)
{
    int in = va_arg(ap, int);

    if (in < 0)
    {
        index = buffer_check(buffer, index);
        in = _abs(in);
        buffer[index] = '-';
        index++;
    }

    char *s = int_b_string(in);
    index = _strcpy(buffer, s, index);

    return index;
}
