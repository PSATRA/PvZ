#include "GameObject.hpp"
#include "GameWorld.hpp"
#include "utils.hpp"


bool GameObject::GetState() { return state; }
void GameObject::SetState(bool sta) { state = sta; }

bool GameObject::Getcool() { return cold_state; }
void GameObject::Setcool(bool sta) { cold_state = sta; }

bool GameObject::Getseed() { return is_seed; }
void GameObject::Setseed(bool sta) { is_seed = sta; }
bool GameObject::Getmask() { return is_mask; }
void GameObject::Setmask(bool sta) { is_mask = sta; }

bool GameObject::get_zombie_right() { return zombie_right; }
void GameObject::set_zombie_right(bool sta) { zombie_right = sta; }

bool GameObject::get_is_shooter() { return is_shooter; }
void GameObject::set_is_shooter(bool sta) { is_shooter = sta; }

bool GameObject::get_is_zombie() { return is_zombie; }
void GameObject::set_is_zombie(bool sta) { is_zombie = sta; }

bool GameObject::get_is_pea() { return is_pea; }
void GameObject::set_is_pea(bool sta) { is_pea = sta; }

bool GameObject::get_change_low() { return change_low; }
void GameObject::set_change_low(bool sta) { change_low = sta; }

bool GameObject::get_is_explosion() { return is_explosion; }
void GameObject::set_is_explosion(bool sta) { is_explosion = sta; }

bool GameObject::get_is_plant() { return is_plant; }
void GameObject::set_is_plant(bool sta) { is_plant = sta; }

bool GameObject::Get_walk() { return walk; }
void GameObject::Set_walk(bool sta) { walk = sta; }
bool GameObject::Get_run() { return run; }
void GameObject::Set_run(bool sta) { run = sta; }

int  GameObject::get_hp() { return hp; }
void GameObject::set_hp(int sta) { hp = sta; }

bool GameObject::Get_is_eating() { return is_eating; }
void GameObject::Set_is_eating(bool sta) { is_eating = sta; }

bool GameObject::Get_lose_bucket() { return lose_bucket; }
void GameObject::Set_lose_bucket(bool sta) { lose_bucket = sta; }



void background::Update() {}
void background::OnClick() {}

void spot::Update() {}
void spot::OnClick() {
  if (ptr_world->getplant() == 1) {                      // Sunflower
    ptr_world->setplant(11);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
  if (ptr_world->getplant() == 2) {                      // Peashooter
    ptr_world->setplant(12);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
  if (ptr_world->getplant() == 3) {                      // Wallnut
    ptr_world->setplant(13);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
  if (ptr_world->getplant() == 4) {                      // Cherry_Bomb
    ptr_world->setplant(14);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
  if (ptr_world->getplant() == 5) {                      // Repeater          
    ptr_world->setplant(15);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
}

void sun::Update() {
  ++trik_copy;
  if (is == 1 && trik_copy <= falltime_sky) {
    MoveTo(GetX(), GetY() - 2);
  }
  if (is == 1 && trik_copy == falltime_sky + 300) {
    SetState(0);
  }
  if (is == 0 && trik_copy <= falltime_flower) {
    MoveTo(GetX() - 1, GetY() + 5 - trik_copy);
  }
  if (is == 0 && trik_copy == falltime_flower + 300) {
    SetState(0);
  }
}    
void sun::OnClick() {
  ptr_world->SetSun(ptr_world->GetSun() + 25);
  SetState(0);
} 

void pea::Update() {
  ++trik_copy;
  MoveTo(GetX() + 8, GetY());
  if (GetX() >= WINDOW_WIDTH) {
    SetState(0);
  }
}    
void pea::OnClick() {} 

void Shovel::Update() {}
void Shovel::OnClick() {
  if (ptr_world->getplant() == 0) {
    if (ptr_world->Get_holding_shovel() == 0) {
      ptr_world->Set_holding_shovel(1);
      return;
    }
  }
  if (ptr_world->Get_holding_shovel() == 1) {
    ptr_world->Set_holding_shovel(0);
  }
}
 
void Cooldown_Mask::Update() {}    
void Cooldown_Mask::OnClick() {} 
