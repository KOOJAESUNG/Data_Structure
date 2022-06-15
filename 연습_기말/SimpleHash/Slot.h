#pragma once

#include "Person.h"

enum SlotStatus {EMPTY,DELETED,INUSE};

typedef struct _slot {
	int key;
	Person* val;
	enum SlotStatus status;
}Slot;