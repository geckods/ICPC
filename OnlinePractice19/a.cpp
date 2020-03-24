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
   		int n,k;
   		cin>>n>>k;

   		int arr[n];
   		for(int i=0;i<n;i++){
   			cin>>arr[i];
   		}

   		sort(arr,arr+n);

   		int lesseqsum=0;
   		int ogsize=0;
   		vector<int> greater;
   		for(int i=0;i<n;i++){
   			if(arr[i]<=k){
   				lesseqsum+=arr[i];
   			}
   			else{
   				greater.push_back(arr[i]-k);
   				ogsize++;
   			}
   		}

   		if(ogsize==0){
   			cout<<lesseqsum<<endl;
   			continue;
   		}

   		int maxelem = greater[greater.size()-1];
   		greater.pop_back();

   		reverse(greater.begin(),greater.end());

   		int minpoint=0;
   		int sumoverk=maxelem;
   		int gsize;

   		while(greater.size()>0){
   			gsize=greater.size();
	   		if(gsize==1){
	   			sumoverk=maxelem-greater[gsize-1];
	   			break;
	   		}
	   		else if (gsize==2){
	   			sumoverk=maxelem-(greater[gsize-2]-greater[gsize-1]);
	   			break;
	   		}
	   		else{
	   			if(greater[0]-greater[1]<greater[gsize-1]){
	   				//0 or 1 based on parity of sum
	   				int sum=0;
	   				for(int i=0;i<gsize;i++){
	   					sum+=greater[i];
	   				}
	   				if(sum%2==0){
	   					sumoverk=maxelem;
	   				}
	   				else{
	   					sumoverk=maxelem-1;	   					
	   				}
	   				break;
	   			}
	   			else{
	   				greater[0]-=greater[gsize-1];
	   				greater.pop_back();
	   			}
	   		}
	   	}

	   	cout<<lesseqsum+k*ogsize+sumoverk<<endl;
   	}

}
