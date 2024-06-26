#ifndef _LOADERH_H
#define _LOADERH_H

#include <stdbool.h> //이게 제발 1비트판정나야하는데... bool...
#include <stddef.h>

typedef void *pnt;                   // pointer
typedef void (*pfn)(void *, void *); // void f(any*, any*) func pointer
typedef size_t FakeType;

typedef struct {
  struct faketypes { // type bit length, bitset을 사용해서 구현할것, 어...보니까
                     // 이거... dlib에서 리턴되는건데.... 오우쉣.
    FakeType DIR;  // split기준이 뭐였징...
    FakeType FILE; //예도 뭐였는지...
    FakeType FILESTRC;
    FakeType FILEDATA;
    FakeType FILEINFO; // JUST INFO, metadata
    FakeType FILENAME; // HEADER
    FakeType FILEVALU; // BODY
  };
  struct Functions {
    struct DirNFileArr {
      pfn DIR2FILEArr; // FILE[]
      pfn FILEArr2Dir;
    };

    struct FileNFileStrc {
      pfn FILE2FILESTRC;
      pfn FILESTRC2FILE;
    };

    struct FileStrcNFileData {
      pfn FILESTRC2FILEDATA;
      pfn FILEDATA2FILESTRC;
    };
  };
} dlibs; // dlib function pointer like-libs

template <typename T> struct SpaceCore {
  T empty;
  T data;
};

template <typename T> union Space {
  struct Memory {
    bool core[sizeof(T) *
              2]; // this is core part, settin' a SpaceCore's Everythin'
  };
  SpaceCore<T> core;
};

template <typename T> union Space<T> newSpace(T data); // vervatim

template <typename I, typename O>
void f1(I *, O *); // I로 받은 변수를 O로 보내니... 하...
// ha... fuck....
template <typename I, typename O> void f1(bool, I *, O *);

typedef bool TEMP; // see line 59 comment at class Spaces private constructer
                   // prototype argv type TEMP
                   // 응, 아니야, 이미 ㅈ됨 ㅋㅋ
                   // 완벽한 계획노트가 있었지만 다시 떠올일려면 한달, 이거
                   // 다시시작하면 5개월 씹어먹음.

typedef void *temp(void *); // getcore만들려고 이지랄, 하.. 타입도 Spcae<T> 아닌것봐...

template <typename T, typename TypeFileStrc>
class Spaces { // TypeFileStrc는 설계 구현에서 추상화성땜에, 생각조차
               // 못했음.
private:
  Space<T> *CORE;
  dlibs *Dlibs; //상속시 포인터 선언, 추가된 항목임
  bool isLoad; //정방향 연산인지? (, 상속시 선언.), 추가된 항목임.
  temp getcore;
  Spaces(Space<T> *, Spaces *, temp); // must be repair //자신을 주는 이유는 추후수정
                   // 떄문이고, Space를 주는 이유는, 핵심 CORE여서.
public:
  Spaces(T, temp); //크윽... 굴욕이다...
  Spaces<T, TypeFileStrc>
  transform(); // sizeof로 switch한다, 근데 이거 분명히 매개변수가 있었던것
               // 같다고 기억한다... 하.....
               // 천하의 ㅅㅂ 로스트태크, 하 버스에서 잃어버린 퍼거새끼(나)땜에,
               // 인류는 오늘도 암걸려 뒤져간ㄷR TLQKF@!!!!!!!! GKSK TLQKF!!!!!
  Spaces<T, TypeFileStrc> rm();
  Spaces<T, TypeFileStrc> shl();
  Spaces<T, TypeFileStrc> shl(size_t);
  Spaces<T, TypeFileStrc> shr();
  Spaces<T, TypeFileStrc> shr(size_t);
  template <typename T2>
  Spaces<T2, TypeFileStrc> PillingUpSpace(); // Spaces private
};

#endif