#include <iostream>
using namespace std;

static int iterations;

typedef int Type;
#define KEY_NOT_FOUND -1

size_t binarySearch(Type a[], size_t start, size_t end, Type key)
{
    while (start <= end)
    {
        size_t mid = start + ((end - start) >> 1);   // x/2 == x>>1
        iterations++;
        if (key == a[mid]) {
            return mid;       // return index of element
        }
        if (key < a[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        
    }
    return KEY_NOT_FOUND;
}

size_t binarySearchV2(Type a[], size_t start, size_t end, Type key)
{
    while (start < end)
    {
        size_t mid = start + ((end - start) >> 1);   // x/2 == x>>1
        iterations++;
        if (key >  a[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }

    if (start == end && key == a[start]) {
        return start; // return index of element
    }
        
    return KEY_NOT_FOUND;
}



int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int idx = binarySearchV2(arr, 0, 9, 4);


    if (idx == KEY_NOT_FOUND){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES, " << "index = " << idx << "\n";
    }

    cout << "num of iterations: " << iterations << "\n";

    return 0;
}

