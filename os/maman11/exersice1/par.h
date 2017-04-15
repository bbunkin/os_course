/*
 * par.h
 *      Author: Boris Bunkin
 */

#ifndef PAR_H_
#define PAR_H_

enum status {
	OUT,
	IN_STRING,
	LEFT_SLASH,
	IN_COMMENT,
	RIGHT_STAR,
	END_LINE,
	ERRORED_LINE,
	CURL_BRACKET
};

#define MAX_LINE 100
#define RED   "\x1B[31m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

/* Struct holds char position */
typedef struct Position {
	int col;
	int line;
} Position;

/* Struct holds position and the bracket char*/
typedef struct DataAndPosition {
	char data;
	Position p;
} DataAndPosition;

/*struct holds stack pointer and size*/
typedef struct Stack {
	DataAndPosition dp[MAX_LINE];
	int size;
} Stack;

/* Init the stack gets pointer to Stack stuck retuns void */
void stackInit(Stack* S);

/* Push the data (open bracket char and it position) to char 
 get Stack stuck, DataAndPosition stuck returns void */ 
void push(Stack* S, DataAndPosition* DP);

/* Pop from the stack, get stack stuck returns DataAndPosition stuck*/
DataAndPosition pop(Stack* S);

/*Close bracket check, get stack, current position and closing bracket char returns state (OUT,ERRORED_LINE)*/
int checkBrackets(Stack* S, Position* p, int c);

/*Init stack and position update gets stack stuck, position stuck returns void */
void newLine(Stack* S, Position* p);

/* End line check if stack not empty prints error and start a new line
gets Stack stuck, Position stuck, line string poiunter returns void */
void checkLine(Stack* S, Position *p, char line_rec[]);

#endif /* PAR_H_ */

