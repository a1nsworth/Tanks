//
// Created by Daniel on 12.05.2023.
//

#include "Subject.h"
void Subject::Add(IObserver *observer)
{
  if (observer == nullptr)
	throw std::invalid_argument("observer is NULL");
  observers_.push_back(observer);
}
void Subject::Remove(IObserver *observer)
{
  if (observer == nullptr)
	throw std::invalid_argument("observer is NULL");
  observers_.remove(observer);
}
void Subject::Notify()
{
  std::for_each(observers_.begin(), observers_.end(), [](auto observer) { observer->Update(); });
}
Subject::Subject() : observers_() {}
