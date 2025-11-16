#pragma once

#include <Novice.h>

#include "Vector2.h"

class Vector2I;

class Mouse {
public:
	Vector2I pos;
	Vector2I size;
	float angle;
	//int texture;
	int color;
	int visibility;

public:
	void invisible();
	void GetPos();
	void Draw();
};