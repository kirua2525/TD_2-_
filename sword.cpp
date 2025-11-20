#include "player.h"
#include "sword.h"



void Sword::Initialize(
	Vector2F swordPos,
	Vector2F swordSize,
	Vector2F swordRadius,
	float swordAngle,
	float swordAngleRotate,
	int swordColor,
	//int swordTexture,
	int swordDamage,
	int swordMinDamage,
	int swordMaxDamage,
	bool swordIsHit
) {
	this->pos = swordPos;
	this->size = swordSize;
	this->radius = swordRadius;
	this->angle = swordAngle;
	this->angleRotate = swordAngleRotate;
	this->color = swordColor;
	//this->texture = swordTexture;
	this->damage = swordDamage;
	this->maxDamage = swordMaxDamage;
	this->minDamage = swordMinDamage;
	this->isHit = swordIsHit;
}

Sword::~Sword() {}

void Sword::Damage() {
	if (this->isHit) {

	}
}

void Sword::Update(Player player, const char* keys) {

	this->pos.x = player.pos.x + player.radius.x;
	this->pos.y = player.pos.y + player.radius.y;
	this->pos.y = this->pos.y += this->radius.y / 2;

	if (keys[DIK_A]) {
		isClockwise = false;
	}
	if (keys[DIK_D]) {
		isClockwise = true;
	}

	if (isClockwise) {
		this->angle += this->angleRotate;
	}
	else {
		this->angle -= this->angleRotate;
	}
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