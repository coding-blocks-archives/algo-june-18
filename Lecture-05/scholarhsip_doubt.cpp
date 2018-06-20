#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/****************************************************************************/
ll n,m,x,y;

bool solve(ll pok){
  return (pok*x<=m+(n-pok)*y);
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
      s3(n,m,x);
      s(y);
      ll lo=0;
      ll hi=n;
      ll ans=0;
      while(lo<=hi){
        ll mid=lo+hi;
        mid>>=1;
        if(solve(mid)){ lo=mid+1; ans=mid; }
        else hi=mid-1;
      }
      p(ans);
  }
  return 0;
 }