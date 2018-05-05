//This program represents "circular queue" as an abstract data type.
//In this, the main() function demonstrates menu-driven approach.

#include <iostream>

using namespace std;
class CircularQueue
{
private:
    int front, rear;                    //Front & rear index
    int capacity;                       //Capacity of queue
    int *arr;                           //Dynamic array

public:
    CircularQueue (int cap)               //Constructor for initializing stack
    {
        capacity = cap;
        front  = rear = -1;
        arr = new int[capacity];        //Dynamic memory allocation
    }
    int isEmpty()                       //To check if stack is empty
    {
        if (front == -1 && rear == -1)
            return 1;                   //Returns 1 if empty
        else
            return 0;                   //Returns 0 if empty
    }
    int isFull()                        //To check if stack is empty
    {
        if ((rear+1)%capacity == front)
            return 1;                   //Returns 1  if full
        else
            return 0;                   //Returns 0  if full
    }
    void insert(int x)                  //Insert element at the rear end
    {
        if (isFull()) {
            cout << "Queue Overflow!" << '\n';
        }
        else if(isEmpty()) {
            front =  0;
            rear = 0;
            arr[rear] = x;
        }
        else {
            rear++;
            arr[rear] = x;
        }
    }
    int remove()                        //Remove element at the front end
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << '\n';
            return -1;
        }
        else if(front == rear)
        {
            int temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }
        else
        {
            int temp = arr[front];
            front++;
            return temp;
        }
    }
    int display()                       //Display the elements of queue
    {
        cout << "Queue : " << '\t';
        if (front != -1) {
            for (int i = front; i <= rear; i++)
            cout << " | " << arr[i];
        }
        cout << " |\n";
    }
};
int main()
{
    int size, choice, num;
    cout << "Enter the size of queue : ";
    cin >> size;
    CircularQueue cq = CircularQueue(size);

    cout << "\n\t" << "+ - - - -MENU- - - - +" << '\n';
    cout << "\t| 1. Insert element  |" << '\n';
    cout << "\t| 2. Remove element  |" << '\n';
    cout << "\t| 3. Display queue   |" << '\n';
    cout << "\t| 4. Exit            |" << '\n';
    cout << "\t+ - - - - -- - - - - +" << '\n';

    //Menu driven program
    while (1)
    {
        cout << "Choice : " << '\t';
        cin >> choice;
        switch (choice)
        {
            case 1 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                cq.insert(num);
                break;
            case 2 :
                cq.remove();
                break;
            case 3 :
                cq.display();
                break;
            case 4 :
                cout << "Bye bye..." << '\n';
                return 0;
                break;
            default :
                cout << "Invalid choice..." << '\n';
        }
    }
    return 0;
}
