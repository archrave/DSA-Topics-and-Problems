#include <iostream>
using namespace std;

template <typename T>
class Stack
{

    T *arr;
    int capacity;
    int nextIndex;

public:
    Stack()
    {
        capacity = 4;
        arr = new T[capacity];
        nextIndex = 0;
    }

    void push(T data)
    {
        if (nextIndex == capacity)
        {
            // cout << "\nStack Overflow!\n";
            capacity *= 2;
            T *newArr = new T[capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            // return;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }
    void pop()
    {
        if (nextIndex == 0)
        {
            cout << "\nStack Underflow!\n";
            return;
        }
        arr[nextIndex] = 0;
        nextIndex--;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    T top()
    {
        if (nextIndex == 0)
        {
            cout << "\nStack is Empty!\n";
            return 0; // Since 0 can act as any data type (even NULL pointer)
        }
        return arr[nextIndex - 1];
    }
    void print()
    {
        cout << "\n Stack: ";
        for (int i = 0; i < nextIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int showCapacity()
    {
        return capacity;
    }
};
int main()
{
    Stack<int> s1;
    int choice;
    while (true)
    {
        cout << "\n\n******** Stack ********\n\n";
        cout << "1. push()\n2. pop()\n3. print()\n4. size()\n5. isEmpty()\n6. top()\n7. capacity()\n8. exit()\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "\nEnter data: ";
            cin >> data;
            s1.push(data);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.print();
            break;
        case 4:
            cout << "\nSize: " << s1.size() << endl;
            break;
        case 5:
            if (s1.isEmpty())
                cout << "\nStack is Empty!";
            else
                cout << "Stack is not Empty!";
            break;
        case 6:
            cout << "\nTop of Stack: " << s1.top() << endl;
            break;
        case 7:
            cout << "\nCapacity: " << s1.showCapacity() << endl;
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