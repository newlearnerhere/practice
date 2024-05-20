//This is written by surekha
//EE10 task1 on 13/5/2024
#include <stdio.h>
#include <stdlib.h> // needed for malloc(), free()
#include <stdio_ext.h>
typedef struct node
{
	int i;
	struct node *next;
} Node;
void showHelp(void);
void add(Node **);
//void removeElement(char *, Node **);
//int isItem(char *, Node *);
//int countItems(Node *);
void removeList(Node **);
void showList(Node *);
//char * trim(char *);
void printCList ( Node* l, const Node* h );
int main(void)
{
	char ch;
	Node *head = NULL;
	//char *pi; // pi = pointer to the instruction
	printf("Test program for a  circular single-linked list.\n");
	printf("\nEnter an instruction (h = help)\n");
	printf("\n> ");
	//__fpurge(stdin);
	while(1)
	{
	__fpurge(stdin);
	ch=getchar();
//	scanf("%d",&integer);
	//printf("%c",ch);
		switch (ch)
		{
			case 'i': add(&head);
				  break;
		//	case 'd': removeElement(trim(pi + 1), &head);
		//		  break;
		//	case 'f': if (isItem(trim(pi + 1), head))
		//			  printf("\"%s\" is in the list.\n", 
		//					  trim(pi+1));
		//		  else
		//			  printf("\"%s\" is NOT in the list.\n",
		//					  trim(pi+1));
		//		  break;
			case 'l': showList(head);
				  break;
		//	case 'n': printf(" Number of list items: %d\n",
		//				  countItems(head));
		//		  break;
		//	case 'r': removeList(&head);
		//		  break;
			case 'h': showHelp();
				  break;
			case 'p': printCList (head->next,head);
                                  printf("%d ", head->i);
			case 'q': return 0;
			default: printf(" Unknown instruction (h = help)\n");
		}
		printf("\n> ");
	//	memset(instruction, '\0', STRLEN);
	//	gets(instruction);
	//	pi = trim(instruction);
	}
	removeList(&head);
	return 0;
	
}
void showHelp(void)
{
	printf("i <string> : inserts the element in <string> alphabetically into the list\n");
//	printf("d <string> : removes the element in <string> from the list\n");
//	printf("f <string> : searches the list and returns if the string is in the list or not.\n");
	printf("l : shows the full list\n");
	printf("p : shows the full list in reverse order\n");
//	printf("n : returns the number of items in the list\n");
//	printf("r : removes the full list\n");
	printf("h : shows the help menu (this list).\n");
	printf("q : end of the program (first remove the list)\n");
}
void add(Node **b)
{
	//printf("This function inserts \"%d\" (sorted) into the list\n", data);
	Node *temp,*newnode,*prev;
	//int data;
	newnode=calloc(1,sizeof(struct node));//allocating memory to new node
	printf("\nEnter integer : ");
	scanf("%d",&newnode->i);
	//printf("%d %d ",newnode->i,data);
//	data=newnode->i;

	temp=*b;
	if(temp==NULL)
	{
		*b=newnode;
		newnode->next=*b;
	}
	else
	{
		
//		temp=*b;
			while(temp->next!=*b)
			{
				temp=temp->next;
			}
			temp->next=newnode; // linking newnode to last node in the list 		
			newnode->next=*b; // newnode->link storing first node addr
	}



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
void printCList(Node* l, const Node* h) {
    if (l == h)
    {
	    // Base case: when reaching the head again
    //printf("%d ", l->i);
        return;
    }
    printCList(l->next, h);  // Recursively call with next node
    printf("%d ", l->i);  // Print data in reverse order
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
