#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int search(int target, vector<vector<int>> const& condition, vector<int> const& cost, vector<long long int> &memo){
	long long int t = cost[target];
	if(memo[target] != -1){
		return memo[target];
	}
	for(auto i : condition[target]){
		t = max(search(i, condition, cost, memo) + cost[target], t); 
	}
	return memo[target] = t;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int N, K;

		cin >> N >> K;

		vector<int> cost(N);
		vector<vector<int>> condition(N);

		for(int i = 0; i < N; i++){
			cin >> cost[i];
		}

		for(int i = 0; i < K; i++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			condition[b].push_back(a);
		}

		int target;
		cin >> target;
		target --;

		vector<long long int> memo(N, -1);

		cout << search(target, condition, cost, memo) << '\n';
	}
}
