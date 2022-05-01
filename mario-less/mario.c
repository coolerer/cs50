#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while(true){
    int n=get_int("Height");
    if(n>=1 && n<=8)
    {
    for(int i=0;i<n;i++)
    {
        for(int g=n;g>i+1;g--)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("#");

        }
printf("\n");
    }
    break;}}
}