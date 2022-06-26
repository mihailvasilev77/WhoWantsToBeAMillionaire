#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "crypting.h"

#define size 256
#define Qsize 10

void readQuestion(char *fname, char *question, char *difficulty, char *A, char *B, char *C, char *D, char *answer, int count){
    FILE* fptr = fopen(fname, "r");
    for(int i = 0; i < count; i++){
        fgets(question, size, fptr);
        fgets(difficulty, size, fptr);
        fgets(A, size, fptr);
        fgets(B, size, fptr);
        fgets(C, size, fptr);
        fgets(D, size, fptr);
        fgets(answer, size, fptr);
    }
    fclose(fptr);
}

/// printing
void printQuestion(char *question, char *difficulty, char *A, char *B, char *C, char *D, char *answer){
    printf("Question: %s", question);
    printDifficulty(difficulty);
    printf("A: %s", A);
    printf("B: %s", B);
    printf("C: %s", C);
    printf("D: %s", D);
    printf("E: for a lifeline\n");

}

void printDifficulty(char *str){
    printf("Rate of difficulty - ");
    if(str[1] == '\n'){
        switch((int)str[0] - '0'){
            case 1:
                printf("Easy\n");
                break;
            case 2:
                printf("Easy\n");
                break;
            case 3:
                printf("Easy\n");
                break;
            case 4:
                printf("Medium\n");
                break;
            case 5:
                printf("Medium\n");
                break;
            case 6:
                printf("Medium\n");
                break;
            case 7:
                printf("Hard\n");
                break;
            case 8:
                printf("Hard\n");
                break;
            case 9:
                printf("Hard\n");
                break;
            }
    }else if(str[1] == '0' && str[0] == '1'){
        printf("Hard\n");
    }else{
        printf("???\n");
    }
}
/// printing

int checkForRepeat(int *arr, int aSize, int var){
    for(int i = 0; i < aSize; i++){
        if(var == arr[i]){
            return 0;
        }
    }
    return 1;
}


/// add and edit
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

void add_dif(int difficulty){
    FILE *data;
    data = fopen("data.txt", "a");
    if(data==NULL) {
        perror("Error opening file.");
    }
    fprintf(data, "%d", difficulty);
    fprintf(data, "%s", "\n");
    fclose(data);
}

int edit_q(int number){
    FILE *file,*temp;
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
/// add and edit

/// info
void instructions(){
    FILE *f = fopen("instruction.txt","r");
    char buffer[255];
    while(fgets(buffer,255,f)){
        printf("%s",buffer);
    }
    fclose(f);
}

void showrules()
{
    printf("\n\t\t************Before we Start The Game**************\n\n\t\t********* Read The Following Rules And Regulations-*********\n\n");
    printf("\n\n\t\t1. Game is divided into three levels:\n\t\t1.Easy\t\t\t2.Medium\t\t\t3.Hard  \n");
    printf("\n\n\t\t2. Each level contains 10 questions which you\n\t\t have to answer one by one .\n");
    printf("\n\t\t3. Each question has a fixed prize money starting from\n\t\t Rs. 10,000 to Rs. 1 Crore which will increase depending \n\t\tupon toughness of the question.\n");
    printf("\n\t\t4.Each correct answer will take you to a higher question\n\t\t and you will earn some money .\n");
    printf("\n\t\t5. If you will give a wrong answer you will fall down\n\t\t to level's starting point and loose your earned money.\n");
    printf("\n\t\t6. You may use  two Life Lines during your game:\n\t\t 1.50-50(two incorrect options will get vanished)\n\t\t 2.Expert Advice:(you can take help from the expert.)\n ");
    printf("\n\t\t7.You may quit the game anytime .");
    getch();
    system("cls");
}
///info

int main()
{
    int key = 75;
    decrypt("c.txt", key);
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
            system("cls");
            char* question = (char*) malloc(size * sizeof(char));
            char* difficulty = (char*) malloc(size * sizeof(char));
            char* A = (char*) malloc(size * sizeof(char));
            char* B = (char*) malloc(size * sizeof(char));
            char* C = (char*) malloc(size * sizeof(char));
            char* D = (char*) malloc(size * sizeof(char));
            char* answer = (char*) malloc(size * sizeof(char));
            int arr[Qsize], a;
            int outcome = 1;
            char *ans1;

            //qanda *q = initQuestion(question, difficulty, A, B, C, D, answer);
            showrules();

            for(int i = 0; i < Qsize; i++){
                a = rand() % 15;
                while(checkForRepeat(arr,Qsize,a) == 0){
                    a = rand() % 15;
                }
                arr[i] = a;
            }

            for(int i = 0; i < Qsize; i++){
                readQuestion("c.txt", question, difficulty, A, B, C, D, answer, arr[i]);
                printQuestion(question, difficulty, A, B, C, D, answer);
                printf("Your answer:");
                scanf("%s", ans1);
                if(!strcmp(ans1,"A")){
                    strcpy(ans1,A);
                }
                else if(!strcmp(ans1,"B")){
                    strcpy(ans1,B);
                }
                else if(!strcmp(ans1,"C")){
                    strcpy(ans1,C);
                }
                else if(!strcmp(ans1,"D")){
                    strcpy(ans1,D);
                }
                if(strcmp(answer,ans1)){
                    if(!strcmp(ans1,"E")){
                        //joker
                    }else{
                        printf("Wrong answer. You`ve lost!\n");
                        outcome = 0;
                        getch();
                        break;
                    }
                }else{
                    printf("Congratulations you`ve got it right! To the next question.\n\n");
                }

            }
            if(outcome == 1)
                printf("Congratulations you`ve won the game\n\n");
            getch();
            system("cls");
        }
        else if(ans == 2){
            /*printf("Enter new question\n");
            char *question1;
            scanf("%s", question1);
            add_q(question1);
            printf("Enter difficulty level");
            int an;
            scanf("%d", &an);
            add_dif(an);
            char *answer1;
            for(int j = 0; j <= 4; j++){
                printf("Enter answer no %d", j);
                add_q(answer1);*/
            //}
        }
        else if(ans == 3){
           int ss = 0;
            printf("Which question do you want to edit\n");
            scanf("%d", &ss);
            edit_q(ss);
        }
    }
    encrypt("c.txt", key);

    return 0;
}
