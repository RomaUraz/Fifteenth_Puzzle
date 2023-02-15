#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class p15 {
public:
    void play() { // метод play() є головним і відповідає за запуск гри
        bool p = true;
        string a;
        while (p) {
            createBrd(); // функція createBrd() відповідає за створення і генерацію значеннь на полі
            while (!isDone()) { drawBrd(); getMove(); } //поки гра не закінчена (isDone() false) будуть відпрацьовувати методи drawBrd() getMove() які відповідають за відображення поля і рухи блоків там
            drawBrd(); // малює ігрове поле
            cout << "\n\nCongratulations!\nPlay again (Y/N)?"; //виводить повідомлення про повторну гру
            cin >> a; if (a != "Y" && a != "y") break;
        }
    }
private:
    void createBrd() { // функція createBrd() відповідає за створення і генерацію значеннь на полі
        int i = 1; vector<int> v;
        for (; i < 16; i++) { brd[i - 1] = i; }
        brd[15] = 0; x = y = 3;
        for (i = 0; i < 1000; i++) {
            getCandidates(v);
            move(v[rand() % v.size()]);
            v.clear();
        }
    }
    void move(int d) { // функція move() переміщує тайли по полю по х і у, вверх вниз вправо вліво
        int t = x + y * 4;    // функція для руху обраного тайлу передаємо v[i] обраного тайлу з номером руху
        switch (d) {
        case 1: y--; break;
        case 2: x++; break;
        case 4: y++; break;
        case 8: x--;
        }
        brd[t] = brd[x + y * 4];
        brd[x + y * 4] = 0;
    }
    void getCandidates(vector<int>& v) { //функція getCandidates() визначає які саме тайли можуть бути переміщені. функція для визначення можливих кандидатів  -
        if (x < 3) v.push_back(2); if (x > 0) v.push_back(8);// ми визначаємо тайли в яких в рядку зліва менше трьох тайлів,то їх ми можемо подвинути вправо по х,
        if (y < 3) v.push_back(4); if (y > 0) v.push_back(1);// якщо більше 0 зліва по х, то вліво при цьоиу додаємо в кінець масиву номер операції, аналогічно по у
    }
    void drawBrd() { // функція drawBrd() малює ігрове поле 4 на 4 використовуючи символи і перенос строки
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
    void getMove() { // відповідає за переміщення тайлів на ігровому полі
        vector<int> v; getCandidates(v); // перевіряє які саме тайли можуть бути переміщенні
        vector<int> p; getTiles(p, v); unsigned int i; //вектор (масив)з можливих рухів
        while (true) {
            cout << "\nPossible moves: ";
            for (i = 0; i < p.size(); i++) cout << p[i] << " ";
            int r; cin >> r;//змінна для зчитування номеру руху
            for (i = 0; i < p.size(); i++)
                if (r == p[i]) { move(v[i]); return; }//перевіряємо чи введене число входить в вектор(масив)можливих рухів та рухаємо обраний тайл
        }
    }
    void getTiles(vector<int>& p, vector<int>& v) { // після руху тайлу перевіряєвсі решту тайлів, здвигає їх та дописує в масив p нові тайли
        for (unsigned int t = 0; t < v.size(); t++) {
            int xx = x, yy = y;
            switch (v[t]) {
            case 1: yy--; break;
            case 2: xx++; break;
            case 4: yy++; break;
            case 8: xx--;
            }
            p.push_back(brd[xx + yy * 4]);// вставляємо новий елемент в кінець вектору
        }
    }
    bool isDone() { // перевіряє чи занчення були зібрані в правильному порядку і завершує гру
        for (int i = 0; i < 15; i++) {
            if (brd[i] != i + 1) return false;
        }
        return true;
    }
    int brd[16], x, y;//brd -масив від 0 до 16 з номерами тайлів
};
int main(int argc, char* argv[]) { // виклик класу p15 
    srand((unsigned)time(0));
    p15 p; p.play(); return 0;
}