/*
Write a program that prompts the user for a credit card number and then reports (via printf) 
whether it is a valid American Express, MasterCard, or Visa card number and determines 
whether a provided credit card number is valid according to Luhn’s algorithm.

*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long n;

    // ask for credit card number
    n = get_long_long("Number: ");

    // get first two letter by dividing credit card number until only two digits left
    int first = n / 100000000000;
    while (first >= 100)
    {
        first = first / 10;
    }

    string cardType;

    // values to use later in for loop to define the condition
    int length = 0;
    int lengthOdd = 0;

    // define credit card types by their length and first digit(s)
    if (n > 999999999999 && n <= 9999999999999 && first / 10 == 4)
    {
        length = 6;
        lengthOdd = 7;
        cardType = "VISA";
    }
    else if (n > 999999999999999 && n <= 9999999999999999)
    {
        length = 8;
        lengthOdd = 8;
        if (first >= 51 && first <= 55)
        {
            cardType = "MASTERCARD";
        }
        else if (first / 10 == 4)
        {
            cardType = "VISA";
        }
        else
        {
            cardType = "INVALID";
        }
    }
    else if (n > 99999999999999 && n <= 999999999999999 && (first == 34 || first == 37))
    {
        length = 7;
        lengthOdd = 8;
        cardType = "AMEX";
    }
    else
    {
        cardType = "INVALID";
    }

    int sum = 0;
    int num = 0;
    long long divider = 100;

    // get every second digit from the end by checking the number's modulo incrementing it by 100 each time and doubling it, adding it together
    for (int i = 0; i < length; i++)
    {
        num = n % divider / (divider / 10) * 2;

        // check if it's a two digit long number
        if (num > 9)
        {
            // reducing it to one digit
            num = num / 10 + num % 10;
        }
        sum += num;
        divider = divider * 100;
    }

    int sumOdd = 0;
    divider = 10;

    // get every second digit from the end by checking the number's modulo incrementing it by 100 each time and adding it together
    for (int j = 0; j < lengthOdd; j++)
    {
        sumOdd += n % divider / (divider / 10);
        divider = divider * 100;
    }

    // add up the two value to get the checksum
    int checkSum = sum + sumOdd;

    // check if the checksum's last digit is 0
    if (checkSum % 10 == 0)
    {
        // if yes, print cardtype
        printf("%s\n", cardType);
    }
    else
    {
        // if not, print invalid
        printf("INVALID\n");
    }
}
