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
    Array a1 = Array(5);
    cout << "\nA1 : " << '\n';
    a1.readArray(3);
    a1.insert(18, 1);
    a1.traverse();
    if(a1.search(18) != -1)
        cout << "Element found!" << '\n';
    else
        cout << "Element not found!" << '\n';
    a1.remove(10);
    a1.traverse();

    Array a2 = Array(3);
    cout << "\nA2 : " << '\n';
    a2.readArray(3);
    a2.traverse();

    Array a3 = a1.merge(a2);
    a3.traverse();
    return 0;
}
