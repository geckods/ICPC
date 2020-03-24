#include <bits/stdc++.h>
using namespace std;

// bool sortbypairfirst(const pair<pair<int,int>,int> &a, 
//               const pair<pair<int,int>,int> &b) 
// { 
//     return (a.first.first < b.first.first); 
// } 

// bool sortbypairsecond(const pair<pair<int,int>,int> &a, 
//               const pair<pair<int,int>,int> &b) 
// { 
//     return (a.first.second < b.first.second); 
// } 

// bool othersortbypairsecond(const pair<pair<int,int>,int> &a, 
//               const pair<pair<int,int>,int> &b) 
// { 
//     return (a.first.second > b.first.second); 
// } 


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

    // cout<<"HI"<<endl;
    // fflush(stdout);


    for(int i=0;i<n;i++){
    	cin>>minipair.first;
    	secondRow.push_back(make_pair(minipair,i));
    }
    for(int i=0;i<n;i++){
    	cin>>secondRow[i].first.second;
    }




    sort(firstRow.begin(),firstRow.end());
    sort(secondRow.begin(),secondRow.end());

    // for(int i=0;i<n;i++){
    // 	cout<<firstRow[i].first.first<<" "<<firstRow[i].first.second<<endl;
    // }
    // cout<<endl;



    // int firstarr[n];
    // for(int i=0;i<n;i++){
    // 	firstarr[i]=firstRow[i].first.first;
    // }

    // int secondarr[n];
    // for(int i=0;i<n;i++){
    // 	secondarr[i]=secondRow[i].first.first;
    // }

    // int i=0;
    // int last;
    // int currSize;

    // while(i<n){
    // 	currSize = firstRow[i].first.first;
    // 	last = upper_bound(firstarr+i,firstarr+n, currSize)-firstarr-1;
    // 	sort(firstRow.begin()+i,firstRow.begin()+last+1,othersortbypairsecond);
    // 	i=last+1;
    // }

    // i=0;
    // while(i<n){
    // 	currSize = secondRow[i].first.first;
    // 	last = upper_bound(secondarr+i,secondarr+n, currSize) - secondarr-1;
    // 	sort(secondRow.begin()+i,secondRow.begin()+last+1,othersortbypairsecond);
    // 	i=last+1;
    // }

    // for(int i=0;i<n;i++){
    // 	cout<<firstRow[i].first.first<<" "<<firstRow[i].first.second<<endl;
    // }
    // cout<<endl;

    // for(int i=0;i<n;i++){
    // 	cout<<secondRow[i].first.first<<" "<<secondRow[i].first.second<<endl;
    // }
    // cout<<endl;


/*
	i=0;
	int j=0;
	int k=0;
	int l;

	int firstRowAnsArr[n];

	
	THIS APPROACH IS INCORRECT
	while(i<n){
		set<pair<int,int> > mySet;
		//fill the set
		pair<int,int> tempPair;
		k = lower_bound(firstarr, firstarr+n, secondRow[i].first.first)-firstarr;
		while(firstarr[k]==secondRow[i].first.first){
			tempPair.first = firstRow[k].first.second;
			tempPair.second = k;
			k++;
		}

		j=i;
		while(secondRow[j].first.first==secondRow[i].first.first){
			set<pair<int,int> > ::iterator it = lower_bound(mySet.begin(), mySet.end(), make_pair(secondRow[j].first.second,-1));
			if(it==mySet.end()){
				cout<<"impossible"<<endl;
				return 0;
			}
			else{
				firstRowAnsArr[j]=(*it).second;
				mySet.erase(it);
			}
		}

		i = j;
	}
*/

	//I'll have to two pointers this
	//one pointer for each thing

	//when the pointer encounters a new price on either row, I'll have to stop, use sets to check if everything has a solution.

	/*
	i=0;
	j=0;

	while(i<n){
		j = i+1;
		while(j<n && firstRow[j].first.first == firstRow[j-1].first.first && secondRow[j].first.first == secondRow[j-1].first.first)j++;
		j--;
//		cout<<i<<" "<<j<<endl;

		set<pair<int,int> > mySet;
		pair<int,int> tempPair;
		for(int k=i;k<=j;k++){
			tempPair.first = firstRow[k].first.second;
			tempPair.second = firstRow[k].second;
			mySet.insert(tempPair);
		}

		for(int k=i;k<=j;k++){
			set<pair<int,int> > ::iterator it = lower_bound(mySet.begin(), mySet.end(), make_pair(secondRow[k].first.second+1,-1));
			if(it==mySet.end()){
				cout<<"impossible"<<endl;
				return 0;
			}
			else{
				firstRowAnsArr[j]=(*it).second;
				mySet.erase(it);
			}
		}
		i=j+1;
	}

	*/

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
	// int prevBigIter=-1;
	while(bigIter<n){
		// prevBigIter = bigIter;

		// if(bj>=n || tj>=n){
		// 	break;
		// }

//		cout<<bigIter<<" "<<botset.size()<<" "<<topset.size()<<" "<<tj<<" "<<endl;

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
				it = lower_bound(topset.begin(), topset.end(), make_pair(currVal+1,-1));
//				cout<<"HI"<<currVal<<" "<<(*topset.begin()).first<<endl;
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
				it = lower_bound(botset.begin(), botset.end(), make_pair(currVal-1,INT_MAX));
//				cout<<bigIter<<"ASD"<<(*it).first<<" "<<currVal<<endl;
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
		// if(bigIter==prevBigIter){
		// 	return 0;
		// }
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
