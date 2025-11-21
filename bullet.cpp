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
    for (int i = 0; i < 5; i++) {
        this->pos[i] = bulletPos;
        this->size = bulletSize;
        this->speed = bulletSpeed;
        this->radius = bulletRadius;
        this->vel[i] = bulletvel;
        this->angle[i] = bulletAngle;
        this->damage = bulletdamage;
        this->color = bulletColor;
        //this->texture = bulletTexture;
        this->isHit[i] = bulletIsHit;
    }
}

Bullet::~Bullet(){}

void Bullet::Update(Gun& gun, Mouse& mouse, Player& player) {

    if (coolTimer > 0) {
        coolTimer--;
    }

    // Shoot one bullet per click
    if (gun.isShot && coolTimer <= 0) {

        for (int i = 0; i < 5; i++) {

            // find empty slot
            if (!isHit[i]) {

                // set initial position
                pos[i].x = player.pos.x + player.radius.x;
                pos[i].y = player.pos.y + player.radius.y;

                // calc direction
                Vector2F dir;
                dir.x = mouse.pos.x - pos[i].x;
                dir.y = mouse.pos.y - pos[i].y;

                float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
                if (len != 0.0f) {
                    dir.x /= len;
                    dir.y /= len;
                }

                // set velocity
                vel[i].x = dir.x * speed.x;
                vel[i].y = dir.y * speed.y;

                this->angle[i] = gun.angle;
                isHit[i] = true;

                coolTimer = kCoolTime;
                break;
            }
        }
    }

    // bullet movement
    for (int i = 0; i < 5; i++) {
        if (isHit[i]) {
            pos[i].x += vel[i].x;
            pos[i].y += vel[i].y;

            // boundary check
            if (pos[i].x < 0.0f || pos[i].x > 1280.0f ||
                pos[i].y < 0.0f || pos[i].y > 720.0f) {

                isHit[i] = false;
            }
        }
    }
}

void Bullet::Draw(Gun gun) {
    for (int i = 0; i < 5; ++i) {
        if (gun.isShot) {
            Novice::DrawBox(
                (int)this->pos[i].x,
                (int)this->pos[i].y,
                (int)this->size.x,
                (int)this->size.y,
                this->angle[i],
                this->color,
                kFillModeSolid
            );
        }
    }
};