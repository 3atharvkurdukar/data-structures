// This program represents selection sort algorithm
#include <iostream>
using namespace std;

void swap(int &x, int &y)           //Swap the contents
{
    int temp = x;
    x = y;
    y = temp;
}
void printArray(int arr[], int n)   //Print the array
{
    for (int i = 0; i < n; i++)
        cout << "\t" << arr[i];
    cout << "\n";
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;                    //Coonsider first element as smallest
        for (j = i+1; j < n; j++)
        {
            if (arr[min] > arr[j])  //Compare with every other element
                min = j;            //If smaller, consider it as smallest
        }
        swap(arr[i], arr[min]);     //Swap with the samllest one
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
    for (int i = 0; i < n; i++)             //Read an array
        cin >> arr[i];
    
    selectionSort(arr, n);
    cout << "Sorted Array : ";
    printArray(arr, n);
    return 0;
}