#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

long int findSize(char FileName[]);
int getText (long int fs, char readText[], char *buffer);

int main (){
    char *buffer = 0;
    long int fs = findSize("sampletxt.txt"); // fs for "File Size"
    char readText[fs];

    printf("%i\n", fs);

    getText(fs, readText, buffer);

    return 1;
}

long int findSize(char FileName[]){
    
    FILE* FilePointer = fopen(FileName, "r"); // "r" - stands for read only mode in FILE handling

    if (FilePointer == NULL){
        printf("Failed to open File.\n");
        return -1;
    }

    fseek(FilePointer, 0L, SEEK_END);
    long int res = ftell(FilePointer) + 2;
    fseek(FilePointer, 0, SEEK_SET);

    fclose(FilePointer);

    return res;
}

int getText(long int fs, char readText[], char *buffer){
    FILE *FileLoc = fopen ("sampletxt.txt", "r");
    int i = 0;

    if (FileLoc == NULL){
        perror("Error: ");
        return (-1);
    }

    while(fgets(readText, fs, FileLoc)){
        printf("%s", readText);
    }
    
/*
    for (i=0; i<strlen(readText); i++){
        printf("%c", readText[i]);
    }
*/
    //printf("%i", strlen(readText));
}
