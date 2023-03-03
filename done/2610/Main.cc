#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> dist(N, vector<int>(N, 0x3F3F3F3F));
	for(int i = 0; i < N; i++){
		dist[i][i] = 0;
	}
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	vector<int> dSum(N, 0);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(dist[i][j] == 0x3F3F3F3F) continue;
			dSum[i] = max(dSum[i], dist[i][j]);
		}
	}

	vector<bool> isDapyo(N, false);
	int dapyoSu = 0;

	for(int i = 0; i < N; i++){
		int dMin = i;
		for(int j = 0; j < N; j++){
			if(dist[i][j] == 0x3F3F3F3F) continue;
			if(dSum[dMin] >= dSum[j]){
				dMin = j;
			}
		}
		if(!isDapyo[dMin]){
			dapyoSu ++;
			isDapyo[dMin] = true;
		}
	}

	cout << dapyoSu << '\n';

	for(int i = 0; i < N; i++){
		if(!isDapyo[i]) continue;
		cout << (i + 1) << '\n';
	}
}
