// This program represents linear search algorithm
#include <iostream>
using namespace std;
bool binary_search(int *arr, int num, int size)
{
    int start = 0, end = size - 1;
    do
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            return true;
        }
        else if (arr[mid] > num)
            end = mid - 1;
        else if (arr[mid] < num)
            start = mid + 1;
    } while (start != end);
    return false;
}
int main()
{
    int *arr, num,  size;
    cout << "Enter the size of array : ";
    cin >> size;
    arr = new int[size];

    cout << "Enter a sorted array : " << '\n';
    for (int i = 0; i < size; i++)             //Read an array
        cin >> arr[i];

    cout << "Enter the element to search : ";
    cin >> num;

    bool found = binary_search(arr, num, size);

    if (found)
        cout << "Element found!";
    else
        cout << "Element not found!";
    return 0;
}