#pragma once

class Character
{
public:
	char* m_name;	//名前
	int m_hp;		//体力
	int m_mp;		//マナ
	int m_atk;		//攻撃力
	int m_def;		//防御力

public:
	//コンストラクタ
	Character(const char* name, int hp, int mp, int atk, int def);
	//デストラクタ
	~Character();
	//コピーコンストラクタ
	Character(const Character& other);
	//代入演算子のオーバーロード
	void operator=(const Character& other);

public:
	//m_atkを返す関数
	int GetAttack() const;
	//m_defを返す関数
	int GetDefense() const;
	//m_hpを返す関数
	int GetHp() const;
	//m_mpを返す関数
	int GetMp() const;

public:
	//剣の攻撃
	void SwordAttack(Character* character);
	//魔法攻撃
	void MagicAttack(Character* character);
	//剣で攻撃受けたとき
	void SwordTakeDamage(Character* character);
	//魔法で攻撃受けたとき
	void MagicTakeDamage(Character* character);
	//Hpの回復
	void HpRecovery();
	//Mpの回復
	void MpRecovery();
	//情報表示関数
	void Show();
	
};
