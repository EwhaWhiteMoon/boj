#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;

int dijk(graph &G, int from, int to){
	int N = G.size();

	vector<int> dest(N, 0x3F3F3F3F);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; //<distance, no>
	
	Q.emplace(0, from);

	while(!Q.empty()){
		auto [d, n] = Q.top(); Q.pop();
		if(dest[n] <= d) continue;
		dest[n] = d;

		for(auto [t, cost] : G[n]){
			Q.emplace(d + cost, t);
		}
	}

	return dest[to];
}

int main(){
	int N, M;
	cin >> N >> M;

	graph G(N);

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].emplace_back(b, c);
	}

	int from, to;
	cin >> from >> to;
	from--; to--;

	cout << dijk(G, from, to);
}
