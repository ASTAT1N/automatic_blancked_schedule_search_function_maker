#include<iostream>
#include<string>
using namespace std;
int main() {
	int MX, i,j;
	char name[20][8], loc[20][6];
	//�Է�
	cout << "�ο����� �Է��� �ּ���.";
	cin >> MX;
	cout << "�̸��� ������ 1������ ��ǥ���� �Է��� �ּ���\n";
	for (i = 0; i < MX; i++){
		cin >> name[i] >> loc[i];
	}
	//�̸���ġ ����ȭ
	
	//���
	//(IF(loc=0,name,"")&",")
	cout << "=";
	for (i = 0; i < MX; ++i) {
		
		if (i < (MX - 1)) {
			cout << "&\"\,\")&";
		}
	}

	return 0;
}