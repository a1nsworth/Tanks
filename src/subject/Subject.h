//
// Created by Daniel on 12.05.2023.
//

#ifndef TANKS_SRC_SUBJECT_SUBJECT_H_
#define TANKS_SRC_SUBJECT_SUBJECT_H_

#include <list>
#include <exception>

#include "../interfaces/IObservable.h"
#include "../interfaces/IObserver.h"

class Subject : public IObservable
{
 private:
  std::list<IObserver *> observers_;

 public:
  explicit Subject();
  ~Subject()  = default;

  void Add(IObserver *observer) override;
  void Remove(IObserver *observer) override;
  void Notify() override;
};

#endif //TANKS_SRC_SUBJECT_SUBJECT_H_
