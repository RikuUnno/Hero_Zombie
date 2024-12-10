#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include <iostream>
#include <cstring>

using namespace std;

//コンストラクタ
Character::Character(const char* name, int hp, int mp, int atk, int def)
{
    //入力された名前で初期化
    m_name = new(nothrow) char[strlen(name) + 1];

    if (m_name != nullptr)
    {
        strcpy(m_name, name);
    }

    //hpの初期化
    m_hp = hp;
    //mpの初期化
    m_mp = mp;
    //atkの初期化
    m_atk = atk;
    //defの初期化
    m_def = def;
}

//デストラクタ
Character::~Character()
{
    if (m_name != nullptr)
    {
        delete[] m_name;
        m_name = nullptr;
    }
}

//コピーコンストラクタ
Character::Character(const Character& other)
{
    //名前のコピー
    m_name = new(nothrow) char[strlen(other.m_name) + 1];
    
    if (m_name != nullptr)
    {
        strcpy(m_name, other.m_name);
    }

    //hpのコピー
    m_hp = other.m_hp;
    //mpのコピー
    m_mp = other.m_mp;
    //atkのコピー
    m_atk = other.m_atk;
    //defのコピー
    m_def = other.m_def;
}

//代入演算子のオーバーロード
void Character::operator=(const Character& other)
{
    delete[] m_name;

    //名前の代入
    m_name = new(nothrow) char[strlen(other.m_name) + 1];

    if (m_name != nullptr)
    {
        strcpy(m_name, other.m_name);
    }

    //hpの代入
    m_hp = other.m_hp;
    //mpの代入
    m_mp = other.m_mp;
    //atkの代入
    m_atk = other.m_atk;
    //defの代入
    m_def = other.m_def;
}

char* Character::GetName() const
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

//剣の攻撃 character1には相手を入れてcharacter2には自分を入れる
void Character::SwordAttack(Character* character1, Character* character2)
{
    character1->SwordTakeDamage(character2);

    cout << "剣で攻撃しました" << endl;
    cout << endl;
}

//魔法攻撃 character1には相手を入れてcharacter2には自分を入れる
void Character::MagicAttack(Character* character1, Character* character2)
{
    if (m_mp > 10) {
        character1->MagicTakeDamage(character2);
        m_mp -= 10;

        cout << "魔法が発動しました" << endl;
    }
    else
    {
        cout << "魔法が発動されませんでした" << endl;
    }
    cout << endl;
}

//攻撃受けたとき
void Character::SwordTakeDamage(Character *character)
{
    m_hp -= character->GetAttack() - m_def;

    if (character->GetAttack() - m_def > 0)
    {
        cout << m_name << "は" << character->GetAttack() - m_def << "ダメージ受けました" << endl;
    }
    else
    {
        cout << m_name << "は" << '0' << "ダメージ受けました" << endl;
    }
}

//魔法で攻撃受けたとき
void Character::MagicTakeDamage(Character* character)
{
    m_hp -= character->GetAttack() + 15 - m_def;

    if (character->GetAttack() - m_def > 0)
    {
        cout << m_name << "は" << character->GetAttack() - m_def << "ダメージ受けました" << endl;
    }
    else
    {
        cout << m_name << "は" << '0' << "ダメージ受けました" << endl;
    }
}

//Hpの回復
void Character::HpRecovery()
{
    m_hp += 20;
    cout << m_name << "のHPが20回復しました" << endl;
}

//Mpの回復
void Character::MpRecovery()
{
    m_mp += 5;
    cout << m_name << "のMPが5回復しました" << endl;
}

//情報表示関数
void Character::Show()
{
    cout << "名前：" << m_name << endl
        << "HP：" << m_hp << endl
        << "MP：" << m_mp << endl
        << "攻撃力：" << m_atk << endl
        << "防御力：" << m_def << endl;
}
