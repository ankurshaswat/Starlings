// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
// #include <conio>
using namespace std;

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace glm;

#include <GL/glut.h>

#include <shader.hpp>
#include <texture.hpp>
#include<flock.h>
#include<bird.h>
#include<simulTimer.h>
#include <objloader.hpp>
#include <math.h>
#include "glm/gtx/string_cast.hpp"
// #include <common/controls.hpp>

#define PI 3.14f
#define FLOCK_SIZE 50


GLuint programID,MatrixID,ViewMatrixID,ModelMatrixID;
std::vector<glm::vec3> vertices;
glm::mat4 ViewMatrix,ProjectionMatrix,MVP,ModelMatrix,ScalingMatrix,TranslationMatrix,RotationMatrix;

void renderBoid(vec3 pos);

void renderFlock(std::vector<vec3> v);

int main( void )
{

								double x_rot=0,y_rot=0,z_rot=0;
								// Initialise GLFW
								if( !glfwInit() )
								{
																fprintf( stderr, "Failed to initialize GLFW\n" );
																getchar();
																return -1;
								}

								glfwWindowHint(GLFW_SAMPLES, 4);
								glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
								glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
								glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
								glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

								// Open a window and create its OpenGL context
								window = glfwCreateWindow( 1024, 768, "Tutorial 04 - Colored Cube", NULL, NULL);
								if( window == NULL ) {
																fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
																getchar();
																glfwTerminate();
																return -1;
								}
								glfwMakeContextCurrent(window);

								// Initialize GLEW
								glewExperimental = true; // Needed for core profile
								if (glewInit() != GLEW_OK) {
																fprintf(stderr, "Failed to initialize GLEW\n");
																getchar();
																glfwTerminate();
																return -1;
								}

								// Ensure we can capture the escape key being pressed below
								glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

								// Dark blue background
								glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

								// Enable depth test
								glEnable(GL_DEPTH_TEST);
								// Accept fragment if it closer to the camera than the former one
								glDepthFunc(GL_LESS);

								GLuint VertexArrayID;
								glGenVertexArrays(1, &VertexArrayID);
								glBindVertexArray(VertexArrayID);

								// Create and compile our GLSL program from the shaders
								programID = LoadShaders( "TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader" );

								// Get a handle for our "MVP" uniform
								MatrixID = glGetUniformLocation(programID, "MVP");
								ViewMatrixID = glGetUniformLocation(programID, "V");
								ModelMatrixID = glGetUniformLocation(programID, "M");

								// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
								glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
								// Camera matrix
								glm::mat4 View       = glm::lookAt(
																glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
																glm::vec3(0,0,0), // and looks at the origin
																glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
																);
								// Model matrix : an identity matrix (model will be at the origin)
								glm::mat4 Model      = glm::mat4(1.0f);
								// Our ModelViewProjection : multiplication of our 3 matrices
								glm::mat4 MVP        = Projection * View * Model;// Remember, matrix multiplication is the other way around

								// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
								// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
								static const GLfloat g_vertex_buffer_data[] = {
																1.0f,0.0f,0.0f,
																-1.0f,0.0f,0.0f,
																0.0f,1.0f,0.0f,
																0.0f,-1.0f,0.0f,
																0.0f,0.0f,1.0f,
																0.0f,0.0f,-1.0f,//axi

																0.0f,1.0f,0.0f,//
																-1.0f,-1.0f,0.0f,//axi
															1.0f,-1.0f,0.0f,//axi

															0.0f,0.0f,-1.0f,//
															-1.0f,-1.0f,0.0f,//axi
														1.0f,-1.0f,0.0f,//axi



																-1.0f,-1.0f,-1.0f,
																-1.0f,-1.0f, 1.0f,
																-1.0f, 1.0f, 1.0f,
																1.0f, 1.0f,-1.0f,
																-1.0f,-1.0f,-1.0f,
																-1.0f, 1.0f,-1.0f,
																1.0f,-1.0f, 1.0f,
																-1.0f,-1.0f,-1.0f,
																1.0f,-1.0f,-1.0f,
																1.0f, 1.0f,-1.0f,
																1.0f,-1.0f,-1.0f,
																-1.0f,-1.0f,-1.0f,
																-1.0f,-1.0f,-1.0f,
																-1.0f, 1.0f, 1.0f,
																-1.0f, 1.0f,-1.0f,
																1.0f,-1.0f, 1.0f,
																-1.0f,-1.0f, 1.0f,
																-1.0f,-1.0f,-1.0f,
																-1.0f, 1.0f, 1.0f,
																-1.0f,-1.0f, 1.0f,
																1.0f,-1.0f, 1.0f,
																1.0f, 1.0f, 1.0f,
																1.0f,-1.0f,-1.0f,
																1.0f, 1.0f,-1.0f,
																1.0f,-1.0f,-1.0f,
																1.0f, 1.0f, 1.0f,
																1.0f,-1.0f, 1.0f,
																1.0f, 1.0f, 1.0f,
																1.0f, 1.0f,-1.0f,
																-1.0f, 1.0f,-1.0f,
																1.0f, 1.0f, 1.0f,
																-1.0f, 1.0f,-1.0f,
																-1.0f, 1.0f, 1.0f,
																1.0f, 1.0f, 1.0f,
																-1.0f, 1.0f, 1.0f,
																1.0f,-1.0f, 1.0f //cube

								};

								// One color for each vertex. They were generated randomly.
								static const GLfloat g_color_buffer_data[] = {
																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,//axi

																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,
																0.597f,  0.770f,  0.761f,
																0.559f,  0.436f,  0.730f,
																0.359f,  0.583f,  0.152f,
																0.483f,  0.596f,  0.789f,
																0.559f,  0.861f,  0.639f,
																0.195f,  0.548f,  0.859f,
																0.014f,  0.184f,  0.576f,
																0.771f,  0.328f,  0.970f,
																0.406f,  0.615f,  0.116f,
																0.676f,  0.977f,  0.133f,
																0.971f,  0.572f,  0.833f,
																0.140f,  0.616f,  0.489f,
																0.997f,  0.513f,  0.064f,
																0.945f,  0.719f,  0.592f,
																0.543f,  0.021f,  0.978f,
																0.279f,  0.317f,  0.505f,
																0.167f,  0.620f,  0.077f,
																0.347f,  0.857f,  0.137f,
																0.055f,  0.953f,  0.042f,
																0.714f,  0.505f,  0.345f,
																0.783f,  0.290f,  0.734f,
																0.722f,  0.645f,  0.174f,
																0.302f,  0.455f,  0.848f,
																0.225f,  0.587f,  0.040f,
																0.517f,  0.713f,  0.338f,
																0.053f,  0.959f,  0.120f,
																0.393f,  0.621f,  0.362f,

																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,
																0.597f,  0.770f,  0.761f,
																0.559f,  0.436f,  0.730f,
																0.359f,  0.583f,  0.152f,
																0.483f,  0.596f,  0.789f,
																0.559f,  0.861f,  0.639f,
																0.195f,  0.548f,  0.859f,
																0.014f,  0.184f,  0.576f,
																0.771f,  0.328f,  0.970f,
																0.406f,  0.615f,  0.116f,
																0.676f,  0.977f,  0.133f,
																0.971f,  0.572f,  0.833f,
																0.140f,  0.616f,  0.489f,
																0.997f,  0.513f,  0.064f,
																0.945f,  0.719f,  0.592f,
																0.543f,  0.021f,  0.978f,
																0.279f,  0.317f,  0.505f,
																0.167f,  0.620f,  0.077f,
																0.347f,  0.857f,  0.137f,
																0.055f,  0.953f,  0.042f,
																0.714f,  0.505f,  0.345f,
																0.783f,  0.290f,  0.734f,
																0.722f,  0.645f,  0.174f,
																0.302f,  0.455f,  0.848f,
																0.225f,  0.587f,  0.040f,
																0.517f,  0.713f,  0.338f,
																0.053f,  0.959f,  0.120f,
																0.393f,  0.621f,  0.362f,

																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,
																0.597f,  0.770f,  0.761f,
																0.559f,  0.436f,  0.730f,
																0.359f,  0.583f,  0.152f,
																0.483f,  0.596f,  0.789f,
																0.559f,  0.861f,  0.639f,
																0.195f,  0.548f,  0.859f,
																0.014f,  0.184f,  0.576f,
																0.771f,  0.328f,  0.970f,
																0.406f,  0.615f,  0.116f,
																0.676f,  0.977f,  0.133f,
																0.971f,  0.572f,  0.833f,
																0.140f,  0.616f,  0.489f,
																0.997f,  0.513f,  0.064f,
																0.945f,  0.719f,  0.592f,
																0.543f,  0.021f,  0.978f,
																0.279f,  0.317f,  0.505f,
																0.167f,  0.620f,  0.077f,
																0.347f,  0.857f,  0.137f,
																0.055f,  0.953f,  0.042f,
																0.714f,  0.505f,  0.345f,
																0.783f,  0.290f,  0.734f,
																0.722f,  0.645f,  0.174f,
																0.302f,  0.455f,  0.848f,
																0.225f,  0.587f,  0.040f,
																0.517f,  0.713f,  0.338f,
																0.053f,  0.959f,  0.120f,
																0.393f,  0.621f,  0.362f,

																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,
																0.597f,  0.770f,  0.761f,
																0.559f,  0.436f,  0.730f,
																0.359f,  0.583f,  0.152f,
																0.483f,  0.596f,  0.789f,
																0.559f,  0.861f,  0.639f,
																0.195f,  0.548f,  0.859f,
																0.014f,  0.184f,  0.576f,
																0.771f,  0.328f,  0.970f,
																0.406f,  0.615f,  0.116f,
																0.676f,  0.977f,  0.133f,
																0.971f,  0.572f,  0.833f,
																0.140f,  0.616f,  0.489f,
																0.997f,  0.513f,  0.064f,
																0.945f,  0.719f,  0.592f,
																0.543f,  0.021f,  0.978f,
																0.279f,  0.317f,  0.505f,
																0.167f,  0.620f,  0.077f,
																0.347f,  0.857f,  0.137f,
																0.055f,  0.953f,  0.042f,
																0.714f,  0.505f,  0.345f,
																0.783f,  0.290f,  0.734f,
																0.722f,  0.645f,  0.174f,
																0.302f,  0.455f,  0.848f,
																0.225f,  0.587f,  0.040f,
																0.517f,  0.713f,  0.338f,
																0.053f,  0.959f,  0.120f,
																0.393f,  0.621f,  0.362f,

																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f,
																0.597f,  0.770f,  0.761f,
																0.559f,  0.436f,  0.730f,
																0.359f,  0.583f,  0.152f,
																0.483f,  0.596f,  0.789f,
																0.559f,  0.861f,  0.639f,
																0.195f,  0.548f,  0.859f,
																0.014f,  0.184f,  0.576f,
																0.771f,  0.328f,  0.970f,
																0.406f,  0.615f,  0.116f,
																0.676f,  0.977f,  0.133f,
																0.971f,  0.572f,  0.833f,
																0.140f,  0.616f,  0.489f,
																0.997f,  0.513f,  0.064f,
																0.945f,  0.719f,  0.592f,
																0.543f,  0.021f,  0.978f,
																0.279f,  0.317f,  0.505f,
																0.167f,  0.620f,  0.077f,
																0.347f,  0.857f,  0.137f,
																0.055f,  0.953f,  0.042f,
																0.714f,  0.505f,  0.345f,
																0.783f,  0.290f,  0.734f,
																0.722f,  0.645f,  0.174f,
																0.302f,  0.455f,  0.848f,
																0.225f,  0.587f,  0.040f,
																0.517f,  0.713f,  0.338f,
																0.053f,  0.959f,  0.120f,
																0.393f,  0.621f,  0.362f,
																0.673f,  0.211f,  0.457f,
																0.820f,  0.883f,  0.371f,
																0.982f,  0.099f,  0.879f//cube
								};

								// Read our .obj file
								// std::vector<glm::vec3> vertices;
								vertices.push_back(vec3(1.0f,0.0f,0.0f));
								vertices.push_back(vec3(-1.0f,0.0f,0.0f));
								vertices.push_back(vec3(0.0f,1.0f,0.0f));
								vertices.push_back(vec3(0.0f,-1.0f,0.0f));
								vertices.push_back(vec3(0.0f,0.0f,1.0f));
								vertices.push_back(vec3(0.0f,0.0f,-1.0f));

								vertices.push_back(vec3(0.0f,1.0f,0.0f));
								vertices.push_back(vec3(-1.0f,-1.0f,0.0f));
								vertices.push_back(vec3(1.0f,-1.0f,0.0f));

								vertices.push_back(vec3(0.0f,1.0f,0.0f));
								vertices.push_back(vec3(0.0f,-1.0f,-1.0f));
								vertices.push_back(vec3(0.0f,-1.0f,1.0f));

								std::vector<glm::vec2> uvs;
								std::vector<glm::vec3> normals; // Won't be used at the moment.
								// bool res = loadOBJ("cube.obj", vertices, uvs, normals);

								// Load it into a VBO

								GLuint vertexbuffer;
								glGenBuffers(1, &vertexbuffer);
								glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
								glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

								GLuint uvbuffer;
								glGenBuffers(1, &uvbuffer);
								glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
								glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);


								// GLuint vertexbuffer;
								// glGenBuffers(1, &vertexbuffer);
								// glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
								// glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

								GLuint colorbuffer;
								glGenBuffers(1, &colorbuffer);
								glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
								glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

								vec3 gPosition1(0.0f, 0.0f, 0.0f);
								vec3 gOrientation1;
								double xpos, ypos,prevxpos,prevypos;
								double lastTime = glfwGetTime();
								double lastFrameTime = lastTime;
								int i=0;
								double theta = 0.0f;
								double omega = 2.0f * 3.14f / 3.0f;
								// double omega = 0.0005f;
								vec3 pos(0.3f,0.3f,0.3f);
								simulTimer timer;
								double dt;
								double fps;

								Flock flock= Flock();
								cout<<"Initail pos-"<<endl;
								for(int i=0;i<FLOCK_SIZE;i++){
									// Bird bird= Bird();
									flock.add(new Bird());
									// glm::vec3 temp=bird.getPosition();
									// cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<endl;
								}
								do {

																glm::vec3 cameraPos = glm::vec3(4.0f, 3.0f, -3.0f);

																glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
																glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

																glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
																glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
																glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

																glm::mat4 view;
																view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
																																			glm::vec3(0.0f, 0.0f, 0.0f),
																																			glm::vec3(0.0f, 1.0f, 0.0f));

																float radius = 5.0f;

																float mouseSpeed = 1.0f;
																//   glm::vec3 position = glm::vec3( 4, 3, -3 );
																//   static double lastTime = glfwGetTime();
																//   double currentTime = glfwGetTime();
																//   float deltaTime = float(currentTime - lastTime);
																glfwGetCursorPos(window, &xpos, &ypos);
																// glfwSetCursorPos(window, 1024/2, 768/2);
																gOrientation1.y += mouseSpeed * float(prevxpos - xpos );
																y_rot += mouseSpeed * float( xpos - prevxpos);

																// gOrientation1.y += mouseSpeed * float(prevxpos - xpos );
																gOrientation1.x   += mouseSpeed * float( prevypos - ypos );
																x_rot   += mouseSpeed * float(  ypos -prevypos );
																double sinx_rot= sin(x_rot * PI/180 ),cosx_rot= cos(x_rot * PI/180 );
																double siny_rot= sin(y_rot * PI/180 ),cosy_rot= cos(y_rot * PI/180 );
																double sinz_rot= sin(z_rot * PI/180 ),cosz_rot= cos(z_rot * PI/180 );

																double Xoff=0,Yoff=0,Zoff=0;

																mat4 transformationMat={{cosy_rot * cosz_rot, cosx_rot * sinz_rot +sinx_rot*siny_rot*cosz_rot,sinx_rot*sinz_rot-cosx_rot*siny_rot*cosz_rot,Xoff},
																																								{-1*cosy_rot*sinz_rot,cosx_rot*cosz_rot-sinx_rot*siny_rot*sinz_rot,sinx_rot*cosz_rot+cosx_rot*siny_rot*sinz_rot,Yoff},
																																								{siny_rot,-1*sinx_rot*cosy_rot,cosx_rot*cosy_rot,Zoff},
																																								{0,0,0,1}};
																vec4 res = transformationMat * vec4(4.0f,3.0f,-3.0f,1.0f);
																vec3 rotated(res);
// glm::vec4 result = m * v;

																// gOrientation1.x   -= mouseSpeed * float( prevypos - ypos );
																prevxpos=xpos;
																prevypos=ypos;


																// float camX = sin(glfwGetTime()) * radius;
																float camX = sin(gOrientation1.x) * radius;
																// float camY = sin(gOrientation1.x) * radius;
																float camZ = cos(gOrientation1.x) * radius;
																// float camZ = cos(glfwGetTime()) * radius;

																ViewMatrix;
																ViewMatrix = glm::lookAt(rotated, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));


																i++;
																double currentTime = glfwGetTime();

																float deltaTime = (float)(currentTime - lastFrameTime);
																lastFrameTime=currentTime;
																// Clear the screen
																glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

																// Use our shader
																glUseProgram(programID);
																ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
															
																RotationMatrix = mat4(1.0f);
																// glm::mat4 RotationMatrix = eulerAngleYXZ(gOrientation1.y, gOrientation1.x, gOrientation1.z);
																TranslationMatrix = translate(mat4(), gPosition1); // A bit to the left
																ScalingMatrix = scale(mat4(), vec3(1.0f, 1.0f, 1.0f));
																ModelMatrix = TranslationMatrix * RotationMatrix * ScalingMatrix;


																MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

																// Send our transformation to the currently bound shader,
																// in the "MVP" uniform
																glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

																// 1rst attribute buffer : vertices
																glEnableVertexAttribArray(0);
																glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
																glVertexAttribPointer(
																								0, // attribute. No particular reason for 0, but must match the layout in the shader.
																								3, // size
																								GL_FLOAT, // type
																								GL_FALSE, // normalized?
																								0, // stride
																								(void*)0 // array buffer offset
																								);

																// 2nd attribute buffer : colors
																glEnableVertexAttribArray(1);
																glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
																glVertexAttribPointer(
																								1,           // attribute. No particular reason for 1, but must match the layout in the shader.
																								3,           // size
																								GL_FLOAT,    // type
																								GL_FALSE,    // normalized?
																								0,           // stride
																								(void*)0     // array buffer offset
																								);

																// 3rd attribute buffer : UVs
																glEnableVertexAttribArray(2);
																glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
																glVertexAttribPointer(
																								2,                   // attribute. No particular reason for 1, but must match the layout in the shader.
																								3,                   // size
																								GL_FLOAT,            // type
																								GL_FALSE,            // normalized?
																								0,                   // stride
																								(void*)0             // array buffer offset
																								);

																// Draw the triangle !
																glDrawArrays(GL_LINES, 0, 3*2); // 12*3 indices starting at 0 -> 12 triangles

																std::vector<vec3> v;
																timer.tick();
																dt = timer.getDeltaTime();
																fps = timer.getFPS();

																flock.update(dt);

																// cout<<"FLOCK-"<<endl<<endl;
																for(auto it: flock.mBirds){
																	v.push_back((*it).getPosition());
																	glm::vec3 temp=(*it).getPosition();
																	cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<endl;
																}
																renderFlock(v);
																glDisableVertexAttribArray(0);
																glDisableVertexAttribArray(1);
																glDisableVertexAttribArray(2);

																// Swap buffers
																glfwSwapBuffers(window);
																glfwPollEvents();
																cin.ignore();
								} // Check if the ESC key was pressed or the window was closed
								while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
															glfwWindowShouldClose(window) == 0 );

								// Cleanup VBO and shader
								glDeleteBuffers(1, &vertexbuffer);
								glDeleteBuffers(1, &colorbuffer);
								glDeleteProgram(programID);
								glDeleteVertexArrays(1, &VertexArrayID);

								// Close OpenGL window and terminate GLFW
								glfwTerminate();

								return 0;
}


void mouseCallBack(){

}

void motionCallBack(){

}

void displayFunc(){

}

//======================================================
// MOUSE CALLBACK ROUTINE
//======================================================
// void mouseCallBack(int btn, int state, int x, int y)
// {
//
//     // Changes the rotation axis depending on the mouse button pressed.
//     if ( state == GLUT_DOWN )
//     {
//         if( btn == GLUT_LEFT_BUTTON ) axis = 0;
//         if( btn == GLUT_MIDDLE_BUTTON ) axis = 1;
//         if( btn == GLUT_RIGHT_BUTTON) axis = 2;
//     }
// }
//
// // YLP 01/05/2013 : add dynamics rotation and scaling speed
// void motionCallBack(int x, int y)
// {
//     int movx, movy;
//
//     movx = lastx - x;
//     movy = lasty - y;
//
//     if ( abs(movx) < 10 ){ rotate_speed += (float)(movx) / 50.0f; }
//     if ( abs(movy) < 10 ){ scaling  += (float)(movy) / 100.0f;  }
//
//     if ( scaling < 00.1f) scaling = 0.1f;
//     if ( scaling > 10.0f) scaling = 10.0f;
//
//     lastx = x;
//     lasty = y;
// }

void renderFlock(std::vector<vec3> v){



								for (size_t i = 0; i < v.size(); i++) {
																renderBoid(v[i]);
								}
}

void renderBoid(vec3 pos){
								TranslationMatrix = translate(mat4(), pos); // A bit to the right
								ScalingMatrix = scale(mat4(), vec3(0.1f));
								ModelMatrix = TranslationMatrix * RotationMatrix * ScalingMatrix;

								MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
								glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
								glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
								glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);


								// Draw the triangle !
								// glDrawArrays(GL_TRIANGLES, 6, vertices.size() );
								glDrawArrays(GL_TRIANGLES, 6, 3*2 );

								// glDrawArrays(GL_TRIANGLES, 6, 12*3); // 12*3 indices starting at 0 -> 12 triangles

}
