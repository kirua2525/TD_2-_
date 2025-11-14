#include "specialWeapon.h"

void SpecialWeapon::Initialize(
	Vector2 specialWeaponPos,
	Vector2 specialWeaponSize,
	float specialWeaponAngle,
	int specialWeaponColor,
	//int specialWeaponTexture,
	int specialWeaponDamage,
	int specialWeaponMinDamage,
	int specialWeaponMaxDamage,
	bool specialWeaponIsHit
) {
	this->pos = specialWeaponPos;
	this->size = specialWeaponSize;
	this->angle = specialWeaponAngle;
	this->color = specialWeaponColor;
	//this->texture = specialWeaponTexture;
	this->damage = specialWeaponDamage;
	this->maxDamage = specialWeaponMaxDamage;
	this->minDamage = specialWeaponMinDamage;
	this->isHit = specialWeaponIsHit;
}

void SpecialWeapon::Damage() {
	if (this->isHit == true) {

	}
}

void SpecialWeapon::Update() {

}

void SpecialWeapon::Draw() {
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