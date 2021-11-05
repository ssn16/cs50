#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
     int charToInt(char c);
     long card;
     char s[16], f_ch, s_ch, s2[2], s2_1, s2_2;
     string type_card="INVALID\n";
     int len, z1, even, kol_f, kol_s, f_mass[16], f_mass2[16], s_mass[16], sum_sec, sum_fir;
     do
    {
        card = get_long("Number card: ");
    }
    while (card <1000000000000);
    //printf("Number card: %ld\n", card);
    sprintf(s,"%ld",card);
    //printf("Number card_str: %s\n", s);
    len=strlen(s);
    f_ch=s[0];
    s_ch=s[1];
    //printf("Length of |%s| is |%d|\n", s, len);
    switch (f_ch)
       {
        case '3':
          if (s_ch=='4' || s_ch=='7') 
          {
           type_card = len==15 ? "AMEX\n" : "INVALID\n";
          }
          break;
        case '4':
          type_card = len==13 || len==16 ? "VISA\n" : "INVALID\n";
          break;
        case '5':
          if (s_ch=='1' || s_ch=='2'|| s_ch=='3'|| s_ch=='4'|| s_ch=='5') 
            {
            type_card = len==16 ? "MASTERCARD\n" : "INVALID\n";
            }
          break;
       }
    if (len % 2 == 0)
    {
        even=1;
        kol_f=len/2;
        kol_s=len/2;
    }
    else
    {
        even=0;
        kol_f=(len-1)/2;
        kol_s=(len+1)/2;
    }
    sum_fir=0;
    for (int i = 1; i <= kol_f; i++ )
       {
           f_mass[i]=s[len-2*i];
           f_mass2[i]=charToInt(f_mass[i])*2;
           //printf("|%c|-|%i|", f_mass[i],f_mass2[i]);
           if (f_mass2[i]<10)
           {
               sum_fir=sum_fir+f_mass2[i];
           }
           else
           {
               sprintf(s2,"%i",f_mass2[i]);
               s2_1=s2[0];
               s2_2=s2[1];
               sum_fir=sum_fir+charToInt(s2_1)+charToInt(s2_2);
           }
       }
       //printf("\n");
       sum_sec=0;
    for (int i = 1; i <= kol_s; i++ )
       {
           s_mass[i]=s[(len+1)-2*i];
           //printf("|%c|", s_mass[i]);
           sum_sec=sum_sec+charToInt(s_mass[i]);
       }
    if ((sum_fir+sum_sec)%10 != 0)
       {
        type_card="INVALID\n";
       }
    //printf("\n");
    //printf("|%i|+|%i|\n", sum_fir,sum_sec);
    printf("%s\n", type_card);
 
 }
int charToInt(char c)
{
   int arr[]={0,1,2,3,4,5,6,7,8,9};
   return arr[c-'0'];
}
