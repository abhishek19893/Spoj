// abhishek gupta
// spoj: AGGRCOW (Aggressive Cows) 
http://www.spoj.com/problems/AGGRCOW/
// execution time = 0.35s

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;

int n, c;
vi v(100002);
bool sol(int x)
{
    int a=v[0], cow=1;
    for(register int i=0; i<n; i++)
    {
        if(v[i]-a>=x)
        {
            cow++;
            if(cow==c)
                return true;
            a=v[i];
        }
    }
    return false;
}
 
int bin_search()
{
    int p=0, q=v[n-1];
    while(p<q)
    {
        int mid=(p+q)/2;
        if(sol(mid))
        {
            p=mid+1;
        }
        else
            q=mid;
    }
    return (p-1);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &c);
        for(register int i=0; i<n; i++)
            scanf("%d", &v[i]);
        sort(v.begin(), v.begin()+n);
        printf("%d\n", bin_search());
    }
   return 0;
}
