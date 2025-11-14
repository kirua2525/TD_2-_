#include "player.h"
#include "sword.h"

void Sword::Initialize(
	Vector2 swordPos,
	Vector2 swordSize,
	float swordAngle,
	float swordAngleRotate,
	int swordColor,
	//int swordTexture,
	float swordDamage,
	float swordMinDamage,
	float swordMaxDamage,
	bool swordIsHit
) {
	this->pos = swordPos;
	this->size = swordSize;
	this->angle = swordAngle;
	this->angleRotate = swordAngleRotate;
	this->color = swordColor;
	//this->texture = swordTexture;
	this->damage = swordDamage;
	this->maxDamage = swordMaxDamage;
	this->minDamage = swordMinDamage;
	this->isHit = swordIsHit;
}

void Sword::Update() {

}

void Sword::Draw() {
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