#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char val;
    struct node * next;
} node_t;

node_t * add_char(node_t * curr, char val) {
	node_t * new_node;
	new_node = malloc(sizeof(node_t));
	if (new_node == NULL) 
		printf ("\nMemory allocation error.\n");
	else{
		curr->next = new_node;
		new_node->val = val;
		new_node->next = NULL;
	}
	return new_node;
}
void print_linked_list(node_t * head){
	node_t * tmp_node;
	while (head->next != NULL){
		putchar(head->val);
		tmp_node = head;		
		head = head->next;
		free(tmp_node);
	}
	putchar(head->val);
	free(head);
}

int main() {

	char c;
	node_t * head = NULL;
	node_t * curr = NULL;
		
	head = malloc(sizeof(node_t));
	head->val = getchar();
	head->next = NULL;
	curr = head;
	while ((c = getchar()) != EOF) {	
		curr = add_char(curr, c);
	}

	printf("\nThe String is :\n");
	print_linked_list(head);
return 0;
}
