//
// Created by Daniel on 29.04.2023.
//

#ifndef _IUPDATABLE_H_
#define _IUPDATABLE_H_

class IUpdatable
{
 public:
  virtual void Update(float delta_time) = 0;
};

#endif //_IUPDATABLE_H_
