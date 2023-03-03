#include <iostream>
#include <vector>

using namespace std;

int fibo(int N){
	if(N == 0) return 0;
	int n1 = 0, n2 = 1;
	for(int i = 0; i < N - 1; i++){
		int n3 = n1 + n2;
		n1 = n2 % 1000000007;
		n2 = n3 % 1000000007;
	}
	return n2;
}

int main(){
	int N;
	cin >> N;
	cout << fibo(N);
}
