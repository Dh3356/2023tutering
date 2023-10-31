#include <iostream>
#include <queue>
int main() {
    std::queue<int> myQueue;  // Á¤¼öÇü Å¥ ¼±¾ð

    // ¼ýÀÚ Ãß°¡
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // ÆËÆËÆË ÆËÆË
    myQueue.pop();

    // ¸Ç À§¿¡²¨
    int frontElement = myQueue.front();
    std::cout << "Front element: " << frontElement << std::endl;

    // Á¦°Å
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