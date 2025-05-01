#include <iostream>
#include <string>
using namespace std;

// 练习四：使用结构体表示图书信息
struct Book {
    string title;
    string author;
    int pages;
    double price;
};

// 打印图书信息的函数
void printBookInfo(const Book& book) {
    cout << "书名: " << book.title << endl;
    cout << "作者: " << book.author << endl;
    cout << "页数: " << book.pages << endl;
    cout << "价格: " << book.price << endl;
}

int main() {
    // 创建一个Book类型的变量并赋值
    Book myBook;
    myBook.title = "C++ Primer";
    myBook.author = "Stanley B. Lippman";
    myBook.pages = 880;
    myBook.price = 49.99;

    // 打印图书信息
    printBookInfo(myBook);

    // 可以创建更多Book类型的变量，并赋值打印
    // ...

    return 0;
}