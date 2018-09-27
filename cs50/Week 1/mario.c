/*
Implement a program that prints out a double half-pyramid of a specified height using hashes (#) 
for blocks, per the below.

$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####

a program that recreates these half-pyramids using hashes (#) for blocks.

*/

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // propts user for height until in range
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    // creates n number of lines
    for (int i = 0; i < n; i++)
    {
        // adds n-i number of spaces to beginning of line
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        int k = 0;
        // adds "#" character until it's less than i+1 number
        while (k < i + 1)
        {
            printf("#");
            k++;
        }
        // prints a space in the middle
        printf(" ");
        printf(" ");
        int m = 0;
        // adds "#" character until it's less than i+1 number
        while (m < i + 1)
        {
            printf("#");
            m++;
        }
        // new line
        printf("\n");
    }
}