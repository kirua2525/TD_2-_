#pragma once

#include <Novice.h>

#include "Vector2.h"
#include "gun.h"

class Vector2I;
class Vector2F;
class Scroll;
class Gun;

class Mouse {
public:
	Vector2I pos;
	Vector2F size;
	Vector2F radius;
	float angle;
	//int texture;
	int color;
	int visibility;

	~Mouse();

public:
	void invisible();
	void GetPos();
	void Initialize(
		Vector2F size,
		Vector2F radius,
		float angle,
		int color
	);
	void Update(Gun gun);
	void Draw();
};