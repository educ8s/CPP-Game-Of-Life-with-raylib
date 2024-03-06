#include "grid.h"

class Simulation 
{
public:
    Simulation(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), grid(width, height, cellSize), temp_grid(width, height, cellSize), run(false) {};
    void Draw();
    void Update();
    int CountLiveNeighbors(int row, int column);
    void ClearGrid();
    void Start();
    void Stop();
    void CreateRandomState();
    void SetValue(int row, int column, int value);
    bool IsRunning();
    void ToggleCell(int row, int column);
    
private:
    int rows;
    int columns;
    Grid grid;
    Grid temp_grid;
    bool run;
};