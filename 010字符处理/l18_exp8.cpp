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
        {   // ���ַָ��ַ���һ�����ʽ�ȡ��� 
    		cout << word << endl;
	        word.clear(); // ��ջ���ĵ���  word = ""
        }
        else
            word += c;  // ��ȡ�ַ����еĵ��� 
    }

    if (!word.empty()) // ��β�����ڷָ��ַ������ 
    		cout << word << endl;
    return 0;
}

