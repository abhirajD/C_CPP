#include<stdio.h>
#define SIZE 10

struct q 
{
	int R,F;
	int data[SIZE];
}q,*p;

int G[SIZE][SIZE];
int n=0;
int visited[SIZE];

int main()			
{
	int i,j,e,v,op;
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G[i][j]=0;
		}
	}

	printf("\nEnter the graph as list of edges");
	printf("\nInitial vertex number = 0\t");

	for(v=0;v<e;v++)
	{
		printf("\nEnter the next edge(start vertex,end vertex):");
		scanf("%d%d",&i,&j);
		G[i][j]=G[j][i]=1;
	}

	x:

	printf("\nMenu\n");
	printf("1.DFS\n");
	printf("2.BFS\n");
	printf("3.Dispaly Graph\n");
	printf("3.Exit\n");
	printf("\nEnter your choice:");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
		printf("\nEnter the starting vertex for DFS");
		scanf("%d",&v);
		for(i=0;i<n;i++)
			visited[i]=0;
		DFS(v);
		goto x;
		break;
		case 2:
		printf("\nEnter the starting vertex for BFS");
		scanf("%d",&v);
		BFS(v);
		goto x;
		break;
		case 3:
		printf("\nAdjacency matrix:\n");
		for(i=0;i<n;i++)
		{
			printf("\n");
			for(j=0;j<n;j++)
				printf("%d\t",G[i][j]);
		}
		goto x;
		break;
	}

	return 0;
}

void BFS(int v)			
{
	int visited[SIZE],i;
	q.R=q.F=-1;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	insert(&q,v);
	printf("\n\nVisit:\n%d",v);
	visited[v]=1;
	while(!empty(&q))
	{
		v=delete(&q);
		for(i=0;i<n;i++)
		{
			if(visited[i]==0&&G[v][i]!=0)
			{
				insert(&q,i);
				visited[i]=1;
				printf("\n%d",i);
			}
		}
	}
}

int empty()
{
	if(p->R==-1)
		return(1);
	return(0);
}

int full()
{
	if(p->R==SIZE-1)
		return(1);
	return(0);
}

void insert()
{
	int x;
	if(p->R==-1)
	{
		p->R=p->F=0;
		p->data[p->R]=x;
	}
	else
	{
		p->R=p->R+1;
		p->data[p->R]=x;
	}
}

int delete()
{
	int x;
	x=p->data[p->F];
	if(p->R==p->F)
	{
		p->R=-1;
	}
	else
	{
		p->F=p->F+1;
		return(x);
	}
}

void DFS(int i)
{
	int j;
	printf("\n%d",i);
	visited[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visited[j]&&G[i][j]==1)
			DFS(j);

	}
}
