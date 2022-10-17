#pragma once
#include "includeHeader.h"
#include "frontend.h"

#include <chrono>

int initGUI();

void delay();
void delay(std::chrono::high_resolution_clock::time_point& pstart);
void delay(int microseonds_to_wait = 20000);
