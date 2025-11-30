/*
write a program to concatenate two strings.
*/

#include<stdio.h>

int main() {
    char string_1[50];
    char string_2[50];

    printf("Write first string:\n");
    gets(string_1);

    printf("Write second string:\n");
    gets(string_2);

    // find length of string_1
    int i = 0;
    while (string_1[i] != '\0') {
        i++;
    }

    // append string_2 into string_1
    int j = 0;
    while (string_2[j] != '\0') {
        string_1[i] = string_2[j];
        i++;
        j++;
    }

    // add null terminator
    string_1[i] = '\0';

    printf("After merge:\n%s", string_1);

    return 0;
}