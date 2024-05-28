//written by surekha
//EE11 on 14/5/2024
//this program gives  The number of employees who will not be able to have the breakfast. 
//Including header files
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // Maximum size of the stack
// Structure to represent a stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmptys(Stack *stack) {
    return stack->top == -1;
}
// Function to check if the stack is full
int isFulls(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFulls(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) 
{
    if (isEmptys(stack)) 
        return -1; // Assuming -1 represents an empty stack
    return stack->items[stack->top--];
}

// Structure to represent a queue
typedef struct {
    int items[MAX_SIZE];
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Current size of the queue
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}
// Function to check if the queue is empty
int isEmptyq(Queue *queue) {
    return queue->size == 0;
}
// Function to check if the queue is full
int isFullq(Queue *queue) {
    return queue->size == MAX_SIZE;
}
// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (isFullq(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->items[queue->rear] = value;
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmptyq(queue)) 
        return -1; // Assuming -1 represents an empty queue
    int frontItem = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    queue->size--;
    return frontItem;
}
// Function to check if a value is present in the queue
int isValuePresent(Queue queue, int value) {
    for (int i = 0; i < queue.size; i++) {
        int index = (queue.front + i) % MAX_SIZE; // Calculate index
		//printf("%d %d\n",queue.items[index],value);
        if (queue.items[index] == value)
            return 1; // Value found
        }
    }
    return 0; // Value not found
}
int main() {
    int *arr,n,i,temp;
    Stack stack;
    Queue queue;
    initializeQueue(&queue);
    initializeStack(&stack);
    printf("Enter the number of plates(elements) in the  dosa stack: ");
    scanf("%d",&n);
    arr=calloc(n,sizeof(int));
   printf("Enter the type of dosa in the stack:");
    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
    for(i=n;i>=0;i--)
	    push(&stack,arr[i]);
  
    printf("Enter the type of dosa like by a person in the queue");
    for(i=0;i<n;i++)
    {
	    scanf("%d",&temp);
	     enqueue(&queue, temp);
    }
    while(isValuePresent(queue,stack.items[stack.top]) )
    {
    if(stack.top==queue.front)
    {
	    pop(&stack);
	    dequeue(&queue);
	    n--;

    }
    else
    {
	    temp=dequeue(&queue);
	    enqueue(&queue, temp);
    }
    }
    printf("%d people not able to do break fast\n",n);
    return 0;
}

