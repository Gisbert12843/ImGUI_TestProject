#include "frontend.h"

namespace SWESoftware{
	void StartGUI()
	{
		ImGui::Begin("Main", NULL);


		static float value = 0.5f;
		ImGui::DragFloat("value", &value);


		ImGui::Text("(% .1f FPS)", 1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));
		if (ImGui::Button("Click me")) {
			// onButtonClick();
		}

		ImGui::End();
	}

	void EinkaufGUI()
	{
		ImGui::Begin("Einkauf");
		ImGui::Text("Einkaufs-GUI");
		ImGui::End();
	}
	void VerkaufGUI()
	{
		ImGui::Begin("Verkauf");
		ImGui::Text("Verkaufs-GUI");
		ImGui::End();
	}
	void LagerGUI()
	{
		ImGui::Begin("Lager");
		ImGui::Text("Lager-GUI");
		ImGui::End();
	}
	void LieferantenGUI()
	{
		ImGui::Begin("Lieferanden");
		ImGui::Text("Lieferanden-GUI");
		ImGui::End();
	}

}