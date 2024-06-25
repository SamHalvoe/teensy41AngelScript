#pragma once

#include <Arduino.h>

#include <angelscript.h>

#include <assert.h>

uint8_t g_input = INPUT;
uint8_t g_output = OUTPUT;
uint8_t g_low = LOW;
uint8_t g_high = HIGH;
uint8_t g_ledBuildIn = LED_BUILTIN;

void _delay(asIScriptGeneric* in_parameterList)
{
	delay(in_parameterList->GetArgDWord(0));
}

void _pinMode(asIScriptGeneric* in_parameterList)
{
	pinMode(in_parameterList->GetArgByte(0), in_parameterList->GetArgByte(1));
}

void _digitalWrite(asIScriptGeneric* in_parameterList)
{
	digitalWrite(in_parameterList->GetArgByte(0), in_parameterList->GetArgByte(1));
}

void register_arduino(asIScriptEngine* io_engine)
{
  int	resultCode = io_engine->RegisterGlobalProperty("uint8 g_input", &g_input); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalProperty("uint8 g_output", &g_output); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalProperty("uint8 g_low", &g_low); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalProperty("uint8 g_high", &g_high); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalProperty("uint8 g_ledBuildIn", &g_ledBuildIn); assert(resultCode >= 0);

	resultCode = io_engine->RegisterGlobalFunction("void delay(uint millis)", asFUNCTION(_delay), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalFunction("void pinMode(uint8 pin, uint8 mode)", asFUNCTION(_pinMode), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterGlobalFunction("void digitalWrite(uint8 pin, uint8 state)", asFUNCTION(_digitalWrite), asCALL_GENERIC); assert(resultCode >= 0);
}
