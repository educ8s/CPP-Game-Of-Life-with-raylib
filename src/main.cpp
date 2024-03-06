#include <raylib.h>
#include <iostream>
#include "simulation.h"

int main()
{
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    const Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    SetTargetFPS(12);

    // Simulation loop
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_ENTER)) 
        {
            simulation.Start();
            SetWindowTitle("Game of Life is running ...");
        }
        else if(IsKeyPressed(KEY_SPACE)) 
        {
            simulation.Stop();
            SetWindowTitle("Game of Life has stopped.");
        } else if(IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        } else if(IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
          Vector2 mousePosition = GetMousePosition();
          int row = mousePosition.y / CELL_SIZE;
          int column = mousePosition.x / CELL_SIZE;
          simulation.ToggleCell(row, column);
        }

        simulation.Update();
        
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}