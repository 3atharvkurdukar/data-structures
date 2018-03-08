#include <iostream>

using namespace std;

class Array {
private:
    int *a;
    int length;
    int size;
public:
    Array(int s)
    {
        length = 0;
        size = s;
        a = new int[size];
    }
    void readArray(int len)
    {
        if (len <= size) {
            length = len;
            cout << "Enter " << len << " array elements : " << '\n';
            for (int i = 0; i < length; i++) {
                cin >> a[i];
            }
        }
    }
    int search(int num)
    {
        int found = -1;
        for (int i = 0; i < length; i++)
        {
            if (a[i] == num)
            {
                found = i;
                break;
            }
        }
        return found;
    }
    void traverse()
    {
        cout << "The array elements are : " << '\t';
        for (int i = 0; i < length; i++)
            cout << a[i] << '\t';
        cout << '\n';
    }
    void insert(int num, int index)
    {
        if (length < size)
        {
            for (int i = length-1; i >= index; i--)
            {
                a[i+1] = a[i];
            }
            a[index] = num;
            length++;
            cout << "Element inserted : " << num << '\n';
        }
        else
            cout << "Array is already full!" << '\n';
    }
    void remove(int num)
    {
        int index = search(num);
        if (index == -1)
        {
            cout << "Element not found\n";
        }
        else
        {
            for (int i = index; i < length-1; i++)
                a[i] = a[i+1];
            length--;
            cout << "Element removed : " << num << '\n';
        }
    }
    Array merge(Array &a2)
    {
        int s = this->size + a2.size;
        int len = 0;
        Array a3 = Array(s);
        for (int i = 0; i < this->length; i++, len++)
            a3.a[i] = this->a[i];
        for (int i = 0; i < a2.length; i++, len++)
            a3.a[len] = a2.a[i];

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

    do
    {
        cout << "\n\t" << "+--------MENU--------+" << '\n';
        cout << "\t| 1. Read array      |" << '\n';
        cout << "\t| 2. Insert element  |" << '\n';
        cout << "\t| 3. Remove element  |" << '\n';
        cout << "\t| 4. Search element  |" << '\n';
        cout << "\t| 5. Traverse array  |" << '\n';
        cout << "\t| 6. Exit            |" << '\n';
        cout << "\t+------------------+" << '\n';
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
        }
    } while(1);

    return 0;
}
