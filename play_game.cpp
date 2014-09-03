#include <stdio.h>
#define MAXN 100005
#define K 3
int bricks[MAXN];
long long first[MAXN],second[MAXN];
long long solve();
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
		printf("%lld\n",solve());
}

long long solve()
{
	int n;
	scanf("%d",&n);
	for (int i=n-1;i>=0;i--)
		scanf("%d",&bricks[i]);
	int k = n<K?n:K;
	long long sum = 0;
	for (int i=0;i<k;i++)
	{
		sum += bricks[i];
		first[i] = sum;
		second[i] = 0;
	}
//	printf("%d,%d,%d\n",k,n,K);
//	for (int i=0;i<k;i++)
//		printf("%lld ",first[i]);
//	printf("\n\n");
	for (int i=k;i<n;i++)
	{
		first[i] = 0;
		sum = 0;
		for (int j=0,idx=i-1;j<k;j++,idx--)
		{
			sum += bricks[idx+1];
			if (sum+second[idx] > first[i])
			{
				first[i] = sum+second[idx];
				second[i] = first[idx];
			}
		}
	}
//	for (int i=0;i<n;i++)
//		printf("%d,%lld,%lld\n",bricks[i],first[i],second[i]);
	return first[n-1];
}
