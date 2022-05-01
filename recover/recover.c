#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }


    // // open memory card
    FILE *file = fopen(argv[1], "r");

    //
    // repeat until end of card
    // read 512 bytes into buffer
    // if srat  of new jpeg
    // if first jpeg
    // if already found jpeg
    // close any remaining files
    uint8_t buffer[513];
    int i=-1;
    int h=0;
    // 太神奇了 加一个int就没有core dump
    // int c=99;
    char filename[13];
    FILE *img = fopen(filename, "w");




 while (fread(buffer, 1, 512, file) == 512)
{



        if((buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0)){
            i++;
            sprintf(filename,"%03i.jpg",i);
            img = fopen(filename, "w");


        }




            fwrite(buffer,1,512,img);




        // printf("%i",i);









}
}