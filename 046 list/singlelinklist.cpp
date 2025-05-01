/**
 *
 * @File:   singlelinklist.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-01
 *
 */
#include <iostream>

// 节点结构体定义
struct Node {
    int data;
    Node* next;
};

// 创建新节点
Node* createNode(int data) {
    Node* newNode = new Node; // 使用new分配内存
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// 函数功能：在链表的起始位置插入一个新节点
struct Node* insertAtBeginning(struct Node* head, int value)
{
    // 创建一个包含给定值的新节点
    struct Node* new_node = createNode(value);

    // 将新节点的 next 指针指向当前的链表头节点
    new_node->next = head;

    // 更新链表头指针，使其指向新节点
    head = new_node;

    // 返回更新后的链表头指针
    return head;
}


// 在链表尾部添加节点
struct Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }

	Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// 在指定位置插入节点
struct Node* insertAtPosition(Node* head, int pos, int data)
{
    // 若位置小于0，则视为无效位置
    if (pos < 0) {
        printf("无效位置!\n");
        return head;
    }

    if (pos == 0) {
        return insertAtBeginning(head, data);
    }

	Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "位置无效，无法插入节点\n";
        delete newNode; // 如果位置无效，释放新节点的内存
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// 删除链表中的指定位置节点
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr || pos < 0) {
        return head;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp; // 使用delete释放内存
        return head;
    }

	Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }

	if (curr == nullptr || curr->next == nullptr) {
        return head;
    }

	Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp; // 使用delete释放内存
    return head;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 主函数，用于测试链表操作
int main() {
    Node* head = nullptr;

    // 添加一些节点到链表
    head = appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 4);

    // 打印链表
    std::cout << "链表内容: ";
    printList(head);

    // 在第三个位置插入节点3 （索引从0开始）
    insertAtPosition(head, 2, 3);

    // 打印插入后的链表
    std::cout << "插入第三个节点后的链表: ";
    printList(head);

    // 删除第三个节点（值为3的节点）
    head = deleteAtPosition(head, 2);

    // 打印删除后的链表
    std::cout << "删除第三个节点后的链表: ";
    printList(head);

    // 释放链表内存（遍历链表并释放每个节点的内存）
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp; // 使用delete释放内存
    }

    return 0;
}
