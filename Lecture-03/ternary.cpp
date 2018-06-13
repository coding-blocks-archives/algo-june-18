#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000000];
	ll n,m;
ll func(ll pos)
{
	ll dis=0;
	
	for(int i=0;i<n&&arr[i]<pos;i+=m)
	{
		dis+=pos-arr[i];
	}
	for(int i=n-1;i>=0&&arr[i]>pos;i-=m)
	{
		dis+=arr[i]-pos;
	}
	return dis*2;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll l=0,r=10000000ll;
	while(r-l>3)
	{
		ll mid1=l+(r-l)/3;
		ll mid2=r-(r-l)/3;
		if(func(mid1)<func(mid2))
		{
			r=mid2;
		}
		else
		{
			l=mid1;
		}
	}
	cout<<min(func(l),min(func(l+1),func(l+2)));
}