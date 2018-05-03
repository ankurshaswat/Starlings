#include "bird.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include<iostream>

double Bird::getRand(){
    return ((double) rand() / (RAND_MAX));
}

Bird::Bird()
{
	//Calculate random velocity
	mVelocity = glm::vec3((getRand())*MAX_SPEED,(getRand())*MAX_SPEED,(getRand())*MAX_SPEED);
	addVelocity();

    //Initialize random position
	mPosition.x = -5.0f + 2*5.0f*getRand();
	mPosition.y = -5.0f + 2*5.0f*getRand();
	mPosition.z = -5.0f + 2*5.0f*getRand();
	

}

void Bird::update(double dt, glm::vec3 velocity)
{
	mVelocity += velocity;
	if(glm::length(mVelocity) > MAX_SPEED)
	{
		mVelocity = glm::normalize(mVelocity)*(float)MAX_SPEED;
	}
	addVelocity();
	glm::vec3 pos = getPosition();
	if(pos.y > 5.0f)
	{
		pos.y = -5.0f;
	}
	else if(pos.y < -5.0f)
	{
		pos.y = 5.0f;
	}
	if(pos.x > 5.0f)
	{
		pos.x = -5.0f;
	}
	else if(pos.x < -5.0f)
	{
		pos.x = 5.0f;
	}

    if(pos.z > 5.0f)
	{
		pos.z = -5.0f;
	}
	else if(pos.z < -5.0f)
	{
		pos.z = 5.0f;
	}

	mPosition.x = pos.x;
	mPosition.y = pos.y;
    mPosition.z=pos.z;

}

glm::vec3 Bird::getPosition()
{
	return glm::vec3(mPosition.x, mPosition.y,mPosition.z);
}

// glm::vec2 Bird::getForward()
// {
// 	glm::mat4 matrix = mShape->getModelMatrix();
// 	return glm::vec2(matrix[1].x, matrix[1].y);
// }

void Bird::addVelocity()
{
	//rotate bird to face velocity (add later, currently no orientation)
	if(glm::length(mVelocity) >0)
	{
		
        //add velocity to position
		// std::cout<<"BEFORE-"<<mPosition.x<<" "<<mPosition.y<<" "<<mPosition.z<<std::endl;
        mPosition= glm::vec3(mPosition+mVelocity);
		// std::cout<<"AFTER-"<<mPosition.x<<" "<<mPosition.y<<" "<<mPosition.z<<std::endl;
	}



}



glm::vec3 Bird::cohesion()
{
	int count = 0;
	glm::vec3 myPos = getPosition();
	glm::vec3 sum = myPos;
	std::set<Bird*>::iterator iter;
	for(iter=neighbours.begin(); iter!=neighbours.end(); iter++)
	{
		sum += (*iter)->getPosition();
		count ++;
	}

	if(count > 0)
	{
		sum /= (float)count;
		glm::vec3 desired = sum-myPos;

		float d = glm::length(desired);
		if(d > 0.0f)
		{
			desired /= d;
			if(d < 0.3f)
			{
				desired *=(float)MAX_SPEED*(d/0.3f);

			}
			else
			{
				desired *=(float)MAX_SPEED;
			}
			return desired-mVelocity;
		}
		else
		{
			return glm::vec3(0,0,0);
		}
	}
	else
	{
		return glm::vec3(0,0,0);
	}
}

glm::vec3 Bird::followTarget()
{
	int count = 0;
		glm::vec3 myPos = getPosition();
		glm::vec3 desired = mTarget-myPos;

		float d = glm::length(desired);
		if(d > 0.0f)
		{
			desired /= d;
			if(d < 0.3f)
			{
				desired *=(float)MAX_SPEED*(d/0.3f);

			}
			else
			{
				desired *=(float)MAX_SPEED;
			}
			return desired-mVelocity;
		}
		else
		{
			return glm::vec3(0,0,0);
		}
	
}



glm::vec3 Bird::aligment()
{
	glm::vec3 mean(0,0,0);
	int count = 0;

	std::set<Bird*>::iterator iter;
	for(iter=neighbours.begin(); iter!=neighbours.end(); iter++)
	{
		mean += (*iter)->getVelocity();
		count ++;
	}
	if(count)
	{
		mean /= (float)count;
	}

	return mean;
}

glm::vec3 Bird::separate()
{
	glm::vec3 mean(0,0,0);
	glm::vec3 myPos = getPosition();

	int count = 0;

	std::set<Bird*>::iterator iter;
	for(iter=neighbours.begin(); iter!=neighbours.end(); iter++)
	{
		glm::vec3 neighbourPos = (*iter)->getPosition();
		glm::vec3 distance = myPos-neighbourPos;
		if(glm::length(distance) < DESIRED_SEPARATION)
		{
			mean += distance/glm::length(distance);
			count ++;
		}
	}

	if(count)
	{
		mean /= (float)count;
	}
	return mean;
}

glm::vec3 Bird::getVelocity()
{
	return mVelocity;
}
