#pragma once

#include "hitpointtypes.h"
class hp {
public:
	bool setMaxHp(hptype new_max_hp) {
		if (new_max_hp < 1)
			return false;

		MaxHP = new_max_hp;

		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;

		return true;
	}

	hptype getMaxHp() {
		return MaxHP;
	}

	hptype getCurrnetHp(){
		return CurrentHP;
	}

	void takeDamage(hptype damage) {
		if (damage > CurrentHP) {
			CurrentHP = 0;
			return;
		}

		CurrentHP -= damage;

	}

	void heal(hptype heal_amount) {
		if (heal_amount + CurrentHP >= MaxHP) {
			CurrentHP = MaxHP;
			return;
		}
		CurrentHP += heal_amount;
	}
	
private:
	
	hptype CurrentHP;
	hptype MaxHP;
};