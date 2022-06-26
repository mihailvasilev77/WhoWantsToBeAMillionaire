#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 64

typedef struct {
    char answer[];
    char A[];
    char B[];
    char C[];
    char D[];
    char question;
}qanda;
int readQuestion(char *fname, char *question, char *difficulty, char *A, char *B, char *C, char *D, char *answer, int count){
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

    return ++count;
}

void printQuestion(char *question, char *difficulty, char *A, char *B, char *C, char *D, char *answer){
    printf("Question: %s", question);
    printDifficulty(difficulty);
    printf("A: %s", A);
    printf("B: %s", B);
    printf("C: %s", C);
    printf("D: %s", D);
    //printf("%s", answer);

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
int main()
{
    char* question = (char*) malloc(size * sizeof(char));
    char* difficulty = (char*) malloc(size * sizeof(char));
    char* A = (char*) malloc(size * sizeof(char));
    char* B = (char*) malloc(size * sizeof(char));
    char* C = (char*) malloc(size * sizeof(char));
    char* D = (char*) malloc(size * sizeof(char));
    char* answer = (char*) malloc(size * sizeof(char));
    int count = 1;
    
    
    int arr[10] = {0};
    
    qanda[10];
    int a = rand() %10;
 
    while (1){
        
     if(arr[a])
           {
        a = rand () %10;
    }
    else {
        arr[a] = 1;
        
        break;
    }
    }
    count = readQuestion("c.txt", question, difficulty, A, B, C, D, answer, count);
    printQuestion(question, difficulty, A, B, C, D, answer);

    count = readQuestion("c.txt", question, difficulty, A, B, C, D, answer, count);
    printQuestion(question, difficulty, A, B, C, D, answer);

    count = readQuestion("c.txt", question, difficulty, A, B, C, D, answer, count);
    printQuestion(question, difficulty, A, B, C, D, answer);

    return 0;
}
