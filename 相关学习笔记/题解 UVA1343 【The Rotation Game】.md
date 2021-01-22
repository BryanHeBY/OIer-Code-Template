这是一道经典的IDA*算法的题目，不知道该算法的小伙伴请移步至百度。


------------

首先，我们可以对1、2、3分三次求解，同时更新答案，提高效率；

其次，一个明显的剪枝是不执行上一层操作的反操作；

最后，本题的重点在于构造估价函数：
我们考虑每次移动的影响，因为每次移动最多可以增加一个相同数字的格子，
所以我们可以这样构造估价函数：

f(state[i])=该状态下中间八个格子中非所求数字格子的个数；

不难证明，f(state[i])一定小于等于实际步数，该估价函数合理。

下面上代码：

------------


```cpp
#include<bits/stdc++.h>
using namespace std;
bool state[50][24];
int table[24],ans[50],res[50],maxd;
int moven[8][7]={
{0,2,6,11,15,20,22},
{1,3,8,12,17,21,23},
{10,9,8,7,6,5,4},
{19,18,17,16,15,14,13},
{23,21,17,12,8,3,1},
{22,20,15,11,6,2,0},
{13,14,15,16,17,18,19},
{4,5,6,7,8,9,10}
};//手动打移动规则
int mid[8]={6,7,8,11,12,15,16,17};//中间八个格子
int oppo[8]={5,4,7,6,1,0,3,2};//剪枝一
int f(int now)//估价函数
{
    int ans=0;
    for(int i=0;i<8;i++)if(!state[now][mid[i]])ans++;
    return ans;
}
bool dfs(int deep)//IDA*
{
    if(deep==maxd)
    {
        if(f(deep)==0)return 1;
        else return 0;
    }
    if(deep+f(deep)>maxd)return 0;
    for(int i=0;i<8;i++)
    if(deep==0||oppo[ans[deep-1]]!=i)
    {
        ans[deep]=i;
        for(int j=0;j<24;j++)state[deep+1][j]=state[deep][j];
        for(int j=0;j<7;j++)state[deep+1][moven[i][j]]=state[deep][moven[i][(j+1)%7]];
        if(dfs(deep+1))return 1;
    }
    return 0;
}
bool judge()//更新答案
{
    if(res[0]!=-1)
    for(int i=0;i<maxd;i++)
        if(res[i]<ans[i])return 0;
        else if(res[i]>ans[i])break;
    for(int i=0;i<maxd;i++)res[i]=ans[i];
    return 1;
}
int main()
{
    while(1)
    {
        memset(res,-1,sizeof(res));
        scanf("%d",&table[0]);
        if(!table[0])break;
        for(int i=1;i<=23;i++)scanf("%d",&table[i]);
        int p=0;
        for(maxd=0;;maxd++)
        {
            for(int k=1;k<=3;k++)//分三次求解
            {
                for(int j=0;j<24;j++)
                state[0][j]=table[j]==k;
                if(dfs(0)&&judge())p=k;//更新答案
            }
            if(p)break;
        }
        if(maxd)
        {
        	for(int i=0;i<maxd;i++)putchar(res[i]+'A');
        	putchar('\n');
        }
        else printf("No moves needed\n");
        printf("%d\n",p);
    }
    return 0;
}
```
