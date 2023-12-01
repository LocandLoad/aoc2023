#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        }
        sum += (first * 10) + last;
    }
    printf("%d",sum);
    fclose(input);
    return 0;
}