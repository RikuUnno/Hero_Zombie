#pragma once
#include "Character.h"

class Hero:
	public Character
{
public:
	//コンストラクタ
	Hero(const char* name, int hp, int mp, int atk, int def);

public:
	//体力の判断
	void HpJudgment();
	//MPの判断
	void MpJudgment();
	//Heroは一ターンごとに体力を５回復する
	void MpPeriodicRecovery();
};
