#include "mouse.h"

void Mouse::invisible() {
	this->visibility ^= 1;
	Novice::SetMouseCursorVisibility(0);
}

void Mouse::GetPos() {
	Novice::GetMousePosition(&this->pos.x, &this->pos.y);
}

void Mouse::Initialize(
	Vector2F mouseSize,
	Vector2F mouseRadius,
	float mouseAngle,
	int mouseColor
) {
	this->size = mouseSize;
	this->radius = mouseRadius;
	this->angle = mouseAngle;
	this->color = mouseColor;
}

Mouse::~Mouse(){}

void Mouse::Update(Gun gun) {

	Mouse::GetPos();

	// Clamp X
	if (this->pos.x - (int)this->radius.x <= 0) {
		this->pos.x = 0 + (int)this->radius.x;
	}
	else if (this->pos.x + (int)this->radius.x >= 1280) {
		this->pos.x = 1280 - (int)this->radius.x;
	}

	// Clamp Y
	if (this->pos.y - (int)this->radius.y <= 0) {
		this->pos.y = 0 + (int)this->radius.y;
	}
	else if (this->pos.y + (int)this->radius.y >= 720) {
		this->pos.y = 720 - (int)this->radius.y;
	}

	if (Novice::IsPressMouse(0)) {
		gun.isShot = true;
	}
}


void Mouse::Draw() {
	Novice::DrawBox(
		this->pos.x - (int)this->radius.x,
		this->pos.y - (int)this->radius.y,
		(int)this->size.x,
		(int)this->size.y,
		this->angle,
		this->color,
		kFillModeSolid
	);
}