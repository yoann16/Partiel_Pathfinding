#pragma once
#include <vector>

#include "Node.h"


class Grid {
public:
    Grid() = default;
    Grid(int _SizeX, int _SizeY); 

    Node& operator[](int Index);
    const Node& operator[](int Index) const;

    void SetNodeState(const Coord& NodeCoord, ENodeState NewState);
private:
    int NodeCoordToIndex(const Coord& NodeCoord);
    Coord NodeIndexToCoord(int NodeIndex);
public:
    int SizeX;
    int SizeY;
private:
    std::vector<Node> InternGrid;
};


class GridUtils {
public:
    static Grid* GenerateBasicGrid(int SizeX, int SizeY); 
    static Grid* GenerateGridWithObstacles(int SizeX, int SizeY, int NbrObstacles); 
};