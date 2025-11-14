#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "player.h"

class SpecialWeapon {
public:
	Vector2 pos;
	Vector2 size;
	float angle;
	int color;
	int texture;
	float damage;
	float minDamage;
	float maxDamage;

public:
	void Initialize(
		Vector2 pos,
		Vector2 size,
		float angle,
		int color,
		int texture,
		float damage,
		float minDamage,
		float maxDamage
	);
	void Update();
	void Drow();

};