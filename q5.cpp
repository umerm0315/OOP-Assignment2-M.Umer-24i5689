#include <iostream>
using namespace std;

class Node 
{
public:
    char data;
    Node* next;
    Node(char c) 
    { 
        data = c; 
        next = nullptr; 
    }
};

class NodeStack 
{
private:
    Node* top;

public:
    NodeStack() 
    { top = nullptr; 
    }
    
    void push(char c) 
    {
        Node* node = new Node(c);
        node->next = top;
        top = node;
    }

    char pop() 
    {
        if (top == nullptr) 
            return '\0';
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }
};


class ArrayStack 
{
private:
    char* arr;
    int size;
    int top;

public:
    ArrayStack() 
    { 
        size = 10;
        arr = new char[size];
        top = -1;
    }

    void push(char c) 
    {
        if (top == size - 1) 
        {
            char* temp = new char[size * 2];
            for (int i = 0; i < size; i++) 
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            size *= 2;
        }
        arr[++top] = c;
    }

    char pop() 
    {
        if (top < 0) 
            return '\0';
        return arr[top--];
    }
};

// Q1a 
void ChangeLA(char* Array, int b1, int b2) 
{
    ArrayStack stack;
    for (int i = b1 - 1; i < b2; i++) 
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++) 
        Array[i] = stack.pop();
}

void ChangeLL(char* Array, int b1, int b2) 
{
    NodeStack stack;
    for (int i = b1 - 1; i < b2; i++) 
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++) 
        Array[i] = stack.pop();
}

// Q1b 
void PrintPA(int n) 
{
    ArrayStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2) 
            { 
                stack.push('2'); 
                rem -= 2; 
            }
            else 
            { 
                stack.push('1'); 
                rem--; 
            }
        }
        
        char c;
        while ((c = stack.pop()) != '\0') 
            cout << c << " ";
        cout << endl;
    }
}

void PrintPL(int n) 
{
    NodeStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2) 
            { 
                stack.push('2'); 
                rem -= 2; 
            }
            else 
            { 
                stack.push('1'); 
                rem--; 
            }
        }
        
        char c;
        while ((c = stack.pop()) != '\0') 
            cout << c << " ";
        cout << endl;
    }
}

int main() 
{
    // part a test 
    char arr1[] = "COMPUTER";
    char arr2[] = "COMPUTER";
    
    cout << "Original " << arr1 << endl;
    
    cout << "Array-based \n " ;
    ChangeLA(arr1, 3, 7);
    cout << "Changed: " << arr1 << endl;
    
    cout << "List-based \n" ;
    ChangeLL(arr2, 3, 7);
    cout << "Changed: " << arr2 << endl;
    
 
    cout << "Pattern for n=4 (Array-based) \n" ;
    PrintPA(4);
    
    cout << "Pattern for n=4 (List-based) \n" ;
    PrintPL(4);
    
    return 0;
}