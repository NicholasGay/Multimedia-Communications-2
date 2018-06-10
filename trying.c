// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// A linked list node
struct payload{
    uint8_t value;
};
struct Node
{
struct payload data;
struct Node *next;
};

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}

	/* 2. allocate new node */
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

	/* 3. put in the data */
	new_node->data.value = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data.value = new_data;

	/* 3. This new node is going to be the last node, so make next of
		it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
while (node != NULL)
{
	printf(" %d ", node->data.value);
	node = node->next;
}
}


void sort(struct Node **head_ref){

    struct Node *Prev = *head_ref;
    struct Node *Curr = Prev -> next;

    if(Prev->data.value > Curr->data.value){
            printf("Start Swaping %d and %d\n",Curr->data.value, Prev->data.value);
            struct Node *temp = Curr->next;
            (*head_ref) = Curr;
            Curr->next = Prev;
            Prev->next = temp;
        }
    while(Curr->next != NULL){

        struct Node *Next = Curr -> next;
        if(Curr->data.value > Next->data.value){
            printf("Swaping %d and %d\n",Curr->data.value, Next->data.value);
            Prev->next = Next;
            Curr->next = Next->next;
            Next->next = Curr; 

            Prev = *head_ref;
            Curr = Prev -> next;
            if(Prev->data.value > Curr->data.value){
                printf("Start Swaping %d and %d\n",Curr->data.value, Prev->data.value);
                struct Node *temp = Curr->next;
                (*head_ref) = Curr;
                Curr->next = Prev;
                Prev->next = temp;
        }

        }
        Curr =Curr->next;
        Prev = Prev->next;
        }
        
    }

/* Driver program to test above functions*/
int main()
{
/* Start with the empty list */
struct Node* head = NULL;
uint8_t array[9] = {5,4,2,3,1,6,9,8,7};

for(int i = 0; i<9;i++){
    append(&head,array[i]);
}


printf("\n Created Linked list is: ");

printList(head);

sort(&head);
printList(head);

return 0;
}
