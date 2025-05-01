/**
 *
 * @File:   wright_sort.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-02-04
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Product {
    std::string name;
    int price;
    double rating;
};

// 函数对象：根据不同权重排序
struct CompareByWeight {
    double weight_price;
    double weight_rating;

    // 构造函数，初始化权重
    CompareByWeight(double wp, double wr) : weight_price(wp), weight_rating(wr) {}

    // 计算综合评分
    bool operator()(const Product &a, const Product &b) const {
        double score_a = a.price * weight_price + a.rating * weight_rating;
        double score_b = b.price * weight_price + b.rating * weight_rating;
        return score_a > score_b; // 综合评分越高，排名越前
    }
};

int main() {
    std::vector<Product> products = {
        {"Laptop", 1000, 4.5},
        {"Phone", 500, 4.7},
        {"Tablet", 700, 4.2}
    };

    // 权重：价格占 30%，评分占 70%
    CompareByWeight comparator(0.3, 0.7);
    
    std::sort(products.begin(), products.end(), comparator);

    for (const auto &p : products) {
        std::cout << p.name << " " << p.price << " " << p.rating << std::endl;
    }

    return 0;
}

