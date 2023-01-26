
/* In computrer language every number has its bit representation 
   Each characther has its integer value >> ASCII table
   The '&'(AND) operator makes a bitwise operation between the binary of a char and a mask
   The below function compares bit by bit with the mask 10000000 and print the resulting bit.
   Then shit the the mask by 1 to the right and compare again. Doing it untill first bit one can
   print the binary form of an integer, or a characther. 
*/

/*
#include <stdio.h>

int	main(void)
{
	char	c;
	int	mask;
	int 	i;

	c = 'b';
	mask = 0b10000000; // 0b followed by zeros and ones is how binary nbrs are expressed in c
	i = 0;
	
	while (i < 8)
	{
		if (c & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
		printf(" - %d\n", mask);
		i++;
	}
	printf("\nc '%c' is %d\n", c, c);
}
*/
/* Bitshift - Here the function above is adpted to print the binary form of an int (or a char).
   And right the we print an int int its char representation in ascii table and in its binary form
   while shiting it's bit by 1 to the right.      
*/
/*
#include <stdio.h>

void	print_bin(int c)
{
	int	mask;
	int 	i;

	mask = 0b10000000;
	i = 0;
	
	while (i < 8)
	{
		if (c & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
		printf(" ");
		i++;
	}
	printf("\n");
	//printf("\nc '%c' is %d\n", c, c);
}

int	main(void)
{
	char ch = 'a';
	printf("%d\n", ch);
	printf("%c\n", ch);
	print_bin(ch);
	ch >>= 1;
	printf("%d\n", ch);
	printf("%c\n", ch);
	print_bin(ch);
	ch >>= 1;
	printf("%d\n", ch);
	printf("%c\n", ch);
	print_bin(ch);
}*/
#include <stdio.h>
#include <stdlib.h>

char	*char_to_bin(char c)
{
	int	mask = 0b10000000;
	char	*bin_char = malloc(sizeof(char *));
	int	i = 0;
	
	while (i < 8)
	{
		if (c & mask)
			bin_char[i] = '1';
		else
			bin_char[i] = '0';
			
		mask >>= 1;
		i++;
	}
	return (bin_char);
}


char	bin_to_char(char *bin)
{
	char	c = 0;
	int	i = 0;
	int	mask = 0b10000000;
	while (bin[i])
	{
		if (bin[i] == '1')
			c |= mask;
		mask >>= 1;
		i++;
	}
	return (c);
}

int	main(void)
{
	char	c = 'a';
	char	*c_bin = char_to_bin(c);
	char	c_new = bin_to_char(c_bin);
	printf("The binary representetion of the character %c is %s\n", c, c_bin);
	printf("Binary %s converted  to char is %c\n", c_bin, c_new);

}
