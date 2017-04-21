#include<bits/stdc++.h>
using namespace std;
int a[100005][2];
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    long long int sum=0;
    for(int i=0;i<n;i++)
        {

            {
                sum+=a[i][0];
            }

        }
        if(sum<=p)
        {printf("-1");return 0;}
    double l=0,r=1e18;
    double ans;
    int cnt=0;
    while(r>l)
    {
        double mid=l+(r-l)/2.0;
        double s=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][1]<(a[i][0]*mid))
            {
                s+=a[i][0]*mid-a[i][1];
            }

        }
        if(s<=(double)p*mid)
        {
            ans=mid;
            l=mid+0.00001;
            //printf("%.10lf\n",ans);
        }
        else
            r=mid-0.00001;
        cnt++;
    }
 //   printf("%d\n",cnt);
    if(r==1e18)
        printf("-1");
    else
    printf("%.10lf",ans);
    return 0;
}