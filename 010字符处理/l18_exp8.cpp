#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str, word;
    
    getline(cin, str);

    for (char c : str)
    {
        if (c == ' ' || c == ',' || c == '.')
        {   // 出现分隔字符，一个单词截取完毕 
    		cout << word << endl;
	        word.clear(); // 清空缓存的单词  word = ""
        }
        else
            word += c;  // 截取字符串中的单词 
    }

    if (!word.empty()) // 行尾不存在分隔字符的情况 
    		cout << word << endl;
    return 0;
}

