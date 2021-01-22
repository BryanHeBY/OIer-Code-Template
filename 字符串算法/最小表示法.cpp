#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    s+=s;
    int i=1,j=2,k;
    while(i<=n&&j<=n)
    {
    	for(k=0;k<=n&&s[i+k-1]==s[j+k-1];k++);
    	if(k==n)break;
    	if(s[i+k-1]>s[j+k-1])i+=k+1;
    	else j+=k+1;
    	if(i==j)j++;
    }
    cout<<min(i,j);
    return 0;
}
