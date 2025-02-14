#include "plant.hpp"
#include "GameWorld.hpp"


void Sunflower_Seed::Update() {                               // Sunflower 
  if (cold_state == 1) {
    ptr_world->Set_cooling(1);
    ++trik_copy;
  }
  if (trik_copy == 240) {
    cold_state = 0;
    trik_copy = 0;
  }
}
void Sunflower_Seed::OnClick() {
  if (ptr_world->GetSun() >= 50 && cold_state == 0 && ptr_world->getplant() == 0 && ptr_world->Get_holding_shovel() == 0) {
    ptr_world->SetSun(ptr_world->GetSun() - 50);
    cold_state = 1;
    ptr_world->Set_cooling(1);
    ptr_world->setplant(1);
  }
}
void Sunflower::Update() {
  ++trik_copy;
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if ((trik_copy - first_porduce) % 600 == 0) {
    ptr_world->set_show_time(1);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
}
void Sunflower::OnClick() {
  if (ptr_world->Get_holding_shovel() == 1) {
    SetState(0);
    ptr_world->Set_holding_shovel(0);
  } 
}


void Peashooter_Seed::Update() {                              // Peashooter
  if (cold_state == 1) {
    ++trik_copy;
    ptr_world->Set_cooling(1);
  }
  if (trik_copy == 240) {
    cold_state = 0;
    trik_copy = 0;
  }
}
void Peashooter_Seed::OnClick() {
  if (ptr_world->GetSun() >= 100 && cold_state == 0 && ptr_world->getplant() == 0 && ptr_world->Get_holding_shovel() == 0) {
    ptr_world->SetSun(ptr_world->GetSun() - 100);
    cold_state = 1;
    ptr_world->Set_cooling(1);
    ptr_world->setplant(2);
  }
}
void Peashooter::Update() {
  ++trik_copy;
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (get_zombie_right() == 1 && trik_copy % 30 == 1) {
    ptr_world->set_show_time(2);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
}
void Peashooter::OnClick() {
  if (ptr_world->Get_holding_shovel() == 1) {
    SetState(0);
    ptr_world->Set_holding_shovel(0);
  } 
}


void Wallnut_Seed::Update() {                                 // Wallnut
  if (cold_state == 1) {
    ++trik_copy;
    ptr_world->Set_cooling(1);
  }
  if (trik_copy == 900) {
    cold_state = 0;
    trik_copy = 0;
  }
}
void Wallnut_Seed::OnClick() {
  if (ptr_world->GetSun() >= 50 && cold_state == 0 && ptr_world->getplant() == 0 && ptr_world->Get_holding_shovel() == 0) {
    ptr_world->SetSun(ptr_world->GetSun() - 50);
    cold_state = 1;
    ptr_world->Set_cooling(1);
    ptr_world->setplant(3);
  }
}
void Wallnut::Update() {
  ++trik_copy;
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (hp < 4000 / 3) {
    set_change_low(1);
  }
}
void Wallnut::OnClick() {
  if (ptr_world->Get_holding_shovel() == 1) {
    SetState(0);
    ptr_world->Set_holding_shovel(0);
  } 
}


void Cherry_Bomb_Seed::Update() {                             // Cherry_Bomb
  if (cold_state == 1) {
    ++trik_copy;
    ptr_world->Set_cooling(1);
  }
  if (trik_copy == 1200) {
    cold_state = 0;
    trik_copy = 0;
  }
}
void Cherry_Bomb_Seed::OnClick() {
  if (ptr_world->GetSun() >= 150 && cold_state == 0 && ptr_world->getplant() == 0 && ptr_world->Get_holding_shovel() == 0) {
    ptr_world->SetSun(ptr_world->GetSun() - 150);
    cold_state = 1;
    ptr_world->Set_cooling(1);
    ptr_world->setplant(4);
  }
}
void Cherry_Bomb::Update() {
  ++trik_copy;
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (trik_copy == 15) {
    ptr_world->setplant(9999);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
    SetState(0);
  }
}
void Cherry_Bomb::OnClick() {
  if (ptr_world->Get_holding_shovel() == 1) {
    SetState(0);
    ptr_world->Set_holding_shovel(0);
  } 
}
void Explosion::Update() {
  ++trik_copy;
  if (trik_copy == 3) {
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
    SetState(0);
  }
}
void Explosion::OnClick() {}


void Repeater_Seed::Update() {                                // Repeater
  if (cold_state == 1) {
    ++trik_copy;
    ptr_world->Set_cooling(1);
  }
  if (trik_copy == 240) {
    cold_state = 0;
    trik_copy = 0;
  }
}
void Repeater_Seed::OnClick() {
  if (ptr_world->GetSun() >= 200 && cold_state == 0 && ptr_world->getplant() == 0 && ptr_world->Get_holding_shovel() == 0) {
    ptr_world->SetSun(ptr_world->GetSun() - 200);
    cold_state = 1;
    ptr_world->Set_cooling(1);
    ptr_world->setplant(5);
  }
}
void Repeater::Update() {
  ++trik_copy;
  if (hp <= 0) {
    SetState(0);
    return;
  }
  if (get_zombie_right() == 1 && (trik_copy % 30 == 1 || trik_copy % 30 == 6)) {
    ptr_world->set_show_time(2);
    ptr_world->set_x(GetX());
    ptr_world->set_y(GetY());
  }
}
void Repeater::OnClick() {
  if (ptr_world->Get_holding_shovel() == 1) {
    SetState(0);
    ptr_world->Set_holding_shovel(0);
  } 
}