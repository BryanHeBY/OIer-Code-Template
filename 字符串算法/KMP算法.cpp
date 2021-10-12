#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int nextn[N],f[N];
string s1,s2;
int l1,l2;
void get_next()
{
	for(int i=2,j=0;i<=l1;i++)
	{
		while(j&&s1[i-1]!=s1[(j+1)-1])j=nextn[j];
		if(s1[i-1]==s1[(j+1)-1])j++;
		nextn[i]=j;
	}
}
void get_f()
{
	for(int i=1,j=0;i<=l2;i++)
	{
		while(j&&s2[i-1]!=s1[(j+1)-1])j=nextn[j];
		if(s2[i-1]==s1[(j+1)-1])j++;
		f[i]=j;
		if(f[i]==l1)
		{
			//do something
			j=nextn[j];
		}
	}
}
int main()
{
	cin>>s2>>s1;
	l1=s1.length(),l2=s2.length();
	get_next();
	get_f();
	return 0;
}


