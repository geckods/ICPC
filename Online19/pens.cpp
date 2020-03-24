#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convtoint(string s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		ans|=(1<<(s[i]-'a'));
	}
	return ans;
}

//does there exist a pen with this combination?
int pennum[1048576];
void addPen(int pen, int ind){
	if(pennum[pen]!=0)return;
	pennum[pen]=ind;
	for(int i=1;i<1048576;i=i<<1){
		if(pen&i){
			addPen(pen^i,ind);
		}
	}
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

    for(int test=0;test<t;test++){
    	int n,k;
    	cin>>n>>k;

    	string s;
    	cin>>s;

    	memset(pennum,0,sizeof(pennum));

    	string pen;
    	for(int i=0;i<k;i++){
    		cin>>pen;
    		addPen(convtoint(pen),i+1);
    		// cout<<convtoint(pen)<<" "<<pennum[convtoint(pen)]<<" "<<i+1<<endl;
    	}

    	int i=0;
    	int z;
    	int tot,oldtot;
    	vector<int> sol;

    	while(i<n){
    		z=i;
    		tot=(1<<(s[z]-'a'));
    		while(z<n && pennum[tot]){
    			// cout<<tot<<endl;
    			oldtot=tot;
    			z++;
    			tot|=(1<<(s[z]-'a'));
    		}
    		//z is the first thing for which it doesnt work
    		for(int j=i;j<z;j++){
    			sol.push_back(pennum[oldtot]);
    		}
    		i=z;
    	}

    	for(int i=0;i<sol.size();i++){
    		cout<<sol[i]<<" ";
    	}
    	cout<<endl;

    }
}