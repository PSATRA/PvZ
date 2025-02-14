#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID) {}
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  bool GetState();
  void SetState(bool sta);

  bool Getcool();
  void Setcool(bool sta);

  bool Getseed();
  void Setseed(bool sta);
  bool Getmask();
  void Setmask(bool sta);

  bool get_zombie_right();
  void set_zombie_right(bool sta);

  bool get_is_shooter();
  void set_is_shooter(bool sta);

  bool get_is_zombie();
  void set_is_zombie(bool sta);

  bool get_is_pea();
  void set_is_pea(bool sta);

  bool get_change_low();
  void set_change_low(bool sta);

  bool get_is_explosion();
  void set_is_explosion(bool sta);
  
  bool get_is_plant();
  void set_is_plant(bool sta);

  bool Get_walk();
  void Set_walk(bool sta);
  bool Get_run();
  void Set_run(bool sta);

  int  get_hp();
  void set_hp(int sta);

  bool Get_is_eating();
  void Set_is_eating(bool sta);

  bool Get_lose_bucket();
  void Set_lose_bucket(bool sta);



protected:
  bool state = 1;
  bool cold_state = 0;
  bool is_seed = 0;
  bool is_mask = 0;
  bool zombie_right = 0;
  bool is_shooter = 0;
  bool is_zombie = 0;
  bool is_pea = 0;
  bool change_low = 0;
  bool is_explosion = 0;
  bool is_plant = 0;
  bool walk = 1;
  bool run = 1;
  int  hp = 0;
  bool is_eating = 0;
  bool lose_bucket = 0;
};

class background : public GameObject {                               // background
public:
  background(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID) 
    : GameObject(imageID, x, y, layer, width, height, animID) {}

  void Update() override;
  void OnClick() override;
};

class spot : public GameObject {                                     // 45 spots
public:
  spot(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {}

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
};

class sun : public GameObject {                                         // sun
public:
  sun(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) , trik_start(start) {}

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_start;
  int trik_copy = 0;
  bool is = (GetY() == WINDOW_HEIGHT - 1 ? 1 : 0);
  int falltime_sky = randInt(63, 263);
  int falltime_flower = 12;
};

class pea : public GameObject {                                         // pea
public:
  pea(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) , trik_start(start) { is_pea = 1; }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_start;
  int trik_copy = 0;
};

class Shovel : public GameObject {                                     // Shovel
public:
  Shovel(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {}

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
};

class Cooldown_Mask : public GameObject {                              // Cooldown_Mask
public:
  Cooldown_Mask(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_mask = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
};



#endif // !GAMEOBJECT_HPP__
