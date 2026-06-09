// null.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <assert.h>	//	製品版では実態がなくなる	

class Test
{
public:
	void Show()
	{
		std:: cout << "Hello World" << std::endl;
	}
};


void Func(Test* test)
{
	assert(test != nullptr);
	test->Show();
}

int main()
{
	Func(new Test());
	Func(nullptr);

}

