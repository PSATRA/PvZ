#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"
#include "utils.hpp"
#include "GameObject.hpp"



class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  int getplant();
  void setplant(int sta);
  int get_x();
  void set_x(int sta);
  int get_y();
  void set_y(int sta);
  int get_show_time();
  void set_show_time(int sta);
  bool Get_holding_shovel();
  void Set_holding_shovel(bool sta);
  int Get_cooling();
  void Set_cooling(int sta);

  
  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  int Gettrik();

private: 
  std::list<std::shared_ptr<GameObject>> lst;
  int  trik = 0;
  bool iss = 0;
  int  falltime = 12;
  int  holding_seed = 0;
  bool holding_shovel = 0;
  int  current_x;
  int  current_y;
  int  show_time = 0;
  int  cooling = 0;
  int  next_wave_time = 1200;
};

#endif // !GAMEWORLD_HPP__
