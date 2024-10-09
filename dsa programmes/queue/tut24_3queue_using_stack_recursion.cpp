#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> st;

public:
    void enqueue(int val)
    {
        st.push(val);
    }
    int dequeue()
    {
        if (st.empty())
        {
            cout << "stack is empty " << endl;
            return 0;
        }
        int x = st.top();
        st.pop();
        if (st.empty())
        {
            return x;
        }
        int temp = dequeue();
        st.push(x);
        return temp;
    }
};

int main()
{
    Queue moon;
    moon.enqueue(1);
    moon.enqueue(2);
    moon.enqueue(3);
    cout << moon.dequeue() << endl;
    cout << moon.dequeue() << endl;
    cout << moon.dequeue() << endl;
    cout << moon.dequeue() << endl;
}