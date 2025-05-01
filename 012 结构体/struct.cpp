#include <iostream>
#include <string>

using namespace std;

// 定义一个名为Student的结构体
struct Student {
    string name;
    int age;
    float score;
};

int main(void)
{
    // 创建一个Student类型的变量
    struct Student student1;

    // 为结构体成员赋值
    student1.name  = "小明";
    student1.age   = 20;
    student1.score = 85.5;

    // 输出结构体成员的值
    cout << "姓名: " << student1.name  << endl;
    cout << "年龄: " << student1.age   << endl;
    cout << "分数: " << student1.score << endl;

    return 0;
}