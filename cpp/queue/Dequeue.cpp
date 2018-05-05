//This program represents "double ended queue" as an abstract data type.
//In this, the main() function demonstrates menu-driven approach.

#include <iostream>

using namespace std;
class Dequeue
{
  private:
    int front, rear; //Front & rear index
    int capacity;    //Capacity of queue
    int *arr;        //Dynamic array

  public:
    Dequeue(int cap) //Constructor for initializing queue
    {
        capacity = cap;
        front = rear = -1;
        arr = new int[capacity]; //Dynamic memory allocation
    }
    int isEmpty() //To check if queue is empty
    {
        if (front == -1 && rear == -1)
            return 1; //Returns 1 if empty
        else
            return 0; //Returns 0 if empty
    }
    int isFull() //To check if queue is empty
    {
        if (rear == capacity - 1)
            return 1; //Returns 1  if full
        else
            return 0; //Returns 0  if full
    }
    void insertAtFront(int x) //Insert element at the front end
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << '\n';
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[front] = x;
        }
        else
        {
            for (int i = rear; i >= front; i--)
                arr[i + 1] = arr[i];
            rear++;
            arr[front] = x;
        }
    }
    void insertAtRear(int x) //Insert element at the rear end
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << '\n';
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    int removeAtFront() //Remove element at the front end
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << '\n';
            return -1;
        }
        else if (front == rear)
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
    int removeAtRear() //Remove element at the rear end
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << '\n';
            return -1;
        }
        else if (front == rear)
        {
            int temp = arr[rear];
            front = -1;
            rear = -1;
            return temp;
        }
        else
        {
            int temp = arr[rear];
            rear--;
            return temp;
        }
    }
    int display() //Display the elements of queue
    {
        cout << "Queue : " << '\t';
        if (front != -1)
        {
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
    Dequeue dq = Dequeue(size);

    cout << "\n"
         << "\t+ - - - - - -MENU- - - - - - +" << '\n';
    cout << "\t| 1. Insert element at front |" << '\n';
    cout << "\t| 2. Insert element at rear  |" << '\n';
    cout << "\t| 3. Remove element at front |" << '\n';
    cout << "\t| 4. Remove element at rear  |" << '\n';
    cout << "\t| 5. Display queue           |" << '\n';
    cout << "\t| 6. Exit                    |" << '\n';
    cout << "\t+ - - - - - - -- - - - - - - +" << '\n';

    //Menu driven program
    while (1)
    {
        cout << "Choice : " << '\t';
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number : " << '\t';
            cin >> num;
            dq.insertAtFront(num);
            break;
        case 2:
            cout << "Enter the number : " << '\t';
            cin >> num;
            dq.insertAtRear(num);
            break;
        case 3:
            dq.removeAtFront();
            break;
        case 4:
            dq.removeAtRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Bye bye..." << '\n';
            return 0;
            break;
        default:
            cout << "Invalid choice..." << '\n';
        }
    }
    return 0;
}
