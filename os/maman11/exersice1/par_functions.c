/*
 * par_functions.c
 *
 *      Author: borisb
 */

#include <stdio.h>
#include <stdlib.h>
#include "par.h"

/* Init the stack gets pointer to Stack stuck retuns void */
void stackInit(Stack* S) {
	S->size = 0;
}

/* Push the data (open bracket char and it position) to char 
 get Stack struct, DataAndPosition struct returns void */ 
void push(Stack* S, DataAndPosition* DP) {
	S->dp[S->size++] = *DP;
}

/* Pop from the stack, get stack struct returns DataAndPosition struct*/
DataAndPosition pop(Stack* S) {
	return S->dp[--S->size];
}

/*Close bracket check, get stack, current position and closing bracket char returns state (OUT / ERRORED_LINE)*/
int checkBrackets(Stack* S, Position* p, int c) {
	DataAndPosition opened;
	if (S->size > 0) {
		opened = pop(S);
		if ((opened.data == '(' && c == ')') || (opened.data == '[' && c == ']'))
			return OUT;
		else {
			printf(RED "ERROR: Line %d , asymmetric brackets, opened %c at column %d when closed %c at column %d.\n" RESET
					       ,p->line, opened.data, opened.p.col, c, p->col);
			return ERRORED_LINE;
		}}
	else {
		printf(RED "ERROR: Line %d asymmetric brackets, closed %c at column %d without opened.\n" RESET
				, p->line, c, p->col);
		return ERRORED_LINE;
	}
}

/*Init stack and position update gets stack struct, position struct returns void */
void newLine(Stack* S, Position* p) {
	p->col=0;
	p->line++;
	stackInit(S);
}

/* End line check if stack not empty prints error and start a new line
gets Stack struct, Position struct, line string pointer returns void */
void checkLine(Stack* S, Position *p, char line_rec[]){
	DataAndPosition dp;
	if (S->size > 0){
		dp = pop(S);
		line_rec[p->col-1] = '\0';
		printf(RED "ERROR: Line %d column %d bracket \"%c\" not closed.\n\t" BLU "%s\n" RESET
					,dp.p.line, dp.p.col, dp.data, line_rec);
	}
	newLine(S, p);
}

