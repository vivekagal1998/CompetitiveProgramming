/*
    first we need to sort our nodes then make edges form smallest node to all other
    nodes plus edges of special offer then get min spanning tree and the cost of it 
    will be the answer
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll n,m,u[500020],v[500020],w[500020],id[500020],p[500010],ran[500010];
pair<ll,ll>a[500050];
ll ans;
bool com(int i,int j)
{
    if(w[i]<w[j])return 1;
    return 0;
}



int findset(int f)
{
    if(p[f]==f)
        return f;
    else
        return p[f]=findset(p[f]);
}
void conect(int x,int y)
{
    x=findset(x);
    y=findset(y);
    if(ran[x]>ran[y])swap(x,y);
    p[x]=y;
    if(ran[x]==ran[y])
        ran[y]++;
}
bool isconect(int x,int y)
{
    if(findset(x)==findset(y))
        return 1;
    else
        return 0;
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;
forr(i,1,n)
{
    p[i]=i;
    cin>>a[i].F,a[i].S=i;
}

sort(a+1,a+1+n);

forr(i,2,n)
{
    u[i]=a[1].S;
    v[i]=a[i].S;
    w[i]=a[1].F+a[i].F;
}

forr(i,1,m)
    cin>>u[i+n]>>v[i+n]>>w[i+n];

forr(i,2,n+m)id[i]=i;
sort(id+2,id+n+m+1,com);


forr(j,2,n+m)
{
    int i=id[j];

    if(isconect(u[i],v[i]))continue;
    conect(u[i],v[i]);
    ans+=w[i];
}
cout<<ans;
return 0;
}
