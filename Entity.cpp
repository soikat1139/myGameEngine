
#include"Entity.h"


Entity::Entity(const size_t id, const std::string & tag):ids(id),tags(tag){
}


bool Entity::isActive() const {

	return active;

};

const std::string& Entity::tag()const {

	return tags;


};

const size_t Entity::id()const {
	return ids;

};

void Entity::destroy() {

};
