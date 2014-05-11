// abhishek gupta
// spoj:EDIT (Edit Distance Again)
http://www.spoj.com/problems/EDIT/
//execution time = 0.06s

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#define check(a, b) ((a!=b)?1:0)
#define min(a, b) ((a<b)?a:b)
using namespace std;

int arr[1002];
void solve(int n);
int main()
{
    char c;
    int i;
    while (c<33)
            c=getchar();
    while(c!=-1)
    {
        i=0;
        while (c>33)
        {
            if(c<=90)
                arr[i]=1;
            else
                arr[i]=0;
            i++;
            c=getchar();
        }
        solve(i);
        while (c<33 && c!=-1)
            c=getchar();
    }
   return 0;
}

void solve(int n)
{
    int i, a=0, b=0;
    for(i=0; i<n; i++)
    {
        if(i&1)
        {
            a+=check(arr[i], 1);
            b+=check(arr[i], 0);
        }
        else
        {
            a+=check(arr[i], 0);
            b+=check(arr[i], 1);
        }
    }
    printf("%d\n", min(a,b));
}
