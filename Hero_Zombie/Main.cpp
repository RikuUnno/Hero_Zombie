#include "Zombie.h"
#include "Hero.h"
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

using namespace std;

int main() {
    // �����_���V�[�h��ݒ�
    srand((unsigned int)time(NULL));

    // �L�����N�^�[�̏�����
    Zombie zombie("Zombie", 50, 20, 12, 5);
    Hero hero("Hero", 50, 20, 15, 7);

    Character& zombieChar = zombie;
    Character& heroChar = hero;

    cout << "�Q�[���X�^�[�g�I" << endl;

    // ������Ԃ�\��
    cout << endl << "�������:" << endl;
    cout << zombieChar.GetName() << endl;
    zombieChar.Show();
    cout << endl;
    cout << heroChar.GetName() << endl;
    heroChar.Show();
    cout << endl;

    // �^�[�����o�g��
    int turn = 1;
    do{
        cout << "=== �^�[�� " << turn << " ===" << endl;

        // �q�[���[�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
            cout << heroChar.GetName() << "�̍U���I���ōU�����܂��B" << endl;
            heroChar.SwordAttack(&zombieChar, &heroChar);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << heroChar.GetName() << "�̍U���I���@�𔭓����܂��B" << endl;
            heroChar.MagicAttack(&zombieChar, &heroChar);
        }
        if (heroChar.GetHp() <= 0) {
            cout << zombieChar.GetName() << "�͓|�ꂽ�I" << heroChar.GetName() << "�̏����I" << endl;
            break;
        }

        // �]���r�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
             cout << zombieChar.GetName() << "�̍U���I���ōU�����܂��B" << endl;
            zombieChar.SwordAttack(&heroChar, &zombieChar);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << zombieChar.GetName() << "�̍U���I���@�𔭓����܂��B" << endl;
            zombieChar.MagicAttack(&heroChar, &zombieChar);
        }
        if (zombieChar.GetHp() <= 0) {
            cout << heroChar.GetName() << "�͓|�ꂽ�I" << zombieChar.GetName() << "�̏����I" << endl;
            break;
        }

        // �񕜏���
        heroChar.HpJudgment();
        heroChar.MpJudgment();

        zombieChar.HpJudgment();
        zombieChar.MpJudgment();

        // ��ԕ\��
        cout << endl << "���݂̏��:" << endl;
        cout << zombieChar.GetName() << endl;
        zombieChar.Show();
        cout << endl;
        cout << heroChar.GetName() << endl;
        heroChar.Show();
        cout << endl;

        // ���̃^�[����
        turn++;
    } while (zombieChar.GetHp() > 0 && heroChar.GetHp() > 0);

    cout << "�Q�[���I���I" << endl;
    return 0;
}
