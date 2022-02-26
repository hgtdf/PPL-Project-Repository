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
int pos = 0;

int checkfile();
void openfile();
void lexical();
char getNonBlank();
char getChar();
void processfile();
int transition(state, char);
bool find_dest(state , char);
int get_dest();
void accept();
void reset();

int main (){
	processfile();
	lexical();
	free(filecontent);
} // end of main

void lexical (){
	int i = 0;
	currchar = getNonBlank();
	printf("Pumasok ako kay lexical. With state %d currchar %c and lexeme of: %s\n", currstate, currchar, lexeme);
	while (i < counter+1){
		printf("Pumasok ako sa while. With state %d currchar %c and lexeme of: %s\n", currstate, currchar, lexeme);
		switch (currstate){
			case q0: 
					printf("Pumasok ako sa case 0\n");
					currstate = transition(currstate, currchar);
					printf("naghanap ako ng transition. at nakuha ko si q%d\n", currstate);
					lexeme[buffcount] = currchar;
					printf("ipinasok ko si currchar: %c sa lexeme[%d] kaya ang laman na niya ay: -%s-\n", currchar, buffcount, lexeme);
					buffcount++;
					break;
			case q1: 
			case q2: currchar = getNonBlank();
					printf("ngayon ang nextchar ko ay: %c, at ang state ko ay q%d\n", currchar, currstate);
					if (find_dest(currstate, currchar) == true){
						lexeme[buffcount] = currchar;
						buffcount++;
						currstate = get_dest();
					}else {
						printf("ang next char ay wala sa transition kaya back to state 0 na at accept na muna ako\n");
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
					}
					break;
			case q5: printf("Pumasok ako sa case 5\n");
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						break;
			case q8: printf("Pumasok ako sa case 8\n");
						accept(lexeme, buffcount);
						reset(&buffcount, &currstate);
						lexeme[50] = 0;
						break;

			default: {
				printf("Lexical Error");
				reset(&buffcount, &currstate);
				lexeme[50] = 0;
				break;
				}
		} // end of switch
		i++;
		printf("q%d when exiting switch\n", currstate);
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
	
	//printf("filecounter[%d]\n", counter);
	//copy contents of file to *filecontent
	filecontent = malloc (counter * sizeof(char) + 1);
	fread (filecontent, counter * sizeof(char), 1, fileptr);
	filecontent[counter] = '\0';
	//printf("filecontent = -%s-\n", filecontent);
	fclose(fileptr);
}

char getNonBlank(){
	while (isspace(filecontent[pos])){
		printf("the content of filecontent[%d] is : %c\n", pos, filecontent[pos]);
		pos++;
	}
	return getChar();
} // end of getNonBlank

char getChar(){
	int p = pos;
	printf("kinuha ko si filecontent[%d]\n", p);
	pos++;
	return filecontent[p];
}
