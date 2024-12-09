#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include <iostream>
#include <cstring>

using namespace std;

//�R���X�g���N�^
Character::Character(const char* name, int hp, int mp, int atk, int def)
{
    //���͂��ꂽ���O�ŏ�����
    m_name = new(nothrow) char[strlen(name) + 1];

    if (m_name != nullptr)
    {
        strcpy(m_name, name);
    }

    //hp�̏�����
    m_hp = hp;
    //mp�̏�����
    m_mp = mp;
    //atk�̏�����
    m_atk = atk;
    //def�̏�����
    m_def = def;
}

//�f�X�g���N�^
Character::~Character()
{
    if (m_name != nullptr)
    {
        delete[] m_name;
        m_name = nullptr;
    }
}

//�R�s�[�R���X�g���N�^
Character::Character(const Character& other)
{
    //���O�̃R�s�[
    m_name = new(nothrow) char[strlen(other.m_name) + 1];
    
    if (m_name != nullptr)
    {
        strcpy(m_name, other.m_name);
    }

    //hp�̃R�s�[
    m_hp = other.m_hp;
    //mp�̃R�s�[
    m_mp = other.m_mp;
    //atk�̃R�s�[
    m_atk = other.m_atk;
    //def�̃R�s�[
    m_def = other.m_def;
}

//������Z�q�̃I�[�o�[���[�h
void Character::operator=(const Character& other)
{
    delete[] m_name;

    //���O�̑��
    m_name = new(nothrow) char[strlen(other.m_name) + 1];

    if (m_name != nullptr)
    {
        strcpy(m_name, other.m_name);
    }

    //hp�̑��
    m_hp = other.m_hp;
    //mp�̑��
    m_mp = other.m_mp;
    //atk�̑��
    m_atk = other.m_atk;
    //def�̑��
    m_def = other.m_def;
}


int Character::GetAttack() const
{
    return m_atk;
}

int Character::GetDefense() const
{
    return m_def;
}

int Character::GetHp() const
{
    return m_hp;
}

int Character::GetMp() const
{
    return m_mp;
}

//���̍U��
void Character::SwordAttack(Character* character)
{
    character->SwordTakeDamage(character);

    cout << "���ōU�����܂���" << endl;
}

//���@�U��
void Character::MagicAttack(Character* character)
{
    if (m_mp > 10) {
        character->MagicTakeDamage(character);
        m_mp -= 10;

        cout << "���@���������܂���" << endl;
    }
    else
    {
        cout << "���@����������܂���ł���" << endl;
    }
}

//�U���󂯂��Ƃ�
void Character::SwordTakeDamage(Character *character)
{
    m_hp -= character->GetAttack() - m_def;

    cout << m_name << "��" << character->GetAttack() - m_def << "�_���[�W�󂯂܂���" << endl;
}

//���@�ōU���󂯂��Ƃ�
void Character::MagicTakeDamage(Character* character)
{
    m_hp -= character->GetAttack() + 10 - m_def;

    cout << m_name << "��" << character->GetAttack() + 10 - m_def << "�_���[�W�󂯂܂���" << endl;
}

//Hp�̉�
void Character::HpRecovery()
{
    m_hp += 20;
    cout << "HP��20�񕜂��܂���" << endl;
}

//Mp�̉�
void Character::MpRecovery()
{
    m_mp += 5;
    cout << "MP��5�񕜂��܂���" << endl;
}

//���\���֐�
void Character::Show()
{
    cout << "���O�F" << m_name << endl
        << "HP�F" << m_hp << endl
        << "MP�F" << m_mp << endl
        << "�U���́F" << m_atk << endl
        << "�h��́F" << m_def << endl;
}
