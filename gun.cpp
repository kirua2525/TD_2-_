#include "player.h"
#include "gun.h"

void Gun::Initialize(
	Vector2 gunPos,
	Vector2 gunSize,
	float gunAngle,
	int gunColor,
	int gunTexture,
	float gunDamage,
	float gunMinDamage,
	float gunMaxDamage
){ 
	this->pos = gunPos;
	this->size = gunSize;
	this->angle = gunAngle;
	this->color = gunColor;
	this->texture = gunTexture;
	this->damage = gunDamage;
	this->maxDamage = gunMaxDamage;
	this->minDamage = gunMinDamage;
}

void Gun::Update() {

}

void Gun::Drow() {
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