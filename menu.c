#include <stdio.h>
#include <stdlib.h>
#include "crypting.h"

void instructions(){
    FILE *f = fopen("instruction.txt","r");
    char buffer[255];
    while(fgets(buffer,255,f)){
        printf("%s",buffer);
    }
    fclose(f);
}

int main()
{
    decrypt("questions.txt");
    while(1){
        int ans;
        instructions();
        printf("Select an option: ");
        scanf("%d",&ans);
        while(ans > 3){
            printf("Enter a valid number: ");
            scanf("%d",&ans);
        }
        if(ans == 0){
            printf("Goodbye!");
            break;
        }
        else if(ans == 1){
            //stenli
            system("cls");
                //programa
            system("cls");
        }
        else if(ans == 2){
            //hristo
            system("cls");
                //programa
            system("cls");
        }
        else if(ans == 3){
            //hristo
            system("cls");
                //programa
            system("cls");
        }
    }
    encrypt("questions.txt");
    return 0;
}
