#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>

using namespace std;

typedef vector<vector<pair<int,int>>> graph; // to, cost
typedef unsigned long long int ULL;

ULL solve(graph &G, int K){
	int N = G.size();

	vector<vector<ULL>> D(N, vector<ULL>(K + 1, ULLONG_MAX));
	
	priority_queue<tuple<ULL, int, int>, vector<tuple<ULL, int, int>>, greater<tuple<ULL, int, int>>> Q; //dist, cur, removed
	
	Q.emplace(0, 0, 0);

	while(!Q.empty()){
		auto [dist, cur, removed] = Q.top(); Q.pop();

		if(D[cur][removed] <= dist) continue;
		D[cur][removed] = dist;

		for(auto [to, cost] : G[cur]){
			Q.emplace(dist + cost, to, removed);
			if(removed < K)
				Q.emplace(dist, to, removed + 1);
		}
	}

//	for(auto i : D){for(auto j : i) cout << j << ' '; cout << '\n';}

	ULL ans = ULLONG_MAX;
	for(int i = K; i >= 0; i--){
		ans = min(D[N - 1][i], ans);
	}
	return ans;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;

	cin >> N >> M >> K;

	graph G(N);

	for(int i = 0; i < M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;

		from --; to --;

		G[from].emplace_back(to, cost);
		G[to].emplace_back(from, cost);
	}

	cout << solve(G, K);
}
