/**
 *
 * @File:   list_erase.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-02
 *
 */
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    for (auto it = lst.begin(); it != lst.end();) {
        if (*it == 3)
            it = lst.erase(it);  // ❌ 错误：删除后 it 失效，但循环仍然使用它
        else
        	it++;
    }
    return 0;
}
