#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;

pair<int, int> farthest(graph &G, int start){ // return pair<no, distance>
	int N = G.size();

	queue<int> Q; //<no>
	vector<int> dist(N, -1);
	int f = start;
	
	dist[start] = 0;
	Q.push(start);

	while(!Q.empty()){
		int n = Q.front(); Q.pop();

//		cout << n << ' ' << dist[n] << '\n';

		for(auto [i, j] : G[n]){
			if(dist[i] != -1) continue;
			dist[i] = dist[n] + j;
			if(dist[f] < dist[i]) f = i;
			Q.push(i);
		}
	}
	return make_pair(f, dist[f]);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	graph G(N);

	for(int i = 0; i < N - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}

	auto [n1, d1] = farthest(G, 0);
	auto [n2, d2] = farthest(G, n1);

	cout << d2 << '\n';
	return 0;
}
