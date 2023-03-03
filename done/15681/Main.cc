#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef vector<vector<int>> graph;

void subtree(graph &G, int R, vector<int> &size){ //모든 정점의 서브트리 크기를 구함
	int N = G.size();

	queue<int> Q;
	stack<int> S;
	vector<bool> visit(N, false);
	vector<int> parent(N);

	Q.push(R);
	S.push(R);

	while(!Q.empty()){
		int from = Q.front(); Q.pop();
		if(visit[from]) continue;
		visit[from] = true;
		for(int to : G[from]){
			if(visit[to]) continue;
			parent[to] = from;
			Q.push(to);
			S.push(to);
		}
	}

	while(!S.empty()){
		int cur = S.top(); S.pop();
		for(int child : G[cur]){
			if(child == parent[cur]) continue;
			size[cur] += size[child];
		}
//		cout << "size of " << cur << " is " << size[cur] << '\n';
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, R, Q; // 정점의 수 N, 루트 노드 R, 쿼리의 수 Q
	
	cin >> N >> R >> Q;
	R--;

	graph G(N);

	for(int i = 0; i < N - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> size(N, 1); //자기 자신의 크기까지 포함하니까 미리미리 1 넣어주기
	
	subtree(G, R, size);
	//	for(int i : size) cout << i << ' '; cout << '\n';

	int u;
	for(int i = 0; i < Q; i++){
		cin >> u;
		u--;
		cout << size[u] << '\n';
	}

	return 0;
}
