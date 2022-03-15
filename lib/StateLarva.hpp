#ifndef _STATELARVAHPP_
#define _STATELARVAHPP_

#include "State.hpp"
#include "StateDead.hpp"
#include "StateAdult.hpp"
#include "StatePupa.hpp"
#include "StateEgg.hpp"

class StateLarva : public State{
 public:
  StateLarva(){}
  ~StateLarva(){}

  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

  int getLarvasAmount() const;
  void setLarvasAmount(int);

  int getEggsAmount() const;
  void setEggsAmount(int);

  int getPupasAmount() const;
  void setPupasAmount(int);

  int getAdultsAmount() const;
  void setAdultsAmount(int);

 private:
  int n_states_larva_, n_states_egg_, n_states_pupa_, n_states_adult_;

};

#endif