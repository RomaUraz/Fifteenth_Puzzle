#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class p15 {
public:
    void play() { // ����� play() � �������� � ������� �� ������ ���
        bool p = true;
        string a;
        while (p) {
            createBrd(); // ������� createBrd() ������� �� ��������� � ��������� �������� �� ���
            while (!isDone()) { drawBrd(); getMove(); } //���� ��� �� �������� (isDone() false) ������ �������������� ������ drawBrd() getMove() �� ���������� �� ����������� ���� � ���� ����� ���
            drawBrd(); // ����� ������ ����
            cout << "\n\nCongratulations!\nPlay again (Y/N)?"; //�������� ����������� ��� �������� ���
            cin >> a; if (a != "Y" && a != "y") break;
        }
    }
private:
    void createBrd() { // ������� createBrd() ������� �� ��������� � ��������� �������� �� ���
        int i = 1; vector<int> v;
        for (; i < 16; i++) { brd[i - 1] = i; }
        brd[15] = 0; x = y = 3;
        for (i = 0; i < 1000; i++) {
            getCandidates(v);
            move(v[rand() % v.size()]);
            v.clear();
        }
    }
    void move(int d) { // ������� move() ������� ����� �� ���� �� � � �, ����� ���� ������ ����
        int t = x + y * 4;    // ������� ��� ���� �������� ����� �������� v[i] �������� ����� � ������� ����
        switch (d) {
        case 1: y--; break;
        case 2: x++; break;
        case 4: y++; break;
        case 8: x--;
        }
        brd[t] = brd[x + y * 4];
        brd[x + y * 4] = 0;
    }
    void getCandidates(vector<int>& v) { //������� getCandidates() ������� �� ���� ����� ������ ���� ��������. ������� ��� ���������� �������� ���������  -
        if (x < 3) v.push_back(2); if (x > 0) v.push_back(8);// �� ��������� ����� � ���� � ����� ���� ����� ����� �����,�� �� �� ������ ��������� ������ �� �,
        if (y < 3) v.push_back(4); if (y > 0) v.push_back(1);// ���� ����� 0 ���� �� �, �� ���� ��� ����� ������ � ����� ������ ����� ��������, ��������� �� �
    }
    void drawBrd() { // ������� drawBrd() ����� ������ ���� 4 �� 4 �������������� ������� � ������� ������
        int r; cout << "\n\n";
        for (int y = 0; y < 4; y++) {
            cout << "+----+----+----+----+\n";
            for (int x = 0; x < 4; x++) {
                r = brd[x + y * 4];
                cout << "| ";
                if (r < 10) cout << " ";
                if (!r) cout << "  ";
                else cout << r << " ";
            }
            cout << "|\n";
        }
        cout << "+----+----+----+----+\n";
    }
    void getMove() { // ������� �� ���������� ����� �� �������� ���
        vector<int> v; getCandidates(v); // �������� �� ���� ����� ������ ���� ���������
        vector<int> p; getTiles(p, v); unsigned int i; //������ (�����)� �������� �����
        while (true) {
            cout << "\nPossible moves: ";
            for (i = 0; i < p.size(); i++) cout << p[i] << " ";
            int r; cin >> r;//����� ��� ���������� ������ ����
            for (i = 0; i < p.size(); i++)
                if (r == p[i]) { move(v[i]); return; }//���������� �� ������� ����� ������� � ������(�����)�������� ����� �� ������ ������� ����
        }
    }
    void getTiles(vector<int>& p, vector<int>& v) { // ���� ���� ����� ���������� ����� �����, ������ �� �� ������ � ����� p ��� �����
        for (unsigned int t = 0; t < v.size(); t++) {
            int xx = x, yy = y;
            switch (v[t]) {
            case 1: yy--; break;
            case 2: xx++; break;
            case 4: yy++; break;
            case 8: xx--;
            }
            p.push_back(brd[xx + yy * 4]);// ���������� ����� ������� � ����� �������
        }
    }
    bool isDone() { // �������� �� �������� ���� ����� � ����������� ������� � ������� ���
        for (int i = 0; i < 15; i++) {
            if (brd[i] != i + 1) return false;
        }
        return true;
    }
    int brd[16], x, y;//brd -����� �� 0 �� 16 � �������� �����
};
int main(int argc, char* argv[]) { // ������ ����� p15 
    srand((unsigned)time(0));
    p15 p; p.play(); return 0;
}