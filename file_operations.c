#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#define MAX_LINE 2048

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
int edit_q(int number){
  FILE *file, *temp;
  char data[1024] = "data.txt";
  char temp_file[1024];
  char buffer[MAX_LINE];
  char replace[MAX_LINE];
  bool keep_reading = true;
  int current_line = 1;
  strcpy(temp_file, "temp");
  strcat(temp_file, data);
  fflush(stdin);
  file = fopen(data, "r");
  temp = fopen(temp_file, "w");
  printf("New Question: ");
  fgets(replace, MAX_LINE, stdin);
  if (file == NULL || temp == NULL){
    printf("Error opening files(s).\n");
  }
  do{
    fgets(buffer, MAX_LINE, file);
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
int main(){
    int q = 1;
    char *question = "Ico e qk";
    /*add_q(question);*/
    edit_q(q);
}





