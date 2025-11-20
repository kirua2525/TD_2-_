#include "Novice.h"
#include "mouse.h"
#include "gun.h"
#include "bullet.h"

void Bullet::Initialize(
	Vector2F bulletPos,
	Vector2F bulletSize,
	Vector2F bulletSpeed,
	Vector2F bulletRadius,
	Vector2F bulletvel,
	float bulletAngle,
	float bulletdamage,
	int bulletColor,
	//int bulletTexture,
	bool bulletIsHit
) {
	this->pos = bulletPos;
	this->size = bulletSize;
	this->speed = bulletSpeed;
	this->radius = bulletRadius;
	this->vel = bulletvel;
	this->angle = bulletAngle;
	this->damage = bulletdamage;
	this->color = bulletColor;
	//this->texture = bulletTexture;
	this->isHit = bulletIsHit;
}

Bullet::~Bullet(){}

void Bullet::Update(Gun& gun, Mouse& mouse, Player& player) {
    if (gun.isShot) {

        // Initialize bullet position at player center (once per shot)
        if (!this->isHit) {
            this->pos.x = player.pos.x + player.radius.x;
            this->pos.y = player.pos.y + player.radius.y;

            // Compute direction
            Vector2F dir;
            dir.x = (mouse.pos.x + (int)mouse.radius.x) - this->pos.x;
            dir.y = (mouse.pos.y + (int)mouse.radius.y) - this->pos.y;

            float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
            if (len != 0.0f) {
                dir.x /= len;
                dir.y /= len;
            }

            // Store velocity
            this->vel.x = dir.x * this->speed.x;
            this->vel.y = dir.y * this->speed.y;
            this->isHit = true;
        }

        // Move bullet
        this->pos.x += this->vel.x;
        this->pos.y += this->vel.y;
    }

    // Check boundaries (1280 x 720)
    if (this->pos.x < 0.0f || this->pos.x > 1280.0f ||
        this->pos.y < 0.0f || this->pos.y > 720.0f) {
        gun.isShot = false;
        this->isHit = false;
        this->pos.x = player.pos.x + player.radius.x;
        this->pos.y = player.pos.y + player.radius.y;
    }

    if (!gun.isShot) {
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