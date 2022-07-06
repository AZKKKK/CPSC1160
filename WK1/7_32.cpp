#include <iostream>

using namespace std;

int partition (int list[], const int size);


int main()
{
    cout << "Enter a size of the list: ";
    int size;
    cin >> size;
    int* list = new int[size];

    for (int i = 0; i < size; i++)
        cin >> list[i];

    partition(list, size);

    cout << "After the partition, the list is: ";
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";


    delete[] list;
    list = nullptr;
    return 0;


}

int partition (int list[], const int size)
{
    int first = 0;
    int last = size - 1;
    int pivot = list[first];
    int low = first + 1;
    int high = last;

    while (high > low)
    {
        while (low <= high && list[low] <= pivot)
            low ++;

        while (low <= high && list[high] > pivot)
            high --;

        if (high > low)
        {
            int temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    while (high > first && list[high] >= pivot)
        high --;

    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot;
        return high;
    }
    else
    {
        return first;
    }
    

  
}