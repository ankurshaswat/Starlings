#include "flock.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include<iostream>

Flock::Flock()
{

}

double Flock::getRand(){
    return ((double) rand() / (RAND_MAX));
}

void Flock::add(Bird *b)
{
	mBirds.push_back(b);
}

void Flock::updateTargets()
{
	glm::vec3 newTarget= glm::vec3 (5.0f * getRand(), 5.0f * getRand(), 5.0f * getRand()  );
	for (auto it: mBirds){
		(*it).mTarget=newTarget + glm::vec3 (2.0f * getRand(), 2.0f * getRand(), 2.0f * getRand()  );
	}
}

void Flock::update(double dt)
{
	
	std::vector<Bird*>::iterator iter;
	for(iter=mBirds.begin(); iter!=mBirds.end(); iter++)
	{
		std::vector<Bird*> neighbours;
		std::vector<Bird*>::iterator second;
		for(second=mBirds.begin(); second!=mBirds.end(); second++)
		{
			vec3 dist = glm::vec3((*iter)->getPosition()-(*second)->getPosition());
			float distance = glm::length(dist);
			if( distance < NEIGHBOUR_RADIUS && distance > 0)
			{
				neighbours.push_back((*second));
			}
		}
		glm::vec3 temp= (*iter)->getPosition();
		// std::cout<<"BEFORE EVERYTHING-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
		vec3 velocity = (*iter)->separate(neighbours)*(float)SEPARATION_WEIGHT; 
		velocity += (*iter)->aligment(neighbours)*(float)ALIGMENT_WEIGHT;
		velocity += (*iter)->cohesion(neighbours)*(float)COHESION_WEIGHT;
		velocity += (*iter)->followTarget()*(float)TARGET_WEIGHT;
		
		
		velocity *= MAX_SPEED;
		temp= (*iter)->getPosition();
		// std::cout<<"BEFORE-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
		(*iter)->update(dt, velocity);
		temp= (*iter)->getPosition();
		// std::cout<<"AFTER-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
	}
	// std::cout<<std::endl;
}
