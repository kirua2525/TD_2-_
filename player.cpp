#include "player.h"

//Constructor
void Player::Initialize(
	Vector2F playerPos,
	Vector2F playerVelocity,
	Vector2F playerSize,
	Vector2F playerRadius,
	float playerAngle,
	unsigned int playerColor,
	//int playerTexture,
	//int playerleftTexture,
	//int playerrightTexture,
	float playerJumpSpeed,
	bool playerAlive,
	bool playerVisible,
	bool playerJumping,
	bool playerMoving,
	bool playerOnGround,
	bool playerWPressed,
	bool playerUpPressed,
	bool playerSpacePressed,
	weaponType playerCurrentWeapon
) {
	this->pos = playerPos;
	this->velocity = playerVelocity;
	this->size = playerSize;
	this->radius = playerRadius;
	this->angle = playerAngle;
	this->color = playerColor;
	//this->texture = playerTexture;
	//this->leftTexture = playerleftTextureHandle;
	//this->rightTexture = playerrightTextureHandle;
	this->jumpSpeed = playerJumpSpeed;
	this->isAlive = playerAlive;
	this->isVisible = playerVisible;
	this->isjumping = playerJumping;
	this->isMoving = playerMoving;
	this->isOnGround = playerOnGround;
	this->wPressed = playerWPressed;
	this->upPressed = playerUpPressed;
	this->spacePressed = playerSpacePressed;
	this->currentWeapon = playerCurrentWeapon;
}

void Player::Gravity() {
	this->velocity.y += 0.5f; // Gravity
}

void Player::Update(const char* keys, const char* prekeys) {
	//left
	if(keys[DIK_A]||keys[DIK_LEFT]) {
		this->pos.x -= this->velocity.x;
		//this->texture = this->leftTexture;
	}
	//right
	if(keys[DIK_D]||keys[DIK_RIGHT]) {
		this->pos.x += this->velocity.x;
		//this->texture = this->rightTexture;
	}

	if (this->pos.x <= 0) {
		this->pos.x = 0;
	}
	
	//if Previous frame = false && if current frame = true && isOnGrund = true
	this->wPressed = (!prekeys[DIK_W] && keys[DIK_W]);
	this->upPressed = (!prekeys[DIK_UP] && keys[DIK_UP]);
	this->spacePressed = (!prekeys[DIK_SPACE] && keys[DIK_SPACE]);

	//jump
	if (this->isOnGround) {
		if (wPressed || upPressed) {
		this->velocity.y = -this->jumpSpeed;
		this->isOnGround = false;
	}
	}

	Player::Gravity();
	this->pos.y += this->velocity.y;
	if(this->pos.y >= 600.0f) { // Ground collision
		this->pos.y = 600.0f;
		this->velocity.y = 0.0f;
		this->isOnGround = true;
	}
	//1 = Sword, 2 = Gun, 3 = Special Item
	bool pressed1 = (!prekeys[DIK_1] && keys[DIK_1]);
	bool pressed2 = (!prekeys[DIK_2] && keys[DIK_2]);
	bool pressed3 = (!prekeys[DIK_3] && keys[DIK_3]);

	if (pressed1) {
		this->currentWeapon = SWORD;
	}
	else if (pressed2) {
		this->currentWeapon = GUN;
	}
	else if (pressed3) {
		this->currentWeapon = SPECIAL_ITEM;
	}


	//Processing for each weapon
	switch (this->currentWeapon) {
	case SWORD:
		if (this->spacePressed) {
			//boss
		}
		break;

	case GUN:
		if (this->spacePressed) {
			//boss
		};
		break;

	case SPECIAL_ITEM:
		if (this->spacePressed) {
			//boss
		}
		break;
	}
}

void Player::Draw() {
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

void Player::debugDraw() {
	Novice::ScreenPrintf(0, 0, "Player Position: (%.2f, %.2f)", this->pos.x, this->pos.y);
	Novice::ScreenPrintf(0, 20, "Velocity: (%.2f, %.2f)", this->velocity.x, this->velocity.y);
	Novice::ScreenPrintf(0, 40, "On Ground: %s", this->isOnGround ? "true" : "false");
	Novice::ScreenPrintf(0, 60, "jumpSpeed: %.2f", this->jumpSpeed);
	Novice::ScreenPrintf(0, 80, "Alive: %s", this->isAlive ? "true" : "false");
	Novice::ScreenPrintf(0, 100, "Moving: %s", this->isMoving ? "true" : "false");
	Novice::ScreenPrintf(0, 120, "Jumping: %s", this->isjumping ? "true" : "false");
	const char* weaponName =
		this->currentWeapon == SWORD ? "Sword" :
		this->currentWeapon == GUN ? "Gun" :
		this->currentWeapon == SPECIAL_ITEM ? "Special Item" : "None";
	Novice::ScreenPrintf(0, 140, "Current Weapon: %s", weaponName);
}

void Player::Damage(float damageAmount) {
	this->hp -= damageAmount;
	if(this->hp < this->minHp) {
		this->hp = this->minHp;
		this->isAlive = false;
	}
}

void Player::Heal(float healAmount) {
	this->hp += healAmount;
	if(this->hp > this->maxHp) {
		this->hp = this->maxHp;
	}
}

void Player::SetWeapon(weaponType newWeapon) {
	this->isAttackSword = (newWeapon == SWORD);
	this->isAttackGun = (newWeapon == GUN);
	this->isAttackSpecialItem = (newWeapon == SPECIAL_ITEM);
}

void Player::resetStatus() {
	this->pos = Vector2F{ 100.0f, 600.0f };
	this->hp = this->maxHp;
	this->isAlive = true;
	this->isVisible = true;
	this->isjumping = false;
	this->isMoving = false;
	this->isOnGround = true;
	this->velocity = Vector2F{0.0f, 0.0f};
}