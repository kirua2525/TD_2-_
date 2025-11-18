#include "player.h"
#include "mouse.h"
#include "gun.h"

void Gun::Initialize(
	Vector2F gunPos,
	Vector2F gunSize,
	Vector2F gunRadius,
	float gunAngle,
	int gunColor,
	//int gunTexture,
	//int gunLeftTexture,
	//int gunRightTexture,
	int gunDamage,
	int gunMinDamage,
	int gunMaxDamage,
	bool gunIsShot
){ 
	this->pos = gunPos;
	this->size = gunSize;
	this->radius = gunRadius;
	this->angle = gunAngle;
	this->color = gunColor;
	//this->texture = gunTexture;
	//this->texture = gunLeftTexture;
	//this->texture = gunRightTexture;
	this->damage = gunDamage;
	this->maxDamage = gunMaxDamage;
	this->minDamage = gunMinDamage;
	this->isShot = gunIsShot;
}

Gun::~Gun(){}

void Gun::Update(Player player, Mouse mouse) {

	this->pos.x = player.pos.x + player.radius.x;
	this->pos.y = player.pos.y + player.radius.y;
	//if(player.texture = player.leftTexture){
	//this->texture = this->leftTexture;
	//}else if(player.texture = player.rightTexture){
	//this->texture = this->rightTexture;
	//}

	Novice::GetMousePosition(&mouse.pos.x, &mouse.pos.y);

	float dx = mouse.pos.x - this->pos.x;
	float dy = mouse.pos.y - this->pos.y;

	this->angle = atan2f(dy, dx);

	//if (player.texture = player.leftTexture) {
	//	 mouse.pos.x <= player.pos.x;
	//}else if (player.texture = player.rightTexture) {
	//	 mouse.pos.x >= player.pos.x;
	//}

	if (Novice::IsPressMouse(0)) {
		this->isShot = true;
	}
	if (player.currentWeapon != Player::weaponType::GUN) {
		this->isShot = false;
	}

}

void Gun::Draw() {
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