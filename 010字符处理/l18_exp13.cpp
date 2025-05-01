#include <iostream>
#include <string>
#include <vector>
#include <limits>   // numeric_limits

using namespace std;

int main() {
    int numLines;
    cout << "请输入你想输入的行数: ";
    cin >> numLines;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> lines(numLines);

    for (int i = 0; i < numLines; ++i) {
        cout << "请输入第 " << (i + 1) << " 行: ";
        getline(std::cin, lines[i]);
    }

    cout << "你输入的内容如下:\n";
    for (const auto& line : lines)
        cout << line << std::endl;

    return 0;
}