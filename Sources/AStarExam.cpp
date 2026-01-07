#include <iostream>

#include "Private/AStartRender.h"
#include "Public/AStarSolver.h"
#include "Private/Grid.h"

int main(int argc, char* argv[]){

    Grid* _Grid = GridUtils::GenerateBasicGrid(10, 20);
    auto ResultPathIt1 = AStarSolver::SolveGrid(*_Grid, {0,0}, {8,12});
    AStartRender::RenderGridWithPath(*_Grid, ResultPathIt1);
    delete _Grid;

    std::cout << "-----------------------------------------------------------\n";
    
    _Grid = GridUtils::GenerateGridWithObstacles(10, 20, 1);
    auto ResultPathIt2 = AStarSolver::SolveGrid(*_Grid, {0, 0}, {8, 16});
    AStartRender::RenderGridWithPath(*_Grid, ResultPathIt2);
    delete _Grid;

    _Grid = nullptr;
    
    return EXIT_SUCCESS;
}
