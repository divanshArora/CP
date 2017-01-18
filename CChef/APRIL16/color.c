#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
int main()
{
 
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int r =0,b=0,g=0,i;
        long int n;scanf("%ld",&n);
        char arr[n];
        scanf("%s",arr);
        for(i=0;i<n;i++)
        {
            if(arr[i]=='R')
            {
                r++;
            }
            else if(arr[i]=='B')
            {
                b++;
            }
            else if(arr[i]=='G')
            {
                g++;
            }
        }
        long int max = r;
        if(b>max)max = b;
        if(g>max)max = g;
        printf("%ld\n",n-max);
 
    }
    return 0;
}
