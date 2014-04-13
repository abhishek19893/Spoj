// abhishek gupta
//spoj: APS (Amazing Prime Sequence)
http://www.spoj.com/problems/APS/
//execution time: 0.3s

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(a,b) ((a>b)?(a):(b))

long long int arr[10000002];
bool prime[10000002];

void sieve();
void generateValue();

int main()
{
    int t;
    long int n;
    sieve();
    generateValue();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%ld", &n);
        printf("%lld\n", arr[n]);
    }

   return 0;
}

void sieve()
{
    long long int i, j;
    for(i=4; i<10000002; i+=2)
    {
            prime[i]=true;
            arr[i]=2;
    }
    for(i=3; i<10000002; i+=2)
    {
        if(!prime[i])
        {
            arr[i]=i;
            for(j=i*i; j<10000002; j+=i)
            {
                prime[j]=true;
                if(arr[j]==0)
                    arr[j]=i;
            }

        }
    }
}

void generateValue()
{
    register long int i, j;
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=5;
    arr[4]=7;
    arr[5]=12;
    
    for(i=6; i<10000002; i++)
        arr[i]+=arr[i-1];
}

