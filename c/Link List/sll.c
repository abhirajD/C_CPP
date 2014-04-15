#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *next;
}*head;

void insert(int num)
{
	struct node *right,*left,*temp;
	temp=head;

	if(temp==NULL)
}