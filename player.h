#pragma once

#include "Vector2.h"

class Player {
public:
	Vector2 pos;
	Vector2 velocity;
	Vector2 size;
	Vector2 radius;
	float angle;
	unsigned int color;
	//int texture;
	float jumpSpeed;
	bool isAlive; 
	bool isVisible; 
	bool isjumping;
	bool isMoving; 
	bool isOnGround;

public:
	void Initialize(
		Vector2 pos,
		Vector2 velocity,
		Vector2 size,
		Vector2 playerRadius,
		float angle,
		unsigned int enemyColor,
		//int textureHandle
		float jumpSpeed,
		bool alive,	
		bool visible,
		bool jumping,
		bool moving,
		bool onGround
	);
	void Gravity();

	void Update(const char* keys);

	void Draw();
};