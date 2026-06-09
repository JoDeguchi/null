// null.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <assert.h>	//	デバッグ時のチェック用製品版では実態がなくなる	

class Weapon
{
public:
	void use(){}

};

class Player {
	std::shared_ptr<Weapon>weapon;
public:

	Player(std::shared_ptr<Weapon>weapon1)
		:weapon(std::move(weapon1))
	{
		std::cout << weapon.use_count() << std::endl;
		std::cout << weapon1.use_count() << std::endl;
	}
	void Attack()
	{
		if (weapon)weapon->use();
	}
};

int main()
{
	auto a = std::make_shared<Player>(std::make_shared<Weapon>());

	std::cout << "a: " << a.use_count() << std::endl;

	auto b = a;

	std::cout << "a: " << a.use_count() << std::endl;
	std::cout << "b: " << b.use_count() << std::endl;

	auto c = std::move(a);

	std::cout << "a: " << a.use_count() << std::endl;
	std::cout << "b: " << b.use_count() << std::endl;
	std::cout << "c: " << c.use_count() << std::endl;

	assert(a != nullptr);
	a->Attack();
	



	////	コピーするように
	//auto wp = std::make_shared<Weapon>();

	//auto a=std::make_shared<int>();
	//auto b = a;
	//auto c = std::move(a);

	////	コピー
	//Player p(wp); 
	////	ムーブ（所有権を移動）メモリの効率化がよくなる
	//Player q(std::move(wp));
	//return 0;
}






