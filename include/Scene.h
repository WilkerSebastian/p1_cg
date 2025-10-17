#pragma once

#include "Actor.h"
#include <string>
#include <vector>
#include <memory>

class Scene {

public:

    std::string name;

private:

    std::vector<std::unique_ptr<Actor>> actors;

    void addActors() {}

    template<typename T, typename... Rest>
    void addActors(T* first, Rest*... rest) {

        actors.push_back(std::unique_ptr<Actor>(first));

        addActors(rest...);

    }

public:

    template<typename... Actor>
    Scene(const std::string& name, Actor*... actorList) : name(name) {

        addActors(actorList...);
        
    }

    void start() {

        for (auto& actor : actors) 
            actor->start();
        
    }

    void update(float deltaTime) {

        for (auto& actor : actors) 
            actor->update(deltaTime);
        
    }

    void render(cg::GLGraphics3& g3) {

        for (auto& actor : actors) 
            actor->render(g3);
        
    }

};