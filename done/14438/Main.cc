#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

struct segTree{
	vector<int> V;
	int N = 1;

	segTree(vector<int> _V){
		int n = _V.size();

		while(N < n) N *= 2;
		V.resize(N * 2, INT_MAX);
		
		for(int i = 0; i < n; i++){
			V[N + i] = _V[i];
		}
		
		for(int i = N - 1; i > 0; i--){
			V[i] = min(V[2 * i], V[2 * i + 1]);
		}
	}

	void set(int i, int v){
		i += N;
		V[i] = v;
		while(i > 1){
			i /= 2;
			V[i] = min(V[2 * i], V[2 * i + 1]);
		}
	}

	int get(int i, int j){
		int ans = INT_MAX;
		i += N; j += N;

		while(i <= j){
			if(i % 2 == 1) ans = min(ans, V[i++]);
			if(j % 2 == 0) ans = min(ans, V[j--]);

			i /= 2; j /= 2;
		}
		return ans;
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	segTree S(A);

	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) S.set(b - 1, c);
		else if(a == 2) cout << S.get(b - 1, c - 1) << '\n';
	}
}
