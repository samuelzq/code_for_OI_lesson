#include <bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int y, m, d;
    int idx;
} stu[120];

bool cmp(student &st1, student &st2)
{
	if (st1.y != st2.y)
		return st1.y < st2.y;
	else if (st1.m != st2.m)
        return st1.m < st2.m;
    else if (st1.d != st2.d)
        return st1.d < st2.d;
    else
    	return st1.idx > st2.idx;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
		stu[i].idx = i;
	}

	sort(stu, stu + n, cmp);

	for (int i = 0; i < n; i++)
		cout << stu[i].name << endl;

	return 0;
}