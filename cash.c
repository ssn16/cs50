#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
 float dollars;
 int coins,kol;
 kol=0;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <=0);
 //printf("Change owed: %f\n", dollars);
  coins = round(dollars * 100);
  if (coins>=25)
    {
      do
      {
      coins=coins-25;
      kol=kol+1;
      }
      while (coins>=25);
    }
    if (coins>=10)
    {
      do
      {
      coins=coins-10;
      kol=kol+1;
      }
      while (coins>=10);
    }
    if (coins>=5)
    {
      do
      {
      coins=coins-5;
      kol=kol+1;
      }
      while (coins>=5);
    }
    if (coins>=1)
    {
      do
      {
      coins=coins-1;
      kol=kol+1;
      }
      while (coins>=1);
    }
    printf("%i\n", kol);
}
