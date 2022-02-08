#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isWhiteSpace(char ch){
   if (ch == ' ' || ch == '\n')
      return (true);
   
   return (false);
}

bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '\n' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}')
      return (true);
   
   return (false);
}
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}
void detectTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);

   while (right <= length && left <= right) { // while right cursor is not beyond the last char and left cursor is beyond the right cursor
      if (isWhiteSpace (str[right] == false)){
          if (isValidDelimiter (str[right]) == false)
            right++;
      }
      if (isValidDelimiter (str[right]) == true && left == right) {
        if (isValidOperator (str[right]) == true)
            printf("Valid operator : '%c'\n", str[right]);

        printf("Valid delimiter: '%c'\n", str[right]);
        right++;
        left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
            printf("Valid keyword : '%s'\n", subStr);
         else if (isValidInteger(subStr) == true)
            printf("Valid Integer : '%s'\n", subStr);
         else if (isRealNumber(subStr) == true)
            printf("Real Number : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == true
            && isValidDelimiter(str[right - 1]) == false)
         printf("Valid Identifier : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == false
            && isValidDelimiter(str[right - 1]) == false)
         printf("Invalid Identifier : '%s'\n", subStr);
         left = right;
      }
   }
   return;
}
    int main(int argc, char const *argv[]) 
    { 
        FILE* inp; 
        inp = fopen("sampletxt.txt","r");		//filename of your data file 
        char arr[100][50];			//max word length 50 max line 100
        int i = 0; 
        while(1){
            int k = 0; 
            char r = ' ';
            while(!feof(inp) && r!='\n'){	
               r = (char)fgetc(inp); //read till , or EOF 
               arr[i][k++] = r;		//store in array 
            } 
            arr[i][k]='\0'; //make last character of string null  
            if(feof(inp)){		//check again for EOF 
                break; 
            } 
            i++; 
        } 
        int j; 
        for(j = 0; j<=i; j++){
            printf("line [%i]: %s", j+1, arr[j] ); //print array 
            detectTokens (arr[j]);
        }
        return 0; 
    } 