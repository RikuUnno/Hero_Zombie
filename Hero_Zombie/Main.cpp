#include "Zombie.h"
#include "Hero.h"
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

using namespace std;

int main() {
    // ランダムシードを設定
    srand(static_cast<unsigned>(time(0)));

    // キャラクターの初期化
    Zombie zombie("Zombie", 50, 20, 10, 5);
    Hero hero("Hero", 50, 20, 15, 7);

    Character& zombieChar = zombie;
    Character& heroChar = hero;

    cout << "ゲームスタート！" << endl;

    // 初期状態を表示
    cout << endl << "初期状態:" << endl;
    cout << "ゾンビ" << endl;
    heroChar.Show();
    cout << endl;
    cout << "ヒーロー" << endl;
    heroChar.Show();
    cout << endl;

    // ターン制バトル
    int turn = 1;
    while (zombieChar.GetHp() > 0 && heroChar.GetHp() > 0) {
        cout << "=== ターン " << turn << " ===" << endl;

        // ヒーローの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
            cout << "ヒーローの攻撃！剣で攻撃します。" << endl;
            heroChar.SwordAttack(&zombie);
        }
        else { // 50%の確率で魔法攻撃
            cout << "ヒーローの攻撃！魔法を発動します。" << endl;
            heroChar.MagicAttack(&zombie);
        }
        if (heroChar.GetHp() <= 0) {
            cout << "ゾンビは倒れた！ヒーローの勝利！" << endl;
            break;
        }

        // ゾンビの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
            cout << "ゾンビの攻撃！剣で攻撃します。" << endl;
            zombieChar.SwordAttack(&hero);
        }
        else { // 50%の確率で魔法攻撃
            cout << "ゾンビの攻撃！魔法を発動します。" << endl;
            zombieChar.MagicAttack(&hero);
        }
        if (heroChar.GetHp() <= 0) {
            cout << "ヒーローは倒れた！ゾンビの勝利！" << endl;
            break;
        }

        // 回復処理
        hero.HpJudgment();
        hero.MpJudgment();
        zombie.HpJudgment();
        zombie.MpJudgment();

        // 状態表示
        cout << endl << "現在の状態:" << endl;
        cout << "ゾンビ" << endl;
        zombieChar.Show();
        cout << endl;
        cout << "ヒーロー" << endl;
        heroChar.Show();
        cout << endl;

        // 次のターンへ
        turn++;
    }

    cout << "ゲーム終了！" << endl;
    return 0;
}
