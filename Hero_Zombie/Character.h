#pragma once

class Character
{
public:
	char* m_name;	//���O
	int m_hp;		//�̗�
	int m_mp;		//�}�i
	int m_atk;		//�U����
	int m_def;		//�h���

public:
	//�R���X�g���N�^
	Character(const char* name, int hp, int mp, int atk, int def);
	//�f�X�g���N�^
	~Character();
	//�R�s�[�R���X�g���N�^
	Character(const Character& other);
	//������Z�q�̃I�[�o�[���[�h
	void operator=(const Character& other);

public:
	//m_atk��Ԃ��֐�
	int GetAttack() const;
	//m_def��Ԃ��֐�
	int GetDefense() const;
	//m_hp��Ԃ��֐�
	int GetHp() const;
	//m_mp��Ԃ��֐�
	int GetMp() const;

public:
	//���̍U��
	void SwordAttack(Character* character);
	//���@�U��
	void MagicAttack(Character* character);
	//���ōU���󂯂��Ƃ�
	void SwordTakeDamage(Character* character);
	//���@�ōU���󂯂��Ƃ�
	void MagicTakeDamage(Character* character);
	//Hp�̉�
	void HpRecovery();
	//Mp�̉�
	void MpRecovery();
	//���\���֐�
	void Show();
	
};
