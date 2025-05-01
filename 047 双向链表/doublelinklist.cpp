/**
 *
 * @File:   doublelinklist.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-01
 *
 */
#include <iostream>

// 定义双向链表节点结构
struct Node {
    int data;
    Node* next;
    Node* prev;

    // 可以添加一个默认构造函数（可选），但在这个例子中不是必需的
    // Node() : data(0), next(nullptr), prev(nullptr) {}
};

// 创建新节点
Node* createNode(int data) {
    Node* newNode = new Node; // 使用new分配内存
    if (!newNode) {
        std::cerr << "内存分配失败" << std::endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// 在链表头部插入节点（代码未变）
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    }
    return newNode;
}

// 在链表尾部插入节点（代码未变）
Node* insertAtTail(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode; // 链表为空，新节点成为头节点
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head; // 头节点不变
}

// 在链表的指定位置插入节点（1-based index）
Node* insertAtPosition(Node* head, int pos, int data) {
    if (pos <= 0) {
        std::cerr << "位置无效" << std::endl;
        return head; // 或者可以选择抛出异常
    }
    Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        return newNode; // 新节点成为新的头节点
    }
    Node* curr = head;
    for (int i = 1; curr && i < pos - 1; ++i) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        std::cerr << "位置超出链表长度" << std::endl;
        delete newNode; // 释放新节点的内存，因为插入失败
        return head;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    return head; // 头节点可能不变，除非在第一个位置插入
}

// 删除指定位置的节点（代码未变）
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) {
        return nullptr; // 链表为空，无需删除
    }
    Node* curr = head;
    for (int i = 1; curr && i < pos; ++i) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head; // 位置超出链表长度，无需删除
    }
    if (curr->prev) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next; // 删除的是头节点，更新头指针
    }
    if (curr->next) {
        curr->next->prev = curr->prev;
    }
    delete curr; // 使用delete释放内存
    return head;
}

// 遍历链表并打印节点数据（代码未变）
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    // 插入一些节点（代码未变）
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtHead(head, 5);
    head = insertAtPosition(head, 2, 15); // 在第二个位置插入15

    // 打印链表（代码未变）
    std::cout << "链表内容: ";
    printList(head);

    // 删除节点（代码未变）
    head = deleteAtPosition(head, 3); // 删除第三个节点（值为20的节点）
    std::cout << "删除第三个节点后的链表内容: ";
    printList(head);

    return 0;
}
