//**************************************************************************************************************
// FILE: Keith.cpp
//**************************************************************************************************************
#include <iostream>
#include <cmath>
#include "Main.hpp"
#include "Keith.hpp"
#include "Thread.hpp"

using std::cout;
using std::endl;

//==============================================================================================================
// Static Function Declarations
//==============================================================================================================
static bool IsKeith
    (
    ulong pNum
    );

//==============================================================================================================
// Function Definitions
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// FindKeiths()
//
// Finds all Keith numbers from 10 to pLimit. We do nothing with the numbers we find.
//--------------------------------------------------------------------------------------------------------------
void FindKeiths
    (
    ulong pLimit
    )
{
    if (GetVerbose()) cout << "FindKeiths() Begin" << endl;
	for(ulong n=0L;n<=pLimit;n++){
        if(IsKeith(n))
			;
    }
    if (GetVerbose()) cout << "FindKeiths() End" << endl;
}

//--------------------------------------------------------------------------------------------------------------
// FindPrimesThread()
//
// A thread which finds all Keith numbers from 10 to pState->mLimit.
//--------------------------------------------------------------------------------------------------------------
void *FindKeithsThread
    (
    void *pState
    )
{
    // If running in verbose mode, then tell the user that the thread is beginning.
    if (GetVerbose()) cout << "FindKeithsThread() Begin" << endl;

    // We know that pState is really a pointer to a ThreadState structure, so type cast it.
    ThreadState *state = static_cast<ThreadState *>(pState);

    // Find all the Keiths from 10 to state->mLimit.
    FindKeiths(state->mLimit);

    // The thread exit code is 0 (success).
    state->mExitCode = 0;

    // If running verbose mode, then tell the user that the thread is ending.
    if (GetVerbose()) cout << "FindKeithsThread() End" << endl;

    // Exit (terminate) the thread and return pState as the return variable.
    pthread_exit(pState);
}

//--------------------------------------------------------------------------------------------------------------
// IsKeith()
//
// Returns true if pNum is a Keith number.
//--------------------------------------------------------------------------------------------------------------
static bool IsKeith
    (
    ulong pNum
    )
{
    ulong g[9],i,n,s,t=pNum;
    for(n=s=0L;t;t/=10L)s+=g[n++]=t%10L;
    for(i=n;s<pNum;){
        i+=n-1L;
		t=g[i%n];g[i%n]=s;s+=s-t;
    }
    return n>1L&&s==pNum;
}
