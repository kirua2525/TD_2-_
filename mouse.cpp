#include "mouse.h"

void Mouse::invisible() {
	this->visibility ^= 1;
	Novice::SetMouseCursorVisibility(0);
}

void Mouse::GetPos() {
	Novice::GetMousePosition(&this->pos.x, &this->pos.y);
}

void Mouse::Draw() {
	Novice::DrawEllipse(
		this->pos.x,
		this->pos.y,
		this->size.x,
		this->size.y,
		this->angle,
		this->color,
		kFillModeSolid
	);
}