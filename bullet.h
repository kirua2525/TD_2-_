#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "mouse.h"
#include "gun.h"

class Gun;
class Mouse;

class Bullet {
public:

	Vector2F pos;
	Vector2F size;
	Vector2F radius;
	Vector2F speed;
	float angle;
	int color;
	//int texture;
	bool isHit;

	~Bullet();

public:

	void Initialize(
		Vector2F pos,
		Vector2F size,
		Vector2F speed,
		Vector2F radius,
		float angle,
		int color,
		//int texture,
		bool isHit
	);
	void Update(Gun gun,Mouse mouse);
	void Draw(Gun gun);

};