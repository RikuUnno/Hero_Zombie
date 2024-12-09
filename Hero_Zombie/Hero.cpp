#include "Hero.h"

using namespace std;

Hero::Hero(const char* name, int hp, int mp, int atk, int def) : Character(name, hp, mp, atk, def)
{}

//‘Ì—Í‚Ì”»’f
void Hero::HpJudgment()
{
	if (m_hp < 8)
	{
		HpRecovery();
	}
}

//MP‚Ì”»’f
void Hero::MpJudgment()
{
	if (m_mp > 10)
	{
		MpRecovery();
	}
}

//Hero‚Íˆêƒ^[ƒ“‚²‚Æ‚É‘Ì—Í‚ğ‚T‰ñ•œ‚·‚é
void Hero::MpPeriodicRecovery()
{
	m_mp += 5;
}