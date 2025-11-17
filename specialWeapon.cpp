#include "specialWeapon.h"

void SpecialWeapon::Initialize(
    Vector2F specialWeaponPos,
    Vector2F specialWeaponSize,
    Vector2F specialWeaponRadius,
    float specialWeaponAngle,
    float specialWeaponAngleRotate,
    float specialWeaponCoolTime,
    int specialWeaponColor,
    int specialWeaponDamage,
    int specialWeaponMinDamage,
    int specialWeaponMaxDamage,
    bool specialWeaponIsHit
) {
    this->pos = specialWeaponPos;
    this->size = specialWeaponSize;
    this->radius = specialWeaponRadius;
    this->angle = specialWeaponAngle;
    this->angleRotate = specialWeaponAngleRotate;

    this->coolTime = specialWeaponCoolTime;
    this->defaultCoolTime = specialWeaponCoolTime;

    this->color = specialWeaponColor;
    this->damage = specialWeaponDamage;
    this->minDamage = specialWeaponMinDamage;
    this->maxDamage = specialWeaponMaxDamage;
    this->isHit = specialWeaponIsHit;
}

SpecialWeapon::~SpecialWeapon(){}

void SpecialWeapon::ReSetCoolTime() {
    this->coolTime = this->defaultCoolTime;
}

void SpecialWeapon::Damage(Player player) {
    if (this->isHit) {

        player.currentWeapon = Player::weaponType::SWORD;

        this->coolTime--;

        if (this->coolTime <= 0) {
            this->ReSetCoolTime();
        }

        this->isHit = false;
    }
}

void SpecialWeapon::Update(Player player) {

    this->pos.x = player.pos.x + player.radius.x;
    this->pos.y = player.pos.y + player.radius.y;

    this->angle += this->angleRotate;
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