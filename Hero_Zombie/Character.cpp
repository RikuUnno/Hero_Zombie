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

const char* Character::GetName() const
{
    return m_name;
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
void Character::SwordAttack(Character* character1)
{
    character1->SwordTakeDamage(this);

    cout << "���ōU�����܂���" << endl;
    cout << endl;
}

//���@�U�� 
void Character::MagicAttack(Character* character1)
{
    if (m_mp > 10) {
        character1->MagicTakeDamage(this);
        m_mp -= 10;

        cout << "���@���������܂���" << endl;
    }
    else
    {
        cout << "���@����������܂���ł���" << endl;
    }
    cout << endl;
}

//�U���󂯂��Ƃ�
void Character::SwordTakeDamage(Character *character)
{
    m_hp -= character->GetAttack() - m_def;

    if (character->GetAttack() - m_def > 0)
    {
        cout << m_name << "��" << character->GetAttack() - m_def << "�_���[�W�󂯂܂���" << endl;

       
    }
    else
    {
        cout << m_name << "��" << '0' << "�_���[�W�󂯂܂���" << endl;
    }

    cout << m_name << "�̗̑͂�" << m_hp << endl;
}

//���@�ōU���󂯂��Ƃ�
void Character::MagicTakeDamage(Character* character)
{
    m_hp -= character->GetAttack() + 15 - m_def;

    if (character->GetAttack() - m_def > 0)
    {
        cout << m_name << "��" << character->GetAttack() - m_def << "�_���[�W�󂯂܂���" << endl;
    }
    else
    {
        cout << m_name << "��" << '0' << "�_���[�W�󂯂܂���" << endl;
    }

    cout << m_name << "�̗̑͂�" << m_hp << endl;
}

//Hp�̉�
void Character::HpRecovery()
{
    m_hp += 20;
    cout << m_name << "��HP��20�񕜂��܂���" << endl;
}

//Mp�̉�
void Character::MpRecovery()
{
    m_mp += 5;
    cout << m_name << "��MP��5�񕜂��܂���" << endl;
}

//���\���֐�
void Character::Show() const
{
    cout << "���O�F" << m_name << endl
        << "HP�F" << m_hp << endl
        << "MP�F" << m_mp << endl
        << "�U���́F" << m_atk << endl
        << "�h��́F" << m_def << endl;
}
