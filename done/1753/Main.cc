#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int,int>>> graph;

void dij(graph &G, int S, vector<int> &D){

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

	Q.emplace(0, S);

	while(!Q.empty()){
		auto [w, v] = Q.top(); Q.pop();
		if(D[v] <= w) continue;
		D[v] = w;
		for(auto [a, b] : G[v]){
			if(D[a] <= D[v] + b) continue;
			Q.emplace(D[v] + b, a);
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	int S;
	cin >> S;
	S--;

	graph G(V);

	for(int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		G[u].push_back(make_pair(v, w));
	}
	
	vector<int> D(V, 0x3F3F3F3F);
	dij(G, S, D);

	for(int i : D){
		if(i == 0x3F3F3F3F) cout << "INF" << '\n';
		else cout << i << '\n';
	}

	return 0;
}
