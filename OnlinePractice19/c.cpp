#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool inGrid(string solutionString,string search){
	bool works=true;
	for(int colno=0;colno<4;colno++){
		works=true;
		for(int rno=0;rno<4;rno++){
			if(solutionString[rno*4+colno] != search[rno]){
				works=false;
				break;
			}
		}

		if(works)return true;
		works=true;

		for(int rno=0;rno<4;rno++){
			if(solutionString[rno*4+colno] != search[3-rno]){
				works=false;
				break;
			}
		}

		if(works)return true;
		works=true;
	}
	return false;
}

string ninRot(string x){
	string y;

	int z=16;
	for(int i=0;i<16;i++){
		z-=4;
		y.push_back(x[z]);
		if(z<4)z+=17;
	}
	return y;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	// cout<<"abcdefghijklmnop"<<endl;
   	// string temp = ninRot("abcdefghijklmnop");
   	// cout<<temp<<endl;

   	int t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		int n;
   		cin>>n;
   		string s,t;
   		set<string> mySet;


   		for(int i=0;i<n;i++){
   			cin>>s;

   			if(mySet.find(s)!=mySet.end()){
   				continue;
   			}
   			t=s;
   			reverse(s.begin(),s.end());
   			if(mySet.find(s)!=mySet.end()){
   				continue;
   			}

   			if(s<t)
	   			mySet.insert(s);
	   		else
	   			mySet.insert(t);
   		}

   		if(mySet.size()<=4){
   			for(int i=0;i<4-mySet.size();i++){
   				cout<<"AAAA"<<endl;
   			}
   			set<string>::iterator asd=mySet.begin();
   			for(int i=4-mySet.size();i<4;i++){
   				cout<<*asd<<endl;
   				asd++;
   			}
   			cout<<endl;
   			continue;
   		}



   		set<char> charSet;
   		for(set<string>::iterator asd = mySet.begin();asd!=mySet.end();asd++){
   			for(int i=0;i<4;i++){
   				charSet.insert((*asd)[i]);
   			}
   		}

   		if(charSet.size()>16 || mySet.size()>8){
   			cout<<"grid"<<endl;
   			cout<<"snot"<<endl;
   			cout<<"poss"<<endl;
   			cout<<"ible"<<endl;
   			cout<<endl;
   			continue;
   		}

   		//main search


   		vector<string> myVec;
   		for(set<string>::iterator asd = mySet.begin();asd!=mySet.end();asd++){
   			myVec.push_back(*asd);
   			// cout<<*asd<<endl;
   		}

   		vector<string> revVec;
   		for(int i=0;i<myVec.size();i++){
   			revVec.push_back(myVec[i]);
   			reverse(revVec[i].begin(), revVec[i].end());
   		}



   		set<string>solutionSet;
   		string solutionString;
   		bool works;
   		int revtemp;

   		for(int i=0;i<myVec.size();i++){
	   		for(int j=0;j<myVec.size();j++){
	   			if(i==j)continue;
		   		for(int k=0;k<myVec.size();k++){
		   			if(i==k||j==k)continue;
			   		for(int l=0;l<myVec.size();l++){

			   			if(i==l||j==l||k==l)continue;

			   			for(int rev=0;rev<16;rev++){
				   			solutionString.clear();
				   			works=true;
				   			revtemp=rev;


				   			if((revtemp)&1)
					   			solutionString+=myVec[i];
					   		else
					   			solutionString+=revVec[i];

					   		revtemp=revtemp>>1;

				   			if((revtemp)&1)
					   			solutionString+=myVec[j];
					   		else
					   			solutionString+=revVec[j];

					   		revtemp=revtemp>>1;

				   			if((revtemp)&1)
					   			solutionString+=myVec[k];
					   		else
					   			solutionString+=revVec[k];

					   		revtemp=revtemp>>1;

				   			if((revtemp)&1)
					   			solutionString+=myVec[l];
					   		else
					   			solutionString+=revVec[l];

				   			for(int z=0;z<myVec.size();z++){
				   				if(z==i||z==j||z==k||z==l)continue;
				   				if(!inGrid(solutionString,myVec[z])){
				   					works=false;
				   					break;
				   				}
				   			}

				   			if(works){
				   				solutionSet.insert(solutionString);
				   				//do three rotates
				   				solutionString=ninRot(solutionString);
				   				solutionSet.insert(solutionString);
				   				solutionString=ninRot(solutionString);
				   				solutionSet.insert(solutionString);
				   				solutionString=ninRot(solutionString);
				   				solutionSet.insert(solutionString);

				   			}
			   			}
			   		}			   			
		   		}		   			
	   		}
   		}

   		string ans = *solutionSet.begin();

   		for(int i=0;i<16;i++){
   			cout<<ans[i];
   			if(i%4==3)cout<<endl;
   		}
   		cout<<endl;

   	}
}