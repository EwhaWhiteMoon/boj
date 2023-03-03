#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void mSort(vector<int> &V, int start, int end, long long &inv){
	if(end - start == 1) return;
	int mid = (start + end) / 2;

	mSort(V, start, mid, inv);
	mSort(V, mid, end, inv);

	int l = start, r = mid;
	vector<int> T;
	while(l != mid && r != end){
		if(V[l] <= V[r]){
			T.push_back(V[l++]);
			inv += (r - mid);
		}
		else{
			T.push_back(V[r++]);
		}
	}
	while(l != mid){
		T.push_back(V[l++]);
		inv += r - mid;
	}
	while(r != end) T.push_back(V[r++]);

	for(int i = start; i < end; i++){
		V[i] = T[i - start];
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	vector<int> V;

	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		V.push_back(a);
	}
	long long inv = 0;
	mSort(V, 0, N, inv);
	cout << inv << endl;
}
