#include <Arduino.h>

#include <angelscript.h>

#include "register_arduino.hpp"
#include "register_arduinoString.hpp"
#include "register_elapsedMillis.hpp"

void MessageCallback(const asSMessageInfo *msg, void *param)
{
	const char *type = "ERR ";
	if( msg->type == asMSGTYPE_WARNING ) 
		type = "WARN";
	else if( msg->type == asMSGTYPE_INFORMATION ) 
		type = "INFO";

	Serial.printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}

void serial_println(asIScriptGeneric* in_string)
{
  Serial.println(*static_cast<String*>(in_string->GetArgAddress(0)));
}

void serial_println_uint(asIScriptGeneric* in_pointer)
{
  Serial.println(in_pointer->GetArgDWord(0));
}

void setup()
{
  Serial.begin(115200);
  while (not Serial) {}
  Serial.println("Serial is up and running (:");

  asIScriptEngine* engine = asCreateScriptEngine();
  if (engine == nullptr)
	{
		Serial.println("Failed to create script engine!");
		while (true) {}
	}

  int r = engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL);
  if (r < 0)
  {
    Serial.println("SetMessageCallback() failed!");
		while (true) {}
  }

	asArduino::registerArduino(engine);
	asArduinoString::registerArduinoString(engine);
	asElapsedMillis::registerElapsedMillis(engine);

  r = engine->RegisterGlobalFunction("void serial_println(const String& in)", asFUNCTION(serial_println), asCALL_GENERIC);
  if (r < 0) { Serial.println("RegisterGlobalFunction(serial_println) failed!"); }
	r = engine->RegisterGlobalFunction("void serial_println_uint(uint)", asFUNCTION(serial_println_uint), asCALL_GENERIC);
  if (r < 0) { Serial.println("RegisterGlobalFunction(serial_println_uint) failed!"); }
  
  String angelScript = "void main() { ElapsedMillis time; serial_println(\"Hello Arduino AngelScript!\"); serial_println_uint(time); pinMode(g_ledBuildIn, g_output); digitalWrite(g_ledBuildIn, g_high); delay(2001); digitalWrite(g_ledBuildIn, g_low); serial_println_uint(time); }";
  asIScriptModule* module = engine->GetModule(0, asGM_ALWAYS_CREATE);
	r = module->AddScriptSection("script", angelScript.c_str(), angelScript.length());
  if (r < 0)
	{
		Serial.println("AddScriptSection() failed!");
		while (true) {}
	}

  r = module->Build();
	if (r < 0)
	{
		Serial.println("Build() failed!");
		while (true) {}
	}

  asIScriptContext* context = engine->CreateContext();
	if (context == nullptr)
	{
		Serial.println("Failed to create the context.");
		engine->Release();
		while (true) {}
	}

  asIScriptFunction* function = engine->GetModule(0)->GetFunctionByDecl("void main()");
	if (function == nullptr)
	{
		Serial.println("The function 'void main()' was not found.");
		context->Release();
		engine->Release();
		while (true) {}
	}

	r = context->Prepare(function);
	if (r < 0) 
	{
		Serial.println("Failed to prepare the context.");
		context->Release();
		engine->Release();
		while (true) {}
	}

	/*String string("Hello Arduino AngelScript!");
  r = context->SetArgObject(0, &string);
  if (r < 0) 
	{
		Serial.println("Failed to SetArgObject.");
		context->Release();
		engine->Release();
		while (true) {}
	}*/

	r = context->Execute();
	if (r != asEXECUTION_FINISHED)
	{
		// The execution didn't finish as we had planned. Determine why.
		if (r == asEXECUTION_ABORTED)
    {
			Serial.println("The script was aborted before it could finish. Probably it timed out.");
    }
		else if (r == asEXECUTION_EXCEPTION)
		{
			Serial.println("The script ended with an exception.");

			// Write some information about the script exception
			asIScriptFunction* exceptioFunction = context->GetExceptionFunction();
			Serial.print("func: "); Serial.println(exceptioFunction->GetDeclaration());
			Serial.print("modl: "); Serial.println(exceptioFunction->GetModuleName());
			Serial.print("sect: "); Serial.println(exceptioFunction->GetScriptSectionName());
			Serial.print("line: "); Serial.println(context->GetExceptionLineNumber());
			Serial.print("desc: "); Serial.println(context->GetExceptionString());
		}
		else
    {
      Serial.print("The script ended for some unforeseen reason (");  Serial.print(r); Serial.println(").");
    }
	}
	else
	{
		Serial.println("The script function returned without error.");
	}

	context->Release();
	engine->ShutDownAndRelease();

  Serial.println("Leave Setup...");
}

void loop()
{
  delay(1000);
}
