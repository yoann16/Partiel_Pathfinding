#pragma once
#include "limits.h"

#define INVALID_NODE_WEIGHT -1.0f
#define INVALID_NODE Node(-1, -1, ENodeState::ENS_NONE)
#define INVALID_PATHNODE PathNode(INVALID_NODE, INT_MAX, INT_MAX, nullptr)

enum ENodeState {
    ENS_Walkable = 0,
    ENS_Obstacle = 1,
    
    ENS_NONE = 2,
};

class Coord {
public:
    Coord() = default;
    Coord(int _X, int _Y);

    bool operator==(const Coord& Other) const;
    bool operator!=(const Coord& Other) const;
    
public:
    int X;
    int Y;
};

class Node {
public:
    Node() = default;
    Node(int _X, int _Y, ENodeState _NodeState);

    int X() const;
    int Y() const;

    bool operator==(const Node& Other) const;
    bool operator!=(const Node& Other) const;

    bool IsNeighbor(const Node& Other) const;
    bool IsValid() const;
private:
    Coord NodeCoord;
public:
    ENodeState NodeState;

};

class PathNode : public Node{
public:
    PathNode() = default;
    PathNode(const Node& _Node);
    PathNode(const Node& _Node, float _GWeight, float _HWeight, int _ParentIndex);

    bool operator==(const Coord& Other) const;
    bool operator!=(const Coord& Other) const;
    
    bool operator==(const PathNode& Other) const;
    bool operator!=(const PathNode& Other) const;

    bool operator<(const PathNode& Other) const;
    bool operator>(const PathNode& Other) const;

    float GetFWeight() const;
public:
    float GWeight;
    float HWeight;
    int ParentIndex;
};


class NodeUtils {
public:
    static float Distance(const Node& _NodeA, const Node& _NodeB);
    static float Distance(const Coord& _CoordA, const Coord& _CoordB);
    static float Distance(const Node& _NodeA, const Coord& _CoordB);
    static float Distance(const Coord& _CoordA, const Node& _NodeB);
    
};
