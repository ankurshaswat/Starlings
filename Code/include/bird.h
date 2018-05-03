#ifndef __bird_h__
#define __bird_h__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include<vector>
#include<set>

//Weights for behaviour
#define SEPARATION_WEIGHT 0.003
#define ALIGMENT_WEIGHT .7
#define COHESION_WEIGHT .3
#define TARGET_WEIGHT .3

//radii for neighbours
#define NEIGHBOUR_RADIUS 30.8
#define DESIRED_SEPARATION 0.3

#define MAX_SPEED 0.002

class Bird
{
public:

	Bird();
	void update(double dt, glm::vec3 velocity);

	glm::vec3 getPosition();
	glm::vec3 getForward();
	glm::vec3 getVelocity();


	void addVelocity();

	glm::vec3 separate();
	glm::vec3 aligment();
	glm::vec3 cohesion();
	glm::vec3 followTarget();

	struct compare {
        bool operator()(Bird* a, Bird* b) {
		  glm::vec3 apos=a->getPosition(), bpos=b->getPosition();	
          return glm::all(glm::lessThan(apos, bpos));        }   
    };
	
	std::set<Bird*,compare> neighbours;
	
    double getRand(); //simple utility function 

	glm::vec3 mTarget;

	

private:
    glm::vec3 mPosition;
	glm::vec3 mVelocity;
};
#endif // __bird_h__