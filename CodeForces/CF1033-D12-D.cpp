//https://codeforces.com/blog/entry/62287
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;

ll n,a[505],mod=998244353;
map<ll,ll>m,c,qp;

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
for(ll i=1;i<=2000000;i++)qp[i*i*i]=i;
cin>>n;
forr(i,1,n)
{
    cin>>a[i];
    ll sq=sqrt(a[i]);
    if(sq*sq==a[i])
    {
        ll g=sq;
        for(int j=2;j*j<=g;j++)
        {
            while(g%j==0)
            {
                m[j]+=2;
                g/=j;
            }
        }
        if(g>1)m[g]+=2;
    }
    else if(qp.count(a[i])) m[qp[a[i]]]+=3;
    else c[a[i]]++;
}
ll ans=1;
for(auto p:c)
{
    int ck=1;
    for(auto k:m)
    {
        if(p.F%k.F==0)
        {
            m[k.F]+=p.S;
            m[p.F/k.F]+=p.S;
            ck=0;
            break;
        }
    }
    if(ck)
    {
    for(auto y : c)
    {
        if(p.F==y.F)continue;
        ll g=__gcd(p.F,y.F);
        if(g>1)
        {
            m[g]+=p.S;
            m[p.F/g]+=p.S;
            ck=0;
            break;
        }
    }
    if(ck)
    {
        ans*=(p.S+1),ans%=mod;
        ans*=(p.S+1),ans%=mod;
    }
    }
}

for(auto p:m)ans*=(p.S+1),ans%=mod;
cout<<(ans+mod)%mod;
return 0;
}
