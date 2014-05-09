//**************************************************************************************************************
// FILE: Keith.hpp
//**************************************************************************************************************
#ifndef KEITH_HPP
#define KEITH_HPP

#include "Types.hpp"

//==============================================================================================================
// Global Function Declarations
//==============================================================================================================
extern void FindKeiths
    (
    ulong pLimit
    );
extern void *FindKeithsThread
    (
    void *pState
    );
/* I think this was an error - static methods shouldn't be in the header
extern bool IsKeith
    (
    ulong pNum
    );*/

#endif
