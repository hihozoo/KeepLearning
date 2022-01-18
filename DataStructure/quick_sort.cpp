/**
 * 分解成子问题，
 * 找到基准值 pivot，将数组分成2个部分，左边为 < pivot，右边 >= pivot
 *
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int part(vector<int>& arr, int left, int right);
void sort(vector<int>& arr, int left, int right);

void sort(vector<int>& arr){
	sort(arr, 0, arr.size() - 1);
}

void sort(vector<int>& arr, int left, int right){
	if (left >= right){
		return;
	}
	int pivot = part(arr, left, right);
	sort(arr, left, pivot - 1);
	sort(arr, pivot + 1, right);
}

int part(vector<int>& arr, int left, int right){
	int pivot = arr[right];
	int i = 0;
	int j = 0;
	while (i < right){
		if (arr[i] <= pivot){
			swap(arr[i], arr[j]);
			j++;
		}
		i++;
	}
	swap(arr[j], arr[right]);
	return j;
}

int main(){
	vector<int> arr = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(arr.begin(), arr.end(), default_random_engine(seed));

	sort(arr);

	for (int val: arr){
		cout << val << endl;
	}
	return 0;
}