/**
 * https://www.luogu.com.cn/problem/P8306
 *
 * @File:   P8306.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-29
 *
 **/
#include <iostream>
#include <string>
#include <vector>
#include <map>    // 引入 map 容器
// #include <unordered_map> // 如果追求极致性能且不介意无序，可以考虑使用 unordered_map
#include <cstring> // For memset (虽然这里不再直接用于children数组)

// 字典树节点结构体
struct TrieNode {
    // 替换固定大小数组为map，键是字符，值是指向子节点的指针
    std::map<char, TrieNode*> children;
    int prefix_count;          // 记录有多少个模式串以前缀形式经过此节点

    TrieNode() {
        // map 会自动初始化为空，无需memset
        prefix_count = 0;
    }

    // 析构函数：释放子节点内存，避免内存泄漏
    // 在竞赛中通常省略，但实际项目中很重要
    ~TrieNode() {
        for (auto const& [key, val] : children) {
            delete val;
        }
    }
};

// 字典树的根节点
TrieNode* root;

// 插入模式串到字典树
void insert(const std::string& s) {
    TrieNode* curr = root;
    for (char ch : s) {
        // 使用map的find方法查找子节点
        if (curr->children.find(ch) == curr->children.end()) {
            // 如果不存在，创建新节点并插入到map中
            curr->children[ch] = new TrieNode();
        }
        curr = curr->children[ch];
        curr->prefix_count++; // 经过此节点的模式串数量加一
    }
}

// 查询文本串是模式串前缀的数量
int query(const std::string& t) {
    TrieNode* curr = root;
    for (char ch : t) {
        // 使用map的find方法查找子节点
        if (curr->children.find(ch) == curr->children.end()) {
            // 路径中断，说明文本串t不是任何模式串的前缀
            return 0;
        }
        curr = curr->children.find(ch)->second; // 获取子节点指针
    }
    // 走到这里，说明文本串t在字典树中有一条完整的路径
    // 它作为前缀的模式串数量就是当前节点的 prefix_count
    return curr->prefix_count;
}

// 主函数
int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // 数据组数
    std::cin >> T;
    while (T--) {
        // 每组数据开始时，清空之前的字典树，并创建新的根节点
        // 这里需要小心内存泄漏，因为每次循环都new了root
        // 正确的做法是如果root已存在，先delete root; 再 new TrieNode();
        // 或者更简洁：
        if (root != nullptr) { // 如果上一组数据有根节点，需要释放
            delete root;
        }
        root = new TrieNode(); // 为当前组数据创建新的根节点

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

    // 程序结束时，释放最后一组数据的字典树内存
    if (root != nullptr) {
        delete root;
        root = nullptr; // 防止悬空指针
    }

    return 0;
}

