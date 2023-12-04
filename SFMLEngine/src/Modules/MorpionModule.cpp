#include "Modules/MorpionModule.h"

#include <imgui.h>
#include <iostream>

void MorpionModule::Update()
{
	Module::Update();

	DrawGrid();
	CheckWin();
}

void MorpionModule::DrawGrid()
{
	ImGui::Begin("Game");

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x > 0)
				ImGui::SameLine();
			ImGui::PushID(y * 3 + x);

			switch (grid[y][x])
			{
			case 1: ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(255, 0, 0, 255));
				break;
			case 2: ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 255, 0, 255));
				break;
			default: ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 0, 255, 255));
				break;
			}

			if (ImGui::Button("X", ImVec2(50, 50)))
			{
				if (grid[y][x] == 0)
				{
					grid[y][x] = turn;
					std::cout << "selected " << x << " - " << y << '\n';
					turn = turn == 1 ? 2 : 1;
				}
			}

			ImGui::PopStyleColor();

			ImGui::PopID();
		}
	}

	ImGui::End();
}

bool MorpionModule::CheckWin()
{
	if (CheckWinRow(grid[0][0], grid[0][1], grid[0][2]))
		return true;
	if (CheckWinRow(grid[1][0], grid[1][1], grid[1][2]))
		return true;
	if (CheckWinRow(grid[2][0], grid[2][1], grid[2][2]))
		return true;

	if (CheckWinRow(grid[0][0], grid[1][0], grid[2][0]))
		return true;
	if (CheckWinRow(grid[0][1], grid[1][1], grid[2][1]))
		return true;
	if (CheckWinRow(grid[0][2], grid[1][2], grid[2][2]))
		return true;

	if (CheckWinRow(grid[0][0], grid[1][1], grid[2][2]))
		return true;
	if (CheckWinRow(grid[2][0], grid[1][1], grid[0][2]))
		return true;

	return false;
}

bool MorpionModule::CheckWinRow(char _1, char _2, char _3)
{
	if (_1 != 0)
	{
		if (_1 == _2 && _2 == _3)
		{
			winner = _1;
			std::cout << "Winner : " << winner;
			return true;
		}
	}

	return false;
}
