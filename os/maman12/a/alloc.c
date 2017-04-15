#include <stdio.h>
#include <stdlib.h>

int main() {

   char c, *pointer;
   int i=0;

   pointer = malloc( sizeof(char) );

   while ((c = getchar()) != EOF) {	
	pointer[i++] = c;	
	if ((pointer = realloc( pointer, (i+2) * sizeof(char))) == NULL){
		printf("\nMemmory allocation failure.\n");
		return 1;
	}
   }
pointer[i]=0;	
printf("\nThe String is %d chars:\n%s\n",i ,pointer);
free(pointer);
return 0;
}
