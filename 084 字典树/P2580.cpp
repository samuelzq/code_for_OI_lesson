/**
 * https://www.luogu.com.cn/problem/P2580
 *
 * @File:   P2580.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-29
 *
 **/
#include <iostream>
#include <string>
#include <vector>
#include <cstring> // For memset

// 定义字典树节点结构体
struct TrieNode {
    TrieNode* children[26]; // 26个指针，对应'a'到'z'
    int count;              // 记录该名字被点到的次数 (或标记是否存在/是否已点)

    TrieNode() {
        // 初始化所有子节点指针为 nullptr
        std::memset(children, 0, sizeof(children));
        // 初始化计数为0
        count = 0;
    }
};

// --- 静态内存分配优化部分 ---
// 估算最大节点数：
// 假设N个名字，每个名字最长50。最大节点数可能接近 N * 50
// 或者更安全地估算一个足够大的值。
// 这里我们假设最多有 100000 个名字，每个名字平均长度 10，那么节点数可能在 100W 左右。
// 题目中 N <= 10^5, 长度 <= 50，则最大节点数约为 10^5 * 50 = 5 * 10^6
// 为了防止爆内存，我们可以保守估计，比如 50 万个节点，或者 50 * N (N是最大学生数)。
// 或者直接给一个足够大的常数，比如 5000005 （通常会留一点余量）
const int MAX_NODES = 500005;
TrieNode trieNodes[MAX_NODES]; // 预分配一个足够大的TrieNode数组作为节点池
int nodesCount = 0;            // 记录当前已使用的节点数量，也是下一个可用节点的索引

// 获取新节点
TrieNode* getNewNode() {
    // 从预分配的数组中取出一个TrieNode，并初始化它
    trieNodes[nodesCount] = TrieNode(); // 调用默认构造函数初始化
    return &trieNodes[nodesCount++];    // 返回其地址并递增计数器
}

// --- 静态内存分配优化部分结束 ---


// 全局根节点指针
TrieNode* root;

// 插入名字到字典树的函数 (用于构建学生名单)
void insertName(const std::string& name) {
    TrieNode* curr = root;
    for (char ch : name) {
        int index = ch - 'a';
        if (curr->children[index] == nullptr) {
            // 从节点池中获取新节点，而不是使用 new
            curr->children[index] = getNewNode();
        }
        curr = curr->children[index];
    }
    // 标记这个节点代表一个学生名字的结束
    // 这里我们用 count = 1 来表示名单里有这个名字
    // 在查询时再增加 count 来记录点名次数
    if (curr->count == 0) { // 确保只在首次插入时标记为学生名单中的名字
        curr->count = 1;
    }
}

// 查询点名情况的函数
void queryName(const std::string& name) {
    TrieNode* curr = root;
    for (char ch : name) {
        int index = ch - 'a';
        if (curr->children[index] == nullptr) {
            // 路径中断，名字不存在
            std::cout << "WRONG\n";
            return;
        }
        curr = curr->children[index];
    }

    // 走到这里，说明名字的前缀路径存在
    // 检查这个节点是否是名单中一个名字的结尾
    if (curr->count == 0) {
        // 路径存在，但它不是一个完整的学生名字（例如名单里有"apple"，报了"app"）
        // 或者说，这个名字不在名单里，尽管它的前缀可能存在
        std::cout << "WRONG\n";
    } else if (curr->count == 1) {
        // 名字正确，且第一次被点到（count 从 1 变为 2）
        curr->count++; // 增加点名次数
        std::cout << "OK\n";
    } else { // curr->count > 1
        // 名字正确，但之前已经被点到过
        curr->count++; // 再次增加点名次数
        std::cout << "REPEAT\n";
    }
}

// 主函数
int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    root = getNewNode(); // 从节点池中获取根节点

    int n; // 学生人数
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;
        insertName(name); // 将学生名字插入字典树
    }

    int m; // 教练报的名字个数
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string name;
        std::cin >> name;
        queryName(name); // 查询教练报的名字
    }

    // 使用静态数组分配，无需手动释放内存，因为它们在程序结束时由系统自动回收

    return 0;
}
