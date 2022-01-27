#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

long int findSize(char FileName[]);

int main (){
    char FileName[] = {"sampletxt.txt"};
    FILE *FPointer;

    long int FileSize = findSize(FileName)-1;
    char *buffer = 0;
    char textfile[FileSize];
    
    FPointer = fopen (FileName, "r"); // "r" - for read only mode
    if(FPointer == NULL){
        printf("File failed to open");
        return -1;
    }
    else{
        
    }
    return 0;
}

long int findSize(char FileName[]){
    
    FILE* FilePointer = fopen(FileName, "r"); // "r" - stands for read only mode in FILE handling

    if (FilePointer == NULL){
        printf("Failed to open File.\n");
        return -1;
    }

    fseek(FilePointer, 0L, SEEK_END);
    long int res = ftell(FilePointer);
    fseek(FilePointer, 0, SEEK_SET);

    fclose(FilePointer);

    return res;
}