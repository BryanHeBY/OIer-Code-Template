#include<bits/stdc++.h>
using namespace std;
double a[105][105];
int n;
void guass();

int main()
{
    
    return 0;
}

void guass()
{
    for(int i=1;i<=n;i++)
    {
        int temp=i;
        for(int j=n;j>=i;j--)
            if(fabs(a[j][i])>1e-8)temp=j;
        if(fabs(a[temp][i])<=1e-8)
        {
            printf("No Solution");
            return;
        }
        else if(temp!=i)swap(a[i],a[temp]);
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            double rate=a[j][i]/a[i][i];
            for(int k=i;k<=n+1;k++)
                a[j][k]-=a[i][k]*rate;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",a[i][n+1]/a[i][i]);
}