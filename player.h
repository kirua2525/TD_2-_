#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "sword.h"
#include "gun.h"
#include "specialWeapon.h"

class Vector2F;

class Player {
public:

	enum weaponType {
		SWORD = 1,
		GUN = 2,
		SPECIAL_ITEM = 3
	};

	Vector2F pos;
	Vector2F velocity;
	Vector2F size;
	Vector2F radius;
	float angle;
	unsigned int color;
	float hp;
	float maxHp;
	float minHp;
	//int texture;
	//int leftTexture;
	//int rightTexture;
	float jumpSpeed;
	bool isAlive; 
	bool isVisible; 
	bool isjumping;
	bool isMoving; 
	bool isOnGround;
	bool isAttackSword;
	bool isAttackGun;
	bool isAttackSpecialItem;
	bool wPressed;
	bool upPressed;
	bool spacePressed;
	weaponType currentWeapon;

	~Player();

public:
	void Initialize(
		Vector2F pos,
		Vector2F velocity,
		Vector2F size,
		Vector2F playerRadius,
		float angle,
		unsigned int playerColor,
		//int texture,
		//int leftTextureHandle,
		//int rightTextureHandle
		float jumpSpeed,
		bool alive,	
		bool visible,
		bool jumping,
		bool moving,
		bool onGround,
		bool wPressed,
		bool upPressed,
		bool spacepressed,
		weaponType currentWeapon
	);
	void Gravity();

	void Update(const char* keys, const char* prekeys);

	void Draw();

	void debugDraw();

	void Damage(float damageAmount);

	void Heal(float healAmount);

	void SetWeapon(weaponType newWeapon);

	void resetStatus();
};