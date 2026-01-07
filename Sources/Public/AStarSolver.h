#pragma once
#include <vector>
#include "../Private/Node.h"

class Grid;

class AStarSolver {
public:
    static std::vector<PathNode> SolveGrid(const Grid& _Grid, Coord Start, Coord Target);
};
