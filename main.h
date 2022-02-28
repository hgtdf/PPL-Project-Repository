#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int i=0;
int k=0;
FILE *fptr = NULL;

void accept();
void reset();

typedef enum states{
	q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10,
	q11, q12, q13, q14, q15, q16, q17, q18, q19, q20,
	q21, q22, q23, q24, q25, q26, q27, q28, q29, q30,
	q31, q32, q33, q34, q35, q36, q37, q38, q39, q40,
	q41, q42, q43, q44, q45, q46, q47, q48, q49, q50,
	q51, q52, q53, q54, q55, q56, q57, q58, q59, q60,
	q61, q62, q63, q64, q65, q66, q67, q68, q69, q70,
	q71, q72, q73, q74, q75, q76, q77, q78, q79, q80,
	q81, q82, q83, q84, q85, q86, q87, q88, q89, q90,
	q91, q92
}state;

struct transition {
	state src_state;
	char reqChar;
	state dest_state;
};

struct transition transition_table [] = {
    {q0, '+', q2}, {q2, '+', q8}, {q2, '=', q12},
    {q0, '-', q3}, {q3, '-', q9}, {q3, '=', q13},
    {q0, '*', q4}, {q4, '=', q14}, {q4, '/', q85},
    {q0, '/', q5}, {q5, '/', q10}, {q5, '=', q15}, {q5, '-', q83}, {q5, '*', q84},
    {q0, '%', q6}, {q6, '=', q16},
    {q0, '^', q7}, {q7, '=', q17},
    {q0, '=', q11}, {q11, '=', q25},
    {q0, '<', q18}, {q18, '=', q27},
    {q0, '>', q19}, {q19,'=', q28},
    {q0, '!', q20}, {q20, '=', q26},
    {q0, '&', q21}, {q21, '&', q22},
    {q0, '|', q23}, {q23, '|', q24},
    {q0, 'i', q29}, {q29, 'n', q30}, {q30, 't', q31},
    {q0, 'f', q32}, {q32, 'l', q33}, {q33, 'o', q34}, {q34, 'a', q35}, {q35, 't', q36},
    {q0, 'c', q37}, {q7, 'h', q38}, {q38, 'a', q39}, {q39, 'r', q40},
    {q0, 'b', q41}, {q41, 'o', q42}, {q42, 'o', q43}, {q43, 'l', q44},
    {q0, 'n', q45}, {q45, 'u', q46}, {q46, 'l', q47}, {q47, 'l', q48},
    {q0, 't', q49}, {q49, 'r', q50}, {q50, 'u', q51}, {q51, 'e', q52},
    {q0,'f', q32}, {q32, 'a', q53}, {q53, 'l', q54}, {q54, 's', q55}, {q55, 'e', q56},
    {q0, 'f', q32}, {q32, 'o', q57}, {q57, 'r', q58},
    {q0, 'w', q59}, {q59, 'h', q60}, {q60, 'i', q61}, {q61, 'l', q62}, {q62, 'e', q63},
    {q0, 'i', q29}, {q29, 'f', q64},
    {q0, 'e', q65}, {q65, 'l', q66}, {q66, 's', q67}, {q67, 'e', q68},
    {q0, 'p', q69}, {q69, 'r', q70}, {q70, 'i', q71}, {q71, 'n', q72}, {q72, 't', q73},
    {q0, 's', q74}, {q74, 'c', q75}, {q75, 'a', q76}, {q76, 'n', q77},
    {q0, 'h', q78}, {q78, 'e', q79}, {q79, 'n', q80}, {q80, 'c', q81}, {q81, 'e', q82},
	{q0, ',', q86},
	{q0, ';', q87},
	{q0, 39, q88},
	{q0, 34, q89},
	{q0, '(', q90},
	{q0, ')', q91}
};

bool find_dest(state srcstate, char currchar){//checks if specified transition is present in transitions_table[]
    //printf("ako si find dest, tinawag mo ako ang laman ng i ko ngayon ay %d hinahanap ko si srcstate: %d, at si currchar: %c\n", i, srcstate, currchar);
	if (srcstate == transition_table[i].src_state && currchar == transition_table[i].reqChar){
		return true;
	}
	else if (i == 84){ // The number here, refers to transition_table[] size
		i=0;
		//printf("wala parin talaga... \n");
		return false;
	}else
		i++;
		find_dest(srcstate, currchar);
}

void accept (char lexeme[], int buffcount){
	int i;
    for (i=0; i<buffcount; i++){
        fprintf(fptr, "%c", lexeme[i]);
    }
    fprintf(fptr, "\n");
}

void reset (int *buffcount, state *currstate){
	*currstate = q0;
	*buffcount = 0;
}

int get_dest(){	//gets the dest_state of the specified transition
	int tobereturned = transition_table[i].dest_state;
	i = 0;
	return tobereturned;
}

int transition (state currstate, char currchar){ //function for transitioning states into another state
	if (find_dest(currstate, currchar) == true){
		currstate = get_dest();
		return currstate;
	}else{
		return 1;
	}
}

bool isq0_identifier(char nextchar){
	if (isalpha(nextchar) || nextchar == 95){
		return true;
	} else 
		return false;
}

bool is_identifier(char nextchar){
	if (isalnum(nextchar) || nextchar == 95){
		return true;
	} else 
		return false;
}

bool isq0_digit(char nextchar){
	if (isdigit(nextchar) || nextchar == '.'){
		return true;
	}else
		return false;
}

int checkfile (char *plfile){ // check for file's filetype

    char extn[] = ".simp";
    int len1 = strlen(plfile);
    int len2 = strlen(extn);
    int found = 0;
    
    if(len1 >= len2) {
        for(int s1=0, s2=0; s1<len1; s1++) {
            do {
                if(plfile[s1] == extn[s2]) {
                    if(++found == len2) return 1;
                    s1++;
                    s2++;
                }
                else {
                s1 -= found; 
                found = 0; 
                s2 = 0;
                }
            } while(found);
        }
        printf("File extension not recognized.\n");
        exit(1);
    }
    else {
        printf("File invalid.");
        exit(1);
    }
}


/*
char find_Tokens (state fstate){
	int a;
	if (fstate == token_table[k].final_state){
		a = k;
		k = 0;
		return token_table[a].token;
	}else{
		k++;
		find_Tokens(fstate);
	}
}

char find_Desc (state fstate){
	int a;
	if (fstate == token_table[k].final_state){
		a = k;
		k = 0;
		return token_table[a].token_desc;
	}else{
		k++;
		find_Desc(fstate);
	}
}*/