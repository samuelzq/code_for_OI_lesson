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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
        	// 寻找arr[i]之后小于（大于）它的成员
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // 交换 arr[i] 和 arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {3, 5, 9, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}