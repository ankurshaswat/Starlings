#ifndef __bird_h__
#define __bird_h__

#include "shape.h"

//Weights for behaviour
#define SEPARATION_WEIGHT 0.003
#define ALIGMENT_WEIGHT .7
#define COHESION_WEIGHT .3

//radii for neighbours
#define NEIGHBOUR_RADIUS .8
#define DESIRED_SEPARATION 0.3

#define MAX_SPEED 0.002

class Bird
{
public:

	Bird(glm:vec3 position);
	void update(double dt, glm::vec3 velocity);

	glm::vec3 getPosition();
	glm::vec3 getForward();
	glm::vec3 getVelocity();

	void addVelocity();

	glm::vec3 separate(std::vector<Bird*> neighbours);
	glm::vec3 aligment(std::vector<Bird*> neighbours);
	glm::vec3 cohesion(std::vector<Bird*> neighbours);

private:
    glm:vec3 mPosition;
	glm::vec3 mVelocity;
};
#endif // __bird_h__