#pragma once

#include<string>
#include "Components.h"


class Entity {

	friend class EntityManager;

	std::string tag;

	bool active = true;

	size_t id;


	Entity(const size_t id, const std::string& tag);
public:
	CTransform* cTransform;
	CShape* cShape;
	CCollision* cCollision;
	CInput* cInput;
	CScore* cScore;
	CLifespan* cLifespan;

	//Private Member access function here 

	bool isActive() const;

	const std::string& tag()const;
	const size_t id()const;

	void destroy();



};
