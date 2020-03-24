#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bc[32];

ll countSetBits(int n) 
{ 
    ll count = 0; 
    while (n) 
    { 
	    n &= (n-1) ; 
    	count++; 
    } 
    return count; 
} 

void addtobc(ll x){
	for(int i=0;i<32;i++){
		bc[i]+=x&1;
		x=x>>2;
	}
}

bool compare(ll x, ll y){
	return ((int)log2(x)*100 - countSetBits(x)) < ((int)log2(x)*100 - countSetBits(y));
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    memset(bc,0,sizeof(bc));

    for(int test=0;test<t;test++){
    	ll n;
    	cin>>n;

    	vector<ll> myVec;
    	ll x;

    	ll curror=0;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		myVec.push_back(x);
    		addtobc(x);
    		curror|=x;
    	}

    	sort(myVec.begin(),myVec.end(),compare);

    	bool erased[n];

    	for(int i=0;i<n;i++){
    		erased[i]=false;
    	}

    	ll ans=curror;
    	for(int i=0;i<n;i++){
    		bool works=true;
    		for(int j=0;j<32;j++){
    			if(bc[j]==1 && (1<<(j+1))&myVec[i]){
    				works=false;
    				break;
    			}
    		}

    		cout<<i<<" "<<bc[0]<<" "<<bc[1]<<" "<<bc[2]<<" "<<bc[3]<<endl;
    		if(works){
    			erased[i]=true;
    			ans+=curror;
	    		for(int j=0;j<32;j++){
	    			if((1<<(j+1))&myVec[i]){
	    				bc[j]--;
	    			}
	    		}
    		}
    	}

    	for(int i=0;i<n;i++){
    		if(!erased[i]){
    			for(int j=0;j<32;j++){
	    			if((1<<j)&myVec[i]){
	    				bc[j]--;
	    			}
	    		}

				erased[i]=true;
				curror^=myVec[i];
				ans+=curror;
    		}
    	}
    	cout<<ans<<endl;
    }
}