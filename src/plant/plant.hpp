#ifndef PLANT_HPP__
#define PLANT_HPP__

#include <memory>
#include "GameObject.hpp"


class plant : public GameObject {                                        // plant
public:
  plant(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) { is_plant = 1; }

  void Update() override = 0;
  void OnClick() override = 0;
protected:
  pGameWorld ptr_world;
};

class Sunflower_Seed : public GameObject {                               // Sunflower_Seed
public:
  Sunflower_Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_seed = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_copy = 0;
};
class Sunflower : public plant {                                         // Sunflower
public:
  Sunflower(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : plant(imageID, x, y, layer, width, height, animID, ptr) , trik_start(start) { hp = 300;}

  void Update() override;
  void OnClick() override;
private:
  int trik_start;
  int trik_copy = 0;
  int first_porduce = randInt(30, 600);
};

class Peashooter_Seed : public GameObject {                              // Peashooter_Seed
public:
  Peashooter_Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_seed = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_copy = 0;
};
class Peashooter : public plant {                                        // Peashooter
public:
  Peashooter(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : plant(imageID, x, y, layer, width, height, animID, ptr) , trik_start(start) { is_shooter = 1; hp = 300; }

  void Update() override;
  void OnClick() override;
private:
  int trik_start;
  int trik_copy = 0;
};

class Wallnut_Seed : public GameObject {                                 // Wallnut_Seed
public:
  Wallnut_Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_seed = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_copy = 0;
};
class Wallnut : public plant {                                           // Wallnut
public:
  Wallnut(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : plant(imageID, x, y, layer, width, height, animID, ptr) , trik_start(start) { hp = 4000;}

  void Update() override;
  void OnClick() override;
protected:
  int trik_start;
  int trik_copy = 0;
};

class Cherry_Bomb_Seed : public GameObject {                             // Cherry_Bomb_Seed
public:
  Cherry_Bomb_Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_seed = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_copy = 0;
};
class Cherry_Bomb : public plant {                                       // Cherry_Bomb
public:
  Cherry_Bomb(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : plant(imageID, x, y, layer, width, height, animID, ptr) , trik_start(start) { hp = 4000;}

  void Update() override;
  void OnClick() override;
protected:
  int trik_start;
  int trik_copy = 0;
};
class Explosion : public Cherry_Bomb {                                   // Explosion
public:
  Explosion(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : Cherry_Bomb(imageID, x, y, layer, width, height, animID, ptr, start) {
      trik_copy = 0;
      is_explosion = 1;
      is_plant = 0;
    }
  void Update() override;
  void OnClick() override;
private:  
};

class Repeater_Seed : public GameObject {                                // Repeater_Seed
public:
  Repeater_Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr) 
    : GameObject(imageID, x, y, layer, width, height, animID) , ptr_world(ptr) {
      is_seed = 1;
    }

  void Update() override;
  void OnClick() override;
private:
  pGameWorld ptr_world;
  int trik_copy = 0;
};
class Repeater : public plant {                                          // Repeater
public:
  Repeater(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld ptr, int start) 
    : plant(imageID, x, y, layer, width, height, animID, ptr) , trik_start(start) { is_shooter = 1; hp = 300;}

  void Update() override;
  void OnClick() override;
private:
  int trik_start;
  int trik_copy = 0;
};



#endif // !PLANT_HPP__













