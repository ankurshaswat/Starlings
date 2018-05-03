#ifndef __flock_h__
#define __flock_h__


#include "bird.h"
#include <glm/glm.hpp>
#include <vector>

using namespace glm;

class Flock
{
public:
	Flock();
	void add(Bird *b);
	void update(double dt, float separation, float alignment, float cohesion, float target , bool target_present );
	void updateTargets();

	double getRand();
	double getAveragePower();
	std::vector<Bird*> mBirds;

};

#endif // __flock_h__
