#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> D(N, vector<int>(N, 0x3F3F3F3F));
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a --;
		b --;
		D[a][b] = min(D[a][b], c);
	}
	for(int i = 0; i < N; i++){
		D[i][i] = 0; 
	}
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(D[i][j] == 0x3F3F3F3F) D[i][j] = 0;
			cout << D[i][j] << ' ';
		}
		cout << '\n';
	}
}
