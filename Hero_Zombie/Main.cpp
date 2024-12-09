#include "Zombie.h"
#include "Hero.h"
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

using namespace std;

int main() {
    // �����_���V�[�h��ݒ�
    srand(static_cast<unsigned>(time(0)));

    // �L�����N�^�[�̏�����
    Zombie zombie("Zombie", 50, 20, 10, 5);
    Hero hero("Hero", 50, 20, 15, 7);

    Character& zombieChar = zombie;
    Character& heroChar = hero;

    cout << "�Q�[���X�^�[�g�I" << endl;

    // ������Ԃ�\��
    cout << endl << "�������:" << endl;
    cout << "�]���r" << endl;
    heroChar.Show();
    cout << endl;
    cout << "�q�[���[" << endl;
    heroChar.Show();
    cout << endl;

    // �^�[�����o�g��
    int turn = 1;
    while (zombieChar.GetHp() > 0 && heroChar.GetHp() > 0) {
        cout << "=== �^�[�� " << turn << " ===" << endl;

        // �q�[���[�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
            cout << "�q�[���[�̍U���I���ōU�����܂��B" << endl;
            heroChar.SwordAttack(&zombie);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << "�q�[���[�̍U���I���@�𔭓����܂��B" << endl;
            heroChar.MagicAttack(&zombie);
        }
        if (heroChar.GetHp() <= 0) {
            cout << "�]���r�͓|�ꂽ�I�q�[���[�̏����I" << endl;
            break;
        }

        // �]���r�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
            cout << "�]���r�̍U���I���ōU�����܂��B" << endl;
            zombieChar.SwordAttack(&hero);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << "�]���r�̍U���I���@�𔭓����܂��B" << endl;
            zombieChar.MagicAttack(&hero);
        }
        if (heroChar.GetHp() <= 0) {
            cout << "�q�[���[�͓|�ꂽ�I�]���r�̏����I" << endl;
            break;
        }

        // �񕜏���
        hero.HpJudgment();
        hero.MpJudgment();
        zombie.HpJudgment();
        zombie.MpJudgment();

        // ��ԕ\��
        cout << endl << "���݂̏��:" << endl;
        cout << "�]���r" << endl;
        zombieChar.Show();
        cout << endl;
        cout << "�q�[���[" << endl;
        heroChar.Show();
        cout << endl;

        // ���̃^�[����
        turn++;
    }

    cout << "�Q�[���I���I" << endl;
    return 0;
}
