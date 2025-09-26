#include <iostream>
using namespace std;

struct cup {
	int Vmax;
	int v;
	cup(int k) {
		Vmax = k;
		v = 0;
	}
	cup() {
		Vmax = v = 0;
	}
	void drop() {
		v = 0;
	}
	void fill() {
		v = Vmax;
	}
	bool isFull() {
		return v == Vmax;
	}
	bool isEmpty() {
		return v == 0;
	}
	int remaining() {
		return Vmax - v;
	}	
};

void pour(cup& c1, cup& c2) {
	if (c2.isFull()) return;
	if (c1.v > c2.remaining()) {
		c1.v -= c2.remaining();
		c2.fill();
	} else {
		c2.v += c1.v;
		c1.drop();
	}
}

void print(cup a, cup b) {
	printf("%d %d\n", a.v, b.v );
}
int ans_solution(int a, int b, int c) {
	if (a == b) {
		if (a == c) return 1;
		else return -1;
	} 
	
	cup Min, Max;
	if (a > b) {
		Max.Vmax = a;
		Min.Vmax = b;
	} else {
		Max.Vmax = b;
		Min.Vmax = a;
	}
	
	int step = 0;
	while(true) {
		if (Min.isEmpty()) {
			step++;
			Min.fill();	
			//print(Min, Max);
		}
		
		step++;
		pour(Min, Max);
		//print(Min, Max);
		if (Min.v == c) return step;
		
		if (Max.isFull()) {
			step++;
			Max.drop();
			//print(Min, Max);
		}
		
		if (Min.v == 0 && Max.v == 0) return -1;
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << ans_solution(a, b, c) << endl;
	return 0;
}
