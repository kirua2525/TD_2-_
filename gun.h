#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "mouse.h"
#include "player.h"
#include "bullet.h"

class Player;
class Bullet;
class Mouse;

class Gun {
public:
	Vector2F pos;
	Vector2F initialPos;
	Vector2F size;
	Vector2F radius;
	float angle;
	int color;
	//int texture;
	//int leftTexture;
	//int rightTexture;
	int damage;
	int minDamage;
	int maxDamage;
	bool isShot;

	~Gun();
	
public:
	void Initialize(
		Vector2F pos,
		Vector2F size,
		Vector2F radius,
		float angle,
		int color,
		//int texture,
		//int leftTexture,
		//int rightTexture,
		int damage,
		int minDamage,
		int maxDamage,
		bool isShot
	);
	void Reset();
	void Update(Player player, Mouse mouse);
	void Draw();

};