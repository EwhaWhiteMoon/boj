#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define _M 1000000007

using namespace std;

typedef long long int llint;

struct segTree{
	int N = 1;
	vector<pair<llint, llint>> V;

	void update(int n){
		// c(ax + b) + d = acx + bc + d;
		auto [a, b] = V[n * 2];
		auto [c, d] = V[n * 2 + 1];

		//cout << n << " : " << (a * c) << "x + " << (b * c + d) << '\n';
		V[n] = make_pair((a * c) % _M, (b * c + d) % _M);
	}

	segTree(vector<pair<int, int>> v){
		int n = v.size(); while(N < n) N *= 2;

		V.resize(N * 2, make_pair(1, 0)); // 1x + 0 = x
		for(int i = 0; i < n; i++){
			V[N + i] = v[i];
		}

		for(int i = N - 1; i > 0; i--) update(i);
	}

	llint change(int i, pair<int, int> p){
		i += N;
		V[i] = p;

		while(i > 1){
			i /= 2;
			update(i);
		}
		
		auto [a, b] = V[1];
		return b;
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	vector<pair<int, int>> V(N); // ax + b에서 a, b

	for(int i = 0; i < N; i++){
		char c;
		int n;

		cin >> c >> n;
		if(c == '+') V[i] = make_pair(1, n);
		if(c == '*') V[i] = make_pair(n, 0);
	}

	segTree S(V);

	for(int i = 0; i < Q; i++){
		int t, n;
		char c;
		cin >> t >> c >> n;
		t--;
		cout << S.change(t, c == '*' ? 
				make_pair(n, 0):
				make_pair(1, n)) << '\n';
	}
}
