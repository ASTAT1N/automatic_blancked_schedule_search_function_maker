#include<iostream>
#include<string>
#include<vector>
class data{
public:
	data(char _name[6]){
		int ms = strlen(_name);
		//월요일 1교시 위치 찾기
		loc[0] = _name[0] + 2;
		loc[ms - 1] = (_name[ms - 1] + 2);
		bool sw = (loc[ms - 1] >= 10);
		for (int i = ms - 2; i > 0; --i) {
			if (sw) {
				loc[i + 1] %= 10;
				loc[i] = _name[i] + 1;
				if (loc[i + 1] < 10) {
					sw = false;
				}
			}
			else {
				loc[i] = _name[i];
			}
		}
		loc[ms] = NULL;
		//이름위치 고정화
		for (int i = ms; i > 0; --i) {
			name[i + 2] = _name[i];
		}
		name[1] = _name[0];
		name[0] = '$';
		name[2] = '$';
	}
	char* get_name() {
		return name;
	}
	char* get_loc() {
		return loc;
	}
private:
	char name[8];
	char loc[6];
};
using namespace std;
int main() {
	int MX,i;
	char name[6];
	vector<class::data>con;
	//입력
	cout << "인원수를 입력해 주세요.";
	cin >> MX;
	cout << "이름의 좌표값을 입력해 주세요\n";
	for (i = 0; i < MX; i++) {
		cin >> name;
		con.push_back(name);
		cout << con[i].get_name() << " " << con[i].get_loc() << "\n";
	}
	//출력
	//(IF(loc=0,name,"")&",")
	cout << "=";
	for (i = 0; i < MX; ++i) {
		
		if (i < (MX - 1)) {
			cout << "&\"\,\")&";
		}
	}

	return 0;
}