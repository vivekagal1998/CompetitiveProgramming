//http://codeforces.com/blog/entry/5514
#include<queue>
#include<map>
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
int n,k,v[105][105],c;

 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
cin>>k;
n=100;
for(int i=2;i<=n;i++)
{
for(int j=1;j<i;j++)
{
    int cnt=0;
    forr(u,1,n)
    {
      if(u==i||u==j)continue;
      if(v[i][u]&&v[u][j])cnt++;
    }

    if(c+cnt<=k)
    {
        c+=cnt;
        v[i][j]=v[j][i]=1;
    }
if(c==k)break;
}
if(c==k)break;
}


cout<<"100"<<endl;
forr(i,1,100)
{
    forr(j,1,100)cout<<v[i][j];
    cout<<endl;
}
return 0;
}
