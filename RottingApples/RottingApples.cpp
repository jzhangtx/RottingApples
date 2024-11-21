// RottingApples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

int GetRotDays(std::vector<std::vector<int>>& grid, size_t row, size_t col)
{
    if (row == grid.size() || col == grid.size() || row == (size_t)-1 || col == (size_t)-1)
        return -1;

    std::queue<std::pair<size_t, size_t>> next;
    if (grid[row][col] != 1)    // if the cell is empty or it contains a rotton apple, do not need to check
        return -1;

    if (row == grid.size() - 1 && col == grid[0].size() - 1 && grid[row][col] == 1) // the furthest cell from 0, 0
        return 1;

    grid[row][col] = 2;

    // all the cells around one rotten apple
    next.push(std::make_pair(row, col - 1));
    next.push(std::make_pair(row - 1, col));
    next.push(std::make_pair(row, col + 1));
    next.push(std::make_pair(row + 1, col));

    int days = -1;
    while (!next.empty())
    {
        auto p = next.front();
        next.pop();
        int d = GetRotDays(grid, p.first, p.second);
        if (d != -1)
        {
            if (days == -1)
                days = d;
            else
                days = std::min(days, d);
        }
    }

    if (days == -1)
        return days;

    return 1 + days;
}

int GetDaysToRot(std::vector<std::vector<int>>& grid)
{
    std::vector<std::vector<int>> gridCopy(grid);  // copy the grid so that it won't change the original grid

    int days = GetRotDays(gridCopy, 0, 0); // 0, 0 is the up-left corner and this will be treated as the first day
                                           //  so, the result should take the first day out
    if (days == -1)
        return days;

    return days-1;
}

int main()
{
    while (true)
    {
        int rows = 0, columns = 0;
        std::cout << "Rows and Columns of the grid: ";
        std::cin >> rows >> columns;
        if (rows == 0 && columns == 0)
            break;

        std::vector<std::vector<int>> grid(rows, std::vector<int>(columns, 0));
        std::cout << "Enter the grid: ";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
                std::cin >> grid[i][j];
        }

        std::cout << "It takes " << GetDaysToRot(grid) << " days to rot all the apples" << std::endl;
    }
}
