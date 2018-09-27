// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths /////////////////////////////
int duration(string fraction)
{
// extract numerator

    // find '/' character position
    char *sl;
    int slIndex;
    sl = strchr(fraction, '/');
    slIndex = (int)(sl - fraction);

// extract numerator
    char *num = (char *) malloc(slIndex);
    strncpy(num, fraction + 0, slIndex);

    // convert string to number
    int numerator = atoi(num);

// extract denominator

    // calculate denominator length
    int denLen = strlen(fraction) - slIndex - 1;

    // extract denominator
    char *den = (char *) malloc(denLen);
    strncpy(den, fraction + slIndex + 1, strlen(fraction));

    // convert string to number
    int denominator = atoi(den);

// calculate eighth
    float result = (8 / denominator) * numerator;
    return result;
}

// Calculates frequency (in Hz) of a note //////////////////////////////////////
int frequency(string note)
{
    int length = strlen(note);

// calculate note character length
    int soundLen = 1;

// extract note characters
    char sound = note[0];

    char mod = (char) malloc(1);

// get mod character if length is 3
    if (length == 3)
    {
        soundLen = 2;
        mod = note[1];
    }

// extract octave character

    char *oct = (char *) malloc(1);
    strncpy(oct, note + soundLen, soundLen + 1);
    int octave = atoi(oct);

    int octDist = octave - 4;

// calculate distance based on note

    float dist = 0;

    switch (sound)
    {
        case 'C':
            dist = -9;
            break;
        case 'D':
            dist = -7;
            break;
        case 'E':
            dist = -5;
            break;
        case 'F':
            dist = -4;
            break;
        case 'G':
            dist = -2;
            break;
        case 'A':
            dist = 0;
            break;
        case 'B':
            dist = 2;
            break;
    }

    // if # or b, modify distance
    if (length == 3)
    {
        if (mod == '#')
        {
            dist++;
        }
        else if (mod == 'b')
        {
            dist--;
        }
    }

    // calculate distance from A4
    dist += octDist * 12;
    // calculate frequency in hertz
    int frz = round(pow(2, dist / 12) * 440);

    return frz;
}

// Determines whether a string represents a rest ///////////////////////////////
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
