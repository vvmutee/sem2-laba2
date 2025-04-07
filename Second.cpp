//Быстрая сортировка
#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int left = low + 1;
        int right = high;
        
        while (true) {
            while (left <= high && arr[left] <= pivot) left++;
            while (right >= low + 1 && arr[right] > pivot) right--;
            
            if (left >= right) break;
            swap(arr[left], arr[right]);
        }
        
        swap(arr[low], arr[right]);
        
        quicksort(arr, low, right - 1);
        quicksort(arr, right + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size() - 1);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

//Пузырек
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    bubbleSort(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

