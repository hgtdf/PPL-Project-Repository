#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValidDelimiter (char ch);
bool isValidOperator (char ch);
bool isvalidIdentifier (char* str);
bool isValidKeyword(char* str);
bool isValidInteger(char* str);
char* subString(char* str, int left, int right);
void detectTokens(char* str);
bool isQuotes (char ch);

int main(int argc, char const *argv[]) 
    { 
        FILE* inp; 
        inp = fopen("sampletxt.txt","r");		
        char arr[100][50];			
        int i = 0; 
        while(1){
            int k = 0; 
            char r = ' ';
            while(!feof(inp) && r!='\n'){	
               r = (char)fgetc(inp); 
               arr[i][k++] = r;		
            } 
            arr[i][k]=0; 
            if(feof(inp)){
                break; 
            } 
            i++; 
        } 
        int j; 
        for(j = 0; j<=i; j++){
            printf("LINE [%i]: %s\n", j+1, arr[j] ); //print array 
            detectTokens (arr[j]);
        }
        return 0; 
   }


bool isValidDelimiter (char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
   ch == '|' || ch == '&' || ch == '!' || ch == 9 || ch == 10 ||  ch == 39 || ch == 34) //digits here are ascii codes
   return (true);
   return (false);
}

bool isValidOperator (char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '=' || ch == '|' || ch == '&' || ch == '!')
   return (true);
   return (false);
}

bool isvalidIdentifier (char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
      str[0] == '3' || str[0] == '4' || str[0] == '5' ||
      str[0] == '6' || str[0] == '7' || str[0] == '8' ||
      str[0] == '9' || str[0] == '_' || isValidDelimiter(str[0]) == true)
         return (false);
   return (true);
}

bool isValidKeyword(char* str) {
   if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "break") || !strcmp(str, "int")
      || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case")
      || !strcmp(str, "long") || !strcmp(str, "switch") || !strcmp(str, "void") || !strcmp(str, "default") || !strcmp(str, "print") || !strcmp(str, "scan"))
         return (true);
   return (false);
}

bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' 
      && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' 
      && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
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
   while (right <= length && left <= right) {
      if (isValidDelimiter(str[right]) == false)
      right++;
      if (isValidDelimiter(str[right]) == true && left == right) {
         if (isValidOperator(str[right]) == true){
            printf("Valid operator : %c\n", str[right]);}
         else if (str[right] == ' ' || str[right] == 9 || str[right] == 10)
            ;
         else if (str[right] == 34 || str[right] == 39){
            do {
               right++;
            } while(isQuotes(str[right]) == false);
            char* strLit = subString (str, left+1, right-1);
            printf("String Literal: %s \n", strLit);
         }
         else
          printf("Valid delimiter : %c\n", str[right]);
         
         right++;
         left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
            printf("Valid keyword : %s\n", subStr);
         else if (isValidInteger(subStr) == true)
            printf("Valid Integer : %s\n", subStr);
         else if (isvalidIdentifier(subStr) == true
            && isValidDelimiter(str[right - 1]) == false)
         printf("Valid Identifier : %s\n", subStr);
         else if (isvalidIdentifier(subStr) == false
            && isValidDelimiter(str[right - 1]) == false)
         printf("Invalid Identifier : %s\n", subStr);
         left = right;
      }
   }
   return;
}

bool isQuotes (char ch){
   if ((ch == 34) || (ch == 39))
      return (true);
   return false;
}