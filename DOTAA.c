//abhishek gupta
//Spoj: DOTAA (Dota Heroes)
http://www.spoj.com/problems/DOTAA/
//execution time: 0.13s

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int t, m, n, d;
	scanf("%d", &t);
	while(t--)
	{
		register int i, count=0;
		scanf("%d %d %d", &n, &m, &d);
		int h;
		for(i=0; i<n; i++)
		{
			scanf("%d", &h);
			while(count<=m)
			{
				h-=d;
				if(h>0)
					count++;
				else
					break;
			}
		}
		if(count>=m)
			puts("YES");
		else
			puts("NO");
			
	}
	
	return 0;
}

