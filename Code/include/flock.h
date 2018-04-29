#ifndef __flock_h__
#define __flock_h__


#include "bird.h"
#include <glm/glm.hpp>
#include <vector>
#include "engineUtils.h"

using namespace glm;

class Flock
{
public:
	Flock();
	void add(Bird *b);
	void update(double dt);

	std::vector<Bird*> mBirds;

};

#endif // __flock_h__
