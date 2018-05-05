//This program represents array as an abstract data type.
//In this, the static data is used in main() to demonstrate the logic

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
            cout << num <<" not found\n";
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
    Array a1 = Array(5);                //Create an array of size 5
    cout << "\nA1 : " << '\n';
    a1.readArray(3);
    a1.insert(18, 1);
    a1.traverse();
    if(a1.search(18) != -1)
        cout << "18 found!" << '\n';
    else
        cout << "18 not found!" << '\n';
    a1.remove(10);
    a1.traverse();

    Array a2 = Array(3);                //Create another array of size 3
    cout << "\nA2 : " << '\n';
    a2.readArray(3);
    a2.traverse();

    Array a3 = a1.merge(a2);            //Merge both arrays into third one
    a3.traverse();
    return 0;
}
