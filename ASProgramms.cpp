//Created by Asriel_Story

//����������
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <fstream>
#include <locale>
#include <cmath>

using namespace std;

//"���������" �� �������� �������� ��� �������� ���������
int new_brut () {
    string sim;
    int min_length, max_length;
    cout << "������� ��� �������:";
    cin >> sim;
    //������� ����� �������� - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
    cout << "������� ������������ ������:";
    cin >> max_length;
    int l = sim.length();
    int r[max_length];
    //�������� �� ������ ������� ������� ��������
    for (int i=0;i<max_length;i++) {
        r[i]=-1;
    }
    //b - ��� ������ �� "����" � ������ ����� � �������� �����
    char b[10];
    for (int i=0;i<10;i++) {
        b[i]=48;
    }
    //������ � ����� ����� �������� �����
    string a1="file",a2=".txt",g;
    ofstream file;
    bool o=0;
    long long i=1000000000;
    //�������� ��������
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

//�������� ���������� ��������/����� ��� ���� ����
int random_name () {
    srand(time(0));
    cout << "������� ���/�������� ��� ����?" << endl;
    int num;
    cin >> num;
    cout << "���� ������� �����/��������?" << endl << "1. �������" << endl << "2. ����" << endl;
    int v;
    cin >> v;
    //���� ��������
    char sg[21], gl[6];
    //���������
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
    //�������
    gl[0]='a';
    gl[1]='e';
    gl[2]='i';
    gl[3]='o';
    gl[4]='u';
    gl[5]='y';
    //o - ��� switch
    bool o=0;
    //��������� (�������/����) �� ��������� ��������/�����
    if (v==1) {
        for (int i=0, l;i<num;i++) {
            if (rand()%2==0) {
                o=1;
            }
            else {
                o=0;
            }
            while (l<=3) {
                l=rand()%10;
            }
            for (int j=0;j<l;j++) {
                if (o==0) {
                    o=1;
                    cout << gl[rand()%6];
                }
                else {
                    o=0;
                    cout << sg[rand()%21];
                }
            }
            cout << endl;
        }
    }
    else {
        ofstream file("Names.txt");
        for (int i=0, l;i<num;i++) {
            if (rand()%2==0) {
                o=1;
            }
            else {
                o=0;
            }
            while (l<=3) {
                l=rand()%10;
            }
            for (int j=0;j<l;j++) {
                if (o==0) {
                    o=1;
                    file << gl[rand()%6];
                }
                else {
                    o=0;
                    file << sg[rand()%21];
                }
            }
            file << endl;
        }
        file.close();
    }
    return 0;
}

//��������� �������
int gpassword () {
    srand(time(0));
    cout << "������� ������ ������ ������:" << endl;
    int max_length;
    cin >> max_length;
    cout << "������� ���������� �������:" << endl;
    long long num;
    cin >> num;
    cout << "�������� ������ ������:" << endl << "1. �������" << endl << "2. ����" << endl;
    int v;
    cin >> v;
    //������������� "����" ��� ��������� ������
    string sim="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    //��������� (�������/����) �� ��������� ������
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

//�������
int main () {
    setlocale(LC_ALL, "Rus");
    cout << "����� ���������� � ASProgramms" << endl << "�������� ��� ������ ���������:" << endl;
    cout << "1. New Brut (0.1)" << endl;
    cout << "2. RandomName (0.2)" << endl;
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
