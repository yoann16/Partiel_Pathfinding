#include "AStarSolver.h"
#include <algorithm>
#include "../Private/Grid.h"

std::vector<PathNode> AStarSolver::SolveGrid(const Grid& _Grid, Coord Start, Coord Target) {
    std::vector<PathNode> ResultPath = {};
    auto Distance_Manhattan = abs(Target.X - Start.X) + abs(Target.Y - Start.Y);
    for (int i = 0; i < _Grid.SizeX*_Grid.SizeY; ++i)
    {
        if (_Grid[i].IsNeighbor(_Grid[i+1]))
        {
            if (_Grid[i+1].IsValid() && _Grid[i + 1].NodeState== ENS_Walkable)
            {
                ResultPath.push_back(_Grid[i]);
                if (_Grid[i + 1].X() == Target.X && _Grid[i + 1].Y() == Target.Y)
                {
                    i = i + 1;
                    ResultPath.push_back(_Grid[i]);
                    break;
                }
                
            }
            if (_Grid[i+1].NodeState == ENS_NONE)
            {
                break;
            }
            if (_Grid[i+1].NodeState == ENS_Obstacle)
            {
                i = +2;
            }
        }
    }
    return ResultPath;
}
