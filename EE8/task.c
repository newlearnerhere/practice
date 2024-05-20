#include <stdio.h>
#include <string.h> // needed for strcpy() and strcmp()
#include <stdlib.h> // needed for malloc(), free()
#define STRLEN 64
int cnt=0;
typedef struct node
{
	char name[STRLEN];
	struct node *next;
} Node;
void showHelp(void);
void add(char *, Node **);
void removeElement(char *, Node **);
int isItem(char *, Node *);
int countItems(Node *);
void removeList(Node **);
void showList(Node *);
char * trim(char *);
int main(void)
{
	char instruction[STRLEN];
	Node *head = NULL;
	char *pi; // pi = pointer to the instruction
	printf("Test program for a single-linked list.\n");
	printf("\nEnter an instruction (h = help)\n");
	printf("\n> ");
	memset(instruction, '\0', STRLEN);
	gets(instruction);
	pi = trim(instruction);
	while (*pi != 'q')
	{
		switch (*pi)
		{
			case 'i': add(trim(pi + 1), &head);
				  break;
			case 'd': removeElement(trim(pi + 1), &head);
				  break;
			case 'f': if (isItem(trim(pi + 1), head))
					  printf("\"%s\" is in the list.\n", 
							  trim(pi+1));
				  else
					  printf("\"%s\" is NOT in the list.\n",
							  trim(pi+1));
				  break;
			case 'l': showList(head);
				  break;
			case 'n': printf(" Number of list items: %d\n",
						  countItems(head));
				  break;
			case 'r': removeList(&head);
				  break;
			case 'h': showHelp();
			case 'q': break;
			default: printf(" Unknown instruction (h = help)\n");
		}
		printf("\n> ");
		memset(instruction, '\0', STRLEN);
		gets(instruction);
		pi = trim(instruction);
	}
	removeList(&head);
	return 0;
}
void showHelp(void)
{
	printf("i <string> : inserts the element in <string> alphabetically into the list\n");
	printf("d <string> : removes the element in <string> from the list\n");
	printf("f <string> : searches the list and returns if the string is in the list or not.\n");
	printf("l : shows the full list\n");
	printf("n : returns the number of items in the list\n");
	printf("r : removes the full list\n");
	printf("h : shows the help menu (this list).\n");
	printf("q : end of the program (first remove the list)\n");
}
void add(char *s, Node **b)
{
	printf("This function inserts \"%s\" (alphabetically) into the list\n", s);
	Node *temp,*prev,*newnode;
	newnode=calloc(1,sizeof(struct node));//allocating memory to new node
	strcpy(newnode->name,s);
	temp=*b;
	if(temp==NULL)
	{
		*b=newnode;
		newnode->next=NULL;
	}
	else
	{
		
		if(strcmp(temp->name,s)>0)
		{
			*b=newnode;
			newnode->next=temp;
		}
		else
		{
		prev=temp;
		while(temp)
		{
		//	printf("loop %s %s \n",temp->name,s);
			if(strcmp(temp->name,s)>0)
			{
		//		printf("cmp\n");
				prev->next=newnode;
				newnode->next=temp;
				break;
			}
			prev=temp;
			temp=temp->next;

		}
		if(temp==NULL)
		{
		prev->next=newnode;
		newnode->next=NULL;
		}
		}

	}



}
void removeElement(char *s, Node **b)
{
	printf("This function removes \"%s\" from the list\n", s);
	Node *temp,*prev;
	temp=*b;
	if(strcmp(temp->name,s)==0)
	{
		(*b)=temp->next;
		free(temp);
	}
	else
	{
		prev=temp;
		while(temp)
		{
		//	printf("loop %s %s \n",temp->name,s);
			if(strcmp(temp->name,s)==0)
			{
		//		printf("cmp\n");
				prev->next=temp->next;
				free(temp);
				break;
			}
			prev=temp;
			temp=temp->next;

		}
	}
}
int isItem(char *s, Node *b)
{
	Node *temp;
	temp=b;
	printf("This function searches \"%s\" in the list\n", s);
	while(temp)
	{
		if(strcmp(temp->name,s)==0)
			return 1;
		temp=temp->next;
	}
	return 0;
}
int countItems(Node *b)
{
	cnt=0;
	Node *temp;
	temp=b;
	printf("This function returns the number of items in the list\n");
	while(temp)
	{
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
void removeList(Node **b)
{
	Node * p = *b;
	while (p != NULL)
	{
		*b = p->next;
		free(p);
		p = *b;
	}
}
void showList(Node *b)
{
	if (b == NULL)
	{
		printf("The list is EMPTY\n");
	}
	else
	{
		printf("The list:\n");
		while (b != NULL)
		{
			printf("%s ", b->name);
			b = b->next;
		}
	}
	printf("\n\n");
}
char * trim(char *s)
{
	while (*s == ' ') s++;
	return s;
}
