#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument

    if(argc==2){
        // printf("%s",argv[1]);
        // for loop analys if it is char would be a false
        bool a=true;
        string v=argv[1];
        for(int i=0,n=strlen(v);i<n;i++)
        {
            if(isdigit(argv[1][i])){

            }else{
                a=false;
            }

        }
        // int a=atoi(argv[1]);
        // printf("%i",a);
        // char c=(char)a;
        // printf("%c",c);
        // printf("%c",isdigit(c));
        if(a){
            // argv[1]=(int)argv[1];
            int g=atoi(argv[1]);
            string b=get_string("plaintext");
            printf("ciphertext: ");
            for(int i=0,n=strlen(b);i<n;i++)
        {
            if(isalpha(b[i])){
                int l=g%26;
                // printf("666%d666%d",'z','Z');
                if(b[i]+l>'z'){
                    int y=b[i]+l-'z';
                    printf("%c",'a'+y-1);
                }
                else if(b[i]+l>'Z'&&isupper(b[i])){
                     int f=b[i]+l-'Z';
                    printf("%c",b[i]+f);
                }else{
                printf("%c",b[i]+l);}

            }else{
                printf("%c",b[i]);
            }

        }
printf("\n");
return 0;
        }else{
            printf("Usage: ./caesar key2\n");
            return 1;
        }


    }else if(argc==1){
        printf("Usage: ./caesar key\n");
        return 1;

    }else{
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit

    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter

}