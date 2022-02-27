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
						lexeme[50] = 0;
						break;
						
			case q2: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q3: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q4: 	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q5:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q6:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q7:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q8: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q9: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;
						
			case q10: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q11:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q12: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q13: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q14: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q15: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q16: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q17: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q18:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q19:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q20:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q21:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q22: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q23:	nextchar = getNextChar();
						if (find_dest(currstate, nextchar) == true){
						currchar = getNonBlank();
						currstate = get_dest();
						}else {
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						}
						break;

			case q24: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q25: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q26: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q27: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
						break;

			case q28: 	lexeme[buffcount] = currchar;  //++
						buffcount++;
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						currchar = ' ';
						nextchar = ' ';
						lexeme[50] = 0;
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
							printf("So nag accept ako here... Line 365\n");
							accept(lexeme, buffcount);
							reset(&buffcount, &currstate);
							currchar = ' ';
							nextchar = ' ';
							lexeme[50] = 0;
						}
						break;

			default: {
				printf("Lexical Error, with current state of %d\n", currstate);
				reset(&buffcount, &currstate);
				lexeme[50] = 0;
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
	//printf("filecontent = -%s-\n", filecontent);
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
