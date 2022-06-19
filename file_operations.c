#include<string.h>
#include<stdlib.h>
#include<stdio.h>

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
void edit_q(int number, char* new_question){


}
int main(){
    char question[]= "MNOGO VAJEN TEKST 2";
    add_q(question);
}