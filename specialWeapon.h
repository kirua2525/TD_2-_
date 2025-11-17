#pragma once

#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "player.h"

class Player;

class SpecialWeapon {
public:
    Vector2F pos;
    Vector2F size;
    Vector2F radius;
    float angle;
    float angleRotate;
    float coolTime;
    float defaultCoolTime; 
    int color;
    int damage;
    int minDamage;
    int maxDamage;
    bool isHit;

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
    void Update(Player player);
    void Draw();
};