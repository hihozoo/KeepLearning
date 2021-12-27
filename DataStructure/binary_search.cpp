#include<iostream>
#include<vector>

using namespace std;

/**
 * 二分查找和边界查找
 *
*/
int find(const vector<int>& arr, int tgt){
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right){
		int mid = left + (right - left) / 2;
		if (arr[mid] == tgt){
			return mid;
		}
		if (arr[mid] > tgt){
			right = mid - 1;
		}else if (arr[mid] < tgt){
			left = mid + 1;
		}
	}
	return -1;
}

int find_left(vector<int>& arr, int tgt){
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right){
		int mid = left + (right - left) / 2;
		if (arr[mid] == tgt){
			right = mid - 1;
		}
		if (arr[mid] > tgt){
			right = mid - 1;
		}
		else if (arr[mid] < tgt){
			left = mid + 1;
		}
	}
	return left;
}

int find_right(vector<int>& arr, int tgt){
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right){
		int mid = left + (right - left) / 2;
		if (arr.at(mid) == tgt){
			left = mid + 1;
		}else if (arr.at(mid) > tgt){
			right = mid - 1;
		}else if (arr.at(mid) < tgt){
			left = mid + 1;
		}
	}
	return right;
}

int main(){
	vector<int> arr = {1, 1, 2, 2, 2, 5, 6, 7};

	cout << find_left(arr, 2) << endl;
	cout << find_right(arr, 2) << endl;

	return 0;
}
