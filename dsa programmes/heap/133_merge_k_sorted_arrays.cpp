
/*

Certainly! The purpose of this code is to merge multiple sorted arrays into a single sorted array using a priority queue (min-heap). Here's a simplified explanation of the code:

The code starts by declaring a class called Data, which represents an element from the input arrays. It holds three pieces of information: the value of the element, the array number it belongs to, and its position within that array.

Another class called mycomp is defined, which serves as a comparison function for the priority queue. It ensures that the elements with smaller values are given higher priority.

In the main function, the code takes input for the number of arrays and their sizes. It then reads the elements for each array and stores them in a 2D vector called arr.

A priority queue named min_heap is created with the element type set as Data and the comparison function set as mycomp. This priority queue will be used to merge the arrays.

The code initializes the priority queue by pushing the first element from each array into the min_heap.

The main part of the code is the while loop that continues until the min_heap is empty. In each iteration, it removes the element with the smallest value (top element) from the min_heap, appends its value to the ans vector, and updates the indices for the next element from the corresponding array.

If there are more elements remaining in the array from which the top element was taken, the next element is pushed into the min_heap.

Finally, the code prints the elements in the ans vector, which represents the merged and sorted array.

In summary, this code efficiently merges multiple sorted arrays into a single sorted array using a min-heap data structure.

*/

#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
    int val;
    int array_number;
    int arr_position;

    Data(int val, int array_number, int arr_position)
    {
        this->val = val;
        this->array_number = array_number;
        this->arr_position = arr_position;
    }
};

// comparator function defines will swap happen
// here if d1.value means top value > d2.value means last value then return ture
// if return true swap fun will be in effect
// as min_heap small value will have smallest value as top
class mycomp
{
public:
    bool operator()(Data &d1, Data &d2)
    {
        return d1.val > d2.val;
    }
};

int main()
{
    vector<int> ans;              // Vector to store the merged array
    vector<vector<int>> arr(200); // Vector of vectors to store the input arrays
    int number_of_arr, size;
    cin >> number_of_arr; // Read the number of arrays

    // Read the sizes and elements of each array
    for (int i = 0; i < number_of_arr; i++)
    {
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            int val;
            cin >> val;
            arr[i].push_back(val);
        }
    }

    priority_queue<Data, vector<Data>, mycomp> min_heap; // Priority queue (min-heap) to merge the arrays

    // Insert the first elements of all the sorted arrays into the min_heap
    for (int i = 0; i < number_of_arr; i++)
    {
        // Create a Data object with the value, array number, and position
        Data d(arr[i][0], i, 0);

        min_heap.push(d); // Push the object into the min_heap
    }

    // Merge the arrays
    while (!min_heap.empty())
    {
        Data head = min_heap.top(); // Get the element with the smallest value (top element)
        min_heap.pop();             // Remove the top element from the min_heap
        ans.push_back(head.val);    // Append the value to the ans vector

        int arr_number = head.array_number, arr_pos = head.arr_position;

        // If there are more elements remaining in the array from which the top element was taken
        if (arr_pos + 1 < arr[arr_number].size())
        {
            // Create a new Data object with the next element from the same array
            min_heap.push(Data(arr[arr_number][arr_pos + 1], arr_number, arr_pos + 1));
        }
    }

    // Print the merged and sorted array
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}