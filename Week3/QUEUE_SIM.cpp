#include <iostream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class queue {
private:
	struct Node {
		int val;
		Node* next;
		Node(int k) {
			val = k;
			next = NULL;
		}
	};
	
	Node* head;
	Node* pos;
	
public:
	queue() {
		head = pos = NULL;
	}
	
	void push(int k) {
		Node* newNode = new Node(k);
		if (head == NULL) {
			head = pos = newNode;
		} else {
			pos->next = newNode;
			pos = pos->next;
		}
		return;
	}
	
	int pop() {
		if (head == NULL) {
			return INT_MIN;	
		} else {
			Node* temp = head;
			head = head->next;
			int ans = temp->val;
			delete temp;
			return ans;
		}
	}
	
	void print() {
		Node* temp = head;
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
	queue Q;
	while(q != "#") {
		Q.query(q);
		fflush(stdin);
		getline(cin, q);
	
	}
	return 0;
}
