#include "Hero.h"

using namespace std;

Hero::Hero(const char* name, int hp, int mp, int atk, int def) : Character(name, hp, mp, atk, def)
{}

//�̗͂̔��f
void Hero::HpJudgment()
{
	if (m_hp < 8)
	{
		HpRecovery();
	}
}

//MP�̔��f
void Hero::MpJudgment()
{
	if (m_mp > 10)
	{
		MpRecovery();
	}
}

//Hero�͈�^�[�����Ƃɑ̗͂��T�񕜂���
void Hero::MpPeriodicRecovery()
{
	m_mp += 5;
}