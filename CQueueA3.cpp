#include <iostream>
using namespace std;

// Node structure for the circular queue
struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue(){
		 front=nullptr;
		 rear=nullptr;
	}

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (front == nullptr) {
            // Queue is empty
            front = newNode;
            rear = newNode;
            rear->next = front; // Point to itself
        } else {
            rear->next = newNode; // Link new node at the end
            rear = newNode;       // Update rear
            rear->next = front;  // Make it circular
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == nullptr) {
            throw runtime_error("Queue underflow: The queue is empty.");
        }

        int value;
        if (front == rear) {
            // Single element in the queue
            value = front->data;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            value = temp->data;
            front = front->next; // Move front to next node
            rear->next = front;  // Maintain circular link
            delete temp;
        }

        return value;
    }

    // Display the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Check if the queue is empty
    /*bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }*/
    };

int main() {
    CircularQueue queue;

    cout << "Circular Queue Implementation using Linked List" << endl;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            try {
                cout << "Dequeued value: " << queue.dequeue() << endl;
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
            break;
        case 3:
            queue.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
