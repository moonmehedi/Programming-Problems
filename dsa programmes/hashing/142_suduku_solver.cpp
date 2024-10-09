#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, map<int, int>> grid; // 2D map to track 3x3 grid
map<int, int> row[9];                    // Array of maps to track rows
map<int, int> coloum[9];                 // Array of maps to track columns

void helper(int r, int c, vector<vector<char>> &sudoku)
{
    // Base case: If end of the grid is reached, print the solved Sudoku
    if (r == 9)
    {
        for (auto it : sudoku)
        {
            for (auto ele : it)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // If end of the row is reached, move to the next row
    if (c == 9)
    {
        helper(r + 1, 0, sudoku);
        return;
    }

    // If the current cell is not empty, move to the next column
    if (sudoku[r][c] != '.')
    {
        helper(r, c + 1, sudoku);
        return;
    }

    // Try each digit from 1 to 9 in the current cell
    for (int i = 1; i <= 9; i++)
    {
        // Check if the digit is not present in the current 3x3 grid, row, or column
        if (grid[{r / 3, c / 3}][i] == false && row[r][i] == false && coloum[c][i] == false)
        {
            sudoku[r][c] = '0' + i;           // Assign the digit to the cell
            grid[{r / 3, c / 3}][i] = true;   // Update the 3x3 grid map
            row[r][i] = true;                 // Update the row map
            coloum[c][i] = true;              // Update the column map

            helper(r, c + 1, sudoku);         // Recursively move to the next column

            // Backtrack: Undo the changes made to the cell, row, column, and 3x3 grid maps
            grid[{r / 3, c / 3}][i] = false;
            row[r][i] = false;
            coloum[c][i] = false;
            sudoku[r][c] = '.';               // Assign '.' to signify an empty cell

        }
    }
    return;
}

int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Initialize the grid and maps based on the given initial configuration
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] != '.')
            {
                grid[{i / 3, j / 3}][sudoku[i][j] - '0'] = true;
                row[i][sudoku[i][j] - '0'] = true;
                coloum[j][sudoku[i][j] - '0'] = true;
            }
        }
    }

    helper(0, 0, sudoku); // Call the helper function to solve the Sudoku puzzle
}


/*
The given code is an implementation of a Sudoku solver using a backtracking algorithm. The main function, helper, is a recursive function that solves the Sudoku puzzle. It takes three parameters: r and c, representing the row and column indices of the current cell being processed, and sudoku, a reference to the Sudoku grid.

The algorithm starts by checking if r is equal to 9, which indicates that the end of the grid has been reached. If so, it prints the solved Sudoku grid and returns. This serves as the base case for the recursion.

If r is not equal to 9, the algorithm proceeds to check if c is equal to 9, which indicates the end of a row. In this case, it moves to the next row by making a recursive call to helper with r + 1 as the new row index and 0 as the column index.

If neither of the above conditions is met, the algorithm checks if the current cell is empty (denoted by .). If the cell is not empty, it moves to the next column by making a recursive call to helper with the same row index r but c + 1 as the new column index.

If the current cell is empty, the algorithm tries to fill it with a digit from 1 to 9. It checks if the digit is not already present in the current row, column, or 3x3 grid to which the cell belongs. If the digit satisfies this condition, it is assigned to the cell, and the corresponding entries in the row, column, and 3x3 grid maps are updated accordingly. Then, the algorithm makes a recursive call to helper with the same row index r but c + 1 as the new column index.

After the recursive call, the algorithm backtracks by undoing the changes made to the cell, row, column, and 3x3 grid maps. This allows the algorithm to explore other possible digits for the current cell. Finally, the algorithm assigns a . to the current cell to signify that it is empty again, and returns from the function.

The main function initializes the Sudoku grid and sets up the initial entries in the row, column, and 3x3 grid maps based on the given initial configuration. Then, it calls the helper function to solve the Sudoku puzzle.
*/