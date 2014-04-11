// abhishek gupta
// spoj: ACPC10D (Trigraph)
//execution time = 0.26s

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int graph[100001][3];
int dp[100001][3];
int main()
{
    register int i;
    int n, k=0;
    scanf("%d", &n);
    while(n!=0)
    {
        k++;
        for(i=0; i<n; i++)
            scanf("%d%d%d", &graph[i][0], &graph[i][1], &graph[i][2]);
        
        dp[0][1]=graph[0][1];
        dp[0][2]=dp[0][1]+graph[0][2];
        dp[1][0]=graph[1][0]+dp[0][1];
        dp[1][1]=min(min(dp[1][0], dp[0][2]), dp[0][1])+graph[1][1];
        dp[1][2]=min(min(dp[1][1], dp[0][2]), dp[0][1])+graph[1][2];
        for(i=2; i<n; i++)
        {
            dp[i][0]=min(dp[i-1][0], dp[i-1][1])+graph[i][0];
            dp[i][1]=min(min(dp[i-1][0], dp[i-1][1]), min(dp[i][0], dp[i-1][2]))+graph[i][1];
            dp[i][2]=min(min(dp[i-1][1], dp[i-1][2]), dp[i][1])+graph[i][2];
        }
        printf("%d. %d\n", k, dp[n-1][1]);
        scanf("%d", &n);
    }
   return 0;
}

