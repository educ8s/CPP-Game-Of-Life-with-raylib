#pragma once
#include "grid.hpp"

class Simulation {

public:
    Simulation(int width, int height, int cellSize)
    : grid(width, height, cellSize), temp_grid(width, height, cellSize), run(false) {grid.FillRandom();};
    void Update();
    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    bool IsRunning() {return run;}
    void Start() {run = true;}
    void Stop() {run = false;}
    void ClearGrid();
    void CreateRandomState();
private:
    Grid grid;
    Grid temp_grid;
    bool run;
};