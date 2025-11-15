/**
 * https://www.luogu.com.cn/problem/P3369
 *
 * @File:   P3369.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-08-16
 *
 */
#include <iostream>
#include <utility>
#include <random>
#include <ctime>

// 使用 std::pair 作为键值，以支持可重集合
// 当 key 的数值不同时，first 元素决定了它们的相对顺序。
// 当 key 的数值相同时，唯一的 second 元素确保它们在 Treap 中有唯一的键值，
// 从而可以被视为独立的节点，正确地进行插入、删除和查找操作
using KeyType = std::pair<int, int>;

// Treap 节点的结构体，带有 size 增强
struct Node {
    KeyType key;      // 键值，用于 BST 性质
    int priority;     // 优先级，用于堆性质
    int size;         // 以该节点为根的子树大小
    Node* left;       // 左子节点
    Node* right;      // 右子节点

    Node(KeyType k) : key(k), size(1), left(nullptr), right(nullptr) {
        // 使用一个随机数生成器来确保优先级是随机的
        static std::mt19937 rng(time(nullptr));
        priority = rng();
    }
};

class Treap {
private:
    Node* root;
    int unique_id_counter;

    // 辅助函数：更新节点的大小
    void push_up(Node* node) {
        if (!node) return;
        node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
    }

    // 右旋操作
    Node* right_rotate(Node* p) {
        Node* l = p->left;
        p->left = l->right;
        l->right = p;
        push_up(p); // 先更新p
        push_up(l); // 再更新x
        return l;
    }

    // 左旋操作
    Node* left_rotate(Node* p) {
        Node* r = p->right;
        p->right = r->left;
        r->left = p;
        push_up(p); // 先更新p
        push_up(r); // 再更新r
        return r;
    }

    // 递归插入
    Node* insert_recursive(Node* node, KeyType key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert_recursive(node->left, key);
            if (node->left->priority > node->priority) {
                node = right_rotate(node);
            }
        } else {
            node->right = insert_recursive(node->right, key);
            if (node->right->priority > node->priority) {
                node = left_rotate(node);
            }
        }
        push_up(node);
        return node;
    }

    // 递归删除
    Node* erase_recursive(Node* node, KeyType key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = erase_recursive(node->left, key);
        } else if (key > node->key) {
            node->right = erase_recursive(node->right, key);
        } else {
            // 找到了要删除的节点
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // 如果有两个子节点，不能直接删除，需要通过旋转将其下沉
                // 比较左右子节点的优先级，将优先级高的子节点提升上
                if (node->left->priority > node->right->priority) {
                    // 如果左孩子的优先级更高，执行右旋
                    // 右旋后，当前节点（node）会下沉到右子树，然后我们递归删除它
                    node = right_rotate(node);
                    node->right = erase_recursive(node->right, key);
                } else {
                    // 如果右孩子的优先级更高，执行左旋
                    // 左旋后，当前节点（node）会下沉到左子树，然后我们递归删除它
                    node = left_rotate(node);
                    node->left = erase_recursive(node->left, key);
                }
            }
        }
        push_up(node);
        return node;
    }

    // 递归查找第k小的元素
    int find_kth_recursive(Node* node, int k) {
        if (!node || k <= 0 || k > node->size) {
            return -1; // 错误或找不到
        }
        int left_size = (node->left) ? node->left->size : 0;

        // 如果 k 等于左子树的大小 + 1，则当前节点就是我们要找的第 k 小的元素	
        if (k == left_size + 1) {
            return node->key.first;
        }
        if (k <= left_size) {  // 在左子树继续查找
            return find_kth_recursive(node->left, k);
        } else {  // 在右子树继续查找
            return find_kth_recursive(node->right, k - left_size - 1);
        }
    }

    // 统计严格小于 key 的元素数量
    int get_rank_recursive(Node* node, int key, int current_rank) {
        if (!node) {
            return current_rank;
        }
        if (key <= node->key.first) {
            return get_rank_recursive(node->left, key, current_rank);
        } else {
            int left_size = (node->left) ? node->left->size : 0;
            return get_rank_recursive(node->right, key, current_rank + left_size + 1);
        }
    }

    // 递归查找前驱
    int find_predecessor_recursive(Node* node, int key) {
        int pred = -1;
        while(node) {
            if (node->key.first < key) {
                pred = node->key.first;
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return pred;
    }

    // 递归查找后继
    int find_successor_recursive(Node* node, int key) {
        int succ = -1;
        while(node) {
            if (node->key.first > key) {
                succ = node->key.first;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return succ;
    }

public:
    Treap() : root(nullptr), unique_id_counter(0) {}

    // 公有插入方法
    void insert(int key) {
        root = insert_recursive(root, {key, unique_id_counter++});
    }

    // 公有删除方法
    void erase(int key) {
        // 由于存在相同键值，我们找到第一个要删除的
        // 这里的erase_recursive需要一个完整的KeyType，
        // 但我们只知道key。一个简单的办法是找到第一个等于x的元素，然后删除它
        KeyType key_to_erase = {key, 0};
        Node* node_to_erase = nullptr;
        Node* curr = root;

        while(curr) {
            if (key_to_erase.first < curr->key.first) {
                curr = curr->left;
            } else if (key_to_erase.first > curr->key.first) {
                curr = curr->right;
            } else {
                node_to_erase = curr;
                break;
            }
        }
        if(node_to_erase) {
            root = erase_recursive(root, node_to_erase->key);
        }
    }

    // 公有排名查询
    int get_rank(int key) {
        return get_rank_recursive(root, key, 1);
    }

    // 公有第k大查询
    int find_kth(int k) {
        return find_kth_recursive(root, k);
    }

    // 公有前驱查询
    int get_predecessor(int key) {
        return find_predecessor_recursive(root, key);
    }

    // 公有后继查询
    int get_successor(int key) {
        return find_successor_recursive(root, key);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    Treap treap;

    for (int i = 0; i < n; ++i) {
        int opt, x;
        std::cin >> opt >> x;

        switch (opt) {
            case 1:
                treap.insert(x);
                break;
            case 2:
                treap.erase(x);
                break;
            case 3:
                std::cout << treap.get_rank(x) << "\n";
                break;
            case 4:
                std::cout << treap.find_kth(x) << "\n";
                break;
            case 5:
                std::cout << treap.get_predecessor(x) << "\n";
                break;
            case 6:
                std::cout << treap.get_successor(x) << "\n";
                break;
        }
    }

    return 0;
}

