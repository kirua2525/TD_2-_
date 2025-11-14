#include <Novice.h>
#include <math.h>
#include "Vector2.h"
#include "player.h"

void Player::Initialize(
	Vector2 playerPos,
	Vector2 playerVelocity,
	Vector2 playerSize,
	Vector2 playerRadius,
	float playerAngle,
	unsigned int playerColor,
	//int textureHandle
	float playerJumpSpeed,
	bool playerAlive,
	bool playerVisible,
	bool playerJumping,
	bool playerMoving,
	bool playerOnGround
) {
	this->pos = playerPos;
	this->velocity = playerVelocity;
	this->size = playerSize;
	this->radius = playerRadius;
	this->angle = playerAngle;
	this->color = playerColor;
	//this->texture = textureHandle;
	this->jumpSpeed = playerJumpSpeed;
	this->isAlive = playerAlive;
	this->isVisible = playerVisible;
	this->isjumping = playerJumping;
	this->isMoving = playerMoving;
	this->isOnGround = playerOnGround;
}

void Player::Gravity() {
	this->velocity.y += 0.5f; // Gravity
}

void Player::Update(const char* keys) {
	if(keys[DIK_A]||keys[DIK_LEFT]) {
		this->pos.x -= 5.0f;
	}
	if(keys[DIK_D]||keys[DIK_RIGHT]) {
		this->pos.x += 5.0f;
	}
	if((keys[DIK_W]||keys[DIK_UP]||keys[DIK_SPACE]) && this->isOnGround) {
		this->velocity.y = -this->jumpSpeed;
		this->isOnGround = false;
	}
	Player::Gravity();
	this->pos.y += this->velocity.y;
	if(this->pos.y >= 600.0f) { // Ground collision
		this->pos.y = 600.0f;
		this->velocity.y = 0.0f;
		this->isOnGround = true;
	}
}

void Player::Draw() {
	Novice::DrawBox(
		(int)this->pos.x,
		(int)this->pos.y,
		(int)this->radius.x,
		(int)this->radius.y,
		this->angle,
		this->color,
		kFillModeSolid
	);
}