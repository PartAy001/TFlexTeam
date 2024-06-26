#ifndef _TEMP_H
#define _TEMP_H

#include "loader.h"
#include <cassert>

#define ELIF else if
#define elif ELIF

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

template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc>::Spaces(T data) {
  this.CORE = &newSpace(data);
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc>::transform() {

  switch (sizeof(T)) {
  case this.Dlibs.faketypes.DIR: // FILEArr이랑 길이가 같다... ㅁㅊ...
    if (this.isLoad) {
      this.Dlibs.Functions.DirNFileArr.DIR2FILEArr();
    } else {
      this.Dlibs.Functions.DirNFileArr.FILEArr2Dir();
    };
    break;

  case this.Dlibs.faketypes
      .FILE: //일단은 크게는 문제는 없다, 근데 예, FILESTRC랑 길이가 같다...
             //후...., ㅈㄴ어렵개 설계했네, 과거의 나 그저 G.O.A.T..... 이딴걸
             //쉬운거 취급하다니...
    if (std::is_same_v<T, TypeFileStrc> && this.isLoad) {
      this.Dlibs.Functions.FileNFileStrc.FILE2FILESTRC();
    }
    elif (std::is_same_v<T, TypeFileStrc>) {
      this.Dlibs.Functions.FileNFileStrc.FILESTRC2FILE();
    }
    elif (this.isLoad) { this.Dlibs.Functions.FileNFileStrc.FILE2FILESTRC(); }
    else {
      this.Dlibs.Functions.FileNFileStrc.FILESTRC2FILE();
    };
  }

case 

  // case this.Dlibs.faketypes
  //     .F: //기준을 모르겠다 ㅠㅠ, 분명히 로드시에 구분이 되야하는데.., 에초에
  //         //크기비교가 아니었다는 증거다 이건.
  //   if (this.isLoad) {
  //     this.Dlibs.Functions.FileNFileStrc.FILE2FILESTRC();
  //   }
  //   break;
  // }
  // ㄹㅇㅋㅋ (실성)
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc> Spaces<T, TypeFileStrc>::rm() {
  this.CORE.core.data = 0;
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc> Spaces<T, TypeFileStrc>::shl() {
  this.CORE << 1;
  return this;
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc> Spaces<T, TypeFileStrc>::shl(size_t N) {
  this.CORE << N;
  return this;
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc> Spaces<T, TypeFileStrc>::shr() {
  this.CORE << 1;
  return this;
}
template <typename T, typename TypeFileStrc>
Spaces<T, TypeFileStrc> Spaces<T, TypeFileStrc>::shr(size_t N) {
  this.CORE >> N;
  return this;
}

//???

template <typename T, typename TypeFileStrc>
template <typename T2>
Spaces<T2, TypeFileStrc> Spaces<T, TypeFileStrc>::PillingUpSpace();
  //???

#endif