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
    bool bulletIsActive,
	bool bulletIsHit
) {
    for (int i = 0; i < 5; i++) {
        this->pos[i] = bulletPos;
        this->initialPos[i] = bulletPos;
        this->size = bulletSize;
        this->speed = bulletSpeed;
        this->radius = bulletRadius;
        this->vel[i] = bulletvel;
        this->angle[i] = bulletAngle;
        this->damage = bulletdamage;
        this->color = bulletColor;
        //this->texture = bulletTexture;
        this->isActive[i] = bulletIsActive;
        this->isHit[i] = bulletIsHit;
    }
}

Bullet::~Bullet(){}

void Bullet::ReSet(Player player, Gun gun) {
    for (int i = 0; i < 5; i++) {
        // Reset bullet position to player position
        this->pos[i].x = player.pos.x + player.radius.x;
        this->pos[i].y = player.pos.y + player.radius.y;

        // Reset velocity
        this->vel[i] = { 0.0f, 0.0f };

        // Mark bullet as not shot
        this->isHit[i] = false;
        this->isActive[i] = false;

        // Optional: reset individual bullet angle to gun angle
        this->angle[i] = gun.angle;
    }
}

void Bullet::Update(Gun& gun, Mouse& mouse, Player& player) {
    // Cooldown timer decrement
    if (this->coolTimer > 0) {
        this->coolTimer--;
    }

    // Update bullets that have not been shot yet
    for (int i = 0; i < 5; i++) {
        if (!this->isHit[i]) {
            // Follow the player position
            this->pos[i].x = player.pos.x + player.radius.x;
            this->pos[i].y = player.pos.y + player.radius.y;
        }
    }

    // Shoot a bullet if gun is shot and cooldown is over
    if (gun.isShot && this->coolTimer <= 0) {
        for (int i = 0; i < 5; i++) {
            if (!this->isHit[i]) {
                // Calculate direction toward mouse
                Vector2F dir = { mouse.pos.x - this->pos[i].x, mouse.pos.y - this->pos[i].y };
                float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
                if (len != 0.0f) {
                    dir.x /= len;
                    dir.y /= len;
                }

                // Set velocity and angle
                this->vel[i].x = dir.x * this->speed.x;
                this->vel[i].y = dir.y * this->speed.y;
                this->angle[i] = gun.angle;

                // Mark bullet as shot
                this->isHit[i] = true;
                this->isActive[i] = true;

                // Reset cooldown timer
                this->coolTimer = this->kCoolTime;
                break;
            }
        }
    }

    // Move active bullets
    for (int i = 0; i < 5; i++) {
        if (this->isHit[i]) {
            this->pos[i].x += this->vel[i].x;
            this->pos[i].y += this->vel[i].y;

            // Reset bullet if it goes out of screen bounds
            if (this->pos[i].x < 0.0f || this->pos[i].x > 1280.0f ||
                this->pos[i].y < 0.0f || this->pos[i].y > 720.0f) {
                this->isHit[i] = false;
                this->isActive[i] = false;
                this->vel[i] = { 0.0f, 0.0f };
            }
        }
    }
}

void Bullet::Draw() {
    for (int i = 0; i < 5; i++) {
        // Draw bullets that are either active or not yet shot
        if (!this->isHit[i] || this->isActive[i]) {
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
}
