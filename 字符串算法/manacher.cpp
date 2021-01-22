#include<bits/stdc++.h>
using namespace std;
const int N=51000100;
char s1[N],s[N<<1];
int l,p[N];
int mid,mx;
void init();
int manacher();
int main()
{
	init();
	printf("%d",manacher());
	return 0;
}
void init()
{
	scanf("%s",s1);
	s[0]=s[1]='$';
	l=strlen(s1);
	for(int i=0;i<l;i++)
	{
		s[i*2+2]=s1[i];
		s[i*2+3]='$';
	}
	l=l*2+2;
}
int manacher()
{
	int ans=-1;
	mid=mx=1;
	for(int i=1;i<l;i++)
	{
		if(i<mx)p[i]=min(mx-i,p[2*mid-i]);
		else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])p[i]++;
		if(i+p[i]>mx)mid=i,mx=i+p[i];
		ans=max(ans,p[i]-1);
	}
	return ans;
}