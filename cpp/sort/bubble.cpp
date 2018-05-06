// This program represents selection sort algorithm
#include <iostream>
using namespace std;

void swap(int &x, int &y)               //Swap the contents
{
    int temp = x;
    x = y;
    y = temp;
}
void printArray(int arr[], int n)       //Print the array
{
    for (int i = 0; i < n; i++)
        cout << "\t" << arr[i];
    cout << "\n";
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])      //Compare consecutive elements
                swap(arr[j], arr[j+1]); //If smaller, swap with the samllest one
        }
        cout << "Step" << i + 1 << ": \t";
        printArray(arr, n);
    }
}
int main()
{
    int *arr, n;
    cout << "Enter the size of array : ";
    cin >> n;
    arr = new int[n];

    cout << "Enter a sorted array : " << '\n';
    for (int i = 0; i < n; i++)         //Read an array
        cin >> arr[i];
    
    bubbleSort(arr, n);
    cout << "Sorted Array : ";
    printArray(arr, n);
    return 0;
}