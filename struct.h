#pragma once

struct Vector2F {
	float x, y;
};

struct Vector2I {
	int x, y;
};

typedef struct Transform {
	Vector2F pos_;
	Vector2F speed_;
	Vector2F radius_;
	float angle;
	int color;
}Transform;

typedef struct MousePos {
	Vector2I pos_;
}MousePos;