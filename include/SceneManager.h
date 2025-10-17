#pragma once

#include "Scene.h"
#include <string>
#include <map>
#include <memory> 

class SceneManager {

private:

    std::map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* activeScene = nullptr;

public:

    template<typename... Actors>
    void createScene(const std::string& name, Actors*... actorList) {

        auto newScene = std::make_unique<Scene>(name, actorList...);

        Scene* sceneP = newScene.get();

        scenes[name] = std::move(newScene);

    }

    void addLight(const std::string& name, cg::vec3f position, cg::Color) {

        auto it = scenes.find(name);

        if (it != scenes.end()) {

            cg::Light light;

            light.setPosition(position);
            light.color = cg::Color::white;

            it->second.get()->addLight(light);

        }


    }

    void setActiveScene(const std::string& name) {

        auto it = scenes.find(name);

        if (it != scenes.end()) {

            activeScene = it->second.get();

            activeScene->start();

        }

        else 
            puts("não foi achado a cena");
        
    }

    Scene* getActiveScene() {
        return activeScene;
    }

    void update(float deltaTime) {

        if (activeScene) 
            activeScene->update(deltaTime);

    }

    void render(cg::GLGraphics3& g3) {

        if (activeScene) 
            activeScene->render(g3);
    
    }

};