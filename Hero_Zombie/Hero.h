#pragma once
#include "Character.h"

class Hero:
	public Character
{
public:
	//�R���X�g���N�^
	Hero(const char* name, int hp, int mp, int atk, int def);

public:
	//�̗͂̔��f
	void HpJudgment();
	//MP�̔��f
	void MpJudgment();
	//Hero�͈�^�[�����Ƃɑ̗͂��T�񕜂���
	void MpPeriodicRecovery();
};
