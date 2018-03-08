//This program represents array as an abstract data type.
//In this, the main() function demonstrates menu-driven approach.

#include <iostream>

using namespace std;

class Array
{
private:
    int *a;         //The dynamic Array
    int length;     //The current length of Array
    int size;       //The maximum size of array
public:
    Array(int s)    //Constructor for initializing the array
    {
        length = 0;
        size = s;
        a = new int[size];  //Dynamic memory allocation
    }
    void readArray(int len)     //Read 'n' no. of elements at a time
    {
        if (len <= size)
        {
            length = len;
            cout << "Enter " << len << " array elements : " << '\n';
            for (int i = 0; i < length; i++)
            {
                cin >> a[i];
            }
        }
    }
    int search(int num)         //Search for an element in the array
    {
        int found = -1;         //For detecting whether it is found
        for (int i = 0; i < length; i++)
        {
            if (a[i] == num)
            {                   //If element entered matches with the
                found = i;      //array element, found will store its index
                break;          //and break the whole loop
            }
        }
        return found;           //Return index if found or -1 if not found
    }
    void traverse()             //Print the whole array
    {
        cout << "The array elements are : " << '\t';
        for (int i = 0; i < length; i++)
        {
            cout << a[i] << '\t';
        }
        cout << '\n';
    }
    void insert(int num, int index)     //Insert element at given index
    {
        if (length < size)
        {
            for (int i = length-1; i >= index; i--) //Push all the elemnts ahead
            {                                       //by one position
                a[i+1] = a[i];
            }
            a[index] = num;                         //& put new element there
            length++;
            cout << "Element inserted : " << num << '\n';
        }
        else
            cout << "Array is already full!" << '\n';
    }
    void remove(int num)                //Remove specified element
    {
        int index = search(num);        //Search for index of element
        if (index == -1)                //if -1, it is not in array
        {
            cout << "Element not found\n";
        }
        else
        {
            for (int i = index; i < length-1; i++)  //Move all the elements
                a[i] = a[i+1];                      //backward by 1
            length--;
            cout << "Element removed : " << num << '\n';
        }
    }
    Array merge(Array &a2)      //Merge one array with the other
    {
        int s = this->size + a2.size;
        int len = 0;
        Array a3 = Array(s);
        for (int i = 0; i < this->length; i++, len++)   //Add all elements
            a3.a[i] = this->a[i];                       //from array 1
        for (int i = 0; i < a2.length; i++, len++)      //Add all elements
            a3.a[len] = a2.a[i];                        //from array 2

        a3.length = len;
        return a3;
    }
};
int main()
{
    int s, n, num, index;
    int choice;
    cout << "Enter the size of  array : " << '\t';
    cin >> s;
    Array arr = Array(s);

    //Menu driven program
    do
    {
        cout << "\n\t" << "+- - - --MENU-- - - -+" << '\n';
        cout << "\t| 1. Read array      |" << '\n';
        cout << "\t| 2. Insert element  |" << '\n';
        cout << "\t| 3. Remove element  |" << '\n';
        cout << "\t| 4. Search element  |" << '\n';
        cout << "\t| 5. Traverse array  |" << '\n';
        cout << "\t| 6. Exit            |" << '\n';
        cout << "\t+- - - - ---- - - - -+" << '\n';
        cout << "Choice : " << '\t';
        cin >> choice;
        switch (choice)
        {
            case 1 :
                cout << "Enter the no. of elements : " << '\t';
                cin >> n;
                arr.readArray(n);
                break;
            case 2 :
                cout << "Enter the number and index : " << '\t';
                cin >> num >> index;
                arr.insert(num, index);
                break;
            case 3 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                arr.remove(num);
                break;
            case 4 :
                cout << "Enter the number : " << '\t';
                cin >> num;
                if (arr.search(num) != -1)
                    cout << "Element found!" << '\n';
                else
                    cout << "Element not found!" << '\n';
                break;
            case 5 :
                arr.traverse();
                break;
            case 6 :
                cout << "Bye bye..." << '\n';
                return 0;
                break;
            default :
                cout << "Invalid choice....";
        }
    } while(1);

    return 0;
}
