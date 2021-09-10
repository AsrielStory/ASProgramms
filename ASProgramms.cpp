//Created by Asriel_Story

//Библиотеки
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <fstream>
#include <locale>
#include <cmath>

using namespace std;

//"Программа" по созданию словорей для программ брутфорса
int new_brut () {
    string sim;
    int min_length, max_length;
    cout << "Введите все символы:";
    cin >> sim;
    //Большая часть символов - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
    cout << "Введите максимальную длинну:";
    cin >> max_length;
    int l = sim.length();
    int r[max_length];
    //Очищение от мусора массива индекса символов
    for (int i=0;i<max_length;i++) {
        r[i]=-1;
    }
    //b - это массив из "цифр" а именно номер в названии файла
    char b[10];
    for (int i=0;i<10;i++) {
        b[i]=48;
    }
    //Правая и левая части названия файла
    string a1="file",a2=".txt",g;
    ofstream file;
    bool o=0;
    long long i=1000000000;
    //Алгоритм перебора
    while (o!=1) {
        if (i==1000000000) {
            file.close();
            b[0]++;
            if (b[0]==58) {
                for (int j=0;j<10;j++) {
                    if (b[j]==58) {
                        b[j+1]++;
                        b[j]=48;
                    }
                }
            }
            g="";
            for (int j=9;j>-1;j--) {
                g+=b[j];
            }
            file.open(a1+g+a2);
            i=0;
        }
        r[0]++;
        if (r[0]==l) {
            for (int j=0; j < max_length; j++) {
                if (r[j]==l) {
                    r[j+1]++;
                    r[j] = 0;
                }
            }
        }
        for (int j = max_length - 1; j > -1; j--) {
            if (r[j]!=-1) {
                file << sim[r[j]];
            }
        }
        file << endl;
        i++;
        for (int j=0, n=0;j<max_length;j++) {
            if (r[j]==l-1) {
                n++;
            }
            if (n==max_length) {
                o=1;
            }
        }
    }
    return 0;
}

//Создание рандомного названия/имени для чего либо
int random_name () {
    //Генератор по времени
    srand(time(0));
    //Максимальная длинна
    cout << "Введите максимальную длинну имя:" << endl;
    int max_length;
    cin >> max_length;
    //Количество имён
    cout << "Введите количество имён:" << endl;
    int num;
    cin >> num;
    //Выбор вывода
    cout << "Выберите вариант вывода:" << endl;
    cout << "1. Консоль" << endl;
    cout << "2. Файл" << endl;
    bool choice;
    cin >> choice;
    //База согласных и гласных
    string gl[6],sg[24];
    //Согласные
    sg[0]='b';
    sg[1]='c';
    sg[2]='d';
    sg[3]='f';
    sg[4]='g';
    sg[5]='h';
    sg[6]='j';
    sg[7]='k';
    sg[8]='l';
    sg[9]='m';
    sg[10]='n';
    sg[11]='p';
    sg[12]='q';
    sg[13]='r';
    sg[14]='s';
    sg[15]='t';
    sg[16]='v';
    sg[17]='w';
    sg[18]='x';
    sg[19]='y';
    sg[20]='z';
    sg[21]="th";
    sg[22]="ch";
    sg[23]="zh";
    //Гласные
    gl[0]='a';
    gl[1]='e';
    gl[2]='i';
    gl[3]='o';
    gl[4]='u';
    gl[5]='y';
    //Генератор
    bool o = 0;
    if (choice == 0) {
        //Консоль
        for (int i = 0, l = 0; i < num; i++) {
            o = rand() % 2;
            while (l < 3) {
                l = rand() % (max_length + 1);
            }
            for (int j = 0; j < l; j++) {
                if (o == 0) {
                    cout << sg[rand() % 24];
                    o = 1;
                }
                else {
                    cout << gl[rand() % 6];
                    o = 0;
                }
            }
            cout << endl;
            l = 0;
        }
    }
    else {
        //Файл
        ofstream file("Names.txt");
        for (int i = 0, l = 0; i < num; i++) {
            o = rand() % 2;
            while (l < 3) {
                l = rand() % (max_length + 1);
            }
            for (int j = 0; j < l; j++) {
                if (o == 0) {
                    file << sg[rand() % 24];
                    o = 1;
                }
                else {
                    file << gl[rand() % 6];
                    o = 0;
                }
            }
            file << endl;
            l = 0;
        }
        file.close();
    }
    return 0;
}

//Генератор паролей
int gpassword () {
    srand(time(0));
    cout << "Введите нужную длинну пароля:" << endl;
    int max_length;
    cin >> max_length;
    cout << "Введите количество паролей:" << endl;
    long long num;
    cin >> num;
    cout << "Выберите способ вывода:" << endl << "1. Консоль" << endl << "2. Файл" << endl;
    int v;
    cin >> v;
    //Универсальный "Ключ" для генерации пароля
    string sim="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    //Алгоритмы (Консоль/файл) по генерации пароля
    if (v==1) {
        for (long long i=0;i<num;i++) {
            for (int j=0;j<max_length;j++) {
                cout << sim[rand()%62];
            }
            cout << endl;
        }
    }
    else {
        ofstream file("password.txt");
        for (long long i=0;i<num;i++) {
            for (int j=0;j<max_length;j++) {
                file << sim[rand()%62];
            }
            file << endl;
        }
        file.close();
    }
    return 0;
}

//Главная
int main () {
    setlocale(LC_ALL, "Rus");
    cout << "Добро пожаловать в ASProgramms" << endl << "Выберите что хотите запускать:" << endl;
    cout << "1. New Brut (0.1)" << endl;
    cout << "2. RandomName (0.6)" << endl;
    cout << "3. GPassword (0.1)" << endl;
    int z;
    cin >> z;
    switch (z) {
    case 1:
        system("cls");
        new_brut();
        break;
    case 2:
        system("cls");
        random_name();
        break;
    case 3:
        system("cls");
        gpassword();
        break;
    }
    return 0;
}
