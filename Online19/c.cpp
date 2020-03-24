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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	vector<pair<ll,pair<ll,ll> > > myVec;

    	ll l,r,v;
    	for(int i=0;i<n;i++){
    		cin>>l>>r>>v;
    		myVec.push_back(make_pair(v,make_pair(l,r)));
    	}

    	sort(myVec.begin(),myVec.end());

    	vector<pair<ll,ll> > tempVec;

    	int i=0,j=0;
    	bool works=true;
    	while(i<n){
    		j=i+1;
    		while(j<n && myVec[j].first==myVec[i].first){
    			j++;
    		}

    		vector<int> entryvec;
    		vector<int> exitvec;

    		for(int k=i;k<j;k++){
    			// tempVec.push_back(myVec[k].second);
    			entryvec.push_back(myVec[k].second.first);
    			exitvec.push_back(myVec[k].second.second);
    		}

    		sort(entryvec.begin(),entryvec.end());
    		sort(exitvec.begin(),exitvec.end());

    		int m=entryvec.size();
    		// cout<<m<<endl;

    		//check if tempVec has three collisions
    		int currrangemin;
    		int currrangemax;


    		// for(int z=0;z<m-1;z++){    			
    		// 	if(tempVec[z+1].first<=tempVec[z].second){
    		// 		//z and z+1 clash
    		// 		currrangemin=max(tempVec[z].first,tempVec[z+1].first);
    		// 		currrangemax=min(tempVec[z].second,tempVec[z+1].second);
    		// 		for(int x=0;x<m;x++){
    		// 			if(x==z||x==z+1)continue;
    		// 			if(tempVec[x].first> currrangemax || tempVec[x].second<currrangemin)continue;
    		// 			works=false;
    		// 			break;
    		// 		}
    		// 	}

    		// 	if(!works)break;
    		// }
    		// if(!works)break;

    		int x=0,y=0;
    		int count=0;
    		while(x<m || y<m){
    			// cout<<x<<" "<<y<<" "<<count<<endl;
    			if(x>=m || entryvec[x]>exitvec[y]){
    				count--;
    				y++;
    			}
    			else{
    				count++;
    				x++;
    			}
    			// cout<<x<<" "<<y<<" "<<count<<endl;

    			if(count>=3){
    				works=false;
    				break;
    			}
    		}
    		if(!works)break;

    		i=j;
    	}
    	if(works){
    		cout<<"YES"<<endl;
    	}
    	else{
    		cout<<"NO"<<endl;
    	}

    }
    
}
