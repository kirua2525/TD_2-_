#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "player.h"

class Player;

class Sword {
public:
	Vector2F pos;
	Vector2F size;
	Vector2F radius;
	float angle;
	float angleRotate;
	int color;
	int texture;
	int damage;
	int minDamage;
	int maxDamage;
	bool isHit;

	~Sword();

public:
	void Initialize(
		Vector2F pos,
		Vector2F size,
		Vector2F radius,
		float angle,
		float rotate,
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