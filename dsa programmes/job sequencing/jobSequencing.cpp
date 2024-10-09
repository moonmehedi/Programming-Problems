#include <bits/stdc++.h>
using namespace std;

class job
{
public:
    int id;
    int deadline;
    int profit;

    job()
    {
    }

    job(int i, int d, int p)
    {
        id = i;
        deadline = d;
        profit = p;
    }
};

bool mycmp(job a, job b)
{
    return a.profit > b.profit;
}

int jobSequencing(vector<job> jobs)
{
    sort(jobs.begin(), jobs.end(), mycmp);

    vector<int> timeSlot(100, -1);

    int profit = 0;

    for (auto Job : jobs)
    {
        int DeadLine = Job.deadline;
        while (DeadLine > 0 and timeSlot[DeadLine] != -1)
        {
            DeadLine--;
            /* code */
        }

        if (DeadLine > 0)
        {
            timeSlot[DeadLine] = Job.id;
            profit = profit + Job.profit;
        }
    }
    for (auto ele : timeSlot)
    {
        cout << ele;
    }
    return profit;
}

int main()
{
    std::vector<job> jobs = {
        {1, 2, 60},
        {2, 1, 100},
        {3, 3, 20},
        {4, 2, 40}};

    cout
        << jobSequencing(jobs);
}