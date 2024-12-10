#include "Zombie.h"
#include "Hero.h"
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

using namespace std;

int main() {
    // ランダムシードを設定
    srand((unsigned int)time(NULL));

    // キャラクターの初期化
    Zombie zombie("Zombie", 50, 20, 12, 5);
    Hero hero("Hero", 50, 20, 15, 7);

    Character& zombieChar = zombie;
    Character& heroChar = hero;

    cout << "ゲームスタート！" << endl;

    // 初期状態を表示
    cout << endl << "初期状態:" << endl;
    cout << zombieChar.GetName() << endl;
    zombieChar.Show();
    cout << endl;
    cout << heroChar.GetName() << endl;
    heroChar.Show();
    cout << endl;

    // ターン制バトル
    int turn = 1;
    do{
        cout << "=== ターン " << turn << " ===" << endl;

        // ヒーローの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
            cout << heroChar.GetName() << "の攻撃！剣で攻撃します。" << endl;
            heroChar.SwordAttack(&zombieChar, &heroChar);
        }
        else { // 50%の確率で魔法攻撃
            cout << heroChar.GetName() << "の攻撃！魔法を発動します。" << endl;
            heroChar.MagicAttack(&zombieChar, &heroChar);
        }
        if (heroChar.GetHp() <= 0) {
            cout << zombieChar.GetName() << "は倒れた！" << heroChar.GetName() << "の勝利！" << endl;
            break;
        }

        // ゾンビの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
             cout << zombieChar.GetName() << "の攻撃！剣で攻撃します。" << endl;
            zombieChar.SwordAttack(&heroChar, &zombieChar);
        }
        else { // 50%の確率で魔法攻撃
            cout << zombieChar.GetName() << "の攻撃！魔法を発動します。" << endl;
            zombieChar.MagicAttack(&heroChar, &zombieChar);
        }
        if (zombieChar.GetHp() <= 0) {
            cout << heroChar.GetName() << "は倒れた！" << zombieChar.GetName() << "の勝利！" << endl;
            break;
        }

        // 回復処理
        heroChar.HpJudgment();
        heroChar.MpJudgment();

        zombieChar.HpJudgment();
        zombieChar.MpJudgment();

        // 状態表示
        cout << endl << "現在の状態:" << endl;
        cout << zombieChar.GetName() << endl;
        zombieChar.Show();
        cout << endl;
        cout << heroChar.GetName() << endl;
        heroChar.Show();
        cout << endl;

        // 次のターンへ
        turn++;
    } while (zombieChar.GetHp() > 0 && heroChar.GetHp() > 0);

    cout << "ゲーム終了！" << endl;
    return 0;
}
