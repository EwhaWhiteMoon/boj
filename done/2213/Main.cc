#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector<vector<int>> graph;

void solve(graph &G, vector<int> &W){
	//음... tree dfs로 풀 수 있을까?
	//자신이 포함되는 경우와 아닌 경우로 나눠서 수를 세자
	//정점을 출력해야 하네... 벡터를 하나 더 만들자
	
	//자신이 포함되는 경우, 자식들(미포함)의 합 + 자신의 가중치
	//자신이 포함 안 되는 경우, 자식들(max(포함, 미포함))의 합 << 여기서, 포함되는 애들을 벡터로 저장해야댐

	int N = G.size();
	vector<pair<int, int>> D(N); //자신이 포함되는 경우, 아닌 경우

	function<void(int, int)> dfs = [&](int cur, int parent){
		int y = W[cur], n = 0; //자신 포함, 자신 미포함

//		cout << cur << ' ' << parent << endl;

		for(int i : G[cur]){
			if(i == parent) continue;
			
			dfs(i, cur);
			
			auto [cy, cn] = D[i];
			y += cn;
			n += max(cy, cn);
		}

		D[cur] = make_pair(y, n);
	};

	dfs(0, -1);
	auto [a, b] = D[0];

	cout << max(a, b) << '\n';

	vector<int> ans;
	function<void(int, int, bool)> track = [&](int cur, int parent, bool contain){
		if(contain) ans.push_back(cur + 1);

		for(int i : G[cur]){
			if(i == parent) continue;

			if(contain) track(i, cur, false);
			else track(i, cur, D[i].first > D[i].second); 
		}
	};

	track(0, -1, a > b);
	
	sort(ans.begin(), ans.end());
	for(int i : ans) cout << i << ' ';
}

int main(){
	int N;
	cin >> N;

	vector<int> W(N);

	for(int i = 0; i < N; i++) cin >> W[i];

	graph G(N);

	for(int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	solve(G, W);
}
