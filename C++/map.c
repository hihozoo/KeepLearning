#include<iostream>
#include<map>

using namespace std;


int main(void){
	std::map<int, int> a;
	a.insert(pair<int, int>(2, 3));
	a.insert(pair<int, int>(5, 3));
	a.insert(pair<int, int>(4, 3));

	for (map<int, int>::iterator i = a.begin(); i != a.end(); i++){
		cout << i->first << endl;
	}
	return 0;
}
