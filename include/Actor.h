#pragma once

#include "graphics/GLGraphics3.h"
#include "math/Matrix4x4.h"
#include "Shape3.h"
#include "graphics/Material.h"
#include "geometry/Ray.h"

#include <memory>

class Actor {

public:

    cg::vec3f position{0, 0, 0};
    cg::quatf rotation{};
    cg::vec3f scale{1, 1, 1};

    virtual ~Actor() = default;

    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render(cg::GLGraphics3& g3) {}

    cg::Material material{cg::Color::white};

    Intersection intersect(cg::Ray3f& ray) {
        
        if (!shape)
            return {}; 

        auto hit = shape->intersect(ray, transform);

        if (hit.distance > 0) {

            hit.actor = this; 

            return hit;       

        }

        return {};

    }

protected:

    std::unique_ptr<Shape3> shape;

    cg::mat4f transform;

    void updateTransform() {

        transform = cg::mat4f::TRS(position, rotation, scale);

    }

};