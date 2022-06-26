#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "crypting.h"

void instructions(){
    FILE *f = fopen("instruction.txt","r");
    char buffer[255];
    while(fgets(buffer,255,f)){
        printf("%s",buffer);
    }
    fclose(f);
}
int edit_q(int number){
    FILE *file, *temp;
    char data[1024] = "data.txt";
    char temp_file[1024];
    char buffer[2048];
    char replace[2048];
    bool keep_reading = true;
    int current_line = 1;
    strcpy(temp_file, "temp");
    strcat(temp_file, data);
    fflush(stdin);
    file = fopen(data, "r");
    temp = fopen(temp_file, "w");
    printf("New Question: ");
    fgets(replace, 2048, stdin);
    if (file == NULL || temp == NULL){
        printf("Error opening files(s).\n");
    }
    do{
        fgets(buffer, 2048, file);
        if (feof(file)) keep_reading = false;
        else if (current_line == number)
        fputs(replace, temp);
        else fputs(buffer, temp);
        current_line++;
    } while (keep_reading);
    fclose(file);
    fclose(temp);
    remove(data);
    rename(temp_file, data);
}
void add_q(char* question){
    FILE *data; 
    data = fopen("data.txt", "a");
    if(data==NULL) {
        perror("Error opening file.");
    }
    fprintf(data, "%s", question);
    fprintf(data, "%s", "\n");
    fclose(data);
}

int main()
{
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
            char question[24];
            printf("Enter new question\n");
            gets(question);
            add_q(question);
        }
        else if(ans == 3){
            int ss = 0;
            printf("Which question you want to edit\n"); 
            scanf("%d", &ss);
            edit_q(ss);
        }
    }
    
    return 0;
}
