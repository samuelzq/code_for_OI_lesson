#include <iostream>

using namespace std;

#define N 10006
bool isprime[N];

void init(int n)
{
    for(int i = 0; i <= n; i++)
        isprime[i] = true;

    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= n; i++) {
    	if (isprime[i]){
	    	for (int j = i * i; j <= n; j += i)
		        isprime[j] = false;
	    }
	}
}


int main()
{
	int n;
	cin >> n;
	init(n);

	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j < i; j++) {
			if (isprime[j] && isprime[i - j]) {
				cout << i << '=' << j << '+' << i-j << endl;
				break;
			}
		}
	}
	return 0;
}