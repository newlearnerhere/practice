#include"header.h"
#define STRLEN 64
typedef struct node
{
char name[STRLEN];
struct node *next;
}Node;
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
