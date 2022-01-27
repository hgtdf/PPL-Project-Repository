#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int findSize(char FileName[]);
int openFile(long int fs, char FileName[], char *buffer);
void detectTokens();

int main (){
    int i;
    char FileName[] = {"sampletxt.txt"};
    long int FileSize = findSize(FileName)-1;
    char *buffer = 0;
    openFile(FileSize, FileName, buffer);
    

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

int openFile (long int fs, char FName[], char *buffer){
    
    FILE *FILECursor;
    char dataToBeRead[fs];
    
    FILECursor = fopen (FName, "r"); // "r" - for read only mode

    if(FILECursor == NULL){
        printf("File failed to open");
        return -1;
    }
    else{
        buffer = malloc (fs + 1);
        if(buffer){
            fread (buffer, 1, fs, FILECursor);
        }
        fclose(FILECursor);
        buffer[fs] = '\0';

        
    if (buffer){
        printf("%s", buffer);
    }
    
    }

    return 0;
}

void detectTokens(){

}