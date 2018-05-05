//This program represents "stack" as an abstract data type.
//In this, the main() function demonstrates menu-driven approach.

#include <iostream>
using namespace std;

class MyStack                       //The construction of stack as a class
{
private:
    int top;                        //Top of stack
    int capacity;                   //Max capacity of stack
    int *arr;                       //The dynamic array to hold values

public:
    MyStack (int c)                 //Constructor for initializing stack
    {
        top = -1;
        capacity = c;
        arr = new int[capacity];    //Dynamic memory allocation
    }
    int isEmpty()                   //To check if stack is empty
    {
        if (top == -1)
            return 1;               //Returns 1  if empty
        else
            return 0;               //Returns 0 if not empty
    }
    int isFull()                    //To check if stack is empty
    {
        if (top == capacity-1)
            return 1;               //Returns 1  if full
        else
            return 0;               //Returns 0  if not full
    }
    void push(int x)                //Push data to the top of the stack
    {
        if (isFull())               //Print error if stack already full
            cout << "Stack overflow!" << '\n';
        else
        {
            top++;
            arr[top] = x;
            cout << "Element pushed" << '\n';
        }
    }
    int pop()                       //Remove data from top of the stack
    {
        if (isEmpty())              //Print error if stack already empty
            cout << "Stack underflow!" << '\n';
        else
        {
            top--;
            cout << "Element popped" << '\n';
            return arr[top+1];
        }
    }
    void display()                  //Display the elements of stack
    {
        cout << "Stack: " << '\t';
        if (top >= 0)
        {
            for (int i = top; i >=0 ; i--)
            {
                cout << " | " << arr[i];
            }
            cout << " |\n";
        }
    }
    ~MyStack()                      //Free memory using destructor
    {
        delete arr;
    }
};
int main()
{
    int size, num;
    int choice;
    cout << "Enter the size of  stack : " << '\t';
    cin >> size;
    MyStack s1 = MyStack(size);

    //Menu driven program
    while(1)
    {
        cout << "\n\t" << "+ - - -MENU- - - +" << '\n';
        cout << "\t| 1. Push element|" << '\n';
        cout << "\t| 2. Pop element |" << '\n';
        cout << "\t| 3. Display     |" << '\n';
        cout << "\t| 4. Exit        |" << '\n';
        cout << "\t+ - - - -- - - - +" << '\n';
        cout << "Choice : " << '\t';
        cin >> choice;
        switch (choice)
        {
            case 1 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                s1.push(num);
                break;
            case 2 :
                s1.pop();
                break;
            case 3 :
                s1.display();
                break;
            case 4 :
                cout << "Bye bye..." << '\n';
                return 0;
                break;
        }
    }

    return 0;
}
