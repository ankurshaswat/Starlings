#ifndef __engine2D_h__
#define __engine2D_h__
/********************************************************************
* @file engine2D.h
* @author Erik Larsson
* @version 1.0
* @section DESCRIPTION
*  flocking demo engine class
*********************************************************************/
#include "engineUtils.h"
#include "glm/glm.hpp"
#include "shape.h"
#include "bufferObject.h"


class Engine2D
{
public:
	Engine2D();

	bool init(GLFWwindow *window);
	void destroy();

	void update(double dt);
	void render(double dt);
	GLFWwindow *getWindow();
	void add(Shape *s);
	void setView(glm::mat4 view);
	void setCamera(glm::vec3 camera);

	void bindBuffers();
	void deleteBuffers();

private:
	char titlestring[64];
	glm::mat4 mViewMatrix;
	GLFWwindow *mWindow;
	std::vector<Shape*> mShapes;
	std::vector<BufferObject* > mBuffers;

	GLuint mProgramID;
	GLuint mModelMatrixID;
	GLuint mVertexColorID;
};
#endif // __engine2D_h__
