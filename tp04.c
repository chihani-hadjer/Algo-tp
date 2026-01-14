#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//_______________Stack____________________

//Stack (Pile) Node
typedef struct SNode {
	char data;
	struct SNode *next;
}SNode;

//Push -> ajouter un élément dans la pile (Stack)
SNode* push(SNode *top, char ch) {
	SNode *newNode = (SNode*)malloc(sizeof(SNode));
	newNode->data = ch;
	newNode -> next = top;
	return newNode;
} 
//Pop -> retirer un élément dans la pile (Stack)
SNode* pop(SNode *top, char *value) {
	if(top == NULL)
	return NULL;
	
	*value = top->data;
	SNode *temp = top;
	top = top->next;
	free(temp);
	
	return top;
}

//_______________Queue______________________

//Queue (File) Node
typedef struct QNode {
	char data;
	struct QNode *next;
}QNode;

typedef struct {
	QNode *front;
	QNode *rear;
}Queue;
//Enqueue -> ajouter un élément à la file (Queue)
void enqueue(Queue *q,char ch) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = ch;
	newNode->next =NULL;
	
	if (q->rear == NULL) {
		q->front = q->rear = newNode;
	}else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}
//Dequeue -> retirer un élément de la file (Queue)
char dequeue(Queue *q) {
	if(q->front == NULL)return'\0';
	
	QNode *temp = q->front;
	char ch = temp->data;
	
	q->front = q->front->next;
	if(q->front == NULL)q->rear = NULL;
	
	free(temp);
	return ch;
}

//_______________Main Prigram_______________________
int main() {
	char str[100];
	SNode *top = NULL;
	Queue q;
	q.front =q.rear =NULL;
	
	printf("enter a string: ");
	fgets(str,sizeof(str), stdin);
	
	//Remplir la pile et la file (stack & queue)
	for(int i = 0; str[i] != '\0';i++) {
		if(isalpha(str[i])) {        //Ignorer les espaces
		char ch = toupper(str[i]);  //Majuscule
		top = push(top,ch);         //stack
		enqueue(&q,ch);             //Queue
		}
	}
//Comparaison
char stackChar, queueChar;
int palindrome = 1;

while (top != NULL && q.front != NULL) {
	top = pop(top, &stackChar);
	queueChar = dequeue(&q);
	
	if (stackChar != queueChar){
		palindrome =0;
		break;
	}
}

if(palindrome)
	printf("Palindrome\n");
else
	printf("Not Palindrome\n");

return 0;
}
