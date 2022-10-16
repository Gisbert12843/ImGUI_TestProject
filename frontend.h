#pragma once
#include "includeHeader.h"

namespace SWESoftware {

	void StartGUI(std::vector<void(*)()>& vectoroffunctions);
	void EinkaufGUI();
	void VerkaufGUI();
	void LagerGUI();
	void LieferantenGUI();
}

enum SmartButtonState {
    None = 0,
    Hovered,
    Pressed,
    Released,
    DoubleClicked // Not yet implemented
};

static SmartButtonState SmartButton(const char* label, ImVec2 size = { 0, 0 }) {
    bool released = ImGui::Button(label, size);

    // Order of these are important
    if (released) return SmartButtonState::Released;
    if (ImGui::IsItemActive()) return SmartButtonState::Pressed;
    if (ImGui::IsItemHovered()) return SmartButtonState::Hovered;
    return SmartButtonState::None;
}