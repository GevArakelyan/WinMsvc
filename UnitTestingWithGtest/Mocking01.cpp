#include "pch.h"



/*
Google Mock Class Generator
Fount at: googlemock\scripts\generator

Requires Python 2.4 installed

Output result to stdout

gmock_gen.py headerFile.h [class name]

--
EXPECT_CALL(myFake, SomeMethod(true,_))
.WillOnce(SetArgPointee<1>(10));

EXPECT_CALL(myFake, SomeMethodReturningBool(true,_))
.WillOnce(DoAll(SetArgPointee<1>(10),Return(true))

--
EXPECT_CALL(myFake, fun())
.WillOnce(Throw(exception))

*/ 

