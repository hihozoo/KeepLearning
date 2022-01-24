#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int travel_count = 0;

void sort(vector<int>& arr){
	travel_count = 0;
	int size = arr.size();
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				swap(arr[j + 1], arr[j]);
			}
			travel_count++;
		}
	}
}

void sort2(vector<int>& arr){
	travel_count = 0;
	int size = arr.size();
	bool dirty = true;
	for (int i = 0; i < size; i++){
		dirty = false;
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
				dirty = true;
			}
			travel_count++;
		}
		if (!dirty){
			break;
		}
	}
}

void sort3(vector<int>& arr){
	travel_count = 0;
	int size = arr.size();
	int last_swap_index = size - 1;
	bool dirty = true;

	while (dirty){
		dirty = false;
		int temp_swap_index = last_swap_index;
		for (int i = 0; i < last_swap_index; i++){
			if (arr[i] > arr[i + 1]){
				swap(arr[i], arr[i + 1]);
				temp_swap_index = i;
				dirty = true;
			}
			travel_count++;
		}
		last_swap_index = temp_swap_index;
	}
}

int main(){
	vector<int> arr = {4, 1, 3, 9, 1, 8, 7, 2};
	sort3(arr);
	cout << "sort3 count: " << travel_count << endl;
	for(int val: arr){
		cout << val << endl;
	}

	sort(arr);
	cout << "sort count: " << travel_count << endl;

	sort2(arr);
	cout << "sort2 count: " << travel_count << endl;
	return 0;
}
