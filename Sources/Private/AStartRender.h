#pragma once
#include "Grid.h"

class AStartRender {
public:
    static void RenderGridWithPath(const Grid& _Grid, const std::vector<PathNode>& Path);
};
