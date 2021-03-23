#ifndef ALGORITHM_SORT_SORT_H
#define ALGORITHM_SORT_SORT_H

typedef void* ElemType;
typedef bool (*ElemTypeCompare)(const ElemType*, const ElemType*);

typedef struct ElemArray{
  int length_;
  ElemType* data_;
}ElemArray;

int selectSort(ElemArray* inout, ElemTypeCompare cmp, bool asc);

int bubbleSort(ElemArray* inout, ElemTypeCompare cmp, bool asc);

#endif
