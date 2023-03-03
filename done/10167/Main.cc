//2022년 7월 30일 토요일 14시 54분 27초 KST

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long int llint;

struct segTree{
	int N;
	vector<tuple<llint, llint, llint, llint>> V; // val, lval, rval, sum;
	
	void update(int i){
		auto [val1, lval1, rval1, sum1] = V[i * 2];
		auto [val2, lval2, rval2, sum2] = V[i * 2 + 1];

		V[i] = make_tuple(
				max(rval1 + lval2, max(val1, val2)),
				max(lval1, sum1 + lval2),
				max(rval2, sum2 + rval1),
				sum1 + sum2
				);
	}

	segTree(int n){
		N = 1;
		while(N <= n) N *= 2;

		//cout << N << "!\n";
		V.resize(N * 2, make_tuple(0, 0, 0, 0));
		fill(V.begin(), V.end(), make_tuple(0, 0, 0, 0));
	}

	llint add(int i, int w){
		i += N;
		auto [val, lval, rval, sum] = V[i];

		V[i] = make_tuple(
				max(sum + w, 0ll), 
				max(sum + w, 0ll),
				max(sum + w, 0ll),
				sum + w);

		while(i > 1){
			i /= 2;
			update(i);
		}

		//cout << "staues : "; for(int i = 0; i <= N; i++){cout << get<3>(V[i + N]) << ' ';} cout << endl;

		return get<0>(V[1]);
	}
};

llint solve(vector<tuple<int, int, int>> &V, int cX, int cY){
	int N = V.size();

	llint ans = LLONG_MIN;

	for(int i = 0; i <= cY; i++){
		segTree S(cX);

		//cout << "staues : "; for(int i = 0; i <= S.N; i++){cout << get<3>(S.V[i + S.N]) << ' ';} cout << endl;
		for(int j = 0; j < N; j++){
			auto[x, y, w] = V[j];

			if(y < i) continue;

			llint t = S.add(x, w);
			if(j == N - 1 || y != get<1>(V[j + 1])){
				ans = max(ans, t);
				//cout << i << ' ' << y << ' ' << t << endl;
			}
		}
	}

	return ans;
}

int main(){
	int N;
	cin >> N;

	vector<tuple<int, int, int>> V(N); //x, y, w
	
	for(int i = 0; i < N; i++){
		int x, y, w;
		cin >> x >> y >> w;

		V[i] = make_tuple(x, y, w);
	}
	//좌표 압축 해야댐...
	sort(V.begin(), V.end());

	int cX = 0;
	int priv = get<0>(V[0]);
	for(int i = 0; i < N; i++){
		if(get<0>(V[i]) != priv) cX ++;
		priv = get<0>(V[i]);

		get<0>(V[i]) = cX;
	}

	sort(V.begin(), V.end(),
			[](tuple<int, int, int> a, tuple<int, int, int> b){
				return get<1>(a) < get<1>(b);
			});

	int cY = 0;
	priv = get<1>(V[0]);
	for(int i = 0; i < N; i++){
		if(get<1>(V[i]) != priv) cY ++;
		priv = get<1>(V[i]);

		get<1>(V[i]) = cY;
	}

	cout << solve(V, cX, cY);
}
