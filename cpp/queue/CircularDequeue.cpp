//This program represents "circular double-ended queue" as an abstract data type.
//In this, the main() function demonstrates menu-driven approach.

#include <iostream>

using namespace std;
class CircularDequeue
{
  private:
    int front, rear; //Front & rear index
    int capacity;    //Capacity of queue
    int *arr;        //Dynamic array

  public:
    CircularDequeue(int cap) //Constructor for initializing circular dequeue
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
        if ((rear + 1) % capacity == front)
            return 1; //Returns 1  if full
        else
            return 0; //Returns 0  if full
    }
    void insertAtFront(int x) //Insert element at the front end
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << '\n';
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if(front==0)
            front = capacity - 1;
        else
            front--;
        arr[front] = x;
    }
    void insertAtRear(int x) //Insert element at the rear end
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << '\n';
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if(rear == capacity - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = x;
    }
    int removeAtFront() //Remove element at the front end
    {
        int temp = -999;
        if (isEmpty())
        {
            cout << "Queue Underflow!" << '\n';
            return temp;
        }
        if (front == rear)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
        }
        else if(front == capacity - 1)
        {
            int temp = arr[front];
            front = 0;
        }
        return temp;
    }
    int removeAtRear() //Remove element at the rear end
    {
        int temp = -999;
        if (isEmpty())
        {
            cout << "Queue Underflow!" << '\n';
            return temp;
        }
        if (front == rear)
        {
            temp = arr[rear];
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
        {
            int temp = arr[rear];
            rear = -1;
        }
        return temp;
    }
    int display() //Display the elements of queue
    {
        cout << "Queue : " << '\t';
        if (front != -1)
        {
            for (int i = front; true;)
            {
                cout << " | " << arr[i];
                if (i == rear)
                    break;
                i = (i + 1) % capacity;
            }
        }
        cout << " |\n";
    }
};
int main()
{
    int size, choice, num;
    cout << "Enter the size of queue : ";
    cin >> size;
    CircularDequeue cdq = CircularDequeue(size);

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
            cdq.insertAtFront(num);
            break;
        case 2:
            cout << "Enter the number : " << '\t';
            cin >> num;
            cdq.insertAtRear(num);
            break;
        case 3:
            cdq.removeAtFront();
            break;
        case 4:
            cdq.removeAtRear();
            break;
        case 5:
            cdq.display();
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
