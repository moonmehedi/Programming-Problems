#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int arr[MAX][MAX];
int split[MAX][MAX];

string matrixOrder(int i, int j, int matrix[])
{
    if (i == j)
    {
        return "A" + to_string(i + 1);
    }

    int k = split[i][j];

    return "(" + matrixOrder(i, k, matrix) + " * " + matrixOrder(k + 1, j, matrix) + ")";
}

int mcm(int i, int j, int matrix[])
{
    if (i == j)
    {
        return 0;
    }
    if (arr[i][j] != INT_MAX)
    {
        return arr[i][j];
    }

    for (int k = i; k < j; k++)
    {
        int cost = mcm(i, k, matrix) + mcm(k + 1, j, matrix) + matrix[i] * matrix[k + 1] * matrix[j + 1];

        if (cost < arr[i][j])
        {
            arr[i][j] = cost;
            split[i][j] = k;
        }
    }
    return arr[i][j];
}

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        fill(arr[i], arr[i] + MAX, INT_MAX);
    }

    int matrix[7] = {30, 35, 15, 5, 10, 20, 25};

    cout << "Minimum number of scalar multiplications: " << mcm(0, 6, matrix) << endl;

    cout << "Optimal Parenthesization: " << matrixOrder(0, 6, matrix) << endl;

    return 0;
}
