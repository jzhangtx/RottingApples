package main

import "fmt"

type Cell struct {
	i, j int
}

func DaysToRot(grid [][]int, rots []Cell) int {
	if len(rots) == 0 {
		return -1
	}
	var newRots []Cell
	for i := 0; i < len(rots); i++ {
		c := rots[i]
		if c.i == len(grid)-1 && c.j == len(grid[0])-1 {
			return 0
		}

		if c.i != 0 && grid[c.i-1][c.j] == 1 {
			grid[c.i-1][c.j] = 2
			newRots = append(newRots, Cell{c.i - 1, c.j})
		}

		if c.j != 0 && grid[c.i][c.j-1] == 1 {
			grid[c.i][c.j-1] = 2
			newRots = append(newRots, Cell{c.i, c.j - 1})
		}

		if c.i != len(grid)-1 && grid[c.i+1][c.j] == 1 {
			grid[c.i+1][c.j] = 2
			newRots = append(newRots, Cell{c.i + 1, c.j})
		}

		if c.j != len(grid[0])-1 && grid[c.i][c.j+1] == 1 {
			grid[c.i][c.j+1] = 2
			newRots = append(newRots, Cell{c.i, c.j + 1})
		}
	}

	d := DaysToRot(grid, newRots)
	if d == -1 {
		return -1
	}
	return d + 1
}

func GetDaysToRot(grid [][]int) int {
	rots := make([]Cell, 1)
	rots[0] = Cell{0, 0}

	return DaysToRot(grid, rots)
}

func main() {
	for {
		fmt.Print("Please enter the size of the grid (rows, cols): ")
		var rows, cols int
		fmt.Scan(&rows, &cols)
		if rows == 0 && cols == 0 {
			break
		}

		grid := make([][]int, rows)
		for r := 0; r < rows; r++ {
			fmt.Print("Please enter the ")
			fmt.Print(r)
			fmt.Print("th row of the grid: ")
			grid[r] = make([]int, rows)
			for c := 0; c < cols; c++ {
				fmt.Scan(&grid[r][c])
			}
		}

		days := GetDaysToRot(grid)
		if days == -1 {
			fmt.Println("It's impossible to rot all the apples!")
		} else {
			fmt.Print("It takes ")
			fmt.Print(days)
			fmt.Println(" days to rot all the apples.")
		}
		fmt.Println("")
	}
}
