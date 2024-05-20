void showHelp(void)
{
printf("i <string> : inserts the element in <string> 
alphabetically into the list\n");
printf("d <string> : removes the element in <string> from the
list\n");
printf("f <string> : searches the list and returns if the string
is in the list or not.\n");
printf("l : shows the full list\n");
printf("n : returns the number of items in the list\n");
printf("r : removes the full list\n");
printf("h : shows the help menu (this list).\n");
printf("q : end of the program (first remove the list)\n");
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
5
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

