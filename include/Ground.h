#pragma once

#include "Actor.h"
#include "PlaneShape.h" 

class Ground : public Actor {

public:

    void start() override {
        
        shape = std::make_unique<PlaneShape>();

        material.diffuse = cg::Color::green; 
        material.specular = cg::Color::blue;
        material.shine = 64.0f;

        position.set(3, 4.5, -3); 

        scale.set(50, -1, 50);

        updateTransform();

    }

    Intersection intersect(cg::Ray3f& ray) override {

        if (!shape)
            return {}; 

        auto hit = shape->intersect(ray, transform);

        if (hit.distance > 0) {

            hit.actor = this; 

            return hit;       
            
        }

        return {};

    }
};