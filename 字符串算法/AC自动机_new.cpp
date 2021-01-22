#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int trie[N][26],tot=1,endn[N];
int fail[N];
char s[N];
void build(char *s)
{
    int now=1,ch,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        ch=s[i]-'a';
        if(!trie[now][ch])trie[now][ch]=++tot;
        now=trie[now][ch];
    }
    endn[now]++;
}
void get_fail()
{
    fail[1]=0;endn[1]=-1;
    for(int ch=0;ch<26;ch++)trie[0][ch]=1;
    queue<int> q;
    q.push(1);
    int now;
    while(!q.empty())
    {
        now=q.front(),q.pop();
        for(int ch=0;ch<26;ch++)
        {
            if(trie[now][ch])
            {
                fail[trie[now][ch]]=trie[fail[now]][ch];
                q.push(trie[now][ch]);
            }
            else trie[now][ch]=trie[fail[now]][ch];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        build(s);
    }
    get_fail();
    
    return 0;
}