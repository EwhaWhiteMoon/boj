#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct segTree{
	int N;
	vector<long long int> V;

	segTree(int _n){
		N = 1;
		while(N < _n) N *= 2;
		V.resize(N * 2, 0);
	}

	long long int sum(int i, int j){
		i += N; j += N;
		long long int s = 0;

		while(i <= j){
			if(i % 2 == 1) s += V[i++];
			if(j % 2 == 0) s += V[j--];
			i /= 2; j /= 2;
		}

		return s;
	}

	void modify(int i, int k){
		i += N;
		V[i] = k;
		while(i > 1){
			i /= 2;
			V[i] = V[i * 2] + V[i * 2 + 1];
		}
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	segTree S(N);

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0){
			if(b > c) swap(b, c);
			cout << S.sum(b, c) << '\n';
		}
		if(a == 1) S.modify(b, c);
	}
}
