#ifndef _STATEHPP_
#define _STATEHPP_

class State{
 public:
  State(){}
  State(int value){SetState(value);}
  int GetState()const{return state_;}
  void SetState(int value){state_ = value;}
  ~State(){}
  
 private:
  int state_;
};

#endif