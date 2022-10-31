#include <iostream>
using namespace std;

static int iterations;

typedef int Type;

size_t binarySearch(Type a[], size_t start, size_t end, Type val)
{
    while (start <= end)
    {
        size_t mid = start + ((end - start) >> 1);   // x/2 == x>>1
        iterations++;
        if (val == a[mid]){
            return mid;       // return index of element
        }
        else if (val < a[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int idx = binarySearch(arr, 0, 9, 99);


    if (idx == -1){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES, " << "index = " << idx << "\n";
    }

    cout << "num of iterations: " << iterations << "\n";

    return 0;
}

