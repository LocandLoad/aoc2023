#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char str[200];
    int sum = 0, redC = 12, greenC = 13, blueC = 14, gameNum;
    int num;
    char c[200];
    int impossible = 0;
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
    fscanf(input, "%s",str);
    while (!feof(input)){
        impossible = 0;
        if (strcmp(str, "Game") == 0)
        {
            fscanf(input, "%d", &gameNum);
            fscanf(input, "%s", c);
            while (strcmp(c, "Game") != 0 && (!(feof(input))))
            {
                fscanf(input, "%d", &num);
                fscanf(input, "%s", c);
                if (c[0] == 'b')
                {
                    if (num > blueC)
                    {
                        impossible = 1;
                    }
                }
                if (c[0] == 'r')
                {
                    if (num > redC)
                    {
                        impossible = 1;
                    }
                }
                if (c[0] == 'g')
                {
                    if (num > greenC)
                    {
                        impossible = 1;
                    }
                }
            }
            if (impossible == 0)
            {
                sum += gameNum;
            }
            strcpy(str,c);
        }
    }
    printf("%d", sum);
    return 0;
}