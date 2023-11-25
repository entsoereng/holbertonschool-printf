#include "formatter_functions.h"
#include "main.h"

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
    char *s;

    if (in < 0)
    {
        index = buffer_check(buffer, index);
        index = negative_copy(buffer, index);
        in = _abs(in);
    }

    s = int_string(in);
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
    char *s;

    if (in < 0)
    {
        index = buffer_check(buffer, index);
        in = _abs(in);
        buffer[index] = '-';
        index++;
    }

    s = int_b_string(in);
    index = _strcpy(buffer, s, index);

    return index;
}
