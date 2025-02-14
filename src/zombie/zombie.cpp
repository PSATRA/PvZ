#include "zombie.hpp"
#include "GameWorld.hpp"

void Regular_Zombie::Update() {                                   // Regular_Zombie
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (Get_is_eating() == 0) {
    MoveTo(GetX() - 1, GetY());

  }
  
}
void Regular_Zombie::OnClick() {}


void Bucket_Head_Zombie::Update() {                               // Bucket_Head_Zombie
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (Get_is_eating() == 0) {
    MoveTo(GetX() - 1, GetY());

  }
  
  if (hp <= 200) {
    Set_lose_bucket(1);
  }
}
void Bucket_Head_Zombie::OnClick() {}


void Pole_Vaulting_Zombie::Update() {                             // Pole_Vaulting_Zombie
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (Get_run() == 1) {
    MoveTo(GetX() - 2, GetY());
    
  }
  else if (Get_is_eating() == 0) {
    MoveTo(GetX() - 1, GetY());

  }
  
}
void Pole_Vaulting_Zombie::OnClick() {}

