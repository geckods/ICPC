#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<pair<int,int>,int> > firstRow;
    vector<pair<pair<int,int>,int> > secondRow;

    pair<int,int> minipair;

    for(int i=0;i<n;i++){
    	cin>>minipair.first;
    	firstRow.push_back(make_pair(minipair, i));
    }
    for(int i=0;i<n;i++){
    	cin>>firstRow[i].first.second;
    }

    for(int i=0;i<n;i++){
    	cin>>minipair.first;
    	secondRow.push_back(make_pair(minipair,i));
    }
    for(int i=0;i<n;i++){
    	cin>>secondRow[i].first.second;
    }

    sort(firstRow.begin(),firstRow.end());
    sort(secondRow.begin(),secondRow.end());

	int firstRowAnsArr[n];
	int secondRowAnsArr[n];
	int tj=0;
	int tk=0;
	int bj=0;
	int bk=0;

	set<pair<int,int> > topset;
	set<pair<int,int> > botset;
	pair<int,int> tempPair;

	int myMin;
	int currVal;
	int currInd;
	set<pair<int,int> >::iterator it;

	int bigIter = 0;
	while(bigIter<n){

		if(topset.empty()){

			// while(tj<n){
			// 	topset.insert(make_pair(firstRow[tj].first.second, firstRow[tj].second));
			// 	tj++;
			// 	if(tj==n || firstRow[tj].first.first  != firstRow[tj-1].first.first) break;
			// }

			tk = tj+1;
			while(tk<n && firstRow[tk].first.first == firstRow[tk-1].first.first)tk++;
			tk--;
			for(int i=tj;i<=tk;i++){
				tempPair.first = firstRow[i].first.second;
				tempPair.second = firstRow[i].second;
				topset.insert(tempPair);
			}
			tj = tk+1;
		}

		if(botset.empty()){
			// while(bj<n){
			// 	botset.insert(make_pair(secondRow[bj].first.second, secondRow[bj].second));
			// 	bj++;
			// 	if(bj==n || secondRow[bj].first.first  != secondRow[bj-1].first.first) break;
			// }


			bk = bj+1;
			while(bk<n && secondRow[bk].first.first == secondRow[bk-1].first.first)bk++;
			bk--;
			for(int i=bj;i<=bk;i++){
				tempPair.first = secondRow[i].first.second;
				tempPair.second = secondRow[i].second;
				botset.insert(tempPair);
			}
			bj = bk+1;
		}


		myMin = min(botset.size(),topset.size());
//		cout<<bigIter<<" "<<botset.size()<<" "<<topset.size()<<endl;

		if(myMin==0){
			cout<<"impossible"<<endl;
			return 0;
		}

		if(myMin==botset.size()){
			while(!botset.empty()){
				currVal = (*botset.begin()).first;
				currInd = (*botset.begin()).second;
				botset.erase(botset.begin());
				it = topset.lower_bound(make_pair(currVal+1,-1));
//				it = lower_bound(topset.begin(), topset.end(), make_pair(currVal+1,-1));
				if(it==topset.end()){
					cout<<"impossible"<<endl;
					return 0;
				}
				else{
					firstRowAnsArr[bigIter] = (*it).second;
					secondRowAnsArr[bigIter] = currInd;
					topset.erase(it);
				}
				bigIter++;
			}
		}
		else{
			while(!topset.empty()){
				currVal = (*topset.begin()).first;
				currInd = (*topset.begin()).second;
				topset.erase(topset.begin());
				it = botset.lower_bound(make_pair(currVal-1, INT_MAX));
//				it = lower_bound(botset.begin(), botset.end(), make_pair(currVal-1,INT_MAX));
				if(it==botset.begin()){
					cout<<"impossible"<<endl;
					return 0;
				}
				else{
					it--;
					firstRowAnsArr[bigIter] = currInd;
					secondRowAnsArr[bigIter] = (*it).second;
					botset.erase(it);
				}
				bigIter++;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<firstRowAnsArr[i]+1<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<secondRowAnsArr[i]+1<<" ";
	}
	cout<<endl;
	return 0;
}
