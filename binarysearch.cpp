#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> key;
    int iterativeResult = binarySearchIterative(arr, n, key);
    int recursiveResult = binarySearchRecursive(arr, 0, n - 1, key);
    cout << "\n----- Search Results -----\n";
    if (iterativeResult != -1)
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    else
        cout << "Iterative: Element not found\n";
    if (recursiveResult != -1)
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    else
        cout << "Recursive: Element not found\n";
    cout << "\nTime Complexity: O(log n)";
    cout << "\nSpace Complexity (Iterative): O(1)";
    cout << "\nSpace Complexity (Recursive): O(log n)\n";
    return 0;
}
