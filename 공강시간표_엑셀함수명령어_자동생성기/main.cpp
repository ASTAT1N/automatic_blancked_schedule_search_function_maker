#include<iostream>
#include<string>
#include<vector>
class data{
public:
	data(char _name[6]){
		int ms = strlen(_name);
		//������ 1���� ��ġ ã��
		loc[0] = _name[0] + 2;
		bool sw = (mInt(&_name[ms - 1]) >= 8);
		loc[ms - 1] = (_name[ms - 1] + 2);
		for (int i = ms - 2; i > 0; --i) {
			if (sw) {
				loc[i + 1] -= 10;
				if (mInt(&_name[i])!=9) {
					sw = false;
				}
				loc[i] = _name[i] + 1;
				
			}
			else {
				loc[i] = _name[i];
			}
		}
		if (sw) {
			loc[1] -= 10;
			for (int i = ms; i > 1;--i) {
				loc[i] = loc[i - 1];
			}
			loc[1] = '1';
		}
		loc[ms+((int)sw)] = NULL;
		//�̸���ġ ����ȭ
		for (int i = ms; i > 0; --i) {
			name[i + 2] = _name[i];
		}
		name[1] = _name[0];
		name[0] = '$';
		name[2] = '$';
	}
	int mInt(char*_mchar) {
		return atoi(_mchar);
	}
	char* get_name() {
		return name;
	}
	char* get_loc() {
		return loc;
	}
private:
	char name[8]="";
	char loc[6]="";
};
using namespace std;
int main() {
	int MX,i;
	char name[6];
	vector<class::data>con;
	//�Է�
	cout << "�ο����� �Է��� �ּ���.";
	cin >> MX;
	cout << "�̸��� ��ǥ���� �Է��� �ּ���\n";
	for (i = 0; i < MX; i++) {
		cin >> name;
		con.push_back(name);
		//cout << con[i].get_name() << " " << con[i].get_loc() << "\n";
	}
	//���
	//(IF(loc=0,name,"")&",")
	cout << "\n=(";
	for (i = 0; i < con.size(); ++i) {
		cout << "IF(" << con[i].get_loc() << "=0," << con[i].get_name() << "&\",\",\"\")";
		if (i < (MX - 1)) {
			cout << "&";
		}
		else {
			cout << ")";
		}
	}

	return 0;
}