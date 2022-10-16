#pragma once
#include "includeHeader.h"

namespace SWESoftware {

	void StartGUI(std::vector<void(*)()>& vectoroffunctions);
	void EinkaufGUI();
	void VerkaufGUI();
	void LagerGUI();
	void LieferantenGUI();
}