#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class tree {
private:
	struct Node {
		int id;
		vector<Node* > childs;
		Node(int v) {
			id = v;
			childs.clear();
		}
	};
	Node* root;
	vector<Node* > tour;
	vector<int> ids;
	
	Node* _find(int v, Node* &start) {
		if (start->id == v) return start;
		for (int i = 0; i < (start->childs).size(); i++) {
			Node* p = _find(v, (start->childs)[i]);
			if (p != NULL) return p;
		}
		return NULL;
	}
	
	void _makeroot(int u) {
		root = new Node(u);
	}
	
	void _insert(int u, int v) {
		if (root == NULL) {
			cout << "Must to makeroot before insert new node" << endl;
			return;
		}
		if (_find(u, root) != NULL) return; //exist
		
		Node* p = _find(v, root);	
		if (p == NULL) return; //unexist

		Node* newChild = new Node(u);
		(p->childs).push_back(newChild);
		
		return; 
	}
	
	void _preOrder(Node* start) {
		if (start == NULL) return;
		tour.push_back(start);
		for (int i = 0; i < (start->childs).size(); i++) {
			_preOrder((start->childs)[i]);
		}
	}
	
	void _inOrder(Node* start) {
		if (start == NULL) return;
		if ((start->childs).size() != 0) {
			_inOrder((start->childs)[0]);
		}
		tour.push_back(start);
		for (int i = 1; i < (start->childs).size(); i++) {
			_inOrder((start->childs)[i]);
		}
		return;
	}
	
	void _postOrder(Node* start) {
		if (start == NULL) return;
		for (int i = 0; i < (start->childs).size(); i++) {
			_postOrder((start->childs)[i]);
		}
		tour.push_back(start);
		return;
	}
	
	void _printTourID() {
		for (int i = 0; i < tour.size(); i++) {
			cout << (tour[i]->id) << " ";
		}
		cout << endl;
		return;
	}
public:
	tree() {
		root = NULL;
	}
	
	void query(string q) {
		stringstream ss(q);
		string Q;
		int u, v;
		ss >> Q >> u >> v;
		if (Q == "MakeRoot") {
			_makeroot(u);
		} else if (Q == "Insert") {
			_insert(u, v);
		} else if (Q == "PreOrder") {
			tour.clear();
			_preOrder(root);
			_printTourID();
			
		} else if (Q == "InOrder") {
			tour.clear();
			_inOrder(root);
			_printTourID();
			
		} else if (Q == "PostOrder") {
			tour.clear();
			_postOrder(root);
			_printTourID();
			
		} else {
			//cout << "Something wrong!" << endl;
			return;
		}
	}
	
	
};

int main() {
	string q;
	getline(cin, q);
		
	tree T;
	while (q != "*") {
		T.query(q);
		fflush(stdin);
		getline(cin, q);
	}
	return 0;
}
