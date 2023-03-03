#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;

int dijk(graph &G, int a, int b){
	int N = G.size();

	vector<int> dist(N, 0x3F3F3F3F);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;//pair<weight, point>
	
	Q.emplace(0, a);

	while(!Q.empty()){
		auto [weight, from] = Q.top(); Q.pop();
		if(dist[from] <= weight) continue;
		dist[from] = weight;
		for(auto [to, cost] : G[from]){
			Q.emplace(weight + cost, to);
		}
	}

/*	cout << a << " to " << b << '\n';
	for(auto i : dist){
		cout << i << ' ';
	}
	cout << '\n';
*/
	return dist[b];
}

bool isInf(int n){
	return (n == 0x3F3F3F3F);
}

int main(){
	int N, E;
	cin >> N >> E;
	graph G(N);

	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}

	int v1, v2;
	cin >> v1 >> v2;
	v1 --; v2 --;
	
	int oneToV1 = dijk(G, 0, v1);
	int oneToV2 = dijk(G, 0, v2);

	int v1ToV2 = dijk(G, v1, v2);

	int v1ToEnd = dijk(G, v1, N - 1);
	int v2ToEnd = dijk(G, v2, N - 1);

	if(isInf(oneToV1) || isInf(v1ToV2) || isInf(v2ToEnd)){
		cout << -1;
		return 0;
	}
	cout << min(oneToV1 + v2ToEnd, oneToV2 + v1ToEnd) + v1ToV2;
}
