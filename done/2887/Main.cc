#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int prim(vector<vector<int>> &P){
	int N = P.size();

	vector<vector<int>> rank(3, vector<int>(N)); // rank[_][n] = n번째로 큰 별의 번호
	vector<vector<int>> rankR(3, vector<int>(N));// rank[_][n] = n번째 별이 몇 번째로 큰지

	for(int i = 0; i < 3; i++){
		auto _P = P;
		sort(_P.begin(), _P.end(), [i](vector<int> a, vector<int> b){
					return a[i] < b[i];
				});
		for(int j = 0; j < N; j++){
			rank[i][j] = _P[j][3];
			rankR[i][_P[j][3]] = j;
		}
	}


	vector<bool> visit(N, false);
	long long int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // cost, from

	Q.emplace(0, 0);

	while(!Q.empty()){
		auto [cost, from] = Q.top(); Q.pop();
		
		if(visit[from]) continue;
		visit[from] = true;
		
//		cout << '\n' << from << ' ' << cost << '\n';
		ans += cost;

		for(int i = 0; i < 3; i++){
			int R = rankR[i][from];
			if(R > 0){
				int to = rank[i][R - 1];
//				cout << from << "->" << to << ':' << P[from][i] - P[to][i] << '\n';
				Q.emplace(P[from][i] - P[to][i], to);
			}
			if(R < N - 1){
				int to = rank[i][R + 1];
//				cout << from << "+>" << to << ':' << P[to][i] - P[from][i] <<'\n';
				Q.emplace(P[to][i] - P[from][i], to);
			}
		}
	}
	return ans;
}

int main(){
	int N;

	cin >> N;
	vector<vector<int>> P(N, vector<int>(4)); // x, y, z, n

	for(int i = 0; i < N; i++){
		int x, y, z;
		cin >> x >> y >> z;
		P[i][0] = x; P[i][1] = y; P[i][2] = z; P[i][3] = i;
	}

	cout << prim(P);
}

