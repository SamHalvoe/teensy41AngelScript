#pragma once

#include <elapsedMillis.h>
#include <angelscript.h>
#include <assert.h>

namespace asElapsedMillis
{
  void Constructor(asIScriptGeneric* out_pointer)
  {
    new(out_pointer->GetObject()) elapsedMillis();
  }

  void CopyConstructor(asIScriptGeneric* io_pointer)
  {
    elapsedMillis* object = static_cast<elapsedMillis*>(io_pointer->GetArgObject(0));
    new(io_pointer->GetObject()) elapsedMillis(*object);
  }
  
  void Destructor(asIScriptGeneric* out_pointer)
  {
    reinterpret_cast<elapsedMillis*>(out_pointer->GetObject())->~elapsedMillis();
  }

  void assign(asIScriptGeneric* out_pointer)
  {
    elapsedMillis* rightOperand = static_cast<elapsedMillis*>(out_pointer->GetArgObject(0));
    elapsedMillis* self = static_cast<elapsedMillis*>(out_pointer->GetObject());
    *self = *rightOperand;
    out_pointer->SetReturnAddress(self);
  }

  void assignUnsignedLong(asIScriptGeneric* out_pointer)
  {
    unsigned long rightOperand = out_pointer->GetArgDWord(0);
    elapsedMillis* self = static_cast<elapsedMillis*>(out_pointer->GetObject());
    *self = rightOperand;
    out_pointer->SetReturnAddress(self);
  }

  void opImplConv(asIScriptGeneric* out_pointer)
  {
    unsigned long value = *static_cast<elapsedMillis*>(out_pointer->GetObject());
    out_pointer->SetReturnDWord(value);
  }

  void equals(asIScriptGeneric* in_generic)
  {
    elapsedMillis* a = static_cast<elapsedMillis*>(in_generic->GetObject());
    elapsedMillis* b = static_cast<elapsedMillis*>(in_generic->GetArgAddress(0));
    *reinterpret_cast<bool*>(in_generic->GetAddressOfReturnLocation()) = (*a == *b);
  }

  void compare(asIScriptGeneric* in_generic)
  {
    elapsedMillis* a = static_cast<elapsedMillis*>(in_generic->GetObject());
    elapsedMillis* b = static_cast<elapsedMillis*>(in_generic->GetArgAddress(0));

    int result = 0;

    if (*a < *b)
    {
      result = -1;
    }
    else if (*a > *b)
    {
      result = 1;
    }

    *static_cast<int*>(in_generic->GetAddressOfReturnLocation()) = result;
  }

  void registerElapsedMillis(asIScriptEngine* io_engine)
  {
    int resultCode = io_engine->RegisterObjectType("ElapsedMillis", sizeof(elapsedMillis), asOBJ_VALUE); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterObjectBehaviour("ElapsedMillis", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(Constructor), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterObjectBehaviour("ElapsedMillis", asBEHAVE_CONSTRUCT,  "void f(const ElapsedMillis& in)", asFUNCTION(CopyConstructor), asCALL_GENERIC); assert(resultCode >= 0);
    resultCode = io_engine->RegisterObjectBehaviour("ElapsedMillis", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(Destructor), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterObjectMethod("ElapsedMillis", "ElapsedMillis& opAssign(const ElapsedMillis& in)", asFUNCTION(assign), asCALL_GENERIC); assert(resultCode >= 0);
    resultCode = io_engine->RegisterObjectMethod("ElapsedMillis", "ElapsedMillis& opAssign(uint& in)", asFUNCTION(assignUnsignedLong), asCALL_GENERIC); assert(resultCode >= 0);
    
    resultCode = io_engine->RegisterObjectMethod("ElapsedMillis", "uint opImplConv()", asFUNCTION(opImplConv), asCALL_GENERIC); assert(resultCode >= 0);
    resultCode = io_engine->RegisterObjectMethod("ElapsedMillis", "bool opEquals(const ElapsedMillis& in) const", asFUNCTION(equals), asCALL_GENERIC); assert(resultCode >= 0);
    resultCode = io_engine->RegisterObjectMethod("ElapsedMillis", "int opCmp(const ElapsedMillis& in) const", asFUNCTION(compare), asCALL_GENERIC); assert(resultCode >= 0);
  }
}



