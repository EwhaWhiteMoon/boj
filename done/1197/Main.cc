#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<tuple<int, int, int>> graph; // cost, from, to

struct UnionFind{
	vector<int> V;

	UnionFind(int N) : V(N){
		for(int i = 0; i < N; i++) V[i] = i;
	}

	void Union(int a, int b){
		V[Find(a)] = Find(b);
	}

	int Find(int a){
		if(V[a] == a) return a;
		return V[a] = Find(V[a]);
	}
};

int getMST(graph &G, int N){
	int costSum = 0;

	UnionFind UF(N);

	for(auto [c, a, b] : G){
		if(UF.Find(a) != UF.Find(b)){
			UF.Union(a, b);
			costSum += c;
		}
	}

	return costSum;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;
	graph G(E);

	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[i] = make_tuple(c, a, b);
	}

	sort(G.begin(), G.end());

	cout << getMST(G, V);
}
