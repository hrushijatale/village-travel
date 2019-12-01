#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int cmpfun (const void *p, const void *q)
{
	int l = *((int *)p);
	int r = *((int *)q);
	return (l-r);
}
int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int cost[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &cost[i]);
		qsort(cost, n, sizeof(int), cmpfun);
		long total = 0, i = n - 1;
		while (i > 2)
		{
			int cost1 = cost[i] + cost[0] + cost[i - 1] + cost[0];
			int cost2 = cost[1] + cost[0] + cost[i] + cost[1];
			if (cost1 < cost2) total +=cost1;
			else total+=cost2;
			i -= 2;
		}
		if (i == 2)
			total += (cost[0] + cost[1] + cost[2]);
		else if (i == 1)
			total += max(cost[0], cost[1]);
		else
			total += cost[0];
		printf("%ld\n", total);
	}
return 0;
}
