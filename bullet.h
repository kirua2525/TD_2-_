#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "mouse.h"
#include "gun.h"

class Gun;

class Bullet {
public:

	Vector2F pos;
	Vector2F size;
	Vector2F speed;
	float angle;
	int color;
	//int texture;
	bool isHit;

public:

	void Initialize();
	void Update(Gun gun);
	void Draw();

};