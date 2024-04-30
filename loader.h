#ifndef _LOADER_H
#define _LOADER_H

#include <stdbool.h>
#include <stddef.h>

typedef void *pnt;
typedef void (*pfn)(void *, void *);
typedef size_t FakeType;

typedef struct {
  struct faketypes {
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
      pfn DIR2FILEArr;
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
} dlibs;

template <typename T> struct SpaceCore {
  T empty;
  T data;
};

template <typename T> union Space {
  struct Memory {
    bool core[sizeof(T) * 2];
  };
  SpaceCore<T> core;
};

template <typename T> union Space<T> newSpace(T data);

template <typename I, typename O> void f1(I *, O *);

template <typename I, typename O> void f1(bool, I *, O *);

typedef bool TEMP; // see line 59 comment at class Spaces private constructer
                   // prototype argv type TEMP

template <typename T> class Spaces {
private:
  Space<T> CORE;
  Spaces(TEMP); // must be repair
public:
  Spaces(T);
  Spaces<T> transform();
  Spaces<T> rm();
  Spaces<T> shl();
  Spaces<T> shl(size_t);
  Spaces<T> shr();
  Spaces<T> shr(size_t);
  template <typename T2> Spaces<T2> PillingUpSpace();
};

#endif