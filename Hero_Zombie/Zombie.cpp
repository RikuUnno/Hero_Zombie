#include "Zombie.h"

using namespace std;

//コンストラクタ //コンストラクタが呼ばれた時の引数のの内容がCharacterのコンストラクタにわたされる
Zombie::Zombie(const char* name, int hp, int mp, int atk, int def) : Character(name, hp, mp, atk, def)
{}

//体力の判断
void Zombie::HpJudgment()
{
	if (m_hp < 5)
	{
		HpRecovery();
	}
}

//MPの判断
void Zombie::MpJudgment()
{
	if (m_mp > 10)
	{
		MpRecovery();
	}
}

//Zombieに一ターンごとに体力を５回復する
void Zombie::HpPeriodicRecovery()
{
	m_hp += 1;
}