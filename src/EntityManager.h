#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "./Entity.h"
#include "./Component.h"
#include <vector>

class EntityManager {
    private:
        std::vector<Entity*> entities;
    public:
        void Update(float deltaTime);
        void ClearData();
        void Render();
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
};

#endif