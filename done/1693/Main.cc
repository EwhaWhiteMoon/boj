#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <climits>

#define color_cnt 20

using namespace std;

typedef vector<vector<int>> graph;

int solve(graph &G){
	int N = G.size();

	vector<vector<int>> C(N, vector<int>(color_cnt)); //colors;

	function<void(int, int)> dfs = [&](int cur, int p){
		for(int i = 0; i < color_cnt; i++)C[cur][i] = (i + 1);

		for(int i : G[cur]){
			if(i == p) continue;
			dfs(i, cur);

			int minIdx = 0;
			int minIdx2 = 1;
			if(C[i][minIdx2] <= C[i][minIdx]) swap(minIdx2, minIdx);
			
			for(int j = 2; j < color_cnt; j++){
				if(C[i][j] <= C[i][minIdx2]) minIdx2 = j;
				if(C[i][minIdx2] <= C[i][minIdx]) swap(minIdx2, minIdx);
			}

			for(int c = 0; c < color_cnt; c++){
				if(c != minIdx) C[cur][c] += C[i][minIdx];
				else C[cur][c] += C[i][minIdx2];
			}
		}
	};

	dfs(0, -1);
	int ans = INT_MAX;
	for(int i : C[0]) ans = min(ans, i);
	return ans;
}

int main(){
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

	cout << solve(G);
}
