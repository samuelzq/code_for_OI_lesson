/**
 *
 * @File:   P4551.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-08
 *
 */
/**
 *
 * @File:   P4551.cpp
 * @Author: Lao Zhang <samuelzhang77@outlook.com>
 * @Date:   2025-07-30
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <cstring>   // For memset

// 定义二进制字典树节点结构体
struct TrieNode {
    TrieNode* children[2]; // children[0] for bit 0, children[1] for bit 1

    TrieNode() {
        std::memset(children, 0, sizeof(children)); // 初始化子节点指针为nullptr
    }
};

// --- 静态内存分配优化部分 ---
// 估算最大节点数。
// N个节点，每个节点会插入一个XOR值，每个XOR值最大30-31位（通常考虑30位）。
// 最大节点数约为 N * (MaxBits)。
// N <= 10^5，MaxBits 约 30，所以 MAX_NODES 大约 10^5 * 30 = 3 * 10^6
const int MAX_NODES = 3000005; // 足够存储所有XOR值对应的Trie节点
TrieNode trieNodes[MAX_NODES]; // 预分配一个足够大的TrieNode数组
int nodesCount;                // 当前已使用的节点数量，也是下一个可用节点的索引

// 获取新节点
TrieNode* getNewNode() {
    trieNodes[nodesCount] = TrieNode(); // 从池中取一个节点并初始化
    return &trieNodes[nodesCount++];    // 返回其地址并递增计数器
}

// 字典树的根节点
TrieNode* root;

// 定义最大位数，取决于边权的最大可能值
// 如果边权最大是 10^9，那么需要 log2(10^9) ≈ 29.89，所以取 30 位
const int MAX_BITS = 30;

// 将一个数字（路径异或和）插入二进制字典树
void insert(int val) {
    TrieNode* curr = root;
    // 从最高位开始插入
    for (int i = MAX_BITS; i >= 0; --i) {
        int bit = (val >> i) & 1; // 获取val的第i位 (0 或 1)
        if (curr->children[bit] == nullptr) {
            curr->children[bit] = getNewNode();
        }
        curr = curr->children[bit];
    }
}

// 在字典树中查找与val异或结果最大的数字
int findMaxXOR(int val) {
    TrieNode* curr = root;
    int maxXOR = 0;
    // 从最高位开始查找
    for (int i = MAX_BITS; i >= 0; --i) {
        int bit = (val >> i) & 1; // val的当前位
        int desired_bit = 1 - bit; // 希望得到的位，以最大化异或结果

        if (curr->children[desired_bit] != nullptr) {
            // 如果希望得到的位存在，就走向这个分支
            maxXOR |= (1 << i); // 将该位加入到maxXOR结果中
            curr = curr->children[desired_bit];
        } else {
            // 如果希望得到的位不存在，只能走向与val当前位相同的分支
            curr = curr->children[bit];
        }
    }
    return maxXOR;
}

// ---------------------------------------------
// 树的DFS部分：计算每个节点到根的异或和
std::vector<std::pair<int, int>> adj[100005]; // 邻接表表示树，存储 {v, w}
int path_xor_sum[100005]; // 存储每个节点到根的异或和
bool visited[100005];     // 访问标记

void dfs(int u, int current_xor_sum) {
    visited[u] = true;
    path_xor_sum[u] = current_xor_sum;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (!visited[v]) {
            dfs(v, current_xor_sum ^ w); // 异或上边权
        }
    }
}
// ---------------------------------------------


int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 结点数
    std::cin >> n;

    // 构建邻接表
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // 无向图，双向连接
    }

    // 1. DFS 计算所有节点到根节点1的路径异或和
    // 假设根节点为1，path_xor_sum[1] 初始为 0
    std::memset(visited, 0, sizeof(visited)); // 重置访问标记
    dfs(1, 0);

    // 2. 将所有 path_xor_sum 值插入二进制字典树
    nodesCount = 0; // 重置节点池计数器
    root = getNewNode(); // 获取字典树根节点

    for (int i = 1; i <= n; ++i) {
        insert(path_xor_sum[i]);
    }

    // 3. 查找最大异或路径
    int max_xor_path = 0;
    for (int i = 1; i <= n; ++i) {
        // 对于每个 path_xor_sum[i]，在字典树中找到一个 path_xor_sum[j]
        // 使得它们异或值最大
        max_xor_path = std::max(max_xor_path, findMaxXOR(path_xor_sum[i]));
    }

    std::cout << max_xor_path << "\n";

    // 静态数组分配，无需手动释放内存

    return 0;
}
