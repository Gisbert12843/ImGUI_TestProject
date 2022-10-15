#include "frontend.h"

namespace SWESoftware{
	void designGUI()
	{
		ImGui::Begin("Lieferanten", NULL);


		static float value = 0.5f;
		ImGui::DragFloat("value", &value);


		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));


		ImGui::End();
	}
}