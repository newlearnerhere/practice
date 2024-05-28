//written by surekha
//SRA12 or takeaway1 on 15/5/2024
//This program is creating a matrix and transposing it by using linked lists
//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//structure of node in the martix
typedef struct node {
    int row, column;
    double value;
    struct node* rowPtr;
    struct node* colPtr;
} node;
//structure of matrix
typedef struct matrix {
    node** rowList;// rowList is a pointer to the array of rows
    node** columnList;// column list is a pointer to the array of columns.
    int rows, columns;// store the number of rows and columns of the matrix
} matrix;


matrix* createMatrix(int rows, int columns);
void insertNodeToBeginning(node* ptr, matrix* M);
int duplicateValue(matrix* M, double value);
int resize(matrix** M);
int transpose(matrix** M);
void insertnode(int,int,matrix *);


matrix* createMatrix(int rows, int columns) {
    matrix* M = (matrix*)malloc(sizeof(matrix));
    if (M) {
        M->rows = rows;
        M->columns = columns;
        M->rowList = (node**)malloc(rows * sizeof(node*));
        M->columnList = (node**)malloc(columns * sizeof(node*));
        for (int i = 0; i < rows; i++)
            M->rowList[i] = NULL;
        for (int j = 0; j < columns; j++)
            M->columnList[j] = NULL;
    }
    return M;
}

void insertNodeToBeginning(node* ptr, matrix* M) {
    if (M->rowList[ptr->row] == NULL) {
        M->rowList[ptr->row] = ptr;
        ptr->rowPtr = NULL;
    } else {
        ptr->rowPtr = M->rowList[ptr->row];
        M->rowList[ptr->row] = ptr;
    }

    if (M->columnList[ptr->column] == NULL) {
        M->columnList[ptr->column] = ptr;
        ptr->colPtr = NULL;
    } else {
        ptr->colPtr = M->columnList[ptr->column];
        M->columnList[ptr->column] = ptr;
    }
}

int duplicateValue(matrix* M, double value) {
    for (int i = 0; i < M->columns; i++) {
        node* curr = M->columnList[i];
        while (curr != NULL) {
            if (curr->value == value)
                return 1;
            curr = curr->colPtr;
        }
    }
    return 0;
}

int resize(matrix** M) {
    matrix* newM = createMatrix((*M)->rows * 2, (*M)->columns * 2);
    if (newM) {
        for (int i = 0; i < (*M)->rows; i++) {
            node* curr = (*M)->rowList[i];
            while (curr != NULL) {
                insertNodeToBeginning(curr, newM);
                curr = curr->rowPtr;
            }
        }
        free((*M)->rowList);
        free((*M)->columnList);
        free(*M);
        *M = newM;
        return 1;
    }
    return 0;
}

int transpose(matrix** M) {
    matrix* transposed = createMatrix((*M)->columns, (*M)->rows);
    if (transposed) {
        for (int i = 0; i < (*M)->rows; i++) {
            node* curr = (*M)->rowList[i];
            while (curr != NULL) {
                node* newNode = (node*)malloc(sizeof(node));
                if (newNode) {
                    newNode->row = curr->column;
                    newNode->column = curr->row;
                    newNode->value = curr->value;
                    insertNodeToBeginning(newNode, transposed);
                }
                curr = curr->rowPtr;
            }
        }
        free((*M)->rowList);
        free((*M)->columnList);
        free(*M);
        *M = transposed;
        return 1;
    }
    return 0;
}
void insertnode(int i,int j,matrix *M)
{
	puts("enter the value to enter: ");
	double val;
	__fpurge(stdin);
	scanf("%lf",&val);
	node* node1 = (node*)malloc(sizeof(node));
	node1->row = i;
	node1->column = j;
	node1->value = val;
    	insertNodeToBeginning(node1, M);
}
void print(matrix* M) {
    printf("Matrix:\n");
    for (int i = 0; i < M->rows; i++) {
        for (int j = 0; j < M->columns; j++) {
            node* curr = M->rowList[i];
            int found = 0;
            while (curr != NULL) {
                if (curr->column == j) {
                    printf("%.2lf\t", curr->value);
                    found = 1;
                    break;
                }
                curr = curr->rowPtr;
            }
            if (!found)
                printf("0.0\t");
        }
        printf("\n");
    }
}
int main()
{
    int rows, columns;
    puts("Enter the number of rows and columns:");
    scanf("%d %d", &rows, &columns);

    matrix* M = createMatrix(rows, columns);

    puts("enter all the nodes: ");
    for(int i=0;i<rows;i++)
    {
	    for(int j=0;j<columns;j++)
	    {
		    insertnode(i,j,M);
	    }
    }
    char ch;
    while(1)
    {
	    puts("d:duplicatevalue, r:resize, t:transpose e:exit p:print");
	    __fpurge(stdin);
	    ch=getchar();
	    switch(ch)
	    {
		    case 'p':print(M);
			     break;
		    case 'd':double testValue;
			     printf("enter test value: ");
			     scanf("%lf",&testValue);
			     if (duplicateValue(M, testValue))
				     printf("Duplicate value %lf found.\n", testValue);
			     else
				     printf("Duplicate value %lf not found.\n", testValue);
			     break;
		    case 'r':if (resize(&M))
				     printf("Matrix resized successfully.\n");
			     else
				     printf("Failed to resize matrix.\n");
			     break;
		    case 't':
			     if (transpose(&M))
				     printf("Matrix transposed successfully.\n");
			     else
				     printf("Failed to transpose matrix.\n");
			     break;
		    case 'e':
			     for (int i = 0; i < rows; i++) {
				     node* curr = M->rowList[i];
        				while (curr != NULL) {
            					node* temp = curr;
            					curr = curr->rowPtr;
            					free(temp);
        				}
    				}
    				free(M->rowList);
    				free(M->columnList);
    				free(M);
				exit(0);
		    default: printf("choose from the above opt\n");
	    }
    }
}

