#include "Hero.h"

using namespace std;

Hero::Hero(const char* name, int hp, int mp, int atk, int def) : Character(name, hp, mp, atk, def)
{}

//体力の判断
void Hero::HpJudgment()
{
	if (m_hp < 8)
	{
		HpRecovery();
	}
}

//MPの判断
void Hero::MpJudgment()
{
	if (m_mp > 8)
	{
		MpRecovery();
	}
}

//Heroは一ターンごとに体力を５回復する
void Hero::MpPeriodicRecovery()
{
	m_mp += 10;
}