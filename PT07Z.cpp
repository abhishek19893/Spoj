// abhishek gupta
// spoj: PT07Z (Longest path in a tree)
http://www.spoj.com/problems/PT07Z/
//execution time = 0.08s

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
    vector<int> edge;
    bool visit;
} tree;

tree v[10002];

int ans, n, newx, newy;
void dfs(int x, int a);

inline void init(int n)
{
    for(register int i=0; i<=n;i++)
        v[i].visit=false;
    ans=-1;
}

int main()
{
    int a, b;
    scanf("%d", &n);
    int i;
    for(i=0; i<n-1; i++)
    {
        scanf("%d%d", &a, &b);
        v[a].edge.push_back(b);
        v[b].edge.push_back(a);
    }
    for(i=1; i<n; i++)
    {
        if(!v[i].edge.empty())
        {
            init(n);
            dfs(i, 0);
            
            init(n);
            dfs(newx, 0);
           
            printf("%d", ans);
            break;
        }
    }
   return 0;
}

void dfs(int x, int a)
{
    v[x].visit=true;
    if(ans<a)
    {
        ans=a;
        newx=x;
    }
    for(int i=0; i<v[x].edge.size(); i++)
    {
        int k=v[x].edge[i];
        if(v[k].visit==false)
            dfs(k, a+1);
    }
}
