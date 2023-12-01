#include <stdio.h>
#include <string.h>
#include <ctype.h>


void numCheck(char *str, char *numStr, int numVal, int *pfirst, int *plast)
{
    char str2[100];
    strncpy(str2, str, strlen(numStr));
    str2[strlen(numStr)] = 0;
    if (strcmp(str2, numStr) == 0)
    {
        if (*pfirst == 11)
        {
            *pfirst = numVal;
        }
        *plast = numVal;
    }
}

int main(int argc, char **argv)
{
    char str[100];
    int sum = 0, first, last;
    if (argc != 2)
    {
        printf("Incorrect num of arguments");
        return 0;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("input = NULL");
        return 0;
    }
    while (!feof(input))
    {
        first = 11;
        fgets(str, 100, input);
        for (int i = 0; i < strlen(str); ++i)
        {
            if (isdigit(str[i]) != 0)
            {
                if (first == 11)
                {
                    first = ((int)str[i]) - 48;
                }
                last = ((int)str[i]) - 48;
            }
            else
            {
                if (str[i] == 'o')
                {
                    numCheck(&str[i], "one", 1, &first, &last);
                }
                if (str[i] == 't')
                {
                    numCheck(&str[i], "two", 2, &first, &last);
                    numCheck(&str[i], "three", 3, &first, &last);
                }
                if (str[i] == 'f')
                {
                    numCheck(&str[i], "four", 4, &first, &last);
                    numCheck(&str[i], "five", 5, &first, &last);
                }
                if (str[i] == 's')
                {
                    numCheck(&str[i], "six", 6, &first, &last);
                    numCheck(&str[i], "seven", 7, &first, &last);
                }
                if (str[i] == 'e')
                {
                    numCheck(&str[i], "eight", 8, &first, &last);
                }
                if (str[i] == 'n')
                {
                    numCheck(&str[i], "nine", 9, &first, &last);
                }
            }
        }
        sum += (first * 10) + last;
    }
    printf("%d",sum);
    fclose(input);
    return 0;
}