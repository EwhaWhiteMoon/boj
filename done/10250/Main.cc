#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int H, W, N;
		cin >> H >> W >> N;

		int x, y;
		x = N % H;
		y = N / H + 1;
		if(x == 0){
			x = H;
			y -= 1;
		}
		printf("%d%02d\n", x, y);
	}
}
