#include <iostream>
#include <string>
using namespace std;
#define R   "Rock"
#define S   "Scissors"
#define P   "Paper"

int main()
{
	int n;
	string str1, str2;

	cin >> n;
	while (n--) {
		cin >> str1 >> str2;

		if (str1 == str2) {
			cout << "Tie" << endl;
		} else if ((str1 == R && str2 == S) ||
				   (str1 == S && str2 == P) ||
				   (str1 == P && str2 == R)) {
			cout << "Player1" << endl;
		} else {
			cout << "Player2" << endl;
		}
	}
	return 0;
}