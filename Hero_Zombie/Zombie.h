#pragma once
#include "Character.h"

class Zombie:
	public Character
{
public:
	//�R���X�g���N�^
	Zombie(const char* name, int hp, int mp, int atk, int def);
	
public:
	//�̗͂̔��f
	void HpJudgment();
	//MP�̔��f
	void MpJudgment();
	//Zombie�Ɉ�^�[�����Ƃɑ̗͂��T�񕜂���
	void HpPeriodicRecovery();

};