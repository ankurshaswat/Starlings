#include "flock.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "Octree.h"
#include<iostream>





Flock::Flock()
{
};

void Flock::createOctree(){
	//Minimum coordinates
	float min[3] = {-15.0f, -15.0f, -15.0f};
    // Maximum coordinates.
    float max[3] = {15.0f , 15.0f  , 15.0f };
    // Minimum size to use when subdividing cells.
    float cellSize[3] = {0.1f, 0.1f, 0.1f};
	octree=new Octree<Node>(min,max,cellSize);
}

double Flock::getAveragePower(){
	double Power = 0;
	for (auto it: mBirds){
		Power+=(*it).getPower();
	}

	return (Power/(mBirds.size()));
}

double Flock::getRand(){
    return ( ((double) rand() / (RAND_MAX)) * 2 ) -1;
}

void Flock::add(Bird *b)
{
	glm::vec3 pos= b->getPosition();
	const float param[3]={pos.x,pos.y,pos.z};
	// std::cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<std::endl;
	Node& n = octree->getCell(param);
	n.birds.push_back(b);

	mBirds.push_back(b);
}

void Flock::updateTargets()
{
	glm::vec3 newTarget= glm::vec3 (3.0f * getRand(), 3.0f * getRand(), 3.0f * getRand()  );
	for (auto it: mBirds){
		(*it).mTarget=newTarget + glm::vec3 (2.0f * getRand(), 2.0f * getRand(), 2.0f * getRand()  );
	}
}

void Flock::updateNeighbours()
{

	std::vector<Bird*>::iterator iter;
	for(iter=mBirds.begin(); iter!=mBirds.end(); iter++)
	{
		std::vector<Bird*>::iterator second;
		for(second=mBirds.begin(); second!=mBirds.end(); second++)
		{
			vec3 dist = glm::vec3((*iter)->getPosition()-(*second)->getPosition());
			float distance = glm::length(dist);
			if( distance < NEIGHBOUR_RADIUS && distance > 0)
			{
				(*iter)->neighbours.insert((*second));
			}
			else{
				(*iter)->neighbours.erase((*second));
			}

		}
	}

}

void Flock::update(double dt, float separation_wt, float alignment_wt, float cohesion_wt, float target_wt , bool target_present)
{
	
	std::vector<Bird*>::iterator iter;
	for(iter=mBirds.begin(); iter!=mBirds.end(); iter++)
	{
		
		// std::vector<Bird*>::iterator second;
		// for(second=mBirds.begin(); second!=mBirds.end(); second++)
		// {
		// 	vec3 dist = glm::vec3((*iter)->getPosition()-(*second)->getPosition());
		// 	float distance = glm::length(dist);
		// 	if( distance < NEIGHBOUR_RADIUS && distance > 0)
		// 	{
		// 		neighbours.push_back((*second));
		// 	}
		// }
		glm::vec3 temp= (*iter)->getPosition();
		// std::cout<<"BEFORE EVERYTHING-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
		vec3 velocity = (*iter)->separate()*separation_wt; 
		velocity += (*iter)->aligment()*alignment_wt;
		velocity += (*iter)->cohesion()*cohesion_wt;
		if(target_present) velocity += (*iter)->followTarget()*target_wt;
		
		
		velocity *= MAX_SPEED;
		temp= (*iter)->getPosition();
		// std::cout<<"BEFORE-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
		(*iter)->update(dt, velocity);
		temp= (*iter)->getPosition();
		// std::cout<<"AFTER-"<<temp.x<<" "<<temp.y<<" "<<temp.z<<std::endl;
	}
	// std::cout<<std::endl;
}
