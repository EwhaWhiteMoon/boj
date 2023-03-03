#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> X;
	for(int i = 0; i < N; i++){
		int Xi;
		cin >> Xi;
		X.push_back(Xi);
	}
	vector<int> X_ans = X;
	sort(X.begin(), X.end());
	X.erase(
		unique(X.begin(), X.end()),
		X.end()
	);

	for(int Xi : X_ans){
		cout << lower_bound(X.begin(), X.end(), Xi) - X.begin() << ' ';
	}
}
