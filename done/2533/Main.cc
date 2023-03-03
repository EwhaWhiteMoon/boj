#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef vector<vector<int>> graph; // to

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	graph G(N);
	
	for(int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<vector<int>> DP(N, vector<int>(2)); // 얼리어답터일 때, 아닐 때
	
	function<void(int, int)> dfs = [&](int cur, int p){
		DP[cur][0] = 1;
		DP[cur][1] = 0;

		for(int i : G[cur]){
			if(i == p) continue;
			dfs(i, cur);
			DP[cur][0] += min(DP[i][0], DP[i][1]);
			DP[cur][1] += DP[i][0];
		}
	};

	dfs(0, -1);
	cout << min(DP[0][0], DP[0][1]);
}
