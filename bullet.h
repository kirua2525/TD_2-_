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
	Vector2F pos[5];
	Vector2F size;
	Vector2F radius;
	Vector2F speed;
	Vector2F vel[5];
	float angle[5];
	float damage;
	const int kCoolTime = 5;
	int coolTimer;
	int color;
	//int texture;
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
		bool isHit
	);
	void Update(Gun& gun,Mouse& mouse,Player& player);
	void Draw(Gun gun);

};