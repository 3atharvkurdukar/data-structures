//This program represents "linked list" as an abstract data type.
//The main() function demonstrates menu-driven approach.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class SingleList {
private:
    Node* head;

public:
    SingleList ()
    {
        head = NULL;
    }
    void insertAtBeg(int num)
    {
        Node *temp = new Node();
        temp->data = num;
        temp->next = head;
        head = temp;
    }
    void insertAtEnd(int num)
    {
        Node *temp1 = new Node();
        Node *temp2 = head;
        if(head == NULL)
        {
            insertAtBeg(num);
            return;
        }
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp1->data = num;
        temp1->next = NULL;
        temp2->next = temp1;
    }
    void insert(int num, int n)
    {
        Node *temp1 = new Node();
        if(n == 0)
        {
            insertAtBeg(num);
            return;
        }
        Node *temp2 = head;
        for (int i = 0; i < n-1; i++)
        {
            if (temp2->next == NULL)
                break;
            else
                temp2 = temp2->next;
        }
        temp1->data = num;
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
    void remove(int num)
    {
        Node *temp1;
        Node *temp2 = head;
        if(temp2->data == num)
        {
            temp1 = head;
            head = temp1->next;
            delete temp1;
            return;
        }
        int found = 0;
        temp1 = temp2->next;
        while (temp1->next != NULL)
        {
            if (temp1->data == num)
            {
                found = 1;
                break;
            }
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        cout << temp1->data << '\n';
        if(found == 1)
        {
            temp2->next = temp1->next;
            delete temp1;
        }
        else
            cout << "Element not found!\n";
    }
    void removeAt(int n)
    {
        Node *temp1;
        Node *temp2 = head;
        if(n == 0)
        {
            temp1 = head;
            head = temp1->next;
            delete temp1;
            return;
        }
        for (int i = 0; i < n-1; i++)
        {
            if (temp2->next->next == NULL)
                break;
            else
                temp2 = temp2->next;
        }
        temp1 = temp2->next;
        temp2->next = temp1->next;
        delete temp1;
    }
    void reverse()
    {
        Node *prev, *curr, *next;
        prev = NULL;
        curr = head;
        next = curr->next;
        while(next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = prev;
        head = curr;
    }
    //Recursion logic for reverse of linked list
    /*
    void reverse(Node *prev=NULL, Node *curr=head, Node *next=head->next)
    {
        if (next != NULL)
        {
            curr->next = prev;
            reverse(curr, next, curr->next);
        }
        else
        {
            curr->next = prev;
            head = curr;
        }
    }
    */
    void display()
    {
        Node *temp = head;
        std::cout << "Linked List : " << '\n';
        while(temp != NULL)
        {
            cout << "\t" << temp->data;
            temp = temp->next;
        }
        cout << '\n';
    }
};
int main()
{
    int num, index;
    int choice;
    SingleList s1 = SingleList();

    //Menu driven program
    cout << "\n\t" << "+ - - - - -MENU- - - - - +" << '\n';
    cout << "\t| 1. Insert at beginning |" << '\n';
    cout << "\t| 2. Insert at end       |" << '\n';
    cout << "\t| 3. Insert at index     |" << '\n';
    cout << "\t| 4. Remove number       |" << '\n';
    cout << "\t| 5. Remove at index     |" << '\n';
    cout << "\t| 6. Display             |" << '\n';
    cout << "\t| 7. Reverse list        |" << '\n';
    cout << "\t| 8. Exit                |" << '\n';
    cout << "\t+ - - - - - -- - - - - - +" << '\n';
    do
    {
        cout << "Choice : " << '\t';
        cin >> choice;
        switch (choice)
        {
            case 1 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                s1.insertAtBeg(num);
                break;
            case 2 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                s1.insertAtEnd(num);
                break;
            case 3 :
                cout << "Enter the number and index : " << '\t';
                cin >> num >> index;
                s1.insert(num, index);
                break;
            case 4 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                s1.remove(num);
                break;
            case 5 :
                cout << "Enter the index : " << '\t';
                cin >> index;
                s1.removeAt(index);
                break;
            case 6 :
                s1.display();
                break;
            case 7 :
                s1.reverse();
                break;
            case 8 :
                cout << "Bye bye..." << '\n';
                return 0;
                break;
        }
    } while(1);

    return 0;
}
