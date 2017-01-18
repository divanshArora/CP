#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[1001],b[1001];
        int dpa[26]={0},dpb[26]={0};
        int i;
        scanf("%s",a);
        scanf("%s",b);
        int l1 = strlen(a),l2 = strlen(b);
        for(i=0;i<l1;i++)
        {
            dpa[(int)(a[i]-97)]++;
        }
        for(i=0;i<l2;i++)
        {
            dpb[(int)(b[i]-97)]++;
        }
        int flag =0;
        for(i=0;i<26;i++)
        {
            if(dpa[i]>0&&dpb[i]>0)
            {
                flag =1;
            }
        }
        if(flag == 1)
        {
            printf("Yes\n");
        }
        else{
        printf("No\n");
        }
    }
    return 0;
}
