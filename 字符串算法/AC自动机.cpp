#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct trie
{
    int son[26],end,fail;
    #define son(x,y) AC[x].son[y]
    #define end(x) AC[x].end
    #define fail(x) AC[x].fail
}AC[N];
int cnt=0;
char s[N];
void build(char*);
void get_fail();

int main()
{
    
    return 0;
}

void get_fail()
{
    queue<int> q;
    for(int ch=0;ch<26;ch++)
        if(son(0,ch))q.push(son(0,ch));
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=0;i<26;i++)
        {
            if(son(now,i))
            {
                fail(son(now,i))=son(fail(now),i);
                q.push(son(now,i));
            }else son(now,i)=son(fail(now),i);
        }
    }
}
void build(char *s)
{
    int now=0,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(!son(now,s[i]-'a'))son(now,s[i]-'a')=++cnt;
        now=son(now,s[i]-'a');
    }
	//do something
}
