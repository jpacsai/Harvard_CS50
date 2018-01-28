/*
Implement a program that encrypts messages using Caesar’s cipher, per the below.

$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar

*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main (int argc, string argv[])
{
    // check if user inputted a number or not
    if (argc == 2 && argv[1] > 0)
    {
        // argument number is a string at the moment, transform to ascii value
        char *k = argv[1];
        int y = atoi(k);

        // prompt user to enter text
        string message = get_string("plaintext: ");

        printf("ciphertext: ");

        int n = 0;

        // transform plain tex into ciphertext by looping through the letters
        while (message[n] != '\0')
        {
            // transform message character into ascii values
            char x = message[n];
            int c = x;

            // check if letter is lowercase
            if (message[n] >= 'a' && message[n] <= 'z')
            {
                // add argument number to ascii value
                c = x + y;
                // if number is greater than 122 (char z), wrap around and count from "a"
                while (c > 122)
                {
                    c = c % 122 + 96;
                }
            }
            // check if letter is uppercase
            else if (message[n] >= 'A' && message[n] <= 'Z')
            {
                // add argument number to ascii value
                c = x + y;
                // if number is greater than 122 (char z), wrap around and count from "a"
                while (c > 90)
                {
                    c = c % 90 + 65;
                }
            }
            // print character
            printf("%c", c);
            n++;
        }
        printf("\n");
    }

    else
    {
        // if no argument number or more than 1 has been typed in, print an error
        printf("Please enter a positive integer\n");
        return 1;
    }
}