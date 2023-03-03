#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph; //<to, cost>

pair<int, int> farthest(graph G, int start, int ignore){ // 제일 먼 정점 찾기, return <no, distance>
	int N = G.size();

	queue<int> Q; //no
	vector<int> dest(N, -1);
	
	Q.push(start);
	dest[start] = 0;

	int far = start;

	while(!Q.empty()){
		int from = Q.front(); Q.pop();
		for(auto [to, cost] : G[from]){
			if(to == ignore || dest[to] != -1) continue;
			dest[to] = dest[from] + cost;
			if(dest[to] >= dest[far]) far = to;
			Q.push(to);
		}
	}

	return make_pair(far, dest[far]);
}
int main(){
	int N;
	cin >> N;

	graph G(N);

	for(int i = 0; i < N - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}

	//두 번째 지름을 어떻게 찾지?
	//아이디어: 지름을 일단 찾고, 지름의 양 끝 간선 중에 짧은 걸 잘라내고 다시 지름을 찾으면 어떨까
	//두 번째 지름이 트리의 지름과 같은 상황은 트리의 지름이 여러 개 인 상황이겠구나!!
	//사이클이 없으니까, 지름의 양 끝은 무조건 다른 노드와 이어진 간선이 하나뿐이다. 증명은 여백이 모자람.

	//앗... 둘 다 해 봐야 함!
	//예외 케이스
	/* 6
	 * 1 2 1 <<이 간선과
	 * 3 2 1 <<이 간선
	 * 2 4 1
	 * 4 5 1
	 * 5 6 1 <<이 간선(자르면 안 되는 간선) 을 길이로 구분할 수 없음
	 */

	//트리의 지름의 양쪽 끝
	int A1 = farthest(G, 0, -1).first;
	int B1 = farthest(G, A1, -1).first;
	
	int temp = farthest(G, B1, A1).first;
	int noA1 = farthest(G, temp, A1).second;

	temp = farthest(G, A1, B1).first;
	int noB1 = farthest(G, temp, B1).second;

	cout << max(noA1, noB1);
}
