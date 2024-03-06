#include <raylib.h>
#include <iostream>
#include "grid.h"

void Grid::Draw()
{
    for(int row = 0; row < rows; row ++) 
    {
        for(int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    cells[row][column] = value;
}

int Grid::GetValue(int row, int column)
{
    return cells[row][column];
}

void Grid::FillRandom() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            // Generate a random value between 0 and 9
            int randomValue = GetRandomValue(0, 4);
            // If the random value is 4, set the cell to 1; otherwise, set it to 0.
            cells[row][column] = (randomValue == 4) ? 1 : 0;
        }
    }
}

void Grid::Clear()
{
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            cells[row][column] =  0;
        }
    }
}

void Grid::ToggleCell(int row, int column)
{
    cells[row][column] = !cells[row][column];
}