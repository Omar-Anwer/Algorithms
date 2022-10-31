#include <iostream>
using namespace std;

static int iterations;

typedef int Type;

#define KEY_NOT_FOUND -1


size_t OneWaylinearSearch(Type a[], size_t size, Type key)
{
    for (int i = 0; i < size; ++i)
    {
        if (key == a[i]) {
            return i;
        }
        //iterations++;
    }
    return KEY_NOT_FOUND;
}

size_t TwoWayLinearSearch(Type a[], size_t size, Type key)
{
     size = size - 1;
    for (int i = size; i >= 0; --i)
    {
        if (key == a[i]){
            return i;   
        }
        if (key == a[size - i]) {  // search on both directions to have O(n/2) instead of O(n)
            return (size - i);
        }
        iterations++;
    }
    return KEY_NOT_FOUND;
}

size_t TwoWayLinearSearchV2(Type a[], size_t size, Type key)
{
    size_t front = 0;
    size_t back = size - 1;
    while (front <= back)
    {
        if (key != a[front] &&  key != a[back]) {
            ++front;
            --back;
            //iterations++;
        }
        else {
            return ((key == a[front]) ? front : back);
        }
    }
    return KEY_NOT_FOUND;
}



int main()
{
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(*arr);

    int idx = TwoWayLinearSearch(arr, size, 8);

    if (idx == KEY_NOT_FOUND) {
        cout << "NO " <<"\n";
    }
    else {
        cout << "YES, " << "idx = " << idx<< "\n";
    }

    cout << "num of iterations: " << iterations << "\n";


    return 0;
}
