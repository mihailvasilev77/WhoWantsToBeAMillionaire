#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void encrypt(char *fname, int key){
    char ch;
    FILE *fps, *fpt;

    fps = fopen(fname, "r");
    if(fps == NULL){
        return 0;
    }

    fpt = fopen("temp.txt", "w");
    if(fpt == NULL){
        return 0;
    }

    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch += key;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }

    fclose(fps);
    fclose(fpt);

    fps = fopen(fname, "w");
    if(fps == NULL){
        return 0;
    }

    fpt = fopen("temp.txt", "r");
    if(fpt == NULL){
        return 0;
    }

    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }

    fclose(fps);
    fclose(fpt);
}

void decrypt(char *fname, int key){
    char ch;
    FILE *fps, *fpt;

    fps = fopen(fname, "w");
    if(fps == NULL){
        return 0;
    }

    fpt = fopen("temp.txt", "r");
    if(fpt == NULL){
        return 0;
    }

    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch -= key;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }

    fclose(fps);
    fclose(fpt);
}

int main()
{
    //encrypt("c.txt",100);
    //decrypt("c.txt",100);
    return 0;
}
