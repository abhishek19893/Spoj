// abhishek gupta
// spoj: EDIST (Edit distance)
http://www.spoj.com/problems/EDIST/
//execution time = 1.54s

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

int t, m, n;
int dp[2002][2002];
int solve(int i, int j);
string a, b;

int main()
{
    scanf("%d", &t);
    int i, j;
    while(t--)
    {
        cin>>a;
        cin>>b;
        n=a.size();
        m=b.size();
        printf("%d\n", solve(0,0));
    }
   return 0;
}

int solve(int i, int j)
{
    dp[0][0]=0;
    int x, y;
    for(i=0; i<=n; i++)
        dp[i][0]=i;
    for(i=0; i<=m; i++)
        dp[0][i]=i;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            x=min(dp[i-1][j]+1, dp[i][j-1]+1);
            y=((a[i-1]==b[j-1])?0:1);
            y+=dp[i-1][j-1];
            dp[i][j]=min(x, y);
        }
    }
    return dp[n][m];
}
