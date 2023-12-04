#pragma once
#include "Module.h"

class MorpionModule : public Module
{
public:
	void Update() override;

private:
	void DrawGrid();

	bool CheckWin();
	bool CheckWinRow(char _1, char _2, char _3);

	char grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	char turn = 1;
	char winner = 0;
};
