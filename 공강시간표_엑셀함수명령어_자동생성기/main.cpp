#include<iostream>
#include<string>
using namespace std;
int main() {
	int MX, i;
	char name[20][6], loc[20][6];
	//�Է�
	cout << "�ο����� �Է��� �ּ���.";
	cin >> MX;
	cout << "�̸��� ������ 1������ ��ǥ���� �Է��� �ּ���\n";
	for (i = 0; i < MX; i++){
		cin >> name[i] >> loc[i];
	}
	//���
	//(IF(loc=0,name,"")&",")
	cout << "=";

	return 0;
}