#include "main.h"

bool isInTransition = false;
state currstate = q0;
int buffstate, buffcount = 0; // parang pareho lang tong currstate sa int charClass sa front.c
int counter = 0;
char currchar = 0;
char nextchar = 0;
char lexeme[50] = {'\0'};
FILE *fileptr = NULL;
char *filecontent = NULL; 
int right = 0;
int left = 0;

int checkfile();
void openfile();
void lexical();
char getNonBlank();
char getChar();
char getNextChar();
void processfile();
int transition(state, char);
bool find_dest(state , char);
int get_dest();
void accept();
void reset();

int main (){
	//printf("kahit sa main man lang\n");
	processfile();
	lexical();
	free(filecontent);
} // end of main

void lexical (){ //int
	int i = 0;
	currchar = 'a'; //just to initialize
	while (currchar != 0){ //
		switch (currstate){
			case q0:
					currchar = getNonBlank();
					if (find_dest(currstate, currchar) == true){
						currstate = transition(currstate, currchar);
						lexeme[buffcount] = currchar;
						//printf("ipinasok si %c kay lexeme\n", currchar);
						buffcount++;
					}else if(isq0_identifier(currchar) == true){
						printf("ako ay nandito line 48, currchar ay: %c\n", currchar);
						currstate = q1;
						lexeme[buffcount] = currchar;
						buffcount++;
					}else if (isq0_digit(currchar) == true){
						currstate = q100;
					}else if (currchar == EOF){
						printf("I am EOF!\n");
					}else
						printf("Unrecognized lexeme: %c\n", currchar);
					break;

			case q1:	currchar = getChar();
							while (isalnum(currchar) || currchar == '_'){
								lexeme[buffcount] = currchar;
								buffcount++;
								currchar = getChar();
							}
						lexeme[buffcount] = '\0';
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;
						
			case q2: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q3: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q4: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q5:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q6:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q7:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q8: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q9: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;
						
			case q10: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q11:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q12: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q13: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q14: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q15: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q16: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q17: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q18:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q19:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q20:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q21:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q22: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q23:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						memset(lexeme, 0, 50);
						}
						break;

			case q24: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q25: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q26: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q27: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;

			case q28: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						memset(lexeme, 0, 50);
						break;
			
			case q29: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q30: 	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q31: 	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q32:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q33:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q34:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q35:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q36:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q37:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q38:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q39:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q40:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q41:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q42:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q43:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q44:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q45:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q46:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q47:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q48:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q49:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q50:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q51:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q52:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q53:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q54:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q55:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q56:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q57:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q58:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q59:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q60:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q61:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q62:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q63:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q64:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q65:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q66:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q67:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q68:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q69:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q70:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q71:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q72:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q73:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q74:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q75:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q76:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			case q77:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q78:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q79:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q80:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else
							currchar = q1;
						break;

			case q81:	lexeme[buffcount] = currchar;
						buffcount++;
						nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else  if (is_identifier(nextchar)){
							currstate = q1;
						}else {
							
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							memset(lexeme, 0, 50);
						}
						break;

			default: {
				printf("Lexical Error, with current state of %d\n", currstate);
				reset(&buffcount, &currstate);
				memset(lexeme, 0, 50);
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
	printf("filecontent = -%s-\n", filecontent);
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
