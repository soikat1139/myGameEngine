
#include"Entity.h"
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>




typedef std::vector<Entity*> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;


bool isActive(Entity* e) {


	return !e->active;
};

bool (*ptr)(Entity*)=&isActive;
    



class EntityManger {

	EntityVec entities;

	EntityVec entitiesToAdd;

	size_t totalEntites = 0;

	EntityMap entitymap;


public:
	EntityManger() {

	}

	void update() {

		//remove vector of dead entities:

		for (auto& e : entitiesToAdd) {
			entities.push_back(e);
			entitymap[e->tags].push_back(e);

		}

		removeDeadEntities(entities);
		entitiesToAdd.clear();

		for (auto& pair:entitymap) {
			
			removeDeadEntities(pair.second);

		}


	

	}

	void removeDeadEntities(EntityVec & vec) {

		//Remove all the dead entities from the vector 

		auto toRemove = std::remove_if(vec.begin(), vec.end(), ptr);

		vec.erase(toRemove,vec.end());
	


	




	}

	Entity* addEntity(const std::string & tag) {

		Entity* entity = new Entity(totalEntites++, tag);

		//entities.push_back(entity);
		entitiesToAdd.push_back(entity);
		return entity;
	}

	const EntityVec& getEntities() {
		return entities;
	}

	 EntityVec& getEntities(const std::string& tag) {

		 return entitymap[tag];


	}

	







};
