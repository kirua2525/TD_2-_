#include "Novice.h"
#include "mouse.h"
#include "gun.h"
#include "bullet.h"

void Bullet::Initialize(
	Vector2F bulletPos,
	Vector2F bulletSize,
	Vector2F bulletSpeed,
	Vector2F bulletRadius,
	float bulletAngle,
	int bulletColor,
	//int bulletTexture,
	bool bulletIsHit
) {
	this->pos = bulletPos;
	this->size = bulletSize;
	this->speed = bulletSpeed;
	this->radius = bulletRadius;
	this->angle = bulletAngle;
	this->color = bulletColor;
	//this->texture = bulletTexture;
	this->isHit = bulletIsHit;
}

Bullet::~Bullet(){}

void Bullet::Update(Gun gun,Mouse mouse) {
	if (gun.isShot) {
		// Compute direction vector from bullet to mouse
		Vector2F direction;
		direction.x = mouse.pos.x - this->pos.x;
		direction.y = mouse.pos.y - this->pos.y;

		// Normalize the vector
		float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
		if (length != 0.0f) {
			direction.x /= length;
			direction.y /= length;
		}

		// Move bullet toward mouse
		this->pos.x += direction.x * this->speed.x;
		this->pos.y += direction.y * this->speed.y;
	}

	// Check boundaries
	if (this->pos.x <= 0.0f || this->pos.x >= 1280.0f || // Assuming screen width = 1280
		this->pos.y <= 0.0f || this->pos.y >= 600.0f) { // Assuming screen height = 600
		gun.isShot = false;
		this->isHit = false;
	}
}

void Bullet::Draw(Gun gun) {
	if (gun.isShot) {
		Novice::DrawBox(
			(int)this->pos.x,
			(int)this->pos.y,
			(int)this->size.x,
			(int)this->size.y,
			this->angle,
			this->color,
			kFillModeSolid
		);
	}
};