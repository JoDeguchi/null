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

class Sword : public Weapon {};

int main()
{

	auto sword = std::make_shared<Sword>();

	Player p(sword);
	Player p1(std::move(sword));


}





////	コピーするように
//auto wp = std::make_shared<Weapon>();


////	コピー
//Player p(wp); 
////	ムーブ（所有権を移動）メモリの効率化がよくなる
//Player q(std::move(wp));
//return 0;

