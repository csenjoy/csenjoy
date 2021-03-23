#include "sort.h"

#include <stdlib.h>
#include <stdio.h>

static void swap(ElemType* data1, ElemType* data2) {
	ElemType tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

int selectSort(ElemArray* inout, ElemTypeCompare cmp, bool asc) {
  if (!inout || !cmp) return -1;
  
  ElemType* maxElem = inout->data_;
  for (int slotIndex = 0; slotIndex < inout->length_; ++slotIndex) {
	 //select minimum/maximum and swap with selectSlot
	 maxElem = inout->data_ + slotIndex;
	 for (int travelIndex = slotIndex + 1; travelIndex < inout->length_; ++travelIndex) {
		 bool notLess = (*cmp)(maxElem, inout->data_ + travelIndex);	 	 
		 //if (asc) notLess = !notLess; 
		 if (asc && notLess) {
			 maxElem = inout->data_ + travelIndex;
		 }
		 else if (!asc && !notLess) {
			 maxElem = inout->data_ + travelIndex;
		 } 
	 }
	 swap(inout->data_ + slotIndex, maxElem);
  }
  
  return 0;
}


int bubbleSort(ElemArray* inout, ElemTypeCompare cmp, bool asc) {
  if (!inout || !cmp) return -1;	
    
  for (int sortSlot = 0; sortSlot < inout->length_; ++sortSlot) {
     ElemType* rightPos = inout->data_ + (inout->length_ - 1);
	 for (int travelIndex = inout->length_ - 2; travelIndex >= sortSlot; --travelIndex) {
		bool notLess = (*cmp)(inout->data_ + travelIndex, rightPos);
		if (notLess && asc) {
		  swap(inout->data_ + travelIndex, rightPos);
		}
		else if (!notLess && !asc) {
		  swap(inout->data_ + travelIndex, rightPos);
		}
		rightPos = inout->data_ + travelIndex;
	 }
  }
  return 0;
}


bool intCompare(const ElemType * data1, const ElemType* data2) {
	
	return *((int*)(*data1)) > *((int*)(*data2));
}

void printIntArray(const ElemArray * arry) {
	for (int index = 0; index < arry->length_; ++index) {
		printf("%d\n", (*(int*)(*(arry->data_ + index))));
	}
	
	printf("--------\n");
}


int main() {
	ElemArray arry;
	arry.length_ = 2;
	arry.data_ = (ElemType*)malloc(sizeof(ElemType) * arry.length_);
	
	
	for(int index = 0; index < arry.length_; ++index) {
		*(arry.data_+index) =  malloc(sizeof(int));
		*((int*)(*(arry.data_+index))) = rand() % (10*arry.length_) + 1;
	}
	
	printIntArray(&arry);
		
	selectSort(&arry, intCompare, true);
	printIntArray(&arry);
	
	selectSort(&arry, intCompare, false);
	printIntArray(&arry);
	
	
	bubbleSort(&arry, intCompare, true);
	
	printIntArray(&arry);
	return 0;
}