// This program represents selection sort algorithm
#include <iostream>
using namespace std;

void printArray(int arr[], int n)   //Print the array
{
    for (int i = 0; i < n; i++)
        cout << "\t" << arr[i];
    cout << "\n";
}
void insertionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 1; i < n; i++)
    {
        min = arr[i];                    //Consider first element as smallest
        for (j = i-1; j >= 0; j--)
        {
            if (arr[j] > min)            //Compare with every other element
                arr[j+1] = arr[j];       //If greater, shift the elements
            else
                break;
        }
        arr[j+1] = min;
        cout << "Step " << i << ": ";
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
    for (int i = 0; i < n; i++)     //Read an array
        cin >> arr[i];
    
    insertionSort(arr, n);
    cout << "Sorted Array : ";
    printArray(arr, n);
    return 0;
}