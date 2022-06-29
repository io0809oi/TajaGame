#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#define fscore 2000


//유저 답변
char User_ans[200][100] = { {NULL},{NULL},{NULL},{NULL},{NULL} };
//긴글모음
char eguk_1[10][100] = { {""}, {"동해물과 백두산이 마르고 닳도록"}, {"하느님이 보우하사 우리나라 만세"},
{ "무궁화 삼천리 화려강산" }, { "대한사람 대한으로 길이 보전하세." } };
char eguk_1_4[40][100] = { {""}, {"동해물과 백두산이 마르고 닳도록"}, {"하느님이 보우하사 우리나라 만세"},
{ "무궁화 삼천리 화려강산" }, { "대한사람 대한으로 길이 보전하세." },
	{"남산 위에 저 소나무 철갑을 두른 듯"},{"바람 서리 불변함은 우리 기상일세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."},
	{"가을 하늘 공활한데 높고 구름 없이"},{"밝은 달은 우리가슴 일편 단심일세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."},
	{"이 기상과 이 맘으로 충성을 다하여"},{"괴로우나 즐거우나 나라 사랑하세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."} };
char dimigo[40][100] = { {""}, {"대한민국의 상업정보계열 특성화고등학교."},{"IT 직업계학교 중 명성이 자자하다."},
{"경기도 안산시 단원구 사세충열로 94"},{"운영주체인 학교법인 이산학원은 중견 철강 재벌 계열 이다."},
	{"학교 공식 행사에서 마무리를 지을 때,"},{"대부분 교가를 1절까지만 부른다."},
	{"학교 교복은 동복,하복,체육복,생활복으로 구성되어있다."},{"등교할 때는 여름철 하복 또는 생활복, 겨울철은 동복 착용이 원칙이다."},
	{"체육복은 체육시간 전후 1시간만 착용이 가능하다."},{"귀가시 반드시 교복만 착용해야하며,"},
	{"일요일 오후 귀교 시에는 사복 착용이 가능하다."},{"여학생의 남학생 바지 착용은 가능하지만 남학생 하복 셔츠 착용은 금지되어있다."},
	{"학과는 총 4개로 구성되어있으며,"},{"e-비지니스과,디지털컨텐츠과,웹프로그래밍과,해킹방어과가 있다."},
	{"남녀공학이며, 과별/기수별로 성비가 천차만별이다."},{"오전 6시30분 기상송과 함께 일과가 시작된다."},
	{"주말이나 공휴일의 경우에는 7시이다."},{"생활관 인트라넷인 디미고라이프에서 기상곡 신청을 할 수 있다."},
	{"급식이 정말 맛있다."},{"전교생이 전문 교과 시간 중 프로그래밍,디자인 등의 실습을 위해"},
	{"노트북을 소지하고있다."},{"교내에서는 원칙상 노트북을 통해 공부 이외의 행위는 할 수 없다"}



};

//낱말 모음
char word_animal[100][100] = { {"개"},{"쥐"},{"돼지"},{"원숭이"},{"고양이"},
							{"토끼"},{"소"},{"양"},{"말"},{"호랑이"},{"닭"},{"너구리"},{"북극여우"},
	{"라쿤"},{"미어캣"},{"다람쥐"},{"하늘다람쥐"},{"기니피그"},{"알파카"},{"라마"},{"사슴"},{"고슴도치"},
	{"나무늘보"},{"박쥐"},{"아르마딜로"},{"까치"} };//26개
char word_math[250][100] = { {"가우스"},{"각"},{"각도"},{"각뿔"},{"각뿔대"},{"거듭제곱"},
	{"거듭제곱근"},{"겉넓이"},{"겨냥도"},{"결합법칙"},{"경우의 수"},{"곡선"},{"곱"},{"곱셈"},{"공배수"},
	{"공약수"},{"공역"},{"공집합"},{"관계식"},{"교점"},{"교집합"},{"교환법칙"},{"구"},{"귀류법"},{"그래프"},
	{"근"},{"근삿값"},{"근의 공식"} ,{"근호"},{"기약 분수"},{"기울기"},{"꼭짓점"},{"나눗셈"},{"나머지"},{"내각"},
	{"내분점"},{"내심"},{"내접"},{"내접원"},{"넓이"},{"높이"},{"다각형"},{"다면체"},{"다항식"},
	{"단면"},{"단항식"},{"닮음"},{"닮음비"},{"대각선"},{"대변"},{"대분수"},{"대입"},{"대칭"},{"대칭이동"},
	{"대칭축"}, {"대푯값"},{"덧셈"},{"도수분포표"},{"동위각"},{"동류항"},{"둔각"},{"둘레"},{"등변사다리꼴"},
	{"등식"},{"등호"},{"로그"},{"로그 함수"},{"마름모"},{"막대그래프"},{"맞꼭지각"},{"면"},{"명제"},
	{"모서리"},{"모선"},{"몫"},{"무게중심"},{"무리수"},{"무한대"},{"무한소수"},{"미지수"},{"밑"},{"밑변"},
	{"반비례"},{"반올림"},{"반지름"},{"반직선"},{"받아올림"},{"방정식"},{"배수"},{"백분율"},{"벡터"},{"변"},
	{"변수"},{"복소수"},{"부등식"},{"부등호"},{"부분집합"},{"부채꼴"},{"부피"},{"분모"},{"분배법칙"},
	{"분수"},{"분자"},{"비"},{"비례식"},{"비율"},{"뺄셈"},{"사각형"},{"사다리꼴"},{"사인"},{"산술평균"},
	{"삼각비"},{"삼각함수"},{"삼각형"},{"삼단논법"},{"상수"},{"상수항"},{"상용로그"},{"서로소"},{"선분"},
	{"소수"},{"소인수"},{"소인수분해"},{"수선"},{"수선의 발"},{"수직"},{"수직이등분선"},{"순서쌍"},{"순환소수"},
	{"순열"},{"실수"},{"약분"},{"약수"},{"양수"},{"엇각"},{"여집합"},{"역수"},{"역함수"},{"연립방정식"},
	{"연립부등식"},{"예각"},{"완전제곱식"},{"외각"},{"외분점"},{"외심"},{"외접"},{"외접원"},{"원"},
	{"원기둥"},{"원뿔"},{"원뿔대"},{"원소"},{"원점"},{"원주"},{"원주율"},{"원주각"},{"유한소수"},{"음수"},
	{"이등변 삼각형"},{"이차방정식"},{"이차부등식"},{"이차함수"},{"이항"},{"인수"},{"인수분해"},{"일차방정식"},
	{"일차함수"},{"입체도형"},{"자연수"},{"전개"},{"절댓값"},{"점"},{"접선"},{"접점"},{"정다각형"},{"정다면체"},
	{"정비례"},{"정사각형"},{"정삼각형"},{"정수"},{"정의"},{"제곱근"},{"조합"},{"조립제법"},{"좌표"},{"좌표평면"},
	{"중근"},{"중선"},{"중심각"},{"중점"},{"증명"},{"지름"},{"지수"},{"지수함수"},{"직각"},{"직각삼각형"},
	{"직교"},{"직사각형"},{"직선"},{"직육면체"},{"진부분집합"},{"집합"},{"짝수"},{"차수"},{"차집합"},
	{"최대공약수"},{"최댓값"},{"최소공배수"},{"최솟값"},{"축"},{"켤레복소수"},{"코사인"},{"탄젠트"},
	{"통분"},{"팩토리얼"},{"판별식"},{"평각"},{"평균"},{"평면"},{"평행"},{"평행사변형"},{"평행이동"},
	{"표"},{"표준편차"},{"피타고라스의 정리"},{"필요충분조건"},{"함수"},{"합동"},{"합집합"},{"항"},
	{"항등식"},{"해"},{"현"},{"호"},{"홀수"},{"확률"},{"히스토그램"} };//237개

//짧은글모음
char proverb[120][100] = { {"가는 날이 장날이다"},{"가는 말이 고와야 오는 말이 곱다"},{"가까운 이웃이 먼 친척보다 낫다"},
	{"가랑비에 옷 젖는 줄 모른다"},{"가까운 집 며느리일수록 흉이 많다"},{"가까운 제 눈썹 못 본다"},{"가난한 집 제사 돌아오듯 한다"},
	{"꿩 대신 닭"},{"가재는 게 편"},{"가지 많은 나무에 바람 잘 날이 없다"},{"개똥도 약에 쓰려면 없다"},{"개천에서 용 난다"},
	{"금강산도 식후경"},{"찬물도 위아래가 있다"},{"소 잃고 외양간 고친다"},{"말 한마디로 천 냥 빚을 갚는다"},
	{"강 건너 불구경 하듯 한다"},{"공든 탑이 무너지랴"},{"그림의 떡"},{"꿩 먹고 알 먹기"},{"낮말은 새가 듣고 밤말은 쥐가 듣는다"},
	{"다 된 밥에 재 뿌리기"},{"도둑이 제 발 저린다"},{"돌다리도 두드려 보고 건너라"},{"등잔 밑이 어둡다"},{"똥 묻은 개가 겨 묻은 개 나무란다"},
	{"마른 하늘에 날벼락"},{"믿는 도끼에 발등 찍힌다"},{"백지장도 맞들면 낫다"},{"바늘 도둑이 소 도둑 된다"},{"발 없는 말이 천리 간다"},
	{"배보다 배꼽이 더 크다"},{"소문난 잔치에 먹을 것 없다"},{"식은 죽먹기"}

};

//전체
char all[1000][100] = { {"가는 날이 장날이다"},{"가는 말이 고와야 오는 말이 곱다"},{"가까운 이웃이 먼 친척보다 낫다"},
	{"가랑비에 옷 젖는 줄 모른다"},{"가까운 집 며느리일수록 흉이 많다"},{"가까운 제 눈썹 못 본다"},{"가난한 집 제사 돌아오듯 한다"},
	{"꿩 대신 닭"},{"가재는 게 편"},{"가지 많은 나무에 바람 잘 날이 없다"},{"개똥도 약에 쓰려면 없다"},{"개천에서 용 난다"},
	{"금강산도 식후경"},{"찬물도 위아래가 있다"},{"소 잃고 외양간 고친다"},{"말 한마디로 천 냥 빚을 갚는다"},{"가우스"},{"각"},{"각도"},{"각뿔"},{"각뿔대"},{"거듭제곱"},
	{"거듭제곱근"},{"겉넓이"},{"겨냥도"},{"결합법칙"},{"경우의 수"},{"곡선"},{"곱"},{"곱셈"},{"공배수"},
	{"공약수"},{"공역"},{"공집합"},{"관계식"},{"교점"},{"교집합"},{"교환법칙"},{"구"},{"귀류법"},{"그래프"},
	{"근"},{"근삿값"},{"근의 공식"} ,{"근호"},{"기약 분수"},{"기울기"},{"꼭짓점"},{"나눗셈"},{"나머지"},{"내각"},
	{"내분점"},{"내심"},{"내접"},{"내접원"},{"넓이"},{"높이"},{"다각형"},{"다면체"},{"다항식"},
	{"단면"},{"단항식"},{"닮음"},{"닮음비"},{"대각선"},{"대변"},{"대분수"},{"대입"},{"대칭"},{"대칭이동"},
	{"대칭축"}, {"대푯값"},{"덧셈"},{"도수분포표"},{"동위각"},{"동류항"},{"둔각"},{"둘레"},{"등변사다리꼴"},
	{"등식"},{"등호"},{"로그"},{"로그 함수"},{"마름모"},{"막대그래프"},{"맞꼭지각"},{"면"},{"명제"},
	{"모서리"},{"모선"},{"몫"},{"무게중심"},{"무리수"},{"무한대"},{"무한소수"},{"미지수"},{"밑"},{"밑변"},
	{"반비례"},{"반올림"},{"반지름"},{"반직선"},{"받아올림"},{"방정식"},{"배수"},{"백분율"},{"벡터"},{"변"},
	{"변수"},{"복소수"},{"부등식"},{"부등호"},{"부분집합"},{"부채꼴"},{"부피"},{"분모"},{"분배법칙"},
	{"분수"},{"분자"},{"비"},{"비례식"},{"비율"},{"뺄셈"},{"사각형"},{"사다리꼴"},{"사인"},{"산술평균"},
	{"삼각비"},{"삼각함수"},{"삼각형"},{"삼단논법"},{"상수"},{"상수항"},{"상용로그"},{"서로소"},{"선분"},
	{"소수"},{"소인수"},{"소인수분해"},{"수선"},{"수선의 발"},{"수직"},{"수직이등분선"},{"순서쌍"},{"순환소수"},
	{"순열"},{"실수"},{"약분"},{"약수"},{"양수"},{"엇각"},{"여집합"},{"역수"},{"역함수"},{"연립방정식"},
	{"연립부등식"},{"예각"},{"완전제곱식"},{"외각"},{"외분점"},{"외심"},{"외접"},{"외접원"},{"원"},
	{"원기둥"},{"원뿔"},{"원뿔대"},{"원소"},{"원점"},{"원주"},{"원주율"},{"원주각"},{"유한소수"},{"음수"},
	{"이등변 삼각형"},{"이차방정식"},{"이차부등식"},{"이차함수"},{"이항"},{"인수"},{"인수분해"},{"일차방정식"},
	{"일차함수"},{"입체도형"},{"자연수"},{"전개"},{"절댓값"},{"점"},{"접선"},{"접점"},{"정다각형"},{"정다면체"},
	{"정비례"},{"정사각형"},{"정삼각형"},{"정수"},{"정의"},{"제곱근"},{"조합"},{"조립제법"},{"좌표"},{"좌표평면"},
	{"중근"},{"중선"},{"중심각"},{"중점"},{"증명"},{"지름"},{"지수"},{"지수함수"},{"직각"},{"직각삼각형"},
	{"직교"},{"직사각형"},{"직선"},{"직육면체"},{"진부분집합"},{"집합"},{"짝수"},{"차수"},{"차집합"},
	{"최대공약수"},{"최댓값"},{"최소공배수"},{"최솟값"},{"축"},{"켤레복소수"},{"코사인"},{"탄젠트"},
	{"통분"},{"팩토리얼"},{"판별식"},{"평각"},{"평균"},{"평면"},{"평행"},{"평행사변형"},{"평행이동"},
	{"표"},{"표준편차"},{"피타고라스의 정리"},{"필요충분조건"},{"함수"},{"합동"},{"합집합"},{"항"},
	{"항등식"},{"해"},{"현"},{"호"},{"홀수"},{"확률"},{"히스토그램"},{"개"},{"쥐"},{"돼지"},{"원숭이"},{"고양이"},
    {"토끼"},{"소"},{"양"},{"말"},{"호랑이"},{"닭"},{"너구리"},{"북극여우"},
	{"라쿤"},{"미어캣"},{"다람쥐"},{"하늘다람쥐"},{"기니피그"},{"알파카"},{"라마"},{"사슴"},{"고슴도치"},
	{"나무늘보"},{"박쥐"},{"아르마딜로"},{"까치"},{"동해물과 백두산이 마르고 닳도록"}, {"하느님이 보우하사 우리나라 만세"},
{ "무궁화 삼천리 화려강산" }, { "대한사람 대한으로 길이 보전하세." },
	{"남산 위에 저 소나무 철갑을 두른 듯"},{"바람 서리 불변함은 우리 기상일세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."},
	{"가을 하늘 공활한데 높고 구름 없이"},{"밝은 달은 우리가슴 일편 단심일세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."},
	{"이 기상과 이 맘으로 충성을 다하여"},{"괴로우나 즐거우나 나라 사랑하세"},
	{"무궁화 삼천리 화려강산"},{"대한사람 대한으로 길이 보전하세."}, {"대한민국의 상업정보계열 특성화고등학교."},{"IT 직업계학교 중 명성이 자자하다."},
{"경기도 안산시 단원구 사세충열로 94"},{"운영주체인 학교법인 이산학원은 중견 철강 재벌 계열 이다."},
	{"학교 공식 행사에서 마무리를 지을 때,"},{"대부분 교가를 1절까지만 부른다."},
	{"학교 교복은 동복,하복,체육복,생활복으로 구성되어있다."},{"등교할 때는 여름철 하복 또는 생활복, 겨울철은 동복 착용이 원칙이다."},
	{"체육복은 체육시간 전후 1시간만 착용이 가능하다."},{"귀가시 반드시 교복만 착용해야하며,"},
	{"일요일 오후 귀교 시에는 사복 착용이 가능하다."},{"여학생의 남학생 바지 착용은 가능하지만 남학생 하복 셔츠 착용은 금지되어있다."},
	{"학과는 총 4개로 구성되어있으며,"},{"e-비지니스과,디지털컨텐츠과,웹프로그래밍과,해킹방어과가 있다."},
	{"남녀공학이며, 과별/기수별로 성비가 천차만별이다."},{"오전 6시30분 기상송과 함께 일과가 시작된다."},
	{"주말이나 공휴일의 경우에는 7시이다."},{"생활관 인트라넷인 디미고라이프에서 기상곡 신청을 할 수 있다."},
	{"급식이 정말 맛있다."},{"전교생이 전문 교과 시간 중 프로그래밍,디자인 등의 실습을 위해"},
	{"노트북을 소지하고있다."},{"교내에서는 원칙상 노트북을 통해 공부 이외의 행위는 할 수 없다"},
	{"강 건너 불구경 하듯 한다"},{"공든 탑이 무너지랴"},{"그림의 떡"},{"꿩 먹고 알 먹기"},{"낮말은 새가 듣고 밤말은 쥐가 듣는다"},
	{"다 된 밥에 재 뿌리기"},{"도둑이 제 발 저린다"},{"돌다리도 두드려 보고 건너라"},{"등잔 밑이 어둡다"},{"똥 묻은 개가 겨 묻은 개 나무란다"},
	{"마른 하늘에 날벼락"},{"믿는 도끼에 발등 찍힌다"},{"백지장도 맞들면 낫다"},{"바늘 도둑이 소 도둑 된다"},{"발 없는 말이 천리 간다"},
	{"배보다 배꼽이 더 크다"},{"소문난 잔치에 먹을 것 없다"},{"식은 죽먹기"} };//318개

//구조체
struct User
{
	int longmax[5];
	int shortmax[5];
	int wordmax[5];
	int allmax[5];
};
struct User p1;
int title()
{
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                             타   자   게   임                            □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□                               Made by KSH                                □\n");
	printf("□                                                                          □\n");
	printf("□                           Tester:Clock,Eunty                             □\n");
	printf("□                                                vBeta2.10                 □\n");
	printf("□                                                                          □\n");
	printf("□                                                                          □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	system("pause");
	system("cls");
	Sleep(1000);
}
int rule()
{
	printf("룰 설명입니다\n");
	printf("1)문장이 주어집니다	\n");
	printf("2)주어진 문장을 보고 똑같이 입력합니다\n");
	printf("3)정답이라면 2000-(걸린시간*100)의 점수가 추가됩니다\n");
	printf("4)오답이라면 점수가 추가되지 않습니다\n");
	printf("5)영어로 설정되어있으니 한 / 영키를 누르고 시작해주세요.\n");
	system("pause");
	Sleep(1000);
	system("cls");
}
int egukka_1()
{
	
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	for (int i = 0; i <= 4; i++)
	{
		if (i == 0)
		{
			puts(eguk_1[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		//count();
		puts(eguk_1[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(eguk_1[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);

		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (p1.longmax[0] < score)
	{
		p1.longmax[0] = score;
	}

	Sleep(1000);
	egukka_retry_1();

}
int egukka_regame_1()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	for (int i = 0; i <= 4; i++)
	{
		if (i == 0)
		{
			puts(eguk_1[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(eguk_1[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(eguk_1[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (score > p1.longmax[0])
	{
		p1.longmax[0] = score;
	}
	Sleep(1000);
	egukka_retry_1();

}
int egukka_retry_1()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		egukka_regame_1();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int egukka_1_4()
{
	
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	for (int i = 0; i <= 16; i++)
	{
	    if (i == 0)
		{
			puts(eguk_1[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(eguk_1_4[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(eguk_1_4[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (score > p1.longmax[1])
	{
		p1.longmax[1] = score;
	}
	Sleep(1000);
	egukka_retry_1_4();

}
int egukka_regame_1_4()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	for (int i = 0; i <= 16; i++)
	{
		if (i == 0)
		{
			puts(eguk_1_4[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(eguk_1_4[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(eguk_1_4[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (score > p1.longmax[1])
	{
		p1.longmax[1] = score;
	}
	Sleep(1000);
	egukka_retry_1_4();

}
int egukka_retry_1_4()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		egukka_regame_1_4();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int Animal()
{
	srand(time(NULL));
	int tf = 0;
	int score = 0;
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 100; i++)
	{
		int a = 0;
		
		a = rand() % 26;
		if (i == 0)
		{
			puts(word_animal[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(word_animal[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(word_animal[a], User_ans[i]);
		system("cls");

		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy,"%");


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");
		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도 : %d%s\n", accuracy,"%");
	if (score > p1.wordmax[0])
	{
		p1.wordmax[0] = score;
	}
	Sleep(1000);
	Animal_retry();

}
int Animal_retry()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		Animal_regame();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int Animal_regame()
{
	srand(time(NULL));
	int tf = 0;
	int score = 0;
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 100; i++)
	{
		int a = 0;

		a = rand() % 26;
		if (i == 0)
		{
			puts(word_animal[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		
		puts(word_animal[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(word_animal[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");

		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");
		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도 : %d%s\n", accuracy, "%");
	if (score > p1.wordmax[0])
	{
		p1.wordmax[0] = score;
	}
	Sleep(1000);
	Animal_retry();

}
int Math()
{
	srand(time(NULL));
	int tf = 0;
	int score = 0;
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 100; i++)
	{
		int a = 0;

		a = rand() % 237;
		if (i == 0)
		{
			puts(word_math[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(word_math[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(word_math[a], User_ans[i]);
		system("cls");

		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");
		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도 : %d%s\n", accuracy, "%");
	if (score > p1.wordmax[1])
	{
		p1.wordmax[1] = score;
	}
	Sleep(1000);
	Math_retry();

}
int Math_retry()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		Math_regame();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int Math_regame()
{
	srand(time(NULL));
	int tf = 0;
	int score = 0;
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 100; i++)
	{
		int a = 0;

		a = rand() % 237;
		if (i == 0)
		{
			puts(word_math[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}

		puts(word_math[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(word_math[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");

		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도 : %d%s\n", accuracy, "%");
		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도 : %d%s\n", accuracy, "%");
	if (score > p1.wordmax[1])
	{
		p1.wordmax[1] = score;
	}
	Sleep(1000);
	Math_retry();

}


int dimi()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 22; i++)
	{
		if (i == 0)
		{
			puts(dimigo[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		//count();
		puts(dimigo[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(dimigo[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도:%d%s\n", accuracy,"%");


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도:%d%s\n", accuracy, "%");
	if (score > p1.longmax[2])
	{
		p1.longmax[2] = score;
	}
	Sleep(1000);
	dimi_retry();
}
int dimi_retry()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
	    dimi_regame();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int dimi_regame()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 22; i++)
	{
		if (i == 0)
		{
			puts(dimigo[i]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		//count();
		puts(dimigo[i]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(dimigo[i], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도:%d%s\n", accuracy, "%");

		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도:%d%s\n", accuracy, "%");
	if (score > p1.longmax[2])
	{
		p1.longmax[2] = score;
	}
	Sleep(1000);
	dimi_retry();
}


int Proverb()
{

	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 20; i++)
	{
		int a = 0;
		a = rand() % 34;
		if (i == 0)
		{
			puts(proverb[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(proverb[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(proverb[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도:%d%s\n", accuracy, "%");
		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도:%d%s\n", accuracy, "%");
	if (score > p1.shortmax[0])
	{
		p1.shortmax[0] = score;
	}
	Sleep(1000);
	Proverb_retry();
}
int Proverb_retry()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		Proverb_regame();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int Proverb_regame()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int a = 0;
	int count = 0;
	int accuracy = 0;
	for (int i = 0; i <= 20; i++)
	{ 
		int a = 0;
		a = rand() % 34;
		if (i == 0)
		{
			puts(proverb[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		puts(proverb[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(proverb[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			count++;
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);
			accuracy = (count * 100) / i;
			printf("정확도:%d%s\n", accuracy, "%");


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("점수:%d\n", score);

		}
	}
	printf("최종점수는!!!  %d\n", score);
	printf("정확도:%d%s\n", accuracy, "%");
	if (score > p1.shortmax[0])
	{
		p1.shortmax[0] = score;
	}
	Sleep(1000);
	Proverb_retry();
}

int perfect()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int a = 0;

	for (int i = 0; i <= 200; i++)
	{
		a = rand() % 318;
		if (i == 0)
		{
			puts(all[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		//count();
		puts(all[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(all[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("GAME OVER\n");
			break;

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (score > p1.allmax[0])
	{
		p1.allmax[0];
	}
	Sleep(1000);
	perfect_retry();
}
int perfect_retry()
{
	int re = 0;
	printf("다시 하려면 1  메뉴로 가려면 0을 입력해주세요\n");
	scanf("%d", &re);
	if (re == 1)
	{
		printf("다시 시작하겠습니다\n");
		Sleep(1000);
		system("cls");
		perfect_regame();
	}
	else
	{
		printf("메뉴로 이동합니다\n");
		Sleep(1000);
		system("cls");
		menu();
	}
}
int perfect_regame()
{
	int tf = 0;
	int score = 0;
	char nn = { NULL };
	int a = 0;

	for (int i = 0; i <= 200; i++)
	{
		a = rand() % 318;
		if (i == 0)
		{
			puts(all[a]);
			gets(User_ans[i]);
			system("cls");
			continue;
		}
		//count();
		puts(all[a]);
		clock_t start = clock();
		gets(User_ans[i]);
		tf = strcmp(all[a], User_ans[i]);
		system("cls");
		if (tf == 0)
		{
			printf("정답입니다!!\n");
			clock_t end = clock();
			printf("걸린시간:%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
			score = score + fscore - ((double)(end - start) / CLOCKS_PER_SEC) * 100;
			printf("점수:%d\n", score);


		}
		else
		{
			printf("틀렸습니다..\n");
			printf("GAME OVER\n");
			break;

		}
	}
	printf("최종점수는!!!  %d\n", score);
	if (score > p1.allmax[0])
	{
		p1.allmax[0] = score;
	}
	Sleep(1000);
	perfect_retry();
}
int menu()
{
	int ch = 0;
	printf("★  [1]긴 글 연습    ★\n");
	printf("☆  [2]짧은 글 연습  ☆\n");
	printf("★  [3]낱말 연습     ★\n");
	printf("☆  [4]완벽 모드     ☆\n");
	printf("※종료시에는 alt-f4를 눌러주세요\n");
	scanf("%d", &ch);
	switch (ch)
	{
	
	case 1:
		system("cls");
		Long();
	case 2:
		system("cls");
		Short();
	case 3:

		system("cls");
		Word();
	case 4:
		system("cls");
		perfect_intro();
		
	default:
		menu();
	}
}
int Long()
{
	int cho = 0;
	printf("☆  [0]되돌아가기      ☆\n");
	printf("★  [1]애국가 1절(4)   ★\n");
	printf("☆  [2]애국가1~4절(16) ☆\n");
	printf("★  [3]디미고(22)      ★\n");
	printf("☆  [4]추가예정        ☆\n");
	printf("    현재 최고기록   \n");
	printf("   애국가 1절:%d점\n" , p1.longmax[0]);
	printf("   애국가 1~4절:%d점\n", p1.longmax[1]);
	printf("   디미고:%d점\n", p1.longmax[2]);
	scanf("%d", &cho);
	switch (cho)
	{
	case 0:
		system("cls");
		menu();
	case 1:
		system("cls");
		egukka_1();
	case 2:
		system("cls");
		egukka_1_4();
	case 3:

		system("cls");
		dimi();
	case 4:
		printf("추가될 예정입니다\n");
		Sleep(1000);
		system("cls");
		menu();
	default:
		menu();
	}
}
int Short()
{
	int cho = 0;
	printf("☆  [0]되돌아가기  ☆\n");
	printf("★  [1]속담        ★\n");
	printf("    현재 최고기록  \n");
	printf("속담:%d점\n", p1.shortmax[0]);
	scanf("%d", &cho);
	switch (cho)
	{
	case 0:
		system("cls");
		menu();
	case 1:
		system("cls");
		Proverb();
	case 2:
		printf("추가될 예정입니다\n");
		Sleep(1000);
		system("cls");
		menu();
			
	default:
		menu();
	}
}
int Word()
{
	int cho = 0;
	printf("☆  [0]되돌아가기  ☆\n");
	printf("★  [1]동물        ★\n");
	printf("☆  [2]수학        ☆\n");
	printf("★  [3]추가예정    ★\n");
	printf("  현재 최고기록\n");
	printf("동물:%d점\n", p1.wordmax[0]);
	printf("수학:%d점\n", p1.wordmax[1]);
	scanf("%d", &cho);
	switch (cho)
	{
	case 0:
		system("cls");
		menu();
	case 1:
		system("cls");
		Animal();
	case 2:
		system("cls");
		Math();
	case 3:
		system("cls");
		dimi();
		
	default:
		menu();
	}
}
int perfect_intro()
{
	int ans = 0;
	printf("완벽 모드의 룰 설명입니다 기본적인 룰은 그대로 이며\n");
	printf("한 번이라도 실수를 하면 그대로 게임이 종료됩니다\n");
	printf("모든 카테고리의 문장,단어들이 나오며 총 200개의 문장,단어가 나옵니다\n");
	printf("[0]돌아가기 [1]시작\n");
	printf("   현재 최고기록\n");
	printf("%d점\n", p1.allmax[0]);
	scanf("%d", &ans);
	if (ans == 0)
	{
		menu();
	}
	else if (ans == 1)
	{
		perfect();
	}
	else
	{
		perfect_intro();
	}
}
int main()
{

	system("title 타자게임");
	system("mode con:cols=80 lines=30");
	title();
	rule();
    menu();
	return 0;


}