#pragma once

#include "graphics/GLGraphics3.h"
#include "math/Matrix4x4.h"

class Actor {

public:

    cg::vec3f position{0, 0, 0};
    cg::quatf rotation{};
    cg::vec3f scale{1, 1, 1};

    virtual ~Actor() = default;

    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render(cg::GLGraphics3& g3) {}

protected:

    cg::mat4f transform;

    void updateTransform() {

        transform = transform.TRS(position, rotation, scale);

    }

};