#include<iostream>
#include<queue>
using namespace std;

int main(){
	int arr[] = {1, 5, 4, 2, 8};

	// 最大堆
	priority_queue<int> bigest_q;

	// 最小堆
	priority_queue<int, vector<int>, greater<int>> smallest_q;

	for (auto v: arr){
		bigest_q.push(v);
		smallest_q.push(v);
	}

	cout << "bigest_q: " << bigest_q.top() << endl;
	cout << "smallest_q: " << smallest_q.top() << endl;

	return 0;
}

