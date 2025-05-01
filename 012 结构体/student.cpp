#include <iostream>
#include <cstring>

using namespace std;

// 练习二：创建一个表示学生信息的结构体
struct Student {
    string name;
    int age;
    char gender;  // 'M' 'F'
};

int main(void)
{
    // 创建一个Student类型的数组并赋值
    struct Student students[3];

    students[0].name = "韩磊";
    students[0].age = 20;
    students[0].gender = 'M';

    students[1].name = "李梅";
    students[1].age = 21;
    students[1].gender = 'F';

    students[2].name = "王琳";
    students[2].age = 21;
    students[2].gender = 'F';

    // 打印所有学生的信息
    for (int i = 0; i < 3; ++i) {
        cout << "姓名: " << students[i].name << endl;
    	cout << "年龄: " << students[i].age << endl;
    	cout << "性别: " << students[i].gender << endl;
    	cout << endl;
    }

    return 0;
}