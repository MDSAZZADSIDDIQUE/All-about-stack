#include <iostream>

#include <windows.h>

#include <stdlib.h>

using namespace std;

class MyStack {
    int* stack;
    int top;
    int maxSize;

public:
    MyStack()
    {
    }

    MyStack(int size)
    {
        maxSize = size;
        stack = new int[maxSize];
        top = 0;
    }

    bool isEmpty()
    {
        return (top == 0);
    }

    bool isFull()
    {
        return (top == maxSize);
    }

    bool push(int element)
    {
        if (isFull()) {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "! T H E   S T A C K   I S   F U L L !" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        else
            stack[top++] = element;
        return true;
    }

    bool pop()
    {
        if (isEmpty()) {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "! T H E   S T A C K   I S   E M P T Y !" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        else
            top--;
        return true;
    }

    int topElement()
    {
        return stack[top - 1];
    }

    void resize(int size)
    {
        int* temporaryStack = new int[maxSize + size];
        for (int count = 0; count < maxSize; count++)
            temporaryStack[count] = stack[count];
        delete[] stack;
        stack = new int[maxSize + size];
        maxSize += size;
        stack = temporaryStack;
        delete[] temporaryStack;
    }

    void show()
    {
        if (isEmpty()) {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "! T H E   S T A C K   I S   E M P T Y !" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        else
            for (int count = top - 1; count >= 0; count--) {
                cout << stack[count] << endl;
            }
    }

    ~MyStack()
    {
        delete[] stack;
    }
};

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    int sizeOfTheStack = 0;
    cout << "I N P U T   T H E   S I Z E   O F   T H E   S T A C K :   ";
    cin >> sizeOfTheStack;
    MyStack myStack(sizeOfTheStack);
    int choice = 0;
    do {
        cout << "||================================================================================||" << endl;
        cout << "|| I N P U T   W H A T   Y O U   W A N N A   L I K E   T O   D O:                 ||" << endl;
        cout << "|| \t1 .   C H E C K   I F   T H E   S T A C K   I S   E M P T Y               ||" << endl;
        cout << "|| \t2 .   C H E C K   I F   T H E   S T A C K   I S   F U L L                 ||" << endl;
        cout << "|| \t3 .   P U S H   A N   E L E M E N T                                       ||" << endl;
        cout << "|| \t4 .   P O P   A N   E L E M E N T                                         ||" << endl;
        cout << "|| \t5 .   P R I N T   T H E   T O P   E L E M E N T   O F   T H E   S T A C K ||" << endl;
        cout << "|| \t6 .   R E S I Z E   T H E   S T A C K                                     ||" << endl;
        cout << "|| \t7 .   P R I N T   T H E   T H E   S T A C K                               ||" << endl;
        cout << "|| \t8 .   E X I T                                                             ||" << endl;
        cout << "||================================================================================||" << endl;
        do {
            cout << "----->   ";
            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8)
                cout << "I N P U T   S E R I A L   N U M B E R   F R O M   1   T O   8 . . ." << endl;
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8);
        switch (choice) {
        case 1: {
            myStack.isEmpty();
            break;
        }
        case 2: {
            myStack.isFull();
            break;
        }
        case 3: {
            int element = 0;
            cout << "I N P U T   A N   E L E M E N T :   ";
            cin >> element;
            myStack.push(element);
            break;
        }
        case 4: {
            myStack.pop();
            break;
        }
        case 5: {
            cout << "T H E   T O P   V A L U E   I S :   ";
            cout << myStack.topElement() << endl;
            break;
        }
        case 6: {
            int size = 0;
            cout << "I N P U T   T H E   N E W   S I Z E   O F   T H E   S T A C K :   ";
            cin >> size;
            myStack.resize(size);
            break;
        }
        case 7: {
            myStack.show();
            break;
        }
        case 8:
            break;
        }
    } while (choice != 8);
    return 0;
}
