#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(void)
{
  
    FILE* input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Could not open card.raw.\n");  // error message
        return 1;
    }

    // buffer
    unsigned char buffer[BUFFER_SIZE];

    // file counter
    int filecounter = 0;

    FILE* picture = NULL;

    // check if pic found
    int pic_found = 0; //false

    // iterate through card.raw
    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        // check for jpg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (pic_found == 1)
            {
                // start of a new pic found, close
                fclose(picture);
            }
            else
            {
                // pic found
                pic_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecounter);
            picture = fopen(filename, "a");
            filecounter++;
        }

        if (pic_found == 1)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }

    }

    fclose(input);
    fclose(picture);

    return 0;
}