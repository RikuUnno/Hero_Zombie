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

    Character* pChar[2];
    pChar[0] = &zombie;
    pChar[1] = &hero;

    cout << "�Q�[���X�^�[�g�I" << endl;

    // ������Ԃ�\��
    cout << endl << "�������:" << endl;
    for (int i = 0; i < 2; i++)
    {
        pChar[i]->Show();
        cout << endl;
    }

    // �^�[�����o�g��
    int turn = 1;
    do{
        cout << "=== �^�[�� " << turn << " ===" << endl;

        // �q�[���[�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
            cout << pChar[1]->GetName() << "�̍U���I���ōU�����܂��B" << endl;
            pChar[1]->SwordAttack(pChar[0]);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << pChar[1]->GetName() << "�̍U���I���@�𔭓����܂��B" << endl;
            pChar[1]->MagicAttack(pChar[0]);
        }
        if (pChar[0]->GetHp() <= 0) {
            cout << pChar[1]->GetName() << "�͓|�ꂽ�I" << pChar[1]->GetName() << "�̏����I" << endl;
            break;
        }

        // �]���r�̍s��
        if (rand() % 2 == 0) { // 50%�̊m���Ō��U��
             cout << pChar[0]->GetName() << "�̍U���I���ōU�����܂��B" << endl;
             pChar[0]->SwordAttack(pChar[1]);
        }
        else { // 50%�̊m���Ŗ��@�U��
            cout << pChar[0]->GetName() << "�̍U���I���@�𔭓����܂��B" << endl;
            pChar[0]->MagicAttack(pChar[1]);
        }
        if (pChar[1]->GetHp() <= 0) {
            cout << pChar[1]->GetName() << "�͓|�ꂽ�I" << pChar[0]->GetName() << "�̏����I" << endl;
            break;
        }

        // �񕜏���
        for (int i = 0; i < 2; i++)
        {
            pChar[i]->HpJudgment();
            pChar[i]->MpJudgment();
        }

        // ��ԕ\��
        cout << endl << "���݂̏��:" << endl;
        for (int i = 0; i < 2; i++)
        {
            pChar[i]->Show();
            cout << endl;
        }

        // ���̃^�[����
        turn++;
    } while (pChar[0]->GetHp() > 0 && pChar[1]->GetHp() > 0);

    cout << "�Q�[���I���I" << endl;
    return 0;
}
