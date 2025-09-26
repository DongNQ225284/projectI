#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

struct single_linked {
	struct Node {
		int val;
		Node* next;
		Node(int v = INT_MIN) {
			val = v;
			next = NULL;
		}
	};
	
	bool exist(int u) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->val == u) return true;
			temp = temp->next;
		}
		return false;
	}
	
	Node* head;
	single_linked() {
		head = NULL;
	}
	
	void addfirst(int k) {
		if (exist(k)) return;
		
		Node* newNode = new Node(k);
		if (head == NULL) {
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
		return;
	}	
	
	void addlast(int k) {
		if (exist(k)) return;
		
		Node* newNode = new Node(k);
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		return;
	}
	
	void addafter(int u, int v) {
		if (exist(u)) return;
		if (!exist(v)) return;
		
		Node* newNode = new Node(u);
		Node* temp = head;
		while (temp->val != v) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		return;
	}
	
	void addbefore(int u, int v) {
		if (exist(u)) return;
		if (!exist(v)) return;
			
		if (head->val == v) {
			addfirst(u);
			return;
		}
		
		Node* newNode = new Node(u);
		Node* temp = head;
		while (temp->next->val != v) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		return;
	}
	
	void remove(int k) {
		if (!exist(k)) return;
		
		if (head == NULL) {
			return;
		}
		Node* temp = head;
		if (head->val == k) {
			head = head->next;
			delete temp;
			return;
		}
		
		while (temp->next->val != k) {
			temp = temp->next;
		}
		
		Node* nex = temp->next;
		temp->next = temp->next->next;
		delete nex;
		return;
	}
	
	void reverse() {
		Node* prev = NULL;
		Node* curr = head;
		Node* nex = NULL;
		
		while (curr != NULL) {
			nex = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nex;
		}
		head = prev;
	}
	
	void print() {
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	void query(const string& q) {
		string Q;
		int u, v;
		stringstream ss(q);
		ss >> Q >> u >> v;
		if (Q == "addlast") {
			addlast(u);
		} else if (Q == "addfirst") {
			addfirst(u);
		} else if (Q == "addafter") {
			addafter(u, v);
		} else if (Q == "addbefore") {
			addbefore(u, v);
		} else if (Q == "remove") {
			remove(u);
		} else if (Q == "reverse") {
			reverse();
		} else {
			return;
			//cout << "Something wrong!" << endl;
		}
	}
};

int main() {
	single_linked arr;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int e; cin >> e;
		arr.addlast(e);
	}

	string q;
	fflush(stdin);
	getline(cin, q);
		
	while(q != "#") {
		arr.query(q);
		fflush(stdin);
		getline(cin, q);	
	}
	
	arr.print();
	return 0; 
}
