#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int parsing(char *argv) 
{
    char *endptr;
    long num = strtol(argv, &endptr, 10);

    if (*endptr != '\0' || num < 0 || num > INT_MAX) 
	{
        printf("Error: Invalid number.\n");
        return (-1);
    }

    return (int)num;
}

void print_stars (int size, int flag)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("*");
		if ((flag == 1 && i + 1 != size) || flag == 2)
			printf(" ");
		i++;
	}
	if (flag != 2 && flag != 3)
		printf("\n");
	if (flag == 3)
		printf(" ");
}

void create_matrix(int num)
{
	int i;
	int tmp;

	i = 1;
	tmp = 0;
	if (num == 0)
		return ;
	if (num == 1)
		printf("42\n");
	else
	{
		num = 5 + ((num - 2) * 4);
		while (i <= num)
		{
			if (i <= ((num / 2) + 1))
				tmp = i;
			else 
				tmp = ((num / 2) + 1) - (i - ((num / 2) + 1));
			if (i == 1 || i == num)
				print_stars(num, 0);
			else if (i % 2 == 0)
				print_stars(tmp, 1);
			else
			{
				print_stars(tmp / 2, 2);
				print_stars(num - ((tmp - 1) * 2), 3);
				print_stars(tmp / 2, 1);
			}
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	int	num;

	if (argc != 2)
		return(0);
	num = parsing(argv[1]);
	if (num < 0)
		return (1);
	create_matrix(num);
	return (0);
}