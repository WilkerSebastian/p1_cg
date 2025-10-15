#pragma once

#include "graphics/GLGraphics3.h"
#include "math/Vector3.h"
#include "math/Quaternion.h"

class Actor {

public:

    cg::vec3f position{0, 0, 0};
    cg::quatf rotation{};
    cg::vec3f scale{1, 1, 1};

    virtual ~Actor() = default;

    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render(cg::GLGraphics3& g3) {}
    
};