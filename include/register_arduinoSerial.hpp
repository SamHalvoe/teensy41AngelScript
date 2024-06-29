#pragma once

#include <Arduino.h>
#include <angelscript.h>
#include <assert.h>

namespace asArduinoSerial
{
  void print_bool(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<bool*>(reference));
  }

  void print_int8(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<int8_t*>(reference));
  }

  void print_int16(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<int16_t*>(reference));
  }

  void print_int(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<int32_t*>(reference));
  }

  void print_int64(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<int64_t*>(reference));
  }

  void print_uint8(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<uint8_t*>(reference));
  }

  void print_uint16(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<uint16_t*>(reference));
  }

  void print_uint(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<uint32_t*>(reference));
  }

  void print_uint64(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<uint64_t*>(reference));
  }

  void print_float(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<float*>(reference));
  }

  void print_double(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<double*>(reference));
  }

  void print_String(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.print(*static_cast<String*>(reference));
  }

  void println_bool(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<bool*>(reference));
  }

  void println_int8(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<int8_t*>(reference));
  }

  void println_int16(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<int16_t*>(reference));
  }

  void println_int(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<int32_t*>(reference));
  }

  void println_int64(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<int64_t*>(reference));
  }

  void println_uint8(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<uint8_t*>(reference));
  }

  void println_uint16(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<uint16_t*>(reference));
  }

  void println_uint(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<uint32_t*>(reference));
  }

  void println_uint64(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<uint64_t*>(reference));
  }

  void println_float(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<float*>(reference));
  }

  void println_double(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<double*>(reference));
  }

  void println_String(asIScriptGeneric* in_generic)
  {
    void* reference = in_generic->GetArgAddress(0);
    Serial.println(*static_cast<String*>(reference));
  }

  void registerArduinoSerial(asIScriptEngine* io_engine)
  {
    int resultCode = io_engine->RegisterGlobalFunction("void serialPrint(bool& in)", asFUNCTION(print_bool), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(int8& in)", asFUNCTION(print_int8), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(int16& in)", asFUNCTION(print_int16), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(int& in)", asFUNCTION(print_int), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(int64& in)", asFUNCTION(print_int64), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(uint8& in)", asFUNCTION(print_uint8), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(uint16& in)", asFUNCTION(print_uint16), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(uint& in)", asFUNCTION(print_uint), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(uint64& in)", asFUNCTION(print_uint64), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(float& in)", asFUNCTION(print_float), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(double& in)", asFUNCTION(print_double), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrint(const String& in)", asFUNCTION(print_String), asCALL_GENERIC); assert( resultCode >= 0 );
    
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(bool& in)", asFUNCTION(println_bool), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(int8& in)", asFUNCTION(println_int8), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(int16& in)", asFUNCTION(println_int16), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(int& in)", asFUNCTION(println_int), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(int64& in)", asFUNCTION(println_int64), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(uint8& in)", asFUNCTION(println_uint8), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(uint16& in)", asFUNCTION(println_uint16), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(uint& in)", asFUNCTION(println_uint), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(uint64& in)", asFUNCTION(println_uint64), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(float& in)", asFUNCTION(println_float), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(double& in)", asFUNCTION(println_double), asCALL_GENERIC); assert( resultCode >= 0 );
    resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(const String& in)", asFUNCTION(println_String), asCALL_GENERIC); assert( resultCode >= 0 );
  }
}
