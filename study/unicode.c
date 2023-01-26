/* Unicode - Here we can see how unicode works. If u send two chars one follwed by other the division symbol is printed, otherwise two different symbols are printed

*/

#include <stdio.h>
int main(void)
{
	char a = 0b11000011;
	char b = 0b10110111;
	printf("%c%c\n", a, b);
	printf("%c\n%c", a, b);
	return (0);
}
