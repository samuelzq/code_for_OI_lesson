#include <iostream>

void printFactors(int num) {
    printf("Factors of %d are: ", num);

    // 检查从1到num的所有数
    for (int i = 1; i <= num; i++) {
        // 如果i是num的因数
        if (num % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // 调用函数打印所有因数
    printFactors(num);

    return 0;
}
