#include<stdio.h>
#include<stdlib.h>
#define N 30
#define G_SIZE 20
int main1()
{
    long long int a[N],i,j,sum=0;

    for (i = 0; i < N; ++i)
    a[i]=0;

	a[0]=1;//a[1]=3;a[2]=6;

	for (i = 0; i < (G_SIZE-1); ++i)
	{
		i=0;
		while(a[i+1] != 0)
		{
			a[i+1] = a[i+1] + a[i];
			i++;
		}a[i+1] = a[i]*2;

		/*printf("for G=%d\n",i+2);
		for (j = 0; j < (G_SIZE); ++j)
        {
            printf("%lld\n",a[j]);
        }*/
	}

    for(i=0 ; i<N ; i++)
    {
        sum=sum+a[i];
    }

    printf("SUM=%lld",sum*2);
	return 0;
}
