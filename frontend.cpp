#include "frontend.h"

	void SWESoftware::StartGUI(std::vector<void(*)()>& vectoroffunctions)
	{
		bool is_close = false;
		ImGui::SetNextWindowPos({ -4,0 });
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x+8, ImGui::GetIO().DisplaySize.y * 0.14));
		ImGui::Begin("Main", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		//static float value = 0.5f;
		//ImGui::DragFloat("value", &value);
		//ImGui::Text("(% .1f FPS)", 1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));
		char* x = (char*) vectoroffunctions.size();
		//ImGui::Text((x));
		
	
		static const auto size = ImVec2(ImGui::GetIO().DisplaySize.x / 5 +1, ImGui::GetIO().DisplaySize.y * 0.14);
		static const ImVec4 hoverColor{ 0.60f, 0.60, 0.60, 1.0f };
		static const ImVec4 chosenColor{ 0.5f, 0, 0, 1.0f };
		static const ImVec4 normalColor{ 0.69f, 0.69, 0.69, 1.0f };
		static ImVec4 currentColor_b0 = normalColor;
		static ImVec4 currentColor_b1 = normalColor;
		static ImVec4 currentColor_b2 = normalColor;
		static ImVec4 currentColor_b3 = normalColor;
		static ImVec4 currentColor_b4 = normalColor;


		ImGui::PushStyleColor(ImGuiCol_Button, currentColor_b0);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor_b0);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor_b0);
		ImGui::SetCursorPos(ImVec2(2, 0));
		auto state_b0 = SmartButton("Einkauf", size);
		if (state_b0 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(EinkaufGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == EinkaufGUI)
		{
			currentColor_b0 = chosenColor;
		}
		else if (state_b0 == SmartButtonState::Hovered)
			currentColor_b0 = hoverColor;
		else
			currentColor_b0 = normalColor;
		ImGui::PopStyleColor(3);




		ImGui::PushStyleColor(ImGuiCol_Button, currentColor_b1);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor_b1);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor_b1);
		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 + 2, 0));
		auto state_b1 = SmartButton("Verkauf", size);
		if (state_b1 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(VerkaufGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == VerkaufGUI)
		{
			currentColor_b1 = chosenColor;
		}
		else if (state_b1 == SmartButtonState::Hovered)
			currentColor_b1 = hoverColor;
		else
			currentColor_b1 = normalColor;
		ImGui::PopStyleColor(3);



		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 2 + 2, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor_b2);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor_b2);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor_b2);
		auto state_b2 = SmartButton("Lager", size);
		if (state_b2 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LagerGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == LagerGUI)
		{
			currentColor_b2 = chosenColor;
		}
		else if (state_b2 == SmartButtonState::Hovered)
			currentColor_b2 = hoverColor;
		else
			currentColor_b2 = normalColor;
		ImGui::PopStyleColor(3);




		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 3 + 2, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor_b3);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor_b3);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor_b3);
		auto state_b3 = SmartButton("Lieferand", size);
		if (state_b3 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(LieferantenGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == LieferantenGUI)
		{
			currentColor_b3 = chosenColor;
		}
		else if (state_b3 == SmartButtonState::Hovered)
			currentColor_b3 = hoverColor;
		else
			currentColor_b3 = normalColor;
		ImGui::PopStyleColor(3);




		ImGui::SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x / 5 * 4 + 2, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, currentColor_b4);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, currentColor_b4);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, currentColor_b4);
		auto state_b4 = SmartButton("Dashboard", size);
		if (state_b4 == SmartButtonState::Pressed)
		{
			vectoroffunctions.clear();
			vectoroffunctions.push_back(DashboardGUI);
		}
		if (vectoroffunctions.size() > 0 && vectoroffunctions.at(0) == DashboardGUI)
		{
			currentColor_b4 = chosenColor;
		}
		else if (state_b4 == SmartButtonState::Hovered)
			currentColor_b4 = hoverColor;
		else
			currentColor_b4 = normalColor;
		ImGui::PopStyleColor(3);





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


		ImGui::Begin("Lieferand",0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("Lieferand-GUI");
		ImGui::End();
	}
	void SWESoftware::DashboardGUI()
	{
		ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetIO().DisplaySize.y * 0.14 + 1));
		ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y * 0.86));


		ImGui::Begin("Lieferand", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("Dashboard-GUI");
		ImGui::End();
	}



