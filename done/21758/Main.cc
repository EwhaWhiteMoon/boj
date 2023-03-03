#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> V(N);
	vector<int> sum(N);
	int M = 0;
	for(int i = 0; i < N; i++){
		cin >> V[i];
		sum[i] = V[i] + ((i > 0) ? sum[i - 1] : 0);
		if(i > 0 && i < N - 1) M = max(V[i], M);
	}

	int r = 0; //벌통이 오른쪽일 때
	for(int i = N - 2; i > 0; i--){
		r = max(r,
				sum[N - 1] - V[0] - V[i]
				+ sum[N - 1] - sum[i]
			   );
	}

	int l = 0; //벌통이 왼쪽일 때
	for(int i = 1; i < N - 1; i++){
		l = max(l,
				sum[N - 1] - V[N - 1] - V[i]
				+ sum[i - 1]
			   );
	}

//	cout << r << endl;
//	cout << l << endl;
//	cout << sum[N - 1] - V[0] - V[N - 1] + M<< endl;
				
	cout << max(max(l, r),
				sum[N - 1] - V[0] - V[N - 1] + M
			);
}
