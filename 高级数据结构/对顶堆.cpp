#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > small;
priority_queue<int> large;
void add(int);
int get_mid();

int main()
{
	
	return 0;
}

void add(int x)
{
	if(large.empty()||x<=large.top())large.push(x);
	else small.push(x);
	while(large.size()>small.size()+1)small.push(large.top()),large.pop();
	while(small.size()>large.size())large.push(small.top()),small.pop();
}
int get_mid()
{
	return large.top();
}
