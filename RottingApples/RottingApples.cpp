// RottingApples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

int GetRotDays(std::vector<std::vector<int>>& grid, std::queue<std::pair<size_t, size_t>>& rots)
{
    if (rots.size() == 0)
        return -1;

    std::queue<std::pair<size_t, size_t>> next;

    while (!rots.empty())
    {
        auto [r, c] = rots.front();
        if (r == grid.size() - 1 && c == grid[0].size() - 1)
            return 0;

        rots.pop();
        if (r != 0 && grid[r - 1][c] == 1)
        {
            grid[r - 1][c] = 2;
            next.push({ r - 1, c });
        }
        if (c != 0 && grid[r][c - 1] == 1)
        {
            grid[r][c - 1] = 2;
            next.push({ r, c - 1 });
        }
        if (r != grid.size() - 1 && grid[r + 1][c] == 1)
        {
            grid[r + 1][c] = 2;
            next.push({ r + 1, c });
        }
        if (c != grid[0].size() - 1 && grid[r][c + 1] == 1)
        {
            grid[r][c + 1] = 2;
            next.push({ r, c + 1 });
        }
    }

    auto days = GetRotDays(grid, next);
    if (days == -1)
        return days;
    return 1 + days;
}

int GetDaysToRot(std::vector<std::vector<int>>& grid)
{
    std::vector<std::vector<int>> gridCopy(grid);  // copy the grid so that it won't change the original grid
    std::queue<std::pair<size_t, size_t>> rots;
    rots.push({ 0, 0 });

    return GetRotDays(gridCopy,rots);
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

        auto days = GetDaysToRot(grid);
        if (days != -1)
            std::cout << "It takes " << GetDaysToRot(grid) << " days to rot all the apples" << std::endl;
        else
            std::cout << "It is impossible to rot all the apples!" << std::endl;

        std::cout << std::endl;
    }
}
