#include "frontend.h"

	void SWESoftware::StartGUI(std::vector<void(*)()>& vectoroffunctions)
	{
		bool is_close = false;
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.14));
		ImGui::Begin("Main", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar );

		//static float value = 0.5f;
		//ImGui::DragFloat("value", &value);
		//ImGui::Text("(% .1f FPS)", 1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));
		
		
		
		/*
		ImGui::SetCursorPos(ImVec2(0,0));
		ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(192, 192, 192, 192));
		ImGuiHoveredFlags hoverflag = 0;
		if (ImGui::Button("Einkauf", ImVec2(ImGui::GetIO().DisplaySize.x / 5, ImGui::GetIO().DisplaySize.y * 0.14)), hoverflag) {
			vectoroffunctions.clear();
			vectoroffunctions.push_back(EinkaufGUI);
		}
		if (hoverflag)
		{
			ImGui::PopStyleColor();
			ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(192, 192, 192, 192));
			ImGui::PopStyleColor();
		}
		else
		ImGui::PopStyleColor();
		*/
		static const auto size = ImVec2(ImGui::GetIO().DisplaySize.x / 5, ImGui::GetIO().DisplaySize.y * 0.14);
		static const ImVec4 hoverColor{ 0.60f, 0.60, 0.60, 1.0f };
		static const ImVec4 chosenColor{ 0.5f, 0, 0, 1.0f };
		static const ImVec4 normalColor{ 0.69f, 0.69, 0.69, 1.0f };
		static ImVec4 currentColor = normalColor;


		ImGui::SetCursorPos(ImVec2(0, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor);
		auto state_b0 = SmartButton("Einkauf", size);
		ImGui::PopStyleColor(3);
		if (state_b0 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(EinkaufGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == EinkaufGUI)
		{
			currentColor = chosenColor;
		}
		else if (state_b0 == SmartButtonState::Hovered)
			currentColor = hoverColor;
		else
			currentColor = normalColor;




		//ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(192, 192, 192, 192));
		//ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5, 0));
		//if (ImGui::Button("Verkauf", ImVec2(ImGui::GetIO().DisplaySize.x / 5, ImGui::GetIO().DisplaySize.y * 0.14))) {
		//	vectoroffunctions.clear();
		//	vectoroffunctions.push_back(VerkaufGUI);
		//}
		//ImGui::PopStyleColor();
		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor);
		auto state_b1 = SmartButton("Verkauf", size);
		ImGui::PopStyleColor(3);
		if (state_b1 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(VerkaufGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == VerkaufGUI)
		{
			currentColor = chosenColor;
		}
		else if (state_b1 == SmartButtonState::Hovered)
			currentColor = hoverColor;
		else
			currentColor = normalColor;



		//ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(192, 192, 192, 192));
		//ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 2, 0));
		//if (ImGui::Button("Lager", ImVec2(ImGui::GetIO().DisplaySize.x / 5, ImGui::GetIO().DisplaySize.y * 0.14))) {
		//	vectoroffunctions.clear();
		//	vectoroffunctions.push_back(LagerGUI);
		//}
		//ImGui::PopStyleColor();
		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 2, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor);
		auto state_b2 = SmartButton("Lager", size);
		ImGui::PopStyleColor(3);
		if (state_b2 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LagerGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == LagerGUI)
		{
			currentColor = chosenColor;
		}
		else if (state_b2 == SmartButtonState::Hovered)
			currentColor = hoverColor;
		else
			currentColor = normalColor;


		//ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(192, 192, 192, 192));
		//ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 3, 0));
		//if (ImGui::Button("Lieferanden", ImVec2(ImGui::GetIO().DisplaySize.x / 5, ImGui::GetIO().DisplaySize.y * 0.14))) {
		//	vectoroffunctions.clear();
		//	vectoroffunctions.push_back(LieferantenGUI);
		//}
		//ImGui::PopStyleColor();
		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 3, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor);
		auto state_b3 = SmartButton("Lierferanden", size);
		ImGui::PopStyleColor(3);
		if (state_b3 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LieferantenGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == LieferantenGUI)
		{
			currentColor = chosenColor;
		}
		else if (state_b3 == SmartButtonState::Hovered)
			currentColor = hoverColor;
		else
			currentColor = normalColor;


		ImGui::End();
	}

	void SWESoftware::EinkaufGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));

		bool is_close = false;
		ImGui::Begin("Einkauf", &is_close, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);


		ImGui::Text("Einkaufs-GUI");
		ImGui::End();
	}
	void SWESoftware::VerkaufGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Verkauf",NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("Verkaufs-GUI");
		ImGui::End();
	}
	void SWESoftware::LagerGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Lager",0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("Lager-GUI");
		ImGui::End();
	}
	void SWESoftware::LieferantenGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Lieferanden",0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("Lieferanden-GUI");
		ImGui::End();
	}



