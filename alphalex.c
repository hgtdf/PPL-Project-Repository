#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

long int findSize(char FileName[]);
void getText (long int fs, char readText[], char *buffer);

int main (){
    char *buffer = 0;
    long int fs = findSize("sampletxt.txt"); // fs for "File Size"
    char readText[fs];

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
    long int res = ftell(FilePointer);
    fseek(FilePointer, 0, SEEK_SET);

    fclose(FilePointer);

    return res;
}

void getText(long int fs, char readText[], char *buffer){
    FILE *FileLoc = fopen ("sampletxt.txt", "r");

    if (FileLoc){
        buffer = malloc(fs + 1);

        if (buffer){
            fread (buffer, 1, fs, FileLoc);
        }
        fclose(FileLoc);
        buffer[fs] = '\0';
    }
    if (buffer){
        readText = buffer;
        }

    for (int i=0; i<fs; i++){
        printf("%s", readText[i]);
    }

}
