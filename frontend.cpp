#include "frontend.h"

	void SWESoftware::StartGUI(std::vector<void(*)()>& vectoroffunctions)
	{
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.14));
		ImGui::Begin("Main", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar );

		//static float value = 0.5f;
		//ImGui::DragFloat("value", &value);
		//ImGui::Text("(% .1f FPS)", 1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));

		if (ImGui::Button("Einkauf")) {
			vectoroffunctions.clear();
			vectoroffunctions.push_back(EinkaufGUI);
		}

		if (ImGui::Button("Verkauf")) {
			vectoroffunctions.clear();
			vectoroffunctions.push_back(VerkaufGUI);
		}

		if (ImGui::Button("Lager")) {
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LagerGUI);
		}
		if (ImGui::Button("Lieferanden")) {
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LieferantenGUI);
		}


		ImGui::End();
	}

	void SWESoftware::EinkaufGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));

		bool is_close = false;
		ImGui::Begin("Einkauf", &is_close, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);


		ImGui::Text("Einkaufs-GUI");
		ImGui::End();
	}
	void SWESoftware::VerkaufGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Verkauf",NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::Text("Verkaufs-GUI");
		ImGui::End();
	}
	void SWESoftware::LagerGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Lager",0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::Text("Lager-GUI");
		ImGui::End();
	}
	void SWESoftware::LieferantenGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Lieferanden",0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::Text("Lieferanden-GUI");
		ImGui::End();
	}



