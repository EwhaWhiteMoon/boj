#include <iostream>
#include <string>

using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			return 0;
		}

		string s = to_string(n);
		
		bool isP = true;
		string::iterator l, r;
		l = s.begin();
		r = s.end() - 1;
		while(l < r){
			if(*l != *r){
				isP = false;
				break;
			}
			l++;
			r--;
		}
		cout << (isP ? "yes" : "no") << '\n';
	}
}
