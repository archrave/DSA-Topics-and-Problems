#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int nextIndex;
    int firstIndex;
    int capacity;

public:
    Queue()
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
        firstIndex = 0;
    }

    void push(int data)
    {
        if (nextIndex == capacity)
        {
            capacity *= 2;
            int *newArr = new int[capacity];
            for (int i = firstIndex; i < nextIndex; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }

    void pop()
    {
        if (firstIndex == nextIndex)
        {
            cout << "\nQueue Underflow!\n";
        }
        firstIndex++;
    }

    int size()
    {
        return nextIndex - firstIndex;
    }

    int front()
    {
        if (firstIndex == nextIndex)
        {
            cout << "\nQueue Empty!\n";
            return 0;
        }
        return arr[firstIndex];
    }

    bool isEmpty()
    {
        if (firstIndex == nextIndex)
            return true;
        else
            return false;
    }

    void print()
    {
        cout << "\nQueue: ";
        for (int i = firstIndex; i < nextIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getCapacity()
    {
        return capacity;
    }
};

int main()
{
    Queue q1;
    int choice;
    while (true)
    {
        cout << "\n\n****** Queue ********\n\n";
        cout << "1. push()\n2. pop()\n3. print()\n4. size()\n5. isEmpty()\n6. front()\n7. capacity()\n8. exit()\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "\nEnter data: ";
            cin >> data;
            q1.push(data);
            break;
        case 2:
            q1.pop();
            break;
        case 3:
            q1.print();
            break;
        case 4:
            cout << "\nSize: " << q1.size() << endl;
            break;
        case 5:
            if (q1.isEmpty())
                cout << "\nQueue is Empty!";
            else
                cout << "Queue is not Empty!";
            break;
        case 6:
            cout << "\nfront of Queue: " << q1.front() << endl;
            break;
        case 7:
            cout << "\nCapacity: " << q1.getCapacity() << endl;
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "\nInvalid Input!\n";
            break;
        }
    }
    return 0;
}