#include "main.h"

bool isInTransition = false;
state currstate = q0;
int buffstate, buffcount = 0; // parang pareho lang tong currstate sa int charClass sa front.c
int counter = 0;
char currchar = 0;
char nextchar = 0;
char strToken = 0;
char lexeme[100] = {'\0'};
FILE *fileptr = NULL;
char *filecontent = NULL; 
int right = 0;
int left = 0;

int checkfile();
void lexical();
char getNonBlank();
char getChar();
char getNextChar();
void processfile();
int get_dest();
void accept();
void reset();
void getComment(char []);
char find_Tokens();
char find_Desc();

int main (){
	//printf("kahit sa main man lang\n");
	processfile();
	fptr = fopen("output.simp", "w+");
	if (fptr == NULL)
		printf("Error opening file.");
	lexical();
	free(filecontent);
} // end of main

void lexical (){ //int
	//int i = 0;
	currchar = 'a'; //just to initialize
	while (currchar != 0){ //
		switch (currstate){
			case q0:
					printf("my left is %d my right is %d\n", left, right);
					currchar = getNonBlank(); //2
					printf("currchar in q0 -%c-\n", currchar);
					if (find_dest(currstate, currchar) == true){
						currstate = transition(currstate, currchar);
						lexeme[buffcount] = currchar; //lexeme [0] = i
						//printf("ipinasok si %c kay lexeme\n", currchar);
						buffcount++; //lexeme [1] = 
					}else if(isq0_identifier(currchar) == true){
						printf("ako ay nandito line 48, currchar ay: %c\n", currchar);
						currstate = q1;;
						lexeme[buffcount] = currchar;
						buffcount++;
					}else if (isq0_digit(currchar) == true){
						currstate = q92;
					}else if (currchar == EOF){
						printf("I am EOF!\n");
						currchar = 0;
					}else{
						printf("Unrecognized lexeme: -%d- and state %d\n", currchar, currstate);
					}
					break;

			case q1:	currchar = getChar();
							while (isalnum(currchar) || currchar == '_'){
								lexeme[buffcount] = currchar;
								buffcount++;
								currchar = getChar();
							}
                        fprintf(fptr, "Identifier: ", lexeme[i]);
						lexeme[buffcount] = '\0';
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;
						
			case q2: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Addition Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q3: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Subtraction Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q4: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Multiplication Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q5:	nextchar = getNextChar(); //currchar / nextchar /
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();	//currchar / == nextchar /
						}else {
						fprintf(fptr, "Division Operator: ", lexeme[i]);
						//strDesc = "division operator";
						//strToken = find_Tokens(currstate);
						//printf("I am strToken: %s\n", strToken);
						accept(lexeme, buffcount); // / arithOp division operator
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q6:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Modulus Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q7:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Exponential Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q8: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Increment Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q9: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Decrement Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;
						
			case q10: 	lexeme[buffcount] = currchar;  //++ /
						buffcount++;
                        fprintf(fptr, "Integer Division Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q11:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Assignment Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q12: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Addition Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q13: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Subtraction Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q14: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Multiplication Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q15: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Division Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q16: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Modulus Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q17: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Assignment with Exponent Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q18:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Less than Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q19:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Greater than Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q20:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
                        fprintf(fptr, "Not Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q21:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q22: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "And Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q23:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 100);
						}
						break;

			case q24: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Or Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q25: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Equality Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q26: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Non-equality Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q27: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Less than or equal to Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			case q28: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
                        fprintf(fptr, "Greater than or equal to Operator: ", lexeme[i]);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;
			
			case q29: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q30: 	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q31: 	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
						    fprintf(fptr, "Reserved Word: ", lexeme[i]); // int
							accept(lexeme, buffcount); // on file, Reserved word: int
							reset(&buffcount, &currstate); // buffcount = 0, currstate = 0
							printf("nakapagprint na ako\n");
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100); //lexeme wala ng laman
						}
						break;

			case q32:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q33:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q34:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q35:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q36:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q37:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q38:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q39:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q40:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q41:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q42:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q43:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q44:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q45:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q46:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q47:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q48:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q49:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q51:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;;
						break;

			case q52:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q53:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q54:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q55:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q56:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Reserved Word: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q57:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q58:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q59:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q60:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q61:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q62:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q63:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q64:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q65:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q66:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q67:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q68:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q69:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q70:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q71:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q72:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q73:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q74:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q75:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q76:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q77:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q78:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q79:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q80:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q81:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currstate = q1;
						break;

			case q82:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;;
						}else {
							fprintf(fptr, "Keyword: ", lexeme[i]);
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 100);
						}
						break;

			case q83: 	lexeme[buffcount] = currchar;		//for line comments
						buffcount++;
						fprintf(fptr, "Line comment: ", lexeme[i]);
						accept(lexeme, buffcount);
						buffcount = 0;
						memset(lexeme, 0, 100);
						currchar = getChar();
							while (currchar != 10){
								lexeme[buffcount] = currchar;
								buffcount++;
								currchar = getChar();
							}
						lexeme[buffcount] = '\0';
						fprintf(fptr, "Contents of line comment:~~~");
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

						printf("%s\n", lexeme);
						break;
						
			case q92:	printf("nakapasok ako dito. \n");
						printf("My currchar is -%c-\n", currchar);
						while (isdigit(currchar) || currchar == '.'){
							printf("i am here with currchar -%c-\n", currchar);
								lexeme[buffcount] = currchar;
								//printf("%s", lexeme[buffcount]);
								buffcount++;
								currchar = getChar();
							}
						lexeme[buffcount] = '\0';
						printf("the lexeme is -%s- with buffcount -%d-\n", lexeme, buffcount);
                        fprintf(fptr, "diglit: ", lexeme);
						printf("nakapagoutput na ako supposedly: -%s-\n", lexeme);
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 100);
						break;

			default: {
				printf("Lexical Error, with current state of %d\n", currstate);
				reset(&buffcount, &currstate);
				memset(lexeme, 0, 100);
				break;
				}
		} // end of switch
		//printf("q%d when exiting switch\n", currstate);
	}// end of while != '\0'
		
} // end of lexical

void processfile(){
	checkfile("sample.simp"); // check if filetype is accepted, else exit code immediately
	fileptr = fopen("sample.simp", "r");
	if (fileptr == NULL)
		printf("Error opening file.");
	
	while (fgetc(fileptr) != EOF){
		counter++;
	}
	rewind(fileptr); //reset ng fileptr

	//copy contents of file to *filecontent
	filecontent = malloc (counter * sizeof(char) + 1);
	fread (filecontent, counter * sizeof(char), 1, fileptr);
	filecontent[counter] = '\0';
	//printf("filecontent = |%s| \n", filecontent);
	fclose(fileptr);
}

char getNonBlank(){ 
	while (isspace(filecontent[right])){
		right++;
	}
	return getChar();
} // end of getNonBlank

char getChar(){
	left = right; // initially ay 0
	right++; //to position right to the next char 
	return filecontent[left];
}

char getNextChar(){
	return filecontent[right];
}

void getComment (char lexeme[100]){
	char buffcomment;
	buffcomment = getNonBlank ();
	int count = 0;

	while (buffcomment != 10){
		lexeme[count]=buffcomment;
		count++;
		buffcomment = getchar();
	}
}