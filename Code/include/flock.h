#ifndef __flock_h__
#define __flock_h__


#include "bird.h"
#include "Octree.h"

#include <glm/glm.hpp>
#include <vector>

#define EPSILON 0.0001f


using namespace glm;



struct Node
{
    std::vector<Bird*> birds;
};

class Flock
{
public:
	Flock();
	void add(Bird *b);
	void update(double dt, float separation, float alignment, float cohesion, float target , bool target_present );
	void updateTargets();
	void createOctree();
	void updateNeighbours();

	double getRand();
	double getAveragePower();
	std::vector<Bird*> mBirds;

    Octree<Node>* octree;
	
};

#endif // __flock_h__
