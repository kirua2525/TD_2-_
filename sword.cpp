#include "player.h"
#include "sword.h"

void Sword::Initialize(
	Vector2 swordPos,
	Vector2 swordSize,
	float swordAngle,
	int swordColor,
	int swordTexture,
	float swordDamage,
	float swordMinDamage,
	float swordMaxDamage
) {
	this->pos = swordPos;
	this->size = swordSize;
	this->angle = swordAngle;
	this->color = swordColor;
	this->texture = swordTexture;
	this->damage = swordDamage;
	this->maxDamage = swordMaxDamage;
	this->minDamage = swordMinDamage;
}

void Sword::Update() {

}

void Sword::Drow() {
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