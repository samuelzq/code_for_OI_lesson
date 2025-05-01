#include <iostream>
using namespace std;

#define N 100000
bool isPrime[N];

void init(int n)
{

	for (int i = 0; i <= n; i++)
		isPrime[i] = true;

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
				for (int j = i * i; j <= n; j += i)
					isPrime[j] = false;
		}
	}
}


int main(void)
{
	int n;

	cin >> n;
	init(n);

	for(int i = 4; i <= n; i += 2)
{
	for(int j = 2; j < i; j++)
	{
		if(isPrime[j] && isPrime[i - j])
		{
		cout<< i << '='	<< j << '+' << i - j << endl;
		}

	}


}

	return 0;
}