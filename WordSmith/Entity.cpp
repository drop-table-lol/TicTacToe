#include "Entity.h"

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cin;

/*TODO
	Make Virtual functions
	Better inheritance patterns
*/

Entity::Entity(int type_of_entity) {
  type_of_entity_ = type_of_entity;
  GenerateName();
  health_ = 10;
  base_power_ = 1;
  dexterity_ = base_power_;
  strength_ = base_power_;
}


int Entity::GetHealth(){
  return health_;
}

void Entity::TakeDamage(int damage_to_take) {
  health_ -= damage_to_take;
}

void Entity::RestoreHealth(int health_to_restore) {
  health_ += health_to_restore;
}

void Entity::SetEntityType(int entity_type) {
  type_of_entity_ = entity_type;
}

void Entity::GenerateName() {
  switch(type_of_entity_) {
  case(0):
    name_of_entity_ = "The Unmistakable Hero";
    return;
  case(1):
    name_of_entity_ = "The Unfathomable Beast";
    return;
  case(2):
    name_of_entity_ = "The Undead Queen";
    return;
  case(3):
    name_of_entity_ = "The Unknown Challenger";
    return;
  }
}

string Entity::ReturnName() {
  return name_of_entity_;
}



string Entity::GetAction() {
  if (type_of_entity_ == 0) {
    string input;
    cin >> input;
    return input;
  }
  else {
    int choice;
    choice = (rand() % 3);
    switch(choice) {
      case(0):
        return "quick";
      case(1):
        return "block";
      case(2):
        return "heavy"; //no breaks since we're returning out of switch.
    }
    return "";
  }
}

bool Entity::IsDead() {
	if (health_<=0) {
		return true;
	}
	else {
		return false;
	}
}

void Entity::LevelUp() {
  IncreaseDexterity();
  IncreaseStrength();
} //something simple for now...?

int Entity::GetDexterity() {
	return dexterity_;
}

void Entity::IncreaseDexterity() {
	++dexterity_;
}
void Entity::DecreaseDexterity() {
	--dexterity_;
}
void Entity::SetDexterity(int new_dexterity) {
	dexterity_ = new_dexterity;
}

int Entity::GetStrength(){
	return strength_;
}
void Entity::IncreaseStrength() {
	++strength_;
}
void Entity::DecreaseStrength() {
	--strength_;
}
void Entity::SetStrength(int new_strength) {
	strength_ = new_strength;
}
