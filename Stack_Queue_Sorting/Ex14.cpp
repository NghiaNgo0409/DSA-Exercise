#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
};

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    /*TODO*/
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;

        // Even phase
        for (int i = 0; i < end - start - 1; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]);
                sorted = false;
            }
        }

        // Odd phase
        for (int i = 1; i < end - start - 1; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]);
                sorted = false;
            }
        }

        printArray(start, end);
    }
}