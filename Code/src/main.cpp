// Include standard headers
#include <stdio.h>
#include <stdlib.h>

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

#include <shader.hpp>
#include <texture.hpp>
// #include <common/controls.hpp>

int main( void )
{
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
								GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader" );

								// Get a handle for our "MVP" uniform
								GLuint MatrixID = glGetUniformLocation(programID, "MVP");

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
																0.0f,0.0f,-1.0f
								};

								// One color for each vertex. They were generated randomly.
								static const GLfloat g_color_buffer_data[] = {
																0.583f,  0.771f,  0.014f,
																0.609f,  0.115f,  0.436f,
																0.327f,  0.483f,  0.844f,
																0.822f,  0.569f,  0.201f,
																0.435f,  0.602f,  0.223f,
																0.310f,  0.747f,  0.185f
								};

								GLuint vertexbuffer;
								glGenBuffers(1, &vertexbuffer);
								glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
								glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

								GLuint colorbuffer;
								glGenBuffers(1, &colorbuffer);
								glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
								glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
								vec3 gPosition1(0.0f, 0.0f, 0.0f);
								vec3 gOrientation1;
								double xpos, ypos;
								double lastTime = glfwGetTime();
								double lastFrameTime = lastTime;
								int i=0;
								do {
																i++;
																double currentTime = glfwGetTime();

																float deltaTime = (float)(currentTime - lastFrameTime);

																// Clear the screen
																glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

																// Use our shader
																glUseProgram(programID);
																glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
																glm::mat4 ViewMatrix = glm::lookAt(
																								glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
																								glm::vec3(0,0,0), // and looks at the origin
																								glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
																								);
																// float verticalAngle = 1.57f;
																// float horizontalAngle = 0.0f;
																float mouseSpeed = 0.005f;
//   glm::vec3 position = glm::vec3( 4, 3, -3 );
//   static double lastTime = glfwGetTime();
//   double currentTime = glfwGetTime();
//   float deltaTime = float(currentTime - lastTime);
																glfwGetCursorPos(window, &xpos, &ypos);
																glfwSetCursorPos(window, 1024/2, 768/2);
																gOrientation1.y += mouseSpeed * float(1024/2 - xpos );
																gOrientation1.x   -= mouseSpeed * float( 768/2 - ypos );
																// gOrientation1.y += 3.14159f/2.0f * deltaTime;

																glm::mat4 RotationMatrix = eulerAngleYXZ(gOrientation1.y, gOrientation1.x, gOrientation1.z);
																glm::mat4 TranslationMatrix = translate(mat4(), gPosition1); // A bit to the left
																glm::mat4 ScalingMatrix = scale(mat4(), vec3(1.0f, 1.0f, 1.0f));
																glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScalingMatrix;

																glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;




//
//   // Compute the MVP matrix from keyboard and mouse input

//   // glm::vec3 myRotationAxis( 1.0f, 0.0f, 0.0f);
//   // glm::rotate( horizontalAngle, myRotationAxis );
//
//   glm::mat4 myTranslationMatrix = glm::mat4(1.0f);
//   if (i%1000==0)
//  {	myTranslationMatrix = glm::rotate(myTranslationMatrix, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//   glm::mat4 myModelMatrix = myTranslationMatrix ;
//   MVP = myModelMatrix * MVP;
// }
																// computeMatricesFromInputs();
																// glm::mat4 ProjectionMatrix = getProjectionMatrix();
																// glm::mat4 ViewMatrix = getViewMatrix();
																// glm::mat4 ModelMatrix = glm::mat4(1.0);
																// glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

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

																// Draw the triangle !
																glDrawArrays(GL_LINES, 0, 3*2); // 12*3 indices starting at 0 -> 12 triangles

																glDisableVertexAttribArray(0);
																glDisableVertexAttribArray(1);

																// Swap buffers
																glfwSwapBuffers(window);
																glfwPollEvents();

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
