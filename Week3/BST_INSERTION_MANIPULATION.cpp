#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <vector>
using namespace std;

struct BST {
	struct Node {
		int val;
		Node* right;
		Node* left;
		Node(int v) {
			val = v;
			right = NULL;
			left = NULL;
		}
	};
	
	Node* head;
	BST() {
		head = NULL;
	}
	
	vector<int> trip;
		
	void insert(int k, Node* point) {
		if (head == NULL) {
			head = new Node(k);
			return;
		}
		if (k > point->val) {
			if (point->right == NULL) {
				Node* newNode = new Node(k);
				point->right = newNode;
			} else {
				insert(k, point->right);
			}
		} else if (k < point->val) {
			if (point->left == NULL) {
				Node* newNode = new Node(k);
				point->left = newNode;
			} else {
				insert(k, point->left);
			}
		} else return;
	}
	
	void _preorder(Node* start) {
		if (start == NULL) return;
		trip.push_back(start->val);
		_preorder(start->left);
		_preorder(start->right);
		return;
	}
	
	void _inorder(Node* start) {
		if (start == NULL) return;
		_inorder(start->left);
		trip.push_back(start->val);
		_inorder(start->right);
		return;
	}
	
	void _postorder(Node* start) {
		if (start == NULL) return;
		_postorder(start->left);
		_postorder(start->right);
		trip.push_back(start->val);
		return;
	}
	
	void print() {
		for (int i = 0; i < trip.size(); i++) {
			cout << trip[i] << " ";
		}
		cout << endl;
		return;
	}
	
	void InOrder() {
		trip.clear();
		_inorder(head);
		print();
		return;
	}
	
	void PostOrder() {
		trip.clear();
		_postorder(head);
		print();
		return;
	}
	
	void PreOrder() {
		trip.clear();
		_preorder(head);
		print();
		return;
	}
	
	void query(string q) {
		stringstream ss(q);
		string Q;
		int k;
		ss >> Q >> k;
		if (Q == "insert") {
			insert(k, head);
		} else {
			//cout << "Something wrong" << endl;
			return;
		}
	}
	
};

int main() {
	BST tree;
	string q;
	
	getline(cin, q);
	while (q != "#") {
		tree.query(q);
		fflush(stdin);
		getline(cin, q);
	}
	
	tree.PreOrder();
	
	return 0;
}
