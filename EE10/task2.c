//This is written by surekha 
//EE10 Task2 on 13/5/2024
#include <stdio.h>
#include <stdlib.h> // needed for malloc(), free()
#include <stdio_ext.h>
typedef struct node
{
	int i;
	struct node *next,*prev;//holds the address previous node and next node
} Node;
void showHelp(void);//print the list of options
void add(Node **);//instert the node
void removeList(Node **);//delete all nodes in the list
void showList(Node *);//print all the elements in the list
void printCList ( Node* l, const Node* h );//print all the elements in the list in reverse order
int main(void)
{
	char ch;
	Node *head = NULL;
	printf("Test program for a  circular single-linked list.\n");
	printf("\nEnter an instruction (h = help)\n");
	printf("\n> ");
	while(1)
	{
	__fpurge(stdin);
	ch=getchar();//read the option
		switch (ch)
		{
			case 'i': add(&head);
				  break;
			case 'l': showList(head);
				  break;
			case 'h': showHelp();
				  break;
			case 'p': printCList (head,head);
                                  printf("%d \n", head->i);
				  break;
			case 'q': return 0;
			default: printf(" Unknown instruction (h = help)\n");
		}
		printf("\n> ");
	}
	removeList(&head);
	return 0;
	
}
void showHelp(void)
{
	printf("i <string> : inserts the element in <string> alphabetically into the list\n");
	printf("l : shows the full list\n");
	printf("p : shows the full list in reverse order\n");
	printf("h : shows the help menu (this list).\n");
	printf("q : end of the program (first remove the list)\n");
}
void add(Node **b)
{
	Node *temp,*newnode;
	newnode=calloc(1,sizeof(struct node));//allocating memory to new node
	printf("\nEnter integer : ");
	scanf("%d",&newnode->i);//read the newnode value from stdin
	temp=*b;
	if(temp==NULL)
	{
		*b=newnode;
		newnode->prev=*b;
		newnode->next=*b;
	}
	else
	{
		
			while(temp->next!=*b)
			{
				temp=temp->next;
			}
			temp->next=newnode; // linking newnode to last node in the list 		
			newnode->next=*b; // newnode->link storing first node addr
			newnode->prev=temp;//storing the previous node address
	}
	(*b)->prev=newnode;



}
void showList(Node *b)
{
	Node *temp=b;
	if (b == NULL)
	{
		printf("The list is EMPTY\n");
	}
	else
	{
		printf("The list:\n");
		while (temp->next !=b)
		{
			printf("%d ", temp->i);
			temp = temp->next;
		}
			printf("%d ", temp->i);
	}
	printf("\n\n");
}
void printCList(Node* temp, const Node* h) {
	if (h == NULL)
	{
		printf("The list is EMPTY\n");
	}
	else
	{
		printf("The list:\n");
		temp=temp->prev;
		do
		{
			printf("%d ", temp->i);
			temp = temp->prev;
		}while(temp!=h);//excute until it comes tho starting node

	}
}
void removeList(Node **b)
{
        Node *temp=*b,* p = *b;
        while (p != temp)
        {
                *b = p->next;
                free(p);
                p = *b;
        }
}
