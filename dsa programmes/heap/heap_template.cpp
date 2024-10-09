// Max Heap
#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    int a[101], size;

public:
    Heap()
    {
        size = 0;
    }

private:
    // Function to adjust the heap from bottom to top after insertion
    void bottomTopAdjust(int i)
    {
        while (i != 1)
        {
            int parent = i / 2;
            if (a[parent] < a[i])
            {
                swap(a[parent], a[i]);
                i = parent;
            }
            else
                return;
        }
    }

    // Function to adjust the heap from top to bottom after deletion
    void topBottomAdjust(int daddy)
    {
        while (true)
        {
            int largest = daddy; // assuming daddy is the largest
            int left_child = 2 * daddy;
            int right_child = 2 * daddy + 1;

            // Trying to find the largest in three variables
            if (left_child <= size and a[left_child] > a[largest])
            {
                largest = left_child;
            }
            if (right_child <= size and a[right_child] > a[largest])
            {
                largest = right_child;
            }
            // Making daddy as the largest
            if (largest != daddy)
            {
                swap(a[largest], a[daddy]);
                daddy = largest; // daddy pointing to child and checking its child
            }
            else
                break;
        }
    }

public:
    // Function to insert a value into the heap
    bool insert(int val)
    {
        if (size == 101)
        {
            return false; // Heap is full
        }
        size++;
        a[size] = val;
        bottomTopAdjust(size);
        return true;
    }

    // Function to show the maximum element in the heap
    int showMax()
    {
        return a[1];
    }

    // Function to show the current size of the heap
    int showSize()
    {
        return size;
    }

    // Function to delete the root of the heap (maximum element)
    bool deleteRoot()
    {
        if (size == 0)
        {
            return false; // Heap is empty
        }
        swap(a[1], a[size]);
        size--;
        topBottomAdjust(1);
        return true;
    }

    // Function to build a heap from an array of elements
    void buildHeap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            topBottomAdjust(i);
        }
    }

    // Function to perform heap sort on the heap
    void sort()
    {
        int sz = size;
        while (size > 1)
        {
            swap(a[size], a[1]);
            size--;
            topBottomAdjust(1);
        }
        size = sz;
    }

    // Function to perform level-wise traversal of the heap
    void bfs()
    {
        if (size == 0)
            return; // Heap is empty
        int level = 2;
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            if (parent == level)
            {
                cout << endl;
                level = level * 2;
            }
            cout << a[parent] << " ";
            if (2 * parent <= size)
                q.push(2 * parent);
            if (2 * parent + 1 <= size)
                q.push(2 * parent + 1);
        }
    }
};

int main()
{
    Heap heap;

    while (1)
    {
        cout << "1. Insert    2. Show Max    3. Delete Max    4. Sort    5. Level    6. Build Heap    7. End" << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b)
                cout << y << " is inserted in the heap" << endl;
        }

        else if (choice == 2)
        {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the heap" << endl;
        }

        else if (choice == 3)
        {
            bool b = heap.deleteRoot();
            if (b)
                cout << "Root deleted from heap";
            else
                cout << "Heap is empty";
            cout << endl;
        }

        else if (choice == 4)
        {
            heap.sort();
        }

        else if (choice == 5)
        {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        }
        else if (choice == 6)
        {
            if (heap.showSize() == 0)
                cout << "Heap is Empty!" << endl;
            else
                heap.buildHeap();
        }
        else if (choice == 7)
        {
            break;
        }

        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/
/*
1 9
1 4
1 8
1
1
1
3
1
7
1
2
*/

/*
1
8
1
4
1
2
1
3
1
7
*/

/*
1
7
1
4
1
2
1
1
1
3

*/