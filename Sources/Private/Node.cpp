#include "Node.h"

#include <cmath>

Coord::Coord(int _X, int _Y) : X(_X), Y(_Y){
}

bool Coord::operator==(const Coord& Other) const{
    return Other.X == X && Other.Y == Y;
}

bool Coord::operator!=(const Coord& Other) const{
    return !(*this == Other); 
}

Node::Node(int _X, int _Y, ENodeState _NodeState) : NodeCoord(_X, _Y), NodeState(_NodeState){
}

int Node::X() const {
    return NodeCoord.X;
}

int Node::Y() const {
    return NodeCoord.Y;
}

bool Node::operator==(const Node& Other) const{
    return Other.X() == X() && Other.Y() == Y();
}

bool Node::operator!=(const Node& Other) const{
    return !(*this == Other);
}

bool Node::IsNeighbor(const Node& Other) const{
    return X() - Other.X() == 1 || X() - Other.X() == -1 || Y() - Other.Y() == 1 || Y() - Other.Y() == -1;
}

bool Node::IsValid() const {
    return !(*this == INVALID_NODE);
}

PathNode::PathNode(const Node& _Node) : PathNode(_Node, INVALID_NODE_WEIGHT, INVALID_NODE_WEIGHT, -1){
}

PathNode::PathNode(const Node& _Node, float _GWeight, float _HWeight, int _ParentIndex) : Node(_Node), GWeight(_GWeight), HWeight(_HWeight), ParentIndex(_ParentIndex){
}

bool PathNode::operator==(const Coord& Other) const{
    return Other.X == X() && Other.Y == Y();
}

bool PathNode::operator!=(const Coord& Other) const{
    return !(*this == Other);
}

bool PathNode::operator==(const PathNode& Other) const{
    return Other.X() == X() && Other.Y() == Y();
}

bool PathNode::operator!=(const PathNode& Other) const{
    return !(*this == Other);
}

bool PathNode::operator<(const PathNode& Other) const{
    return GetFWeight() < Other.GetFWeight();
}

bool PathNode::operator>(const PathNode& Other) const{
    return GetFWeight() > Other.GetFWeight();
}

float PathNode::GetFWeight() const {
    return GWeight + HWeight;
}

float NodeUtils::Distance(const Node& _NodeA, const Node& _NodeB) {
    return std::sqrt(std::powf(static_cast<float>(_NodeB.X() - _NodeA.X()), 2.0f) + std::powf(static_cast<float>(_NodeB.Y() - _NodeA.Y()), 2.0f));
}

float NodeUtils::Distance(const Coord& _CoordA, const Coord& _CoordB) {
    return std::sqrt(std::powf(static_cast<float>(_CoordA.X - _CoordB.X), 2.0f) + std::powf(static_cast<float>(_CoordA.Y - _CoordB.Y), 2.0f));
}

float NodeUtils::Distance(const Node& _NodeA, const Coord& _CoordB) {
    return std::sqrt(std::powf(static_cast<float>(_CoordB.X - _NodeA.X()), 2.0f) + std::powf(static_cast<float>(_CoordB.Y - _NodeA.Y()), 2.0f));
}

float NodeUtils::Distance(const Coord& _CoordA, const Node& _NodeB) {
    return std::sqrt(std::powf(static_cast<float>(_NodeB.X() - _CoordA.X), 2.0f) + std::powf(static_cast<float>(_NodeB.Y() - _CoordA.Y), 2.0f));
}
