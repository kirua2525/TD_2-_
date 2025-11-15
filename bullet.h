#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "gun.h"

class Gun;

class Bullet {
public:

	Vector2 pos;
	Vector2 size;
	bool isHit;

public:

	void Initialize();
	void Update();
	void Draw();

};