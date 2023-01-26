#include <stdio.h>
#include <stdlib.h>

char    *char_to_bin(char c)
{       
        int     mask = 0b10000000;
        char    *bin_char = malloc(sizeof(char *));
        int     i = 0;
        
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


char    bin_to_char(char *bin)
{
        char    c = 0;
        int     i = 0;
        int     mask = 0b10000000;
        while (bin[i])
        {
                if (bin[i] == '1')
                        c |= mask;
                mask >>= 1;
                i++;
        }
        return (c);
}

int     main(void)
{
        char    c = 'a';
        char    *c_bin = char_to_bin(c);
        char    c_new = bin_to_char(c_bin);
        printf("The binary representetion of the character %c is %s\n", c, c_bin);
        printf("Binary %s converted  to char is %c\n", c_bin, c_new);

}

