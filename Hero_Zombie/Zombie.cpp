#include "Zombie.h"

using namespace std;

//�R���X�g���N�^ //�R���X�g���N�^���Ă΂ꂽ���̈����̂̓��e��Character�̃R���X�g���N�^�ɂ킽�����
Zombie::Zombie(const char* name, int hp, int mp, int atk, int def) : Character(name, hp, mp, atk, def)
{}

//�̗͂̔��f
void Zombie::HpJudgment()
{
	if (m_hp < 5)
	{
		HpRecovery();
	}
}

//MP�̔��f
void Zombie::MpJudgment()
{
	if (m_mp > 10)
	{
		MpRecovery();
	}
}

//Zombie�Ɉ�^�[�����Ƃɑ̗͂��T�񕜂���
void Zombie::HpPeriodicRecovery()
{
	m_hp += 1;
}