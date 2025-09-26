#include <iostream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class stack {
private:
	struct Node {
		int val;
		Node* next;
		Node(int k) {
			val = k;
			next = NULL;
		}
	};
	
	Node* point;

	
public:
	stack() {
		point = NULL;
	}
	
	void push(int k) {
		Node* newNode = new Node(k);
		if (point == NULL) {
			point = newNode;
		} else {
			newNode->next = point;
			point = newNode;
		}
		return;
	}
	
	int pop() {
		if (point == NULL) {
			return INT_MIN;
		} else {
			Node* temp = point;
			point = point->next;
			int ans = temp->val;
			delete temp;
			return ans;
		}
	}
	
	void print() {
		Node* temp = point;
		while(temp != NULL) {
			cout << (temp->val) << " ";
			temp = temp->next;
		}
		cout << endl;
		return;
	}
	
	void query(string q) {
		stringstream ss(q);
		string Q;
		int k;
		ss >> Q >> k;
		if (Q == "PUSH") {
			push(k);
		} else if (Q == "POP") {
			int val = pop();
			if (val == INT_MIN) {
				cout << "NULL" << endl;
			} else {
				cout << val << endl;
			}
			
		} else {
			//cout << "Something wrong!" << endl;
			return;
		}
	}
};

int main() {
	string q;
	getline(cin, q);
	stack S;
	while(q != "#") {
		S.query(q);
		fflush(stdin);
		getline(cin, q);
	
	}
	return 0;
}
