/*
** EPITECH PROJECT, 2019
** test_pong.c
** File description:
** test pong
*/

#include <stddef.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;

    if ((dest = malloc(sizeof(char) * (strlen(src) + 1))) == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(pong, test_one, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("-2");
    str[7] = my_strdup("4");
    cr_assert_eq(pong(str), 0);
}

Test(pong, test_two, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1.1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("-7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("2");
    str[7] = my_strdup("4");
    cr_assert_eq(pong(str), 0);
}

Test(pong, test_three, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1.1d");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("-7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("2");
    str[7] = my_strdup("4");
    cr_assert_eq(pong(str), 84);
}

Test(pong, test_four, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1.1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("-7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("2");
    str[7] = my_strdup("-4");
    cr_assert_eq(pong(str), 84);
}

Test(pong, test_five, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1.1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("-7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("2");
    str[7] = my_strdup("4p");
    cr_assert_eq(pong(str), 84);
}

Test(pong, test_six, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("0");
    str[2] = my_strdup("0");
    str[3] = my_strdup("0");
    str[4] = my_strdup("0");
    str[5] = my_strdup("0");
    str[6] = my_strdup("0");
    str[7] = my_strdup("0");
    cr_assert_eq(pong(str), 0);
}

Test(pong, test_seven, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("5");
    str[4] = my_strdup("7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("100");
    str[7] = my_strdup("4");
    cr_assert_eq(pong(str), 0);
}

Test(pong, test_eight, .init = redirect_stdout)
{
    char **str = malloc(sizeof(char *) * 8);

    if (str == NULL)
        exit(0);
    str[0] = my_strdup("101pong");
    str[1] = my_strdup("1.1");
    str[2] = my_strdup("3");
    str[3] = my_strdup("-5");
    str[4] = my_strdup("-7");
    str[5] = my_strdup("9");
    str[6] = my_strdup("-2");
    str[7] = my_strdup("4");
    cr_assert_eq(pong(str), 0);
}

Test(print_descr, test_one, .init = redirect_stdout)
{
    cr_assert_eq(print_descr(), 0);
}
