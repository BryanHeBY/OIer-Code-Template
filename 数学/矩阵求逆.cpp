#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=l;i<=r;++i)
#define DF(i,r,l) for(int i=r;i>=l;i--)
const int N=5e5+5;
typedef long long ll;
typedef long double ld;

struct mat{
    int n,m;
    vector<vector<double>> a;
    mat(int n,int m):n(n),m(m){
        a.resize(n);
        F(i,0,n-1)a[i].resize(m);
    }
    vector<double> &operator [](int i){return a[i];}
    static mat eye(int n){
        mat ret(n,n);
        F(i,0,n-1)ret[i][i]=1;
        return ret;
    }
    mat operator+ (const mat &b){
        mat ret(n,m);
        F(i,0,n-1)F(j,0,m-1)ret[i][j]=a[i][j]-b.a[i][j];
        return ret;
    }
    mat operator* (const mat &b){
        mat ret(n,b.m);
        F(i,0,n-1)F(j,0,b.m-1)F(k,0,m-1)ret[i][j]+=a[i][k]*b.a[k][j];
        return ret;
    }
    void print(){
        F(i,0,n-1){F(j,0,m-1)printf("%8.2lf",a[i][j]);puts("");}
    }
    
    bool rref(){
        bool judge=true;
        F(i,0,n-1){
            bool p=false;
            F(k,i,n-1)if(fabs(a[k][i])>1e-10){
                if(k!=i)swap(a[k],a[i]);
                p=true;break;
            }
            if(!p){judge=false;break;}
            double d=a[i][i];
            F(j,0,m-1)a[i][j]/=d;
            F(k,0,n-1)if(k!=i){
                double tmp=a[k][i];
                F(j,0,m-1)a[k][j]-=tmp*a[i][j];
            }
        }
        return judge;
    }

    mat inv(){
        mat t(n,2*n),ret(n,n);
        F(i,0,n-1)F(j,0,n-1)t[i][j]=a[i][j],t[i][n+j]=(i==j);
        t.rref();
        F(i,0,n-1)F(j,0,n-1)ret[i][j]=t[i][n+j];
        return ret;
    }
};

int main(){
    
    return 0;
}
