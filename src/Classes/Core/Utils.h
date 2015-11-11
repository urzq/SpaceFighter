#ifndef  _UTILS_H_
#define  _UTILS_H_

#include <assert.h>

#define delete_safe(obj) assert(obj != nullptr); delete obj; obj = nullptr;

#endif // _UTILS_H_

