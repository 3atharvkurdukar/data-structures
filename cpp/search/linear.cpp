// This program represents linear search algorithm
#include <iostream>
using namespace std;

int main()
{
    int *arr, num, size;
    cout << "Enter the size of array : ";
    cin >> size;
    arr = new int[size];

    cout << "Enter a sorted array : " << '\n';
    for (int i = 0; i < size; i++)             //Read an array
        cin >> arr[i];

    cout << "Enter the element to search : ";
    cin >> num;

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)                      //Compare every element in the array
        {
            found = true;                       //If found, set found to true
            break;
        }
    }                                           //Otherwise, it will remain false
    if (found)
        cout << "Element found!";
    else
        cout << "Element not found!";
    return 0;
}