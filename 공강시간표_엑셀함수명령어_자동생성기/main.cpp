#include<iostream>
#include<string>
#include<vector>
class data{
public:
	data(char _name[6]){
		int ms = strlen(_name);
		//월요일 1교시 위치 찾기
		int addMon = 3,addBlank=2;
		loc[0] = _name[0] + 2;
		bool sw = ((mInt(&_name[ms - 1])+addMon) >= 10);
		loc[ms - 1] = (_name[ms - 1] + addMon);
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
		//공강찾기
		blank[0] = _name[0] + 2;
		blank[1] = '$';
		sw = ((mInt(&_name[ms - 1]) + addBlank) >= 10);
		blank[ms] = (_name[ms - 1] + addBlank);
		for (int i = ms - 2; i > 0; --i) {
			if (sw) {
				blank[i + 2] -= 10;
				if (mInt(&_name[i]) != 9) {
					sw = false;
				}
				blank[i+1] = _name[i] + 1;

			}
			else {
				blank[i+1] = _name[i];
			}
		}
		if (sw) {
			blank[2] -= 10;
			for (int i = ms+1; i > 1; --i) {
				blank[i] = blank[i - 1];
			}
			blank[2] = '1';
		}
		blank[ms +1+ ((int)sw)] = NULL;
		//이름위치 고정화
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
	char* get_blank() {
		return blank;
	}
private:
	char name[8]="";
	char loc[6]="",blank[7]="";
};
using namespace std;
int main() {
	int i;
	char name[6];
	vector<class::data>con;
	//입력
	cout << "인원수를 입력해 주세요.";
	cout << "이름의 좌표값을 입력해 주세요\n";
	while(cin >> name) {
		
		con.push_back(name);
		//cout << con[0].get_name() << " " << con[0].get_blank() << "\n";
	}
	//출력
	//(IF(AND(loc=0,blank<24),name&",","")&)
	cout << "\n시간표: =(";
	for (i = 0; i < con.size(); ++i) {
		cout << "IF(AND(" << con[i].get_loc() << "=0,"<<con[i].get_blank()<<"<24)," << con[i].get_name() << "&\",\",\"\")";
		if (i < (con.size() - 1)) {
			cout << "&";
		}
		else {
			cout << ")";
		}
	}
	//(IF(blank=24,name&",","")&)
	cout << "\n공강확인: =(";
	for (i = 0; i < con.size(); ++i) {
		cout << "IF(" << con[i].get_blank()<<"=24,"<<con[i].get_name()<<"&\",\",\"\")";
		if (i < (con.size() - 1)) {
			cout << "&";
		}
		else {
			cout << ")";
		}
	}
	return 0;
}