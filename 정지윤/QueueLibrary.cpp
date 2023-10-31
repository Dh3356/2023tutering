#include <iostream>
#include <queue>
int main() {
    std::queue<int> myQueue;  // ������ ť ����

    // ���� �߰�
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // ������ ����
    myQueue.pop();

    // �� ������
    int frontElement = myQueue.front();
    std::cout << "Front element: " << frontElement << std::endl;

    // ����
    int backElement = myQueue.back();
    std::cout << "Back element: " << backElement << std::endl;

    int queueSize = myQueue.size();
    std::cout << "Queue size: " << queueSize << std::endl;

    bool isEmpty = myQueue.empty();
    if (isEmpty) {
        std::cout << "Queue is empty." << std::endl;
    }
    else {
        std::cout << "Queue is not empty." << std::endl;
    }

	return 0;
}