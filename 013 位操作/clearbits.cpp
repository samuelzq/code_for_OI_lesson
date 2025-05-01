#include <iostream>
#include <bitset>

// 清除指定位域的函数
unsigned int clearBits(unsigned int num, unsigned int startBit, unsigned int length) {
    // 创建一个掩码，其中要保留的位为1，要清除的位为0
    unsigned int mask = ~(((1U << length) - 1) << startBit); // 然后清除指定的位
    // 使用按位与操作清除指定的位域
    return num & mask;
}

int main() {
    unsigned int num = 0b110111110; // 二进制表示的数，例如：130
    unsigned int startBit = 2; // 从右边数起的起始位（0-based）
    unsigned int length = 3; // 要清除的位域的长度

    // 清除指定位域
    unsigned int result = clearBits(num, startBit, length);

    // 输出结果
    std::cout << "原始整数（二进制）:         " << std::bitset<12>(num) << std::endl;
    std::cout << "清除位域后的整数（二进制）: " << std::bitset<12>(result) << std::endl;

    return 0;
}
