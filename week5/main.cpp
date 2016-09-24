//结构体，共用体，枚举
#include <iostream>
enum myEnum {
	a, b, c, d = 4, e = 9
};
enum class myEnumClass {
	f, g, h, i, j
};
union uselessUnion {
	int a;
	double b;
};
struct myStruct {
	myEnum a;
	int b;
	myEnumClass c;
	uselessUnion d;
}wow;
struct kurise
{
	int heightInFoot;
	int heightInInch;
	float heightInMeter;
	int weightInPound;
	float weightInKg;
	float BMI;
};
kurise calculateBMI(kurise MakiseKurise) {
	MakiseKurise.heightInMeter = (MakiseKurise.heightInFoot * 12 + MakiseKurise.heightInInch)*0.0254;
	MakiseKurise.weightInKg = MakiseKurise.weightInPound / 2.2;
	MakiseKurise.BMI = MakiseKurise.weightInKg / (MakiseKurise.heightInMeter*MakiseKurise.heightInMeter);
	return MakiseKurise;
}
void BMImain() {
	kurise MakiseKurise;
	std::cout << "输入助手的身高（foot,inch):";
	std::cin >> MakiseKurise.heightInFoot >> MakiseKurise.heightInInch;
	std::cout << std::endl;
	std::cout << "输入助手的体重(Pound):";
	std::cin >> MakiseKurise.weightInPound;
	std::cout << std::endl;
	MakiseKurise = calculateBMI(MakiseKurise);
	std::cout << MakiseKurise.BMI;
}
void BMImain2() {
	float a, b;
	std::cin >> a >> b;
	std::cout << b / (a*a);
}
int main() {
	myStruct mystr = {myEnum::a,2,myEnumClass::f,2};
	uselessUnion hgj;
	hgj.a = 1;
	hgj.b = 1.2;
	int a = 0;
	a += mystr.a;//整形提升
				 //a+=mystr.c;error
	a += myEnum::e;
	mystr.d.b = 12.3;
	wow = { myEnum::a,
		2,
		myEnumClass::f,
		1 }
	;
	for (;;)
		BMImain2();

	system("pause");
}
//枚举