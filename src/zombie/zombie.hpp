#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include <memory>
#include "GameObject.hpp"

class zombie : public GameObject {                                        // zombie
public:
  zombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) { is_zombie = 1;}

  void Update() override = 0;
  void OnClick() override = 0;
protected:
  pGameWorld ptr_world;
};

class Regular_Zombie : public zombie {                                        // Regular_Zombie
public:
  Regular_Zombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : zombie(imageID, x, y, layer, width, height, animID, ptr) { hp = 200;}

  void Update() override;
  void OnClick() override;
protected:
};

class Bucket_Head_Zombie : public zombie {                                    // Bucket_Head_Zombie
public:
  Bucket_Head_Zombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : zombie(imageID, x, y, layer, width, height, animID, ptr) { hp = 1300;}

  void Update() override;
  void OnClick() override;
protected:
};

class Pole_Vaulting_Zombie : public zombie {                                  // Pole_Vaulting_Zombie
public:
  Pole_Vaulting_Zombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : zombie(imageID, x, y, layer, width, height, animID, ptr) { hp = 340;}

  void Update() override;
  void OnClick() override;
protected:
};



#endif // !ZOMBIE_HPP__