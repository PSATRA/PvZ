#include "GameWorld.hpp"
#include "plant.hpp"
#include "zombie.hpp"
#include <cmath>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

int  GameWorld::getplant() { return holding_seed; }
void GameWorld::setplant(int sta) { holding_seed = sta; }
int  GameWorld::get_x() { return current_x; }
void GameWorld::set_x(int sta) { current_x = sta; }
int  GameWorld::get_y() { return current_y; }
void GameWorld::set_y(int sta) { current_y = sta; }
int  GameWorld::get_show_time() { return show_time; }
void GameWorld::set_show_time(int sta) { show_time = sta; }
bool GameWorld::Get_holding_shovel() { return holding_shovel; }
void GameWorld::Set_holding_shovel(bool sta) { holding_shovel = sta; }
int  GameWorld::Get_cooling() { return cooling; }
void GameWorld::Set_cooling(int sta) { cooling = sta; }


//----------------------------------------------------------------GameWorld.init()
void GameWorld::Init() {
  // YOUR CODE HERE
  SetWave(0);
  SetSun(50);
  lst.push_back(std::make_shared<background>(                          // background
    IMGID_BACKGROUND, 
    WINDOW_WIDTH / 2,
    WINDOW_HEIGHT / 2,
    LAYER_BACKGROUND,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    ANIMID_NO_ANIMATION
  ));
  for (int i = 0; i < 9; ++i) {                                        // 45 spots
    for (int j = 0; j < 5; ++j) {
      lst.push_back(std::make_shared<spot>(
        IMGID_NONE, 
        FIRST_COL_CENTER + i * LAWN_GRID_WIDTH,
        FIRST_ROW_CENTER + j * LAWN_GRID_HEIGHT,
        LAYER_UI,
        60,
        80,
        ANIMID_NO_ANIMATION,
        shared_from_this()  
      ));
    }
  }
  lst.push_back(std::make_shared<Shovel>(                              // Shovel
    IMGID_SHOVEL, 
    600,
    WINDOW_HEIGHT - 40,
    LAYER_UI,
    50,
    50,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
  lst.push_back(std::make_shared<Sunflower_Seed>(                           // Sunflower_Seed
    IMGID_SEED_SUNFLOWER, 
    130,
    WINDOW_HEIGHT - 44,
    LAYER_UI,
    50,
    70,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
  lst.push_back(std::make_shared<Peashooter_Seed>(                          // Peashooter_Seed
    IMGID_SEED_PEASHOOTER, 
    190,
    WINDOW_HEIGHT - 44,
    LAYER_UI,
    50,
    70,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
  lst.push_back(std::make_shared<Wallnut_Seed>(                             // Wallnut_Seed
    IMGID_SEED_WALLNUT, 
    250,
    WINDOW_HEIGHT - 44,
    LAYER_UI,
    50,
    70,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
  lst.push_back(std::make_shared<Cherry_Bomb_Seed>(                         // Cherry_Bomb_Seed
    IMGID_SEED_CHERRY_BOMB, 
    310,
    WINDOW_HEIGHT - 44,
    LAYER_UI,
    50,
    70,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
  lst.push_back(std::make_shared<Repeater_Seed>(                            // Repeater_Seed
    IMGID_SEED_REPEATER, 
    370,
    WINDOW_HEIGHT - 44,
    LAYER_UI,
    50,
    70,
    ANIMID_NO_ANIMATION,
    shared_from_this()
  ));
}
  
//----------------------------------------------------------------GameWorld.update()
LevelStatus GameWorld::Update() {
  ++trik;  
  set_show_time(0); 

  for (auto it = lst.begin(); it != lst.end(); ++it) {                                               // pea <->> zombie
    if ((*it)->get_is_pea() == 1) {           
      for (auto itt = lst.begin(); itt != lst.end(); ++itt) {
        if ((*itt)->get_is_zombie() == 1) {   
          if ((*itt)->GetX() - (*it)->GetX() < 24 && (*itt)->GetX() - (*it)->GetX() > -24 && (*it)->GetY() - 20 == (*itt)->GetY()) {
            (*it)->SetState(0);
            (*itt)->set_hp((*itt)->get_hp() - 20);
          }
        }
      }
    }
  } 
  for (auto it = lst.begin(); it != lst.end(); ++it) {                                               // explosion <->> zombie
    if ((*it)->get_is_explosion() == 1) {           
      for (auto itt = lst.begin(); itt != lst.end(); ++itt) {
        if ((*itt)->get_is_zombie() == 1) {   
          if ((*itt)->GetX() - (*it)->GetX() < 10 + 1.5 * LAWN_GRID_WIDTH && (*itt)->GetX() - (*it)->GetX() > -(10 + 1.5 * LAWN_GRID_WIDTH) 
              && ((*it)->GetY() == (*itt)->GetY() || (*it)->GetY() == (*itt)->GetY() + LAWN_GRID_HEIGHT || (*it)->GetY() == (*itt)->GetY() - LAWN_GRID_HEIGHT)) {
            (*itt)->SetState(0);
          }
        }
      }
    }
  } 
  for (auto itt = lst.begin(); itt != lst.end(); ++itt) {                                            // plant <<-> zombie stop
    if ((*itt)->get_is_zombie() == 1) { 
      (*itt)->Set_walk(1);
      (*itt)->Set_run(1); 
      (*itt)->Set_is_eating(0);         
      for (auto it = lst.begin(); it != lst.end(); ++it) {
        if ((*it)->get_is_plant() == 1) {   
          if ((*itt)->GetX() - (*it)->GetX() < 40 && (*itt)->GetX() - (*it)->GetX() > -40 && (*it)->GetY() == (*itt)->GetY()) {
            (*it)->set_hp((*it)->get_hp() - 3);
            (*itt)->Set_walk(0);
            (*itt)->Set_run(0);
            (*itt)->Set_is_eating(1);
          }
          else { 
            (*itt)->Set_walk(1);
            (*itt)->Set_run(1);
            (*itt)->Set_is_eating(0);
          }
        }
      }
    }
  }
  for (auto it = lst.begin(); it != lst.end(); ++it) {                                               // plant <<-> zombie eat
    if ((*it)->get_is_zombie() == 1) {           
      if ((*it)->Get_is_eating() == 1 && (*it)->GetCurrentAnimation() != ANIMID_EAT_ANIM) {
        (*it)->PlayAnimation(ANIMID_EAT_ANIM);
      }
      if ((*it)->Get_is_eating() == 0 && (*it)->GetCurrentAnimation() != ANIMID_WALK_ANIM) {
        (*it)->PlayAnimation(ANIMID_WALK_ANIM);
      }
    }
  }
  for (auto itt = lst.begin(); itt != lst.end(); ++itt) {                                 // extra check for crash
    if ((*itt)->get_is_zombie() == 1) { 
      (*itt)->Set_walk(1);
      (*itt)->Set_run(1); 
      (*itt)->Set_is_eating(0);         
      for (auto it = lst.begin(); it != lst.end(); ++it) {
        if ((*it)->get_is_plant() == 1) {   
          if ((*itt)->GetX() - (*it)->GetX() < 40 && (*itt)->GetX() - (*it)->GetX() > -40 && (*it)->GetY() == (*itt)->GetY()) {
            (*it)->set_hp((*it)->get_hp() - 3);
            (*itt)->Set_walk(0);
            (*itt)->Set_run(0);
            (*itt)->Set_is_eating(1);
          }
          else { 
            (*itt)->Set_walk(1);
            (*itt)->Set_run(1);
            (*itt)->Set_is_eating(0);
          }
        }
      }
    }
  }
  
  
  for (const auto& it : lst) {                                               // successively update 
    it->Update();
  }          
  for (const auto& it : lst) {                                               // is there any zombie on the right? 
    if (it->get_is_shooter() == 1) {           
      for (const auto& itt : lst) {
        if (itt->get_is_zombie() == 1) {   
          if (it->GetX() < itt->GetX() && it->GetY() == itt->GetY()) {
            it->set_zombie_right(1);
            break;
          }
          it->set_zombie_right(0);
        }
        it->set_zombie_right(0);
      }
    }
  }       
  if ((trik - 180) % 300 == 0) {                                             // sun sky
    lst.push_back(std::make_shared<sun>(                                      
      IMGID_SUN, 
      randInt(75, WINDOW_WIDTH - 75),
      WINDOW_HEIGHT - 1,
      LAYER_SUN,
      80,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
  }
  if (getplant() == 11){                                                                 // sunflower
    lst.push_back(std::make_shared<Sunflower>(                              
      IMGID_SUNFLOWER, 
      get_x(),
      get_y(),
      LAYER_PLANTS,
      60,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }
  if (getplant() == 12){                                                                 // Peashooter
    lst.push_back(std::make_shared<Peashooter>(                              
      IMGID_PEASHOOTER, 
      get_x(),
      get_y(),
      LAYER_PLANTS,
      60,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }
  if (getplant() == 13){                                                                 // Wallnut_1
    lst.push_back(std::make_shared<Wallnut>(                              
      IMGID_WALLNUT, 
      get_x(),
      get_y(),
      LAYER_PLANTS,
      60,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }
  for (auto it = lst.begin(); it != lst.end(); ++it) {                                   // Wallnut_low
    if ((*it)->get_change_low() == 1) {
      (*it)->ChangeImage(IMGID_WALLNUT_CRACKED);
    }
  }
  if (getplant() == 14){                                                                 // Cherry_Bomb
    lst.push_back(std::make_shared<Cherry_Bomb>(                              
      IMGID_CHERRY_BOMB, 
      get_x(),
      get_y(),
      LAYER_PLANTS,
      60,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }
  if (getplant() == 9999){                                                               // Explosion
    lst.push_back(std::make_shared<Explosion>(                              
      IMGID_EXPLOSION, 
      get_x(),
      get_y(),
      LAYER_PROJECTILES,
      3 * LAWN_GRID_WIDTH,
      3 * LAWN_GRID_HEIGHT,
      ANIMID_NO_ANIMATION,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }
  if (getplant() == 15){                                                                 // Repeater
    lst.push_back(std::make_shared<Repeater>(                              
      IMGID_REPEATER, 
      get_x(),
      get_y(),
      LAYER_PLANTS,
      60,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    setplant(0);
  }

  if (get_show_time() == 1) {                                         // sun from sunflower
    lst.push_back(std::make_shared<sun>(                                     
      IMGID_SUN, 
      get_x(),
      get_y(),
      LAYER_SUN,
      80,
      80,
      ANIMID_IDLE_ANIM,
      shared_from_this(),
      trik
    ));
    set_show_time(0);
  }
  if (get_show_time() == 2) {                                         // pea
    lst.push_back(std::make_shared<pea>(                                      
      IMGID_PEA, 
      get_x() + 30,
      get_y() + 20,
      LAYER_PROJECTILES,
      28,
      28,
      ANIMID_NO_ANIMATION,
      shared_from_this(),
      trik
    ));
    set_show_time(0);
  }
  if (Get_cooling() == 1 && getplant() > 0) {                         // Cooldown_Mask
    lst.push_back(std::make_shared<Cooldown_Mask>(                                      
      IMGID_COOLDOWN_MASK, 
      130 + (getplant() - 1) * 60,
      WINDOW_HEIGHT - 44,
      LAYER_COOLDOWN_MASK,
      50,
      70,
      ANIMID_NO_ANIMATION,
      shared_from_this()
    ));
  }
  for (auto it = lst.begin(); it != lst.end(); ++it) {                // clear cooldown_mask  
    if ((*it)->Getcool() == 1) {   
      Set_cooling(1);
    }
    if ((*it)->Getcool() == 0 && (*it)->Getseed() == 1) { // if it is a seed and not cooling anymore  
      for (auto itt = lst.begin(); itt != lst.end(); ) {
        if ((*itt)->Getmask() == 1 && (*itt)->GetX() == (*it)->GetX()) {   
          itt = lst.erase(itt);
        }
        else { 
          ++itt; 
        }
      }
    }
  } 
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    if ((*it)->Getcool() == 1) {
      break; 
    }
    if ((*it)->Getcool() == 0 && *it == lst.back()) {
      Set_cooling(0);
    }
  }

  if (trik == next_wave_time) {                                                           // zombie
    SetWave(GetWave() + 1);

    int max_num = floor((15 + GetWave()) / 10);
    next_wave_time += (150 > (600 - 20 * GetWave()) ?  150 : (600 - 20 * GetWave()));

    for (int i = 0; i < max_num; ++i) {
      int p1 = 20;
      int p2 = 2 * ((GetWave() - 8) > 0  ?  (GetWave() - 8) : 0);
      int p3 = 3 * ((GetWave() - 15) > 0 ?  (GetWave() - 15) : 0);
      int type_num = randInt(1, p1 + p2 + p3);
      if (type_num <= p1) {                                                // Regular_Zombie   
        lst.push_back(std::make_shared<Regular_Zombie>(                                           
          IMGID_REGULAR_ZOMBIE, 
          randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1),
          randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_ROW_CENTER,
          LAYER_ZOMBIES,
          20,
          80,
          ANIMID_WALK_ANIM,
          shared_from_this()
        ));
      }
      else if (type_num <= p1 + p2) {                                      // Pole_Vaulting_Zombie       
        lst.push_back(std::make_shared<Pole_Vaulting_Zombie>(                                       
          IMGID_POLE_VAULTING_ZOMBIE, 
          randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1),
          randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_ROW_CENTER,
          LAYER_ZOMBIES,
          20,
          80,
          ANIMID_RUN_ANIM,
          shared_from_this()
        ));
      }
      else if (type_num <= p1 + p2 + p3) {                                 // Bucket_Head_Zombie
        lst.push_back(std::make_shared<Bucket_Head_Zombie>(                                      
          IMGID_BUCKET_HEAD_ZOMBIE, 
          randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1),
          randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_ROW_CENTER,
          LAYER_ZOMBIES,
          20,
          80,
          ANIMID_WALK_ANIM,
          shared_from_this()
        ));
      }
    }
  }
  for (auto it = lst.begin(); it != lst.end(); ++it) {                                    // lose bucket          
    if ((*it)->Get_lose_bucket() == 1) {           
      (*it)->ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
  }


  for (auto it = lst.begin(); it != lst.end(); ++it) {                                    // brain eaten
    if ((*it)->get_is_zombie() == 1 && (*it)->GetX() < 0) {   
      return LevelStatus::LOSING;
    }
  }

  for (auto it = lst.begin(); it != lst.end(); ) {                                        // tranverse clear
    if ((*it)->GetState() == 0) {   
      it = lst.erase(it);
    }
    else { 
      ++it; 
    }
  }

  return LevelStatus::ONGOING;
}

//----------------------------------------------------------------GameWorld.cleanup()
void GameWorld::CleanUp() {                                           
  // YOUR CODE HERE
  lst.clear();
}



