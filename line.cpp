#include <Novice.h>
#include "line.h"

void Line::Initialize(
	Vector2F lineTopPos,
	Vector2F lineUnderPos,
	float lineAngle,
	bool lineIsHitLine
) {
	this->topPos = lineTopPos;
	this->underPos = lineUnderPos;
	this->angle = lineAngle;
	this->isHitLine = lineIsHitLine;
}

void Line::Update() {

	this->underPos.x = this->topPos.x;
}