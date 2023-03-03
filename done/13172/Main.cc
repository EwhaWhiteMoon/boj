#include <iostream>
#include <algorithm>

#define P 1000000007

typedef long long int llint;

using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

pair<llint, llint> exGcd(llint a, llint b){
	if(b == 0) return {1, 0};
	//ax + by = c일 때, b = 0, x = 1 y = 0

	llint k = a / b;
	
	auto [x, y] = exGcd(b, a - b * k);

	return {y, x - k * y};
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio();

	int M;
	cin >> M;

	long long int ans = 0;

	int N, S;
	for(int i = 0; i < M; i++){
		cin >> N >> S;
		int t = gcd(N, S);
		N /= t; S/= t;
		ans += (S * ((exGcd(N, P).first + P) % P)) % P;
		ans %= P;
	}

	cout << ans;
}
