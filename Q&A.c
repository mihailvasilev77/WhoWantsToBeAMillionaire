#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fptr = fopen("file.txt", "r");
    char* question = malloc(30);
    char* answer1 = malloc(30);
    char* answer2 = malloc(30);
    char* answer3 = malloc(30);
    char* answer4 = malloc(30);
    size_t size = 0;
    
    getline(&question, &size, fptr);
    getline(&answer1, &size, fptr);
    getline(&answer2, &size, fptr);
    getline(&answer3, &size, fptr);
    getline(&answer4, &size, fptr);

    printf("%s", question);
    printf("%s", answer1);
    printf("%s", answer2);
    printf("%s", answer3);
    printf("%s", answer4);
    
    
    return 0;
}
