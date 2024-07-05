#include <stdio.h>

int main (int argc, char **argv)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '2')
				num += 2;
			else if (argv[1][i] == '3')
				num += 3; 
			else if (argv[1][i] == '4')
				num += 4;
			else if (argv[1][i] == '5')
				num += 5;
			else if (argv[1][i] == '6')
				num += 6;
			else if (argv[1][i] == '7')
				num += 7;
			else if (argv[1][i] == '8')
				num += 8;
			else if (argv[1][i] == '9')
				num += 9;
			else if (argv[1][i] == 'T' || argv[1][i] == 'J' || argv[1][i] == 'D' || argv[1][i] == 'K')
				num += 10;
			else if (argv[1][i] == 'A')
				num += (num + 11 > 21) ? 1 : 11;
			else
				return (printf("Error: Unexpected Character\n") * 0 + 1);
			i++;
		}
		if (num == 21)
			printf("Blackjack!\n");
		else 
			printf("%d\n", num);
	}
	return (0);
}