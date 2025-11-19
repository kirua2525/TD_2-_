#pragma once

#include "line.h"
#include "player.h"

class Player;
class Line;

class Scroll{
public:
	float scrollX;
	float maxScroll;

public:
	void Initialize(
		float scrollX,
		float maxScroll
	);
	void Update(Player player, Line line);
};

