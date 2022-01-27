#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int findSize(char FileName[]);
int OpenFile(long int fs, char FileName[]);

int main (){

    char FileName[] = {"sampletxt.txt"};
    long int FileSize = findSize(FileName)-1;
    OpenFile(FileSize, FileName);

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

    fclose(FilePointer);

    return res;
}

int OpenFile (long int fs, char FName[]){
    
    FILE *FILECursor;
    char dataToBeRead[fs];
    
    FILECursor = fopen (FName, "r"); // "r" - for read only mode

    if(FILECursor == NULL){
        printf("File failed to open");
        return -1;
    }
    else{
        while(fgets(FName, fs, FILECursor) != NULL){
            printf("%s", FName);
        }
        fclose(FILECursor);
    }

    return 0;
}