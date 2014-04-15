/*
 *Author:	Abhiraj D
 *Description:	Stack implementation using Linked List or Array
 */


#include<stdio.h>
#include<conio.h>
#define MAX 6
 void initl(struct stackl **);
 int emptyl(struct stackl *);
 int popl(struct stackl **);
 void pushl(struct stackl *,int);
 void printl(struct stackl *p);
 void init(struct stack *);
 int empty(struct stack *);
 int full(struct stack *);
 int pop(struct stack *);
 void push(struct stack *,int);
 void print(struct stack *);
 void array();
 void linkedlist();

 typedef struct stack
 {
 	int data[MAX];
 	int top;
 }stack;

 typedef struct stackl
 {
 	int data;
 	struct stackl *next;
 }stackl;


 int main()
 {
 	int i;
 	char ch;
 	do
 	{
 		printf("\nEnter the method by which stack has to be implemented:");
 		printf("1.Array\n2.Linked List");
 		scanf("%d",&i);
 		switch(i)
 		{
 			case 1:
 			printf("Stack will be implemented using Arrays");
 			array();
 			break;
 			case 2:
 			printf("Stack will be implemented using Linked List");
 			linkedlist();
 			break;
 			default:
 			printf("\nInvalid option.");
 		}
 		printf("\nDo you want to continue?(y/n)");
 		scanf("\n%c",&ch);
 	}
 	while(ch=='y');
 	return 0;
 }



 void array()
 {
 	stack s;
 	int x,op;
 	init(&s);
 	clrscr();
 	do
 	{
 		printf("\n\n1)push\n)2)pop\n3)print\n4)Quit");
 		printf("\nEnter your choice");
 		scanf("%d",&op);
 		switch(op)
 		{
 			case 1:
 			printf("\n enter a number:");
 			scanf("%d",&x);
 			if(!full(&s))
 				push(&s,x);
 			else
 				printf("\nStack is full...");
 			break;
 			case 2:
 			if(!empty(&s))
 			{
 				x=pop(&s);
 				printf("\npopped value= %d",x);
 			}
 			else
 				printf("\nStack is empty...");
 			break;
 			case 3:print(&s);
 			break;
 		}
 	}while(op!=4);
 }
 void init(stack *s)
 {
 	s->top=-1;
 }
 int empty(stack *s)
 {
 	if(s->top==-1)
 		return(1);
 	return(0);
 }
 int full(stack *s)
 {
 	if(s->top==MAX-1)
 		return(1);
 	return(0);
 }
 void push(stack *s,int x)
 {
 	s->top=s->top+1;
 	s->data[s->top]=x;
 }
 int pop(stack *s)
 {
 	int x;
 	x=s->data[s->top];
 	s->top=s->top-1;
 	return(x);
 }
 void print(stack *s)
 {
 	int i;
 	printf("\n");
 	for(i=s->top;i>=0;i--)
 		printf("%d",s->data[i]);
 }

 void linkedlist()

 {
 	typedef struct stackl
 	{
 		int data;
 		struct stackl *next;
 	}stackl;
 	stackl *TOP;
 	int x,op;
 	initl(&TOP);
 	clrscr();
 	do {
 		printf("\n\n1)Push\n2)Pop\n3)Print\n4)Quit");
 		printf("\nEnter Your choice: ");
 		scanf("%d",&op);
 		switch(op)
 		{ case 1:printf("\n enter a number :");
 		scanf("%d",&x);
 		push(&TOP,x);
 		break;
 		case 2:if(!empty(TOP))
 		{ x=pop(&TOP);
 			printf("\npopped value= %d",x);
 		}
 		else
 			printf("\nStack is empty.....");
 		break;

 		case 3:print(TOP);break;
 	}
 }while(op!=4);

}
void initl(stackl **T)
{
	*T=NULL;
}
int emptyl(stackl *TOP)
{
	if(TOP==NULL)
		return(1);
	return(0);
}
void pushl(stackl **T,int x)
{
	stack *P;
	P=(stack *)malloc(sizeof(stack));
	P->data=x;
	P->next=*T;
	*T=P;
}
int popl(stackl **T)
{
	int x;
	stack * P;
	P=*T;
	*T=P->next;
	x=P->data;
	free(P);
	return(x);
}
void printl(stackl *p)
{
	printf("\n");
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
}


