#pragma once

#include "Vector2.h"

class Player {
public:

	enum weaponType {
		SWORD = 1,
		GUN = 2,
		SPECIAL_ITEM = 3
	};

	Vector2 pos;
	Vector2 velocity;
	Vector2 size;
	Vector2 radius;
	float angle;
	unsigned int color;
	float hp;
	float maxHp;
	float minHp;
	float damage;
	float minDamage;
	float maxDamage;
	//int texture;
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

public:
	void Initialize(
		Vector2 pos,
		Vector2 velocity,
		Vector2 size,
		Vector2 playerRadius,
		float angle,
		unsigned int playerColor,
		//int textureHandle
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