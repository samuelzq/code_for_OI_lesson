#include <iostream>
#include <iomanip> // 包含设置输出格式的库

// 函数用于打印数组，元素对齐输出
void printArray(int arr[], int size) {
    const int width = 4; // 假设每个整数宽度为4个字符
    for (int i = 0; i < size; i++) {
    	// 右对齐，并使用空格填充至指定宽度
        std::cout << std::setw(width) << std::right << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[6] = {3, 5, 9, 7, 2, 1};

    std::cout << "Original array: ";
    printArray(arr, 6);

    bubbleSort(arr, 6);

    std::cout << "Sorted array:   ";
    printArray(arr, 6);

    return 0;
}