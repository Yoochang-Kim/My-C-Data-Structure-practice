#pragma once

#include "Person.h"

typedef int Key; //주민등록 번호 ssn
typedef Person * Value;

typedef struct _slot
{
    Key key;
    Value val;
}Slot;


