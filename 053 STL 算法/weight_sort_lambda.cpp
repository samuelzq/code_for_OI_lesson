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

int main() {
    std::vector<Product> products = {
        {"Laptop", 1000, 4.5},
        {"Phone", 500, 4.7},
        {"Tablet", 700, 4.2}
    };

    double weight_price = 0.3;
    double weight_rating = 0.7;

    std::sort(products.begin(), products.end(), [weight_price, weight_rating](const Product &a, const Product &b) {
        double score_a = a.price * weight_price + a.rating * weight_rating;
        double score_b = b.price * weight_price + b.rating * weight_rating;
        return score_a > score_b;
    });

    for (const auto &p : products) {
        std::cout << p.name << " " << p.price << " " << p.rating << std::endl;
    }

    return 0;
}

