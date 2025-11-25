#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "player.h"
#include "mouse.h"
#include "gun.h"

class Gun;
class Mouse;

class Bullet {
public:
	static const int nums = 5;
	Vector2F pos[nums];
	Vector2F initialPos[nums];
	Vector2F size;
	Vector2F radius;
	Vector2F speed;
	Vector2F vel[nums];
	float angle[nums];
	float damage;
	const int kCoolTime = 5;
	int coolTimer;
	int color;
	//int texture;
	bool isActive[5];
	bool isHit[5];


	~Bullet();

public:

	void Initialize(
		Vector2F pos,
		Vector2F size,
		Vector2F speed,
		Vector2F radius,
		Vector2F vel,
		float angle,
		float damage,
		int color,
		//int texture,
		bool isActive,
		bool isHit
	);
	void ReSet(Player player,Gun gun);
	void Update(Gun& gun,Mouse& mouse,Player& player);
	void Draw();

};