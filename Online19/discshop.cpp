#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll t;
	cin>>t;

	for(int test=0;test<t;test++){
		ll n;
		cin>>n;

		ll ans=LLONG_MAX;

		ll i=0;
		ll a,b;
		string ns=to_string(n);
		int size=ns.size();
		string as,bs;
		// cerr<<size<<" "<<ns<<endl;
		while(i<size){
			// cerr<<size<<" "<<i<<endl;
			if(i<size-1)
				as=ns.substr(0,size-i-1);
			else
				as="";

			if(i>0)
				bs=ns.substr(size-i,i);
			else
				bs="";

			as.append(bs);

			// cerr<<size<<" "<<i<<" "<<"as:"<<" "<<as<<" bs:"<<bs<<endl;
			ans=min(ans,stoll(as));
			i++;
			//remove ith
		}
		cout<<ans<<endl;
	}   
}
