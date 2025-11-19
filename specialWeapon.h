#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "scroll.h"
#include "player.h"

class Player;
class Scroll;

class SpecialWeapon {
public:
    Vector2F pos;
    Vector2F size;
    Vector2F radius;
    float angle;
    float angleRotate;
    float coolTime;
    float defaultCoolTime; 
    float rotationDirection;
    int color;
    int damage;
    int minDamage;
    int maxDamage;
    bool isHit;
    bool isClockwise = true;

    ~SpecialWeapon();

public:
    void Initialize(
        Vector2F pos,
        Vector2F size,
        Vector2F radius,
        float angle,
        float angleRotate,
        float coolTime,
        int color,
        int damage,
        int minDamage,
        int maxDamage,
        bool isHit
    );

    void ReSetCoolTime();     
    void Damage(Player player);
    void Update(const Player& player, const char* keys);
    void Draw(Scroll scroll);
};