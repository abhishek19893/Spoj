//abhishek gupta
//spoj: ACPC10A (What’s Next) 
http://www.spoj.com/problems/ACPC10A/
//execution time = 0.00s

#include<stdio.h>

int main()
{
    int a[3], r;
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        
        while(a[0] != a[1])
        {
                if((a[0]-a[1]) == (a[1]-a[2]))
                        printf("AP %d\n", (2*a[2] - a[1]));
                else
                {
                        r = a[1]/a[0];
                        printf("GP %d\n", (a[2]*r));
                }
                scanf("%d %d %d", &a[0], &a[1], &a[2]);
        }
        return 0;
}
