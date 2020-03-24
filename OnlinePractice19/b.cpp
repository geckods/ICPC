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
   		string s;
   		cin>>s;

   		int n = s.length();
   		int currmin=-1;
   		int currmax=-1;

   		int newmin,newmax;

   		bool safe=true;
   		for(int i=0;i<s.size();i++){
   			if(s[i]!='.'){
   				newmin=max(i-(s[i]-'0'),0);
   				if(newmin<=currmax){
   					safe=false;
   					break;
   				}
   				currmax=min(i+(s[i]-'0'),n-1);
   			}
   		}

   		if(safe){
   			cout<<"safe"<<endl;
   		}
   		else{
   			cout<<"unsafe"<<endl;
   		}
   	}
}