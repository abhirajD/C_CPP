/*
 *Author:	Abhiraj D
 *Description:	Postfix expression evaluator using stack.
 */


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*top;


void push(int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;

	if(top == NULL)
	{
		top=temp;
		top->next=NULL;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

int pop()
{
	struct node *var=top;
	int temp;
	if(var!=NULL)
	{
		temp=top->data;
		top = top->next;
		free(var);
	}
	else
	{
		printf("Stack Empty\n");

	}
	return temp;
}

void disp()
{
	struct node *var=top;

	if(var!=NULL)
	{ 
		while(var!=NULL)
		{
			printf("%d   ",var->data);
			var=var->next;
		} 
		printf("\n");
	}
	else
		printf("Stack is Empty\n");
}

int main()
{
	int i,data,temp,oprnd1,oprnd2;
	int choice;
	char exp[100],ch;

	printf("Enter the Postfix expression:\n(NOTE:Operands can have values from 0-9 only.)\n");
	scanf("%s",exp);

	i=0;
	while((ch=(exp[i++])) != '\0')
	{
		temp=(ch-'0');
		if(0<(temp) && (temp)<9)
			push((temp));
		else if(ch == '+')
		{
			oprnd1=pop();
			oprnd2=pop();
			push(oprnd1+oprnd2);	 		
		}
		else if(ch == '-')
		{
			oprnd1=pop();
			oprnd2=pop();
			push(oprnd1-oprnd2);	 		
		}
		else if(ch == '*')
		{
			oprnd1=pop();
			oprnd2=pop();
			push(oprnd1*oprnd2);	 		
		}	 	
		else if(ch == '/')
		{
			oprnd1=pop();
			oprnd2=pop();
			push(oprnd1/oprnd2);	 		
		}
		else if(ch == '%')
		{
			oprnd1=pop();
			oprnd2=pop();
			push(oprnd1%oprnd2);	 		
		}
		else
			printf("Enter a valid postfix expression\n");
	}

	printf("result:");
	disp();
}
