#include<iostream>
#include<string>
using namespace std;
int main() {
	int MX, i, j,ms;
	char name[20][8], loc[20][6];
	//�Է�
	cout << "�ο����� �Է��� �ּ���.";
	cin >> MX;
	cout << "�̸��� ��ǥ���� �Է��� �ּ���\n";
	for (i = 0; i < MX; i++) {
		cin >> name[i];
	}
	for ( i = 0; i < MX; i++){
		ms = strlen(name[i]);
		//������ 1���� ��ġ ã��
		loc[i][0] = name[i][0] + 2;
		loc[i][ms - 1] = (name[i][ms - 1] + 2);
		bool sw=(loc[i][ms-1]>=10);
		for (j = ms-2; j>0; --j) {
			if (sw) {
				loc[i][j] = name[i][j] + 1;
				if (loc[i][j + 1] < 10) {
					sw = false;
				}
			}
			else {
				loc[i][j] = name[i][j];
			}
			
			loc[i][j] = name[i][j] + ((name[i][j + 1] + 2));
		}
		//�̸���ġ ����ȭ
		for (j = ms; j >= 0; --j) {
			name[i][j+2] = name[i][j];
		}
		name[i][1] = name[i][2];
		name[i][0] = '$';
		name[i][2] = '$';
	}
	
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