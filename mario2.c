#include <cs50.h>
#include <stdio.h>

void p_char(int kol, string symbol);
int main(void)
{
int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1 );
    // printf("Stored: %i\n", n);
    for (int i=1; i <= n; i++ )
    {
        p_char(n-i, " ");
        p_char(i, "#");
        p_char(2, " ");
        p_char(i, "#");
        printf("\n");
    }
}
void p_char(int kol, string symbol)
{
  for (int i=1; i <= kol; i++ )
    {
        printf("%s",symbol);
    } 
  return;
}
