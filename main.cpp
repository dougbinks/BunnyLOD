#include <GLFW/glfw3.h>

#include "glutil.h"
#include "geometric.h"

// Functions and Variables from bunny module
extern void       InitModel();
extern char *     RenderModel( float DeltaT );
extern float3     model_position;      // position of bunny 
extern float4     model_orientation;   // orientation of bunny 



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "BunnyLOD", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    double lastFrameTime = glfwGetTime();

    InitModel();  // initializes some data structures and does progressive mesh polygon reduction algorithm
    GLUtil glUtil;

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    float3 MouseVectorOld;
    const float ViewAngle = 60.f;


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double currTime = glfwGetTime();
        float deltaT = (float)( currTime - lastFrameTime );
        lastFrameTime = currTime;

        int width, height;
        glfwGetFramebufferSize(window,&width,&height);
        float2 res = { (float)width,(float)height };
        float3 MouseVector;

        // ComputeMouseVector
        double mouseposx, mouseposy;
        glfwGetCursorPos(window,&mouseposx,&mouseposy);
		float spread = (float)tan(ViewAngle / 2 * 3.14 / 180);
		float y = spread * ((res.y - (float)mouseposy) - res.y / 2.0f) / (res.y / 2.0f);
		float x = spread * ((float)mouseposx - res.x / 2.0f) / (res.y / 2.0f);
		MouseVector = normalize(float3(x, y, -1));
        if( glfwGetMouseButton(window,0) )
        {
		    model_orientation=qmul(VirtualTrackBall(float3(0,0,0),model_position,MouseVectorOld,MouseVector),model_orientation);
        }
        MouseVectorOld = MouseVector;


        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glPerspective(ViewAngle, (float)width/height, 0.1f, 50.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


        glPushMatrix();
		glLoadIdentity();
		// camera at default (zero) position and orientation
		char * s=RenderModel( deltaT );

        glLoadIdentity();
		glColor3f(1,1,0);
		glUtil.PrintString({ 0, -2 },s);  // print returned status string from rendermodel()  current vert and tri count
		glUtil.PrintString({ 5, 1 },"Demo by Stan Melax (c)1998");
		glUtil.PrintString({ 5, 2 },"Model by Viewpoint Datalabs (c)1996");
		glUtil.PrintString({ 0, -1 }, "FPS: %5.2f   ", 1.0f/deltaT);


        glPopMatrix();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
