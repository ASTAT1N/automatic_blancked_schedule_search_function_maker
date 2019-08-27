#include<iostream>
#include<string>
using namespace std;
int main() {
	int MX, i;
	char name[20][6], loc[20][6];
	//입력
	cout << "인원수를 입력해 주세요.";
	cin >> MX;
	cout << "이름과 월요일 1교시의 좌표값을 입력해 주세요\n";
	for (i = 0; i < MX; i++){
		cin >> name[i] >> loc[i];
	}
	//출력
	//(IF(loc=0,name,"")&",")
	cout << "=";

	return 0;
}