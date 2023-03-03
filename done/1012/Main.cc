#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int solve(vector<vector<bool>> &G){
	int M = G.size();
	int N = G[0].size();

	vector<vector<bool>> visit(M, vector<bool>(N, false));

	int cnt = 0;

	function<void(int, int)> bfs = [&](int i, int j){
		if(i < 0 || i >= M || j < 0 || j >= N) return;

		if(!G[i][j]) return;
		if(visit[i][j]) return;

		visit[i][j] = true;
		bfs(i - 1, j); bfs(i + 1, j);
		bfs(i, j - 1); bfs(i, j + 1);
	};

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(!G[i][j]) continue;
			if(visit[i][j]) continue;

			cnt ++;
			bfs(i, j);
		}
	}
	return cnt;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int _i = 0; _i < T; _i++){
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<bool>> G(M, vector<bool>(N, false));

		for(int i = 0; i < K; i++){
			int x, y;
			cin >> x >> y;
			G[x][y] = true;
		}

		cout << solve(G) << '\n';
	}
}
