#include <iostream>
#include <iomanip> // 包含设置输出格式的库
using namespace std;

// 函数用于打印数组，元素对齐输出
void printArray(int arr[], int size) {
    const int width = 4; // 假设每个整数宽度为4个字符
    for (int i = 0; i < size; i++)
    	// 右对齐，并使用空格填充至指定宽度
        cout << setw(width) << right << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素向右移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // 注意这里的j+1指向的是空格，j指向的是比key小的成员
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {3, 5, 9, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}