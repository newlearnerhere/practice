//written by surekha
//EE11 task2 on 14/5/2024 
//including header files
//this program prints the number of nodes in the sub tree
#include<stdio.h>
//structure of tree
struct tree
{
	int data;
	struct tree *right,*left;
};
struct tree* createnode(int data) {
    struct tree* newNode = (struct tree*)malloc(sizeof(struct tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countnodes(struct tree* root) {
    if (root == NULL)
        return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
int main()
{
	struct tree *root=NULL,*temp=NULL;
	int n,i,l,r;
	root=createnode(1);
	temp=root;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the node values: ");
	scanf("%d %d",&l,&r);
	if(l)
	{
		if(i==0)
		root->left=createnode(l);
		else if(i==1)
			root->left->left=createnode(l);
		else if(i==2)
			root->left->left->left=createnode(l);
		else if(i==3)
			root->left->left->left->left=createnode(l);
		else if(i==4)
			root->left->left->left->left->left=createnode(l);
	}
	if(r)
        {
                if(i==0)
                root->right=createnode(l);
                else if(i==1)
                        root->right->right=createnode(l);
                else if(i==2)
                        root->right->right->right=createnode(l);
                else if(i==3)
                        root->right->right->right->right=createnode(l);
                else if(i==4)
                        root->right->right->right->right->right=createnode(l);
        }
	}
	printf("%d",countnodes(temp));
	while(temp->left)
	{
		printf("%d",countnodes(temp->left));
		temp=temp->left;

	}
	temp=root;
	while(temp->right)
	{
		printf("%d",countnodes(temp->right));
		temp=temp->right;
	}
}



