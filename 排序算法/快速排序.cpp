#include<bits/stdc++.h>
#define ll unsigned long long 
#define F(i,l,r) for(int i=l;i<=r;i++)
const int N=1e5+5;
using namespace std;
int n;
int a[N]; 
void qsort(int l,int r)
{
	int key=a[(l+r)>>1],i=l,j=r;
	while(i<=j)
	{
		while(a[i]<key)i++;
		while(a[j]>key)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
	
}

int main()
{
	scanf("%d",&n);
	F(i,1,n)scanf("%d",&a[i]);
	qsort(n);
	F(i,1,n)printf("%d ",a[i]);
	return 0;
}
