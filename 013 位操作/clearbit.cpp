#include <iostream>
#include <bitset>

unsigned int clearBits(unsigned int num, unsigned int n) {
    // 创建一个掩码，其中n位为0，其余位为1
    unsigned int mask = ~((1 << n) - 1);
    // 使用与操作将num的尾部n位清零
    return num & mask;
}

int main() {
    unsigned int num = 12345; // 示例整数
    unsigned int n = 4; // 要清零的位数
    unsigned int result = clearBits(num, n);
    std::bitset<16> bin;

    bin = num;
    std::cout << "原始整数:     " << num << " " << bin << std::endl;
    bin = result;
    std::cout << "清零后的整数: " << result << " " << bin << std::endl;

    return 0;
}
