#include <iostream>

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("No prime factors for %d\n", num);
        return 0;
    }

    // 尝试从2开始分解num
    for (int i = 2; i * i <= num; i++) {
        bool p = false;    // 质因数是否已经被输出
        // 如果i是num的因数
        while (num % i == 0) {
            if (!p) {
                p = true;
                printf("%d ", i); // 打印质因数
            }
            num /= i;         // 继续分解剩下的数
        }
    }

    // 如果num大于1，那么num是一个质数
    if (num > 1)
        printf("%d ", num);

    printf("\n");
    return 0;
}
