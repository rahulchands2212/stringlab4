/*
Write a program that receives an integer 
(max 9 digits) and prints the number in words.
*/

#include<stdio.h>

int main()
{
    // Words Arrays
    char *ones[]  = {"","One","Two","Three","Four","Five",
                     "Six","Seven","Eight","Nine"};

    char *teens[] = {"Ten","Eleven","Twelve","Thirteen","Fourteen",
                     "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

    char *tens[]  = {"","","Twenty","Thirty","Forty","Fifty",
                     "Sixty","Seventy","Eighty","Ninety"};

    char *groups[] = {"","Thousand","Million"};

    // Input
    char str[11];
    printf("Enter number: ");
    gets(str);

    // Convert string → number manually
    long int n = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        n = n * 10 + (str[i] - '0');
        i++;
    }

    // If number = 0
    if(n == 0)
    {
        printf("Zero");
        return 0;
    }

    int count = 0; // group index

    // MAIN LOOP
    while(n > 0)
    {
        int part = n % 1000;     // Get last 3 digits
        n = n / 1000;            // Remove last 3 digits

        if(part != 0)
        {
            int h = part / 100;        // hundreds
            int t = (part / 10) % 10;  // tens
            int o = part % 10;         // ones

            // HUNDRED
            if(h > 0)
                printf("%s Hundred ", ones[h]);

            // TEENS (10–19)
            if(t == 1)
            {
                printf("%s ", teens[o]);
            }
            else
            {
                // TENS (20–90)
                if(t > 1)
                    printf("%s ", tens[t]);

                // ONES (1–9)
                if(o > 0)
                    printf("%s ", ones[o]);
            }

            // GROUP NAME
            printf("%s ", groups[count]);
        }

        count++;    // Next group (0="", 1="Thousand", 2="Million")
    }

    return 0;
}
