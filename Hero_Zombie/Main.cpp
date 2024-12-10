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

    Character* pChar[2];
    pChar[0] = &zombie;
    pChar[1] = &hero;

    cout << "ゲームスタート！" << endl;

    // 初期状態を表示
    cout << endl << "初期状態:" << endl;
    for (int i = 0; i < 2; i++)
    {
        pChar[i]->Show();
        cout << endl;
    }

    // ターン制バトル
    int turn = 1;
    do{
        cout << "=== ターン " << turn << " ===" << endl;

        // ヒーローの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
            cout << pChar[1]->GetName() << "の攻撃！剣で攻撃します。" << endl;
            pChar[1]->SwordAttack(pChar[0]);
        }
        else { // 50%の確率で魔法攻撃
            cout << pChar[1]->GetName() << "の攻撃！魔法を発動します。" << endl;
            pChar[1]->MagicAttack(pChar[0]);
        }
        if (pChar[0]->GetHp() <= 0) {
            cout << pChar[1]->GetName() << "は倒れた！" << pChar[1]->GetName() << "の勝利！" << endl;
            break;
        }

        // ゾンビの行動
        if (rand() % 2 == 0) { // 50%の確率で剣攻撃
             cout << pChar[0]->GetName() << "の攻撃！剣で攻撃します。" << endl;
             pChar[0]->SwordAttack(pChar[1]);
        }
        else { // 50%の確率で魔法攻撃
            cout << pChar[0]->GetName() << "の攻撃！魔法を発動します。" << endl;
            pChar[0]->MagicAttack(pChar[1]);
        }
        if (pChar[1]->GetHp() <= 0) {
            cout << pChar[1]->GetName() << "は倒れた！" << pChar[0]->GetName() << "の勝利！" << endl;
            break;
        }

        // 回復処理
        for (int i = 0; i < 2; i++)
        {
            pChar[i]->HpJudgment();
            pChar[i]->MpJudgment();
        }

        // 状態表示
        cout << endl << "現在の状態:" << endl;
        for (int i = 0; i < 2; i++)
        {
            pChar[i]->Show();
            cout << endl;
        }

        // 次のターンへ
        turn++;
    } while (pChar[0]->GetHp() > 0 && pChar[1]->GetHp() > 0);

    cout << "ゲーム終了！" << endl;
    return 0;
}
