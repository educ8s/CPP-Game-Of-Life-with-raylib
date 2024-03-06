#include <array>
#include <utility> 
#include "simulation.h"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row = 0; row < rows; row++)
        {
            for(int column = 0; column < columns; column++)
            {
                int live_neighbors = CountLiveNeighbors(row, column);
                int cell_value = grid.GetValue(row, column);
                if(cell_value == 1)
                {
                    if(live_neighbors > 3 || live_neighbors < 2)
                    {
                        temp_grid.SetValue(row, column, 0);
                    }
                    else
                    {
                        temp_grid.SetValue(row, column, 1);
                    }
                } 
                else
                {
                    if(live_neighbors == 3)
                    {
                        temp_grid.SetValue(row, column, 1);
                    }
                    else
                    {
                        temp_grid.SetValue(row, column, 0);
                    }
                }
            }
        }

        grid = temp_grid;
    }
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;

    std::array<std::pair<int, int>, 8> neighbor_offsets = {{
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
    }};

    for(auto& offset: neighbor_offsets)
    {
        int new_row = (row + offset.first + rows) % rows;
        int new_column = (column + offset.second + columns) % columns;
        if(grid.GetValue(new_row, new_column) == 1)
        {
            liveNeighbors++;
        }
    }
    return liveNeighbors;
}

void Simulation::ClearGrid()
{
    if(!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::Start()
{
    run = true;
}

void Simulation::Stop() 
{
    run = false;
}

void Simulation::CreateRandomState()
{
    if(!IsRunning())
    {
        grid.FillRandom();
    }
}

void Simulation::SetValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

bool Simulation::IsRunning()
{
    return run;
}

void Simulation::ToggleCell(int row, int column)
{
    if(!IsRunning())
    {
        grid.ToggleCell(row, column);
    }
}
