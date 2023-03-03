#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct UnionFind {
	vector<int> P;
	UnionFind(int N) : P(N + 1) {
		for(int i = 0; i <= N; i++){
			P[i] = i;
		}
	}

	void U(int a, int b){
		P[F(a)] = F(b);
	}

	int F(int n){
		if(P[n] == n) return n;
		return P[n] = F(P[n]);
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	UnionFind UF(N);
	for(int i = 0; i < M; i++){
		int x, a, b;
		cin >> x >> a >> b;
		if(!x){
			UF.U(a, b);
		}else{
			cout << ((UF.F(a) == UF.F(b)) ? "YES" : "NO") << '\n';
		}
	}
}
