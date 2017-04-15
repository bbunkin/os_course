/*
 ============================================================================
 Name        : par.c
 Author      : Boris Bunkin
 Version     :
 Description : Exercise 1
 Program that tests parenthesis balance in C code files,
 Run with redirected file : ./parenthesis<file.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "par.h"

int main(void) {
	int c; 						/*Checked char from file */
	char line_rec[MAX_LINE];			/* Line record string */
	Position p={0, 1};				/* Position stuck : line and column */
	int state = OUT;				/* State of check (IN-TEXT, IN-COMMENT, OUT, ERRORED-line... )*/
	int curl_brackets_cnt=0;			/* Counter of curly brackets */
	DataAndPosition dp;				/* Stuck to save an opened bracket (data , position stuck) */
	Stack inlineStack;				/* Stack of opened brackets */

	stackInit(&inlineStack);

	while ((c = fgetc(stdin)) != EOF) {
		p.col++;
		if (p.col >= MAX_LINE)
		{
			if (state != ERRORED_LINE){
				printf(RED "ERROR: Line %d longer then max %d.\n" RESET, p.line, MAX_LINE);
				line_rec[p.col-1] = '\0';
			}
			state = ERRORED_LINE;
		}
		else
			line_rec[p.col-1] = c;

		switch (state){
			case OUT:{ /* not in string nor in comment - checking brackets */
				switch (c){
					case '\n':{
						checkLine(&inlineStack, &p, line_rec);
						break;}
					case '/':
						state = LEFT_SLASH;
						break;
					case '\"':
						state = IN_STRING;
						break;

					case '{':
						curl_brackets_cnt++;
						state = CURL_BRACKET;
						break;
					case '}':
						if (curl_brackets_cnt > 0){
							curl_brackets_cnt--;
							state = CURL_BRACKET;
						}
						else{
							printf(RED "ERROR: Line %d curly bracket closed at column %d without opened.\n" RESET
										, p.line, p.col);
							curl_brackets_cnt = 0;
							state = ERRORED_LINE;
						}
						break;
					case '(':
				    case '[':
				    	dp.data = c;
				    	dp.p = p;
						push(&inlineStack, &dp);
						break;
					case ')': /* Close Brackets Cases */
					case ']':
						state = checkBrackets(&inlineStack, &p, c);
						break;
					}}break;
			case LEFT_SLASH: /* Check for enterring C comment*/
				if (c == '*')
					state = IN_COMMENT;
				else
					state = OUT;
				break;
			case IN_COMMENT: /* In comment wait for / to exit */  
				if (c == '*')
					state = RIGHT_STAR;
				break;
			case RIGHT_STAR: /* Suspect end of comment state */
				if (c == '/')
					state = OUT;	
				else if (c != '*')
					state = IN_COMMENT;
				break;
			case IN_STRING: /* In string state - wait for " to exit */
				if (c == '\"')
					state = OUT;
				break;
			case CURL_BRACKET: /*Curly bracket state - check if last char in the line else prints error */
				if (c != '\n') {
					printf(RED "ERROR: Line %d, curly bracket not last in line.\n" RESET, p.line);
					state = ERRORED_LINE;
					} 
				else{
					state = OUT;
					checkLine(&inlineStack, &p, line_rec);
					}
				break;
			case ERRORED_LINE: /* Found error in the line - record the line till the end and prints the errored line*/
				if (c == '\n') {
					line_rec[(p.col>MAX_LINE)?MAX_LINE-1:p.col-1] = '\0';
					printf(BLU "\t%s\n" RESET, line_rec);
					newLine(&inlineStack, &p);
					state = OUT;
					}
				break;
			}
		}
	if (curl_brackets_cnt>0)
		printf(RED "ERROR: %d curly brackets were opened without closing.\n" RESET , curl_brackets_cnt);
	return 0;
}

