#ifndef _TEMP_H
#define _TEMP_H

#include "loader.h"

template <typename T> union Space<T> newSpace(T data) {
  union Space<T> ret;
  ret.core.data = data;
  return ret;
}

//???

template <typename I, typename O>
void f1(I *, O *);
// ha... fuck....
template <typename I, typename O>
void f1(bool, I *, O *); //이것도 뭔가 ㅈㄴ 복잡한거 실행하게 불넣는거 ㅠㅠㅠ
                         //하아 개빡새내 왜이러냐 과거의나...

//???

template <typename T> Spaces<T>::Spaces(T data) { this.CORE = &newSpace(data); }
template <typename T> Spaces<T>::transform() {
  
  switch (sizeof(T)) {
    case this.Dlibs.faketypes.DIR:
      if (this.isLoad) {
        this.Dlibs.Functions.DirNFileArr.DIR2FILEArr();
      } else {
        this.Dlibs.Functions.DirNFileArr.FILEArr2Dir();
      }
      break;
  }
}
template <typename T> Spaces<T> Spaces<T>::rm() { this.CORE.core.data = 0; }
template <typename T> Spaces<T> Spaces<T>::shl() {
  this.CORE << 1;
  return this;
}
template <typename T> Spaces<T> Spaces<T>::shl(size_t N) {
  this.CORE << N;
  return this;
}
template <typename T> Spaces<T> Spaces<T>::shr() {
  this.CORE << 1;
  return this;
}
template <typename T> Spaces<T> Spaces<T>::shr(size_t N) {
  this.CORE >> N;
  return this;
}

//???

template <typename T2, typename T> Spaces<T2> Spaces<T>::PillingUpSpace();
//???

#endif