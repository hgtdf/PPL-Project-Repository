#include "main.h"

	bool isInTransition = false;

void lexical();

int main (){
	char chararray [] = "++\0"; //file content
	state currstate = 0;
	char currchar;
	int j = 0;
	currchar = chararray [j];
	currstate = transition (currstate, currchar);
	currchar = chararray [j+1];
	currstate = transition (currstate, currchar);

	printf("this is my current state: %d", currstate);
}


void lexical (){
	char chararray [] = "++\0";
	state currstate = 0;
	char currchar;
	int j = 0;
	while (currchar != '\0'){
		currchar = chararray [j];
		switch (currstate){
			case q0: transition(currstate, currchar);
					break;
			case q1: 
			case q2: transition (currstate, currchar);
			case q8: 

			default: {
				printf("Lexical Error");
				break;
				}
	}
		printf("%d", currstate);
	} // end of while
} // end of lexical
