/**
 *
 * @File:   binary_search_struct.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-07
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int id;
    std::string name;
};

int main() {
    std::vector<Item> items = {
        {3, "Apple"},
        {1, "Banana"},
        {5, "Cherry"},
        {7, "Date"},
        {9, "Elderberry"}
    };

    // 按 id 排序（升序）
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.id < b.id;
    });

    // 目标 id
    int target_id = 5;

    // 使用 binary_search 查找是否存在目标 id
    bool found = std::binary_search(
        items.begin(),
        items.end(),
        Item{target_id, ""}, // 包装目标值为 Item 类型
        [](const Item& a, const Item& b) {
            return a.id < b.id;
        }
    );

    if (found) {
        std::cout << "Item with id " << target_id << " found!" << std::endl;
    } else {
        std::cout << "Item with id " << target_id << " not found." << std::endl;
    }

    return 0;
}

