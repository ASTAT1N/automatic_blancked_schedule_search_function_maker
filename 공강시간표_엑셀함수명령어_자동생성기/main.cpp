#include<iostream>
#include<string>
using namespace std;
int main() {
	int MX, i,j;
	char name[20][8], loc[20][6];
	//입력
	cout << "인원수를 입력해 주세요.";
	cin >> MX;
	cout << "이름과 월요일 1교시의 좌표값을 입력해 주세요\n";
	for (i = 0; i < MX; i++){
		cin >> name[i] >> loc[i];
	}
	//이름위치 고정화
	for ( i = 0; i < MX; i++)
	{
		for (j = strlen(name[i]); j >= 0; --j) {
			name[i][j+2] = name[i][j];
		}
		name[i][1] = name[i][2];
		name[i][0] = '$';
		name[i][2] = '$';
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