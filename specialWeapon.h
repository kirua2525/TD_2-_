#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "player.h"

class Player;

class SpecialWeapon {
public:
	Vector2 pos;
	Vector2 size;
	float angle;
	int color;
	//int texture;
	int damage;
	int minDamage;
	int maxDamage;
	bool isHit;

public:
	void Initialize(
		Vector2 pos,
		Vector2 size,
		float angle,
		int color,
		//int texture,
		int damage,
		int minDamage,
		int maxDamage,
		bool isHit
	);

public:
	void Damage();
	void Update(Player player);
	void Draw();

};