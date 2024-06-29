#pragma once

#include <Arduino.h>
#include <angelscript.h>
#include <assert.h>

namespace asArduinoSerial
{
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
    int resultCode = io_engine->RegisterGlobalFunction("void serialPrintln(bool& in)", asFUNCTION(println_bool), asCALL_GENERIC); assert( resultCode >= 0 );
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
