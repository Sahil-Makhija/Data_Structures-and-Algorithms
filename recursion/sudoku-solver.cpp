#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rowPoints(vector<vector<char>> &board, vector<int> &row, int rowIndex)
    {
        row.clear();
        for (int i = 0; i < 9; i++)
        {
            if (board[rowIndex][i] != '.')
            {
                row.push_back(board[rowIndex][i] - '0');
            }
        }
    }

    void colPoints(vector<vector<char>> &board, vector<int> &col, int colIndex)
    {
        col.clear();
        for (int i = 0; i < 9; i++)
        {
            if (board[i][colIndex] != '.')
            {
                col.push_back(board[i][colIndex] - '0');
            }
        }
    }

    void gridPoints(vector<vector<char>> &board, vector<int> &grid, vector<int> &point)
    {
        grid.clear();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[point[0 + i]][point[1 + j]] != '.')
                {
                    grid.push_back(board[point[0 + i]][point[1 + j]] - '0');
                }
            }
        }
    }

    void getAvailablePoints(vector<char> &availablePoints, vector<int> &row, vector<int> &col, vector<int> &grid)
    {
        availablePoints.clear();
        for (int i = 1; i <= 9; i++)
        {
            if (find(row.begin(), row.end(), i) != row.end() && find(col.begin(), col.end(), i) != col.end() && find(grid.begin(), grid.end(), i) != grid.end())
            {
                availablePoints.push_back((char)('0' + i));
            }
        }
    }

    void sudokuSolver(vector<vector<char>> &board, vector<int> &point, vector<int> &row, vector<int> &col, vector<int> &grid, vector<char> &availablePoints)
    {
        // rowIndex > 8
        if (point[0] > 8)
            return;

        if (point[1] > 8)
        {
            point[0] = point[0] + 1;
            point[1] = 0;
            sudokuSolver(board, point, row, col, grid, availablePoints);
            return;
        }

        if (point[1] == 0)
        {
            rowPoints(board, row, point[0]);
        }

        if (point[0] % 3 == 0 || point[1] % 3 == 0)
        {
            gridPoints(board, grid, point);
        }

        if (board[point[0]][point[1]] == '.')
        {
            // solver code starts here...
            colPoints(board, col, point[1]);
            getAvailablePoints(availablePoints, row, col, grid);
            if (availablePoints.size() == 0)
                return;
            for (char n : availablePoints)
            {
            }
        }

        point[1] = point[1] + 1;
        sudokuSolver(board, point, row, col, grid, availablePoints);
        return;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        // x,y co-ordinates
        vector<int> point(2, 0);
        vector<int> row;
        vector<int> col;
        vector<int> grid;
        vector<char> availablePoints;
        sudokuSolver(board, point, row, col, grid, availablePoints);
    }
};

int main()
{
}