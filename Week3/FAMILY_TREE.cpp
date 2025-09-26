#include <iostream> 
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class familyTree {
private:
	struct Node {
		string key;
		vector<string> childs;
		Node(string val) {
			key = val;
		}
		int numOfChilds() {
			return childs.size();
		}
	};
	
	Node* root;
	vector<Node *> T;
	
	Node* find(string name) {
		for (int i = 0; i < T.size(); i++) {
			if (T[i]->key == name) return T[i];
		}
		return NULL;
	}
	
	bool exist(string name) {
		return find(name) != NULL;
	}
	
	void _insert(string child, string parent) {
		if (!exist(parent)) {
			T.push_back(new Node(parent));
		}
		if(!exist(child))  {
			T.push_back(new Node(child));
		}
		Node* p = find(parent);
		Node* c = find(child);
		
		if (root == NULL) root = p;
		
		if (c->key == root->key) {
			root = p;
		}
		
		p->childs.push_back(child);
		return;
	}

	int _generation(string name) {
		Node* p = find(name);
		if (p->numOfChilds() == 0) return 0; 
		
		int genOfChild = 0;
		for (int i = 0; i < p->numOfChilds(); i++) {
			genOfChild = max(genOfChild, _generation(p->childs[i]));
		}
		return 1 + genOfChild;
		
	} 
	
	int _descendants(string parent) {
		int sum = 0;
		Node* p = find(parent);
		for (int i = 0; i < p->childs.size(); i++) {
			sum += 1 + _descendants(p->childs[i]);
		}
		return sum;
	}
	
public:
	familyTree() {
		root = NULL;
	}

	void query(string q) {
		stringstream ss(q);
		string s1, s2;
		ss >> s1 >> s2; 
		if (s1 == "descendants") {
			cout << _descendants(s2) << endl;
		} else if (s1 == "generation") {
			cout << _generation(s2) << endl;
		} else {
		 	_insert(s1, s2);
		}
	}
	
	void _print() {
		for (int i = 0; i < T.size(); i++) {
			cout << T[i]->key << ": ";
			for (int j = 0; j < T[i]->childs.size(); j++) {
				cout << T[i]->childs[j] << " ";
			}
			cout << endl;
		}
		return;
	}
};

int main() {
	familyTree T;
	string q;
	getline(cin, q);
	
	while(q != "***") {
		T.query(q);
		fflush(stdin);
		getline(cin, q);
	}
	
	fflush(stdin);
	getline(cin, q);
	while(q != "***") {
		T.query(q);
		fflush(stdin);
		getline(cin, q);
	}
	//T._print();
	return 0;
}
