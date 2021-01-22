#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int trie[N][26],tot=1;
bool end[N];
void insert(char *s)
{
    int now=1,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        int ch=s[i]-'A';
        if(!trie[now][ch])trie[now][ch]=++tot;
        now=trie[now][ch];
    }
    end[now]=1;
}
bool search(char *s)
{
    int now=1,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        now=trie[now][s[i]-'A'];
        if(!now)return 0;
    }
    return end[now];
}
char s[N];
int main()
{
    
    return 0;
}
