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
	bool playerMoveRight,
	bool playerMoveLeft,
	weaponType playerCurrentWeapon,
	float playerFrameCount,
	float playerEndFrame,
	bool playerEasingActive,
	bool playerFacingRight
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
	this->moveRight = playerMoveRight;
	this->moveLeft = playerMoveLeft;
	this->currentWeapon = playerCurrentWeapon;
	this->frameCount = playerFrameCount;
	this->endFrame = playerEndFrame;
	this->easingActive = playerEasingActive;
	this->facingRight = playerFacingRight;
}

Player::~Player(){}

void Player::Gravity() {
	if (this->currentWeapon == Player::weaponType::SPECIAL_ITEM) {
		this->velocity.y += 0.7f;
	}else {
		this->velocity.y += 0.5f; // Gravity
	}
}

void Player::EaseInQuadRight() {
	float t = this->frameCount / (this->endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x + 500.0f;
	}

	float c = this->targetX - this->startX;

	this->pos.x = c * (t * t) + this->startX;
}

void Player::EaseInQuadLeft() {
	float t = this->frameCount / (this->endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x - 500.0f;
	}

	float c = this->targetX - this->startX;

	this->pos.x = c * (t * t) + this->startX;

	if (this->pos.x <= 0) {
		this->pos.x = 0;
	}
}

void Player::EaseInExpoRight() {
	float t = frameCount / (endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x + 500.0f;
	}

	float c = targetX - startX;

	if (t == 0.0f) {
		this->pos.x = startX;
	}	else {
		this->pos.x = c * powf(2.0f, 10.0f * (t - 1.0f)) + startX;
	}
}

void Player::EaseInExpoLeft() {
	float c = startX - targetX;
	float t = frameCount / (endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x - 500.0f;
	}

	if (t == 0.0f) {
		this->pos.x = startX;
	}else {
		this->pos.x = startX - c * powf(2.0f, 10.0f * (t - 1.0f));
	}

	if (this->pos.x <= 0) {
		this->pos.x = 0;
	}
}

void Player::EaseInOutExpoRight() {
	float c = targetX - startX;
	float t = frameCount / (endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x + 500.0f;
	}

	if (t == 0.0f) {
		this->pos.x = startX;
	}
	else if (t == 1.0f) {
		this->pos.x = targetX;
	}
	else if (t < 0.5f) {
		this->pos.x = startX + (c / 2.0f) * powf(2.0f, (20.0f * t) - 10.0f);
	}
	else {
		this->pos.x = startX + (c / 2.0f) * (2.0f - powf(2.0f, (-20.0f * t) + 10.0f));
	}
}

void Player::EaseInOutExpoLeft() {
	float t = frameCount / (endFrame - 1);
	if (t > 1.0f) t = 1.0f;

	if (this->frameCount == 0) {
		this->startX = this->pos.x;
		this->targetX = this->pos.x - 500.0f;
	}

	float c = startX - targetX;

	if (t == 0.0f) {
		this->pos.x = startX;
	}
	else if (t == 1.0f) {
		this->pos.x = targetX;
	}
	else if (t < 0.5f) {
		this->pos.x = startX - (c / 2.0f) * powf(2.0f, (20.0f * t) - 10.0f);
	}
	else {
		this->pos.x = startX - (c / 2.0f) * (2.0f - powf(2.0f, (-20.0f * t) + 10.0f));
	}

	if (this->pos.x <= 0) {
		this->pos.x = 0;
	}
}

void Player::Update(const char* keys, const char* prekeys) {
	//left

	this->moveRight = keys[DIK_D] || keys[DIK_RIGHT] != 0;
	this->moveLeft = keys[DIK_A] || keys[DIK_LEFT] != 0;
	if(this->moveLeft) {
		this->pos.x -= this->velocity.x;
		//this->texture = this->leftTexture;
	}
	//right
	if(this->moveRight) {
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

	if (moveRight) {
		facingRight = true;
	}
	if (moveLeft) {
		facingRight = false;
	}

	//Processing for each weapon
	switch (this->currentWeapon) {
	case SWORD:
		if (this->isAttackSword) {
			//boss
		}
		if (this->spacePressed) {
			this->easingActive = true;
			this->frameCount = 0;
		}

		if (this->easingActive && this->frameCount < this->endFrame) {
			if (this->facingRight) {

				EaseInQuadRight();

			}else{

				EaseInQuadLeft();

			}
			this->frameCount++;
		}

		break;

	case GUN:
		if (this->isAttackGun) {
			//boss
		};

		if (this->spacePressed) {
			this->easingActive = true;
			this->frameCount = 0;
		}

		if (this->easingActive && this->frameCount < this->endFrame) {
			if (this->facingRight) {

				EaseInOutExpoRight();

			}
			else {

				EaseInOutExpoLeft();

			}
			this->frameCount++;
		}

		break;

	case SPECIAL_ITEM:
		if (this->isAttackSpecialItem) {
			//boss
		}

		if (this->spacePressed) {
			this->easingActive = true;
			this->frameCount = 0;
		}

		if (this->easingActive && this->frameCount < this->endFrame) {
			if (this->facingRight) {

				EaseInExpoRight();

			}
			else {

				EaseInExpoLeft();

			}
			this->frameCount++;
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