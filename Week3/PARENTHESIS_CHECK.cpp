#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isCorrect(string str) {
	if (str.length() % 2 != 0) return false;
	stack<char> S;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			S.push(str[i]);
		} else {
			if (str[i] == ')') {
				if (S.top() != '(') return false;
				
			} else if (str[i] == ']') {
				if (S.top() != '[') return false;
				
			} else if (str[i] == '}') {
				if (S.top() != '{') return false;
				
			} else {
				return false;
			}
			S.pop();
		}
	}
	return S.empty();
}

int main() {
	string str;
	getline(cin, str);
	
	cout << isCorrect(str) << endl;
	
	return 0;
}
