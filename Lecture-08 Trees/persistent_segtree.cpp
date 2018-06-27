#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll seg[100000000],newIndex=0,arr[1000000],L[1000000],R[1000000];
ll update(ll st,ll l,ll r,ll i,ll v)
{
	ll id=newIndex++;
	if(l==r)
	{
		seg[id]=v;
		return id;
	}
	ll mid=(l+r)/2;
	L[id]=L[st];
	R[id]=R[st];
	if(i<=mid)
	{
		L[id]=update(L[st],l,mid,i,v);
	}
	else
	{
		R[id]=update(R[st],mid+1,r,i,v);
	}
	seg[id]=min(seg[L[id]],seg[R[id]]);
	return id;
}
ll query(ll st,ll l,ll r,ll ql,ll qr)
{
	if(r<ql||l>qr)
		return INT_MAX;
	if(l>=ql&&r<=qr)
		return seg[st];
	ll mid=(l+r)/2;
	return min(query(L[st],l,mid,ql,qr),query(R[st],l,r,ql,qr));
}
int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	build();//
	ll q;
	cin>>q;
	ll nn=build();
	while(q--)
	{
		ll i,v;
		cin>>i>>v;
		ll n1=update(nn,0,n-1,i,v);
		ll n2=update(n1,0,n-1,i,v);
		ll l,r;
		cin>>i>>l>>r;
		cout<<query(n1,0,n-1,l,r);
	}
}