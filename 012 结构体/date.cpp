#include <iostream>
#include <iomanip> // 用于设置输出格式
using namespace std;

// 练习三：使用结构体表示日期
struct Date {
    int day;
    int month;
    int year;
};

// 比较两个日期的函数
bool compareDates(const Date& date1, const Date& date2) {
    if (date1.year != date2.year) {
        return date1.year < date2.year;
    } else if (date1.month != date2.month) {
        return date1.month < date2.month;
    } else {
        return date1.day < date2.day;
    }
}

// 重载 << 运算符以打印 Date 结构体
ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(2) << date.day << "-"
       << setw(2) << date.month << "-"
       << date.year;
    return os;
}

int main(void)
{
    // 创建两个Date类型的变量并赋值
    Date date1 = {15, 3, 2023};
    Date date2 = {20, 3, 2023};

    // 比较两个日期并输出结果
    if (compareDates(date1, date2)) {
        cout << date1 << " 早于 " << date2 << endl;
    } else {
        cout << date1 << " 不早于 " << date2 << endl;
    }

    return 0;
}