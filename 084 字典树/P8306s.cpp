/**
 *
 * @File:   P8306s.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-08
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

// 题目规定字符串包含大小写字母和数字
// 小写字母 'a'-'z' (26)
// 大写字母 'A'-'Z' (26)
// 数字 '0'-'9' (10)
// 总计 26 + 26 + 10 = 62 种字符
const int ALPHABET_SIZE = 62;

// 根据题目数据规模，所有字符串总长不超过 3*10^6，因此节点总数也大致在这个范围内
// 我们稍微放大一些，以确保有足够的空间
const int MAX_NODES = 3000005;

// 字典树节点结构体
struct TrieNode {
    // 静态数组存储子节点索引
    int children[ALPHABET_SIZE];
    // 记录有多少个模式串以前缀形式经过此节点
    int prefix_count;

    TrieNode() {
        // 使用 -1 来标记没有子节点
        memset(children, -1, sizeof(children));
        prefix_count = 0;
    }
};

// 静态数组存储所有字典树节点
TrieNode trie[MAX_NODES];
// 节点索引，作为简单的“内存管理器”
int node_idx;

// 模拟 new 的接口
// 返回新分配节点的索引
int newNode() {
    // 确保我们没有超出预设的最大节点数
    if (node_idx >= MAX_NODES) {
        // 在实际竞赛中，通常假设不会溢出
        // 如果需要更健壮的程序，这里可以进行错误处理
        // std::cerr << "Error: Max nodes exceeded!" << std::endl;
        return -1;
    }

    int new_node_index = node_idx++;
    // 在这里显式初始化新节点
    // 尽管TrieNode的构造函数会做这些，但这里再次赋值可以保证逻辑的健壮性
    memset(trie[new_node_index].children, -1, sizeof(trie[new_node_index].children));
    trie[new_node_index].prefix_count = 0;

    return new_node_index;
}

// 初始化字典树
void init_trie() {
    // 将节点索引重置为0，表示从头开始构建
    node_idx = 0;
    // 创建根节点，根节点索引为0
    newNode();
}

// 用于将字符映射为 0 到 61 的索引
int char_to_index(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    return -1; // 不可能出现的字符
}

// 插入模式串到字典树
void insert(const std::string& s) {
    int curr = 0; // 从根节点（索引0）开始
    for (char ch : s) {
        int index = char_to_index(ch);
        if (index == -1) continue; // 忽略无效字符

        // 如果子节点不存在，则调用 newNode() 创建新节点并连接
        if (trie[curr].children[index] == -1) {
            trie[curr].children[index] = newNode();
        }
        curr = trie[curr].children[index]; // 移动到子节点
        trie[curr].prefix_count++; // 经过此节点的模式串数量加一
    }
}

// 查询文本串是模式串前缀的数量
int query(const std::string& t) {
    int curr = 0; // 从根节点（索引0）开始
    for (char ch : t) {
        int index = char_to_index(ch);
        if (index == -1) return 0; // 遇到无效字符，中断查询

        // 如果路径中断，说明文本串t不是任何模式串的前缀
        if (trie[curr].children[index] == -1) {
            return 0;
        }
        curr = trie[curr].children[index]; // 移动到子节点
    }
    // 走到这里，说明文本串t在字典树中有一条完整的路径
    // 它作为前缀的模式串数量就是当前节点的 prefix_count
    return trie[curr].prefix_count;
}

int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // 数据组数
    std::cin >> T;
    while (T--) {
        // 每组数据开始时，重新初始化字典树
        init_trie();

        int n, q; // 模式串个数n，询问个数q
        std::cin >> n >> q;

        // 插入所有模式串
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            insert(s);
        }

        // 处理所有询问
        for (int i = 0; i < q; ++i) {
            std::string t;
            std::cin >> t;
            std::cout << query(t) << "\n";
        }
    }

    return 0;
}
