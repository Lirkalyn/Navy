/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *replace_str_s(char *str, char *src, int pos, int opt)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    for (lens[1] = 0; src[lens[1]] != '\0'; lens[1]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = 0; src[j] != '\0'; j++)
        res[i++] = src[j];
    j = (opt == 0) ? (i - lens[1] + 2) : (i - lens[1] + 1);
    for (; str[j] != '\0'; j++) {
        res[i] = str[j];
        i++;
    }
    return res;
}

char *convert(int num, char **hex, int *res)
{
    int i;
    int pos = 3;

    for (i = 0; i < num; i++) {
        hex[i] = (char *)malloc(5 * sizeof(char));
        hex[i][0] = '\\';
        for (int j = 1 ; j < 4; j++)
            hex[i][j] = '0';
        hex[i][4] = '\0';
        if (res[i] > 0) {
            while (res[i] != 0) {
                if ((res[i] % 16) >= 0 && (res[i] % 16) <= 9)
                    hex[i][pos--] = ((res[i] % 16) + '0');
                else
                    hex[i][pos--] = ((res[i] % 16) + 55);
                res[i] /= 16;
            }
            pos = 3;
        }
    }
}

int num_count(int *num, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        if (src[i] < 32 || src[i] >= 127) {
            *num += 1;
        }
}

char *non_printable(char *src)
{
    int i;
    int num = 0;
    int *res;
    char **hex;

    num_count(&num, src);
    res = (int *)malloc(num * sizeof(int));
    hex = (char **)malloc((num + 1) * sizeof(char *));
    hex[num] = '\0';
    num = 0;
    for (i = 0; src[i] != '\0'; i++)
        if (src[i] < 32 || src[i] >= 127)
            res[num++] = src[i];
    convert(num, hex, res);
    num = 0;
    for (i = 0; src[i] != '\0'; i++)
        if (src[i] < 32 || src[i] >= 127)
            src = replace_str_s(src, hex[num++], i, 1);
    return src;
}

char *replace_str_ss(char *str, char *src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    src = non_printable(src);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    for (lens[1] = 0; src[lens[1]] != '\0'; lens[1]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = 0; src[j] != '\0'; j++)
        res[i++] = src[j];
    j = (i - lens[1] + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}