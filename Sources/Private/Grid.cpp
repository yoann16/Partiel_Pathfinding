#include "Grid.h"
#include <ctime>

Grid::Grid(int _SizeX, int _SizeY) : SizeX(_SizeX), SizeY(_SizeY){
    InternGrid.reserve(SizeX * SizeY);
    for (int X = 0; X < SizeX; ++X) {
        for (int Y = 0; Y < SizeY; ++Y) {
            InternGrid.push_back({X, Y, ENodeState::ENS_Walkable});
        }
    }
}

Node& Grid::operator[](int Index) {
    return InternGrid[Index];
}

const Node& Grid::operator[](int Index) const {
    return InternGrid[Index];
}

void Grid::SetNodeState(const Coord& NodeCoord, ENodeState NewState) {
    InternGrid[NodeCoordToIndex(NodeCoord)].NodeState = NewState;
}

int Grid::NodeCoordToIndex(const Coord& NodeCoord) {
    return NodeCoord.X * SizeY + NodeCoord.Y;
}

Coord Grid::NodeIndexToCoord(int NodeIndex) {
    return {NodeIndex / SizeY, NodeIndex % SizeY};
}

Grid* GridUtils::GenerateBasicGrid(int SizeX, int SizeY) {
    return new Grid(SizeX, SizeY);
}

Grid* GridUtils::GenerateGridWithObstacles(int SizeX, int SizeY, int NbrObstacles) {
    srand(SizeX * SizeY / (NbrObstacles + 1) * (unsigned)time(nullptr));
    Grid* _Grid = new Grid(SizeX, SizeY);
    //Retourne dans le solver Arthur au lieu de regarder mon code
    for (int INDEX = 0; INDEX < NbrObstacles; ++INDEX) {
        int LSizeX = 1 + rand() % (SizeX - 2);
        int LSizeY = 1 + rand() % (SizeY - 2);
        if (LSizeX >= 0 && LSizeY >= 0) {
            //TODO
            
            //for (int X = )
        }
    }
    return _Grid;
}
