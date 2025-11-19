#pragma once

#include "Vector2.h"
#include "player.h"
#include "scroll.h"

class Player;
class Scroll;

class Line{
public:
	Vector2F topPos;
	Vector2F underPos;
	float angle;
	bool isHitLine;

public:
	void Initialize(
		Vector2F topPos,
		Vector2F underPos,
		float angle,
		bool isHitLine
	);

	void Update();


};

