/*
Design and implement a program that encrypts messages using Vigenère’s cipher.

$ ./vigenere bacon
plaintext: Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz

*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[])
{
    // check if user inputted a single keyword or not
    if (argc == 2 && argv[1] > 0)
    {
        // check keyword length, to create a right sized array for key to add
        int arraySize = strlen(argv[1]);
        int key[arraySize];

        // add key to array
        for (int i = 0; i < arraySize; i++)
        {
            // transform keyword characters to ascii value keys
            char x = argv[1][i];
            int v = x;

            // if lowercase
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                v -= 97;
            }

            // if uppercase
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                v -= 65;
            }

            // if not a letter, return error
            else
            {
                // if keyword contains anything else than letters, the program rejects
                printf("Please enter a single word\n");
                return 1;
            }
            // add value to array
            key[i] = v;
        }

        // prompt user for text
        string message = get_string("plaintext: ");

        printf("ciphertext: ");

        int n = 0;  // variable for iterating through message characters
        int c = 0;  // variable for iterating key array elements
        while (message[n] != '\0')
        {
            // transform message character to ascii value
            char asc = message[n];
            int ascii = asc;

            int caze = 0;  // variable for upper/lowercase/non-letters

            // uppercase
            if (ascii >= 65 && ascii <= 90)
            {
                caze = 3;
            }

            // lowercase
            else if (ascii >= 97 && ascii <= 122)
            {
                caze = 2;
            }

            // not a letter
            else
            {
                caze = 1;
            }

            // if lower or uppercase
            if (caze > 1)
            {
                // wrap key array around
                if (c >= arraySize)
                {
                    c = c % arraySize;
                }

                // move message ascii values with key values
                int csar = ascii + key[c];

                // wrap around if lowercase
                if (caze == 2)
                {
                    while (csar > 122)
                    {
                        csar -= 26;
                    }
                }

                // wrap around if uppercase
                else if (caze == 3)
                {
                    while (csar > 90)
                    {
                        csar -= 26;
                    }
                }

                // print altered character
                printf("%c", csar);
                c++;
            }

            // if not letter, print the original character
            else if (caze == 1)
            {
                printf("%c", message[n]);
            }
            n++;
        }
        printf("\n");
    }

    // if no or more than one keyword has been entered, return error
    else
    {
        // if no argument number or more than 1 has been typed in, print an error
        printf("Please enter a single word\n");
        return 1;
    }
}