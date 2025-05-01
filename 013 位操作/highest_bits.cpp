#include <stdio.h>

int main() {
    unsigned int num = 12345; // 示例数字
    int highestBit = 0;

    // 检查最高位
    if (num == 0) {
        printf("The highest bit is 0.\n");
    } else {
        // 找到最高位
        while (num >>= 1) {
            highestBit++;
        }

        // 打印最高位
        if (highestBit == 32) {
            printf("The highest bit is the sign bit.\n");
        } else {
            printf("The highest bit is at position %d.\n", highestBit);
        }
    }

    return 0;
}
