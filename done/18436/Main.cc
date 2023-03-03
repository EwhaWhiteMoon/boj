#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> add_pair(pair<int, int> a, pair<int, int> b){
	return make_pair(a.first + b.first, a.second + b.second);
}

struct segTree{
	int N;
	vector<pair<int, int>> T; //odd, even
	segTree(vector<int> V){
		int n = V.size();
		N = 1; while(N < n) N *= 2;

		T.resize(N * 2, make_pair(0, 0));

		for(int i = 0; i < n; i++){
			if(V[i] % 2 == 1){
				T[i + N] = make_pair(1, 0);
			}else{
				T[i + N] = make_pair(0, 1);
			}
		}

		for(int i = N - 1; i > 0; i--){
			T[i] = add_pair(T[i * 2], T[i * 2 + 1]);
		}
	}

	void set(int i, int v){
		i += N;
		if(v % 2 == 1){
			T[i] = make_pair(1, 0);
		}else{
			T[i] = make_pair(0, 1);
		}
		while(i > 1){
			i /= 2;
			T[i] = add_pair(T[i * 2], T[i * 2 + 1]);
		}
	}

	pair<int, int> get(int i, int j){
		i += N; j += N;
		pair<int, int> ans(0, 0);

		while(i <= j){
			if(i % 2 == 1) ans = add_pair(ans, T[i++]);
			if(j % 2 == 0) ans = add_pair(ans, T[j--]);

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
		else if(a == 2) cout << S.get(b - 1, c - 1).second << '\n';
		else if(a == 3) cout << S.get(b - 1, c - 1).first << '\n';
	}
}
