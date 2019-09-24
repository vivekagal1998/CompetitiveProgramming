/*
   if we take two different burger then the number of ways to distribute the remaining burger (n-2)C(n-2)/2
   so the total probability that the two children have two different burger  0.5 ^ (n-2) * (n-2)C(n-2)/2
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=300007,M=1000000;
const double EPS= 1e-9,eps=-1e9;

long double k[N];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
long double ans=1;
for(int i=2;i<=100000;i+=2)
{
    ans*=(long double)i;
    ans*=(long double)(i-1);

    ans/=(long double)i/2,ans/=(long double)i/2;
    ans/=4.0;
    k[i]=ans;
}
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    n-=2;
    if(n==0)cout<<fixed<<setprecision(4)<<0.0<<endl;
    else cout<<fixed<<setprecision(4)<<1.0-k[n]<<endl;
}
return 0;
}
