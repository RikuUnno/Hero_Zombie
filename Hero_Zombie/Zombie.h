#pragma once
#include "Character.h"

class Zombie:
	public Character
{
public:
	//コンストラクタ
	Zombie(const char* name, int hp, int mp, int atk, int def);
	
public:
	//体力の判断
	void HpJudgment();
	//MPの判断
	void MpJudgment();
	//Zombieに一ターンごとに体力を５回復する
	void HpPeriodicRecovery();

};