#include <iostream>

using namespace std;

#define N 100006
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

int main(void)
{
	int l, sum, n, i;

	cin >> l;
	init(l);

	sum = n = 0;
	i = 2;

	while (sum + i <= l) {
		if (isprime[i]) {
			sum += i;
			n++;
			cout << i << endl;
		}
		i++;
	}
	cout << n << endl;
	return 0;
}