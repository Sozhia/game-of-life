#ifndef _STATEPUPAHPP_
#define _STATEPUPAHPP_

#include "State.hpp"
#include "StateDead.hpp"
#include "StateLarva.hpp"
#include "StateAdult.hpp"
#include "StateEgg.hpp"
#include "StatePupa.hpp"

class StatePupa : public State{

 public:
  StatePupa(){}
  ~StatePupa(){}

  void neighbors(const Grid&, int, int);
  State* nextState();
  const char getState() const;

  int getLarvasAmount() const;
  void setLarvasAmount(int);

  int getEggsAmount() const;
  void setEggsAmount(int);

  int getDeadsAmount() const;
  void setDeadsAmount(int);

  int getAdultsAmount() const;
  void setAdultsAmount(int);

  int getPupasAmount() const;
  void setPupasAmount(int);

 private:
  int n_states_larva_, n_states_pupa_, n_states_dead_, n_states_egg_, n_states_adult_;

};

#endif