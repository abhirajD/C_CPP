#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
int data;
struct BSTnode *left,*right;
}BSTnode;

BSTnode *find(BSTnode *,int);
BSTnode *insert(BSTnode *,int);
BSTnode *create();
void inorder(BSTnode *T);
void preorder(BSTnode *T);
void postorder(BSTnode *T);

int main()            //main
{
	BSTnode *root=NULL,*p;
	int x,op;

	x:

	printf("\nMenu:\n");
	printf("1.Create\n");
	printf("2.Search\n");
	printf("3.Insert\n");
	printf("4.Preorder\n");
	printf("5.inorder\n");
	printf("6.Postorder\n");
	printf("7.Exit\n");
	
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			root=create();
			goto x;
		break;
		case 2:
			printf("\nEnter the key to be searched: ");
		    scanf("%d",&x);
		    p=find(root,x);
		    if(p==NULL)
		    	printf("\nNOT FOUND");
		    else
		    	printf("\n FOUND");
		   	goto x;
		break;
		case 3:printf("\nEnter a data to be inserted: ");
		       scanf("%d",&x);
		       root=insert(root,x);
		       goto x;
		break;
		case 4:preorder(root);
				goto x;
		break;
		case 5:inorder(root);
				goto x;
		break;
		case 6:postorder(root);
				goto x;
		break;
		case 7: exit(0);
	}


      return 0;
 }	
 
void inorder(BSTnode *root)     //inorder traversal
{
   if(root!=NULL)
       {
		 inorder(root->left);
		 printf("%d\t",root->data);
		 inorder(root->right);
       }
}

void preorder(BSTnode *root)     //preorder traversal
{
 if(root!=NULL)

      {	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
      }
}

void postorder(BSTnode *root)     //postorder traversal
{
 if(root!=NULL)

    {
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
    }
}

BSTnode *find(BSTnode *root,int x)      //search
{
	while(root!=NULL)
	{
	if(x==root->data)
		return(root);
	if(x>root->data)
		root=root->right;
	else
		root=root->left;
	}
  return(NULL);
}

BSTnode *insert(BSTnode *root,int x)    //insert
{
	BSTnode *p,*q,*r;
	r=(BSTnode*)malloc(sizeof(BSTnode));
	r->data=x;
	r->left=NULL;
	r->right=NULL;
	  if(root!=NULL)
		{
	p=root;
	while(p!=NULL)
	{
	q=p;
		if(x>p->data)
		p=p->right;
		else if(x<p->data)
		p=p->left;
		else if(x==p->data)
			{
			printf("\nDuplicate entry");
			return(root);
			}
	}
	if(x>q->data)
	q->right=r;
	else
	q->left=r;
	return(root);
		}
}

BSTnode *create()        //create
{
	int n,x,i;
	BSTnode *root;
	root=NULL;
	printf("\nEnter no of nodes:\n");
	scanf("%d",&n);
	printf("\nEnter tree values:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insert(root,x);
	}
  return(root);
}
