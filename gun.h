#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>
#include "Vector2.h"
#include "player.h"

class Gun {
public:
	Vector2 pos;
	Vector2 size;
	float angle;
	int color;
	//int texture;
	float damage;
	float minDamage;
	float maxDamage;
	bool isShot;
	
public:
	void Initialize(
		Vector2 pos,
		Vector2 size,
		float angle,
		int color,
		//int texture,
		float damage,
		float minDamage,
		float maxDamage,
		bool isShot
	);
	void Update();
	void Draw();

};