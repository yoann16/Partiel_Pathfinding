#include "AStartRender.h"

#include <iostream>

void AStartRender::RenderGridWithPath(const Grid& _Grid, const std::vector<PathNode>& Path) {
    for (int X = 0; X < _Grid.SizeX; ++X) {
        std::cout << "|";
        for (int Y = 0; Y < _Grid.SizeY; ++Y) {
            int Index = X * _Grid.SizeY + Y;
            if (_Grid[Index].NodeState == ENodeState::ENS_Walkable) {
                auto It = std::find_if(Path.begin(), Path.end(), [&, X, Y](const PathNode& Node) {
                    return Node.X() == X && Node.Y() == Y;
                });
                if (It != Path.end()) {
                    std::cout << "| \033[34m*\033[0m |";
                }
                else {
                    std::cout << "| * |";
                }
            }
            else {
                std::cout << "| \033[31m-\033[0m |";
            }
        }
        std::cout << "|\n";
    }
}
