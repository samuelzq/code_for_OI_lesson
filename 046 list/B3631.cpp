/**
 * https://www.luogu.com.cn/problem/B3631
 *
 * @File:   B3631.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-05
 *
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *findNode(Node *head, int x)
{
	Node *curr = head;
	while (curr) {
		if (curr->data == x)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

Node *newNode(int x)
{
	Node *tmp = new Node;
	tmp->data = x;
	tmp->next = nullptr;
	return tmp;
}

int main(void)
{
	int n;
	Node *head = newNode(1);

	cin >> n;
	while (n--) {
		int ops;

		cin >> ops;
		if (ops == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			Node *nodex = findNode(head, x);
			Node *nodey = newNode(y);
			if (nodex) {
				nodey->next = nodex->next;
				nodex->next = nodey;
			}
		} else if (ops == 2) {
			int x;
			scanf("%d", &x);
			Node *nodex = findNode(head, x);
			if (!nodex || !nodex->next)
				printf("0\n");
			else
				printf("%d\n", nodex->next->data);
		} else if (ops == 3) {
			int x;
			Node *nodex;
			Node *tmp;
			scanf("%d", &x);
			nodex = findNode(head, x);
			tmp = nodex->next;
			nodex->next = tmp->next;
			delete tmp;
		}
	}
	return 0;
}
