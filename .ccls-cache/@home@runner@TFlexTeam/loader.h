#ifndef _LOADER_H
#define _LOADER_H

#include <stdbool.h>
#include <stddef.h>

typedef void *pnt;                   // pointer
typedef void (*pfn)(void *, void *); // void f(any*, any*) func pointer
typedef size_t FakeType;

typedef struct {
  struct faketypes { // type bit length
    FakeType DIR;
    FakeType FILE;
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
      pfn FILE2FILESTRC; // FILESTRC def need (추후)
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

template <typename T> class Spaces {
private:
  Space<T> *CORE;
  Spaces(Space<T> *, Spaces *); // must be repair //자신을 주는 이유는 추후수정
                                // 떄문이고, Space를 주는 이유는, 핵심 CORE여서.
public:
  Spaces(T);
  Spaces<T> transform(); // how????, 예가 확실히 추후 구현 감이다.
  Spaces<T> rm();
  Spaces<T> shl();
  Spaces<T> shl(size_t);
  Spaces<T> shr();
  Spaces<T> shr(size_t);
  template <typename T2> Spaces<T2> PillingUpSpace(); // Spaces private
};

#endif