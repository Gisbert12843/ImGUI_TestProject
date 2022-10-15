#include "rendering.h"




void delay(std::chrono::high_resolution_clock::time_point& pstart)
{

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - pstart).count();
	
	auto to_wait ((1000 / (30+6)) - duration); //seems to wait to exact 30fps, dont ask me for the +6 offset
	std::this_thread::sleep_for(std::chrono::milliseconds(to_wait));
}
void delay() {
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	while (true)
	{
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		if (duration.count() >= 20000)
		{
			return;
		}
		else
			continue;
	}
}
void delay(int microseconds_to_wait)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	while (true)
	{
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		if (duration.count() >= microseconds_to_wait)
		{
			return;
		}
		else
			continue;
	}
}



int imguiMain() {
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// Create a GLFWwindow object of 800 by 800 pixels, naming it "ImGUI_TestProject"
	GLFWwindow* window = glfwCreateWindow(glfwGetVideoMode(glfwGetPrimaryMonitor())->width, glfwGetVideoMode(glfwGetPrimaryMonitor())->height, "Mehrmarkt - Software", glfwGetPrimaryMonitor(), NULL);
	//GLFWwindow* window = glfwCreateWindow(800,800, "Mehrmarkt - Software", glfwGetPrimaryMonitor(), NULL);
	//glfwSwapInterval(10); //Framelimit?
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	//glViewport(0, 0, glfwGetVideoMode(glfwGetPrimaryMonitor())->width, glfwGetVideoMode(glfwGetPrimaryMonitor())->width);
	glViewport(0, 0, 800,800);

	// Initialize ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	// Main while loop

	while (!glfwWindowShouldClose(window))
	{
		std::chrono::high_resolution_clock::time_point frame_starttime = std::chrono::high_resolution_clock::now();

		// Specify the color of the background
		glClearColor(0.49f, 0.49f, 0.49f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		// Tell OpenGL a new frame is about to begin
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		//BELOW HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		ImGuiIO GuiIOTemp = ImGui::GetIO();
		float x = GuiIOTemp.DisplaySize.x;
		float y = GuiIOTemp.DisplaySize.y;
		ImVec2 tempVec2 = { x,y };
		ImGui::SetNextWindowSize(tempVec2);
		ImGui::SetNextWindowPos({ 0,0 });



		// ImGUI window creation

		SWESoftware::StartGUI();
		SWESoftware::EinkaufGUI();
		SWESoftware::VerkaufGUI();
		SWESoftware::LagerGUI();






		// Renders the ImGUI elements
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();


		//FPS limiter below
		//void (*delayfunc)(std::chrono::high_resolution_clock::time_point&) = &delay; //tells the compiler which version of the delay function he should use, remove the 'int' to change paramters requirement to (), values are in microseconds
		delay(frame_starttime);
		//FPS limiter above

	}

	// Deletes all ImGUI instances
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	// Delete all the objects we've created



	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}