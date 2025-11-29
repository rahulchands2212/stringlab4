/*
Write a program that receives an integer
(less than or equal to nine
digits in length) and prints out the number
in words. For example, if
the number input is 12342, then the output
should be Twelve
Thousand Three Hundred Forty Two
*/

#include<stdio.h>

int main(){
    char ones[10][10] = {"","one","two","three","four","five","six","seven","eight","nine"};
    char teens[10][10] = {"ten","eleven","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char tens[10][10] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
    char group[3][10] = {"","thousand","million"};

    //input number ;
    long int number;
    printf("enter number (not more then 9 digit) = ");
    scanf("%ld",&number);

    if(number==0){
        printf("Zero");
        return 0;
    }

    int count=0;    //for index;
    while(number>0){
        int part = number%1000; //last 3 number;
        number = number/1000;   //remove last 3 number;

        if(part!=0){
            int h = part/100;   //hundred
            int t = (part/10)%10;   //tens
            int o = part%10;    //ones

            //hundred
            if(h>0){
                printf("%s hundred ",ones[h]);
            }

            //teens
            if(t==1){
                printf("%s ",teens[o]);
            }else{

                //tens 20 - 90;
                if(t>1){
                    printf("%s ",tens[t]);
                }

                //ones (1-9)
                if(o>0){
                    printf("%s ",ones[o]);
                }
            }
            printf("%s ",group[count]);


        }
        count++;
    }
    return 0;
}
