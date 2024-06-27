#pragma once

#include <Arduino.h>

#include <angelscript.h>

#include <assert.h>
#include <map>

using map_t = std::map<String, int>;

class ArduinoStringFactory : public asIStringFactory
{
  public:
    ArduinoStringFactory() = default;
    ~ArduinoStringFactory() 
    {
      // The script engine must release each String 
      // constant that it has requested
      assert(m_StringCache.size() == 0);
    }

    const void* GetStringConstant(const char* data, asUINT length)
    {
      String str;
      str.copy(data, length);
      map_t::iterator it = m_StringCache.find(str);
      if (it != m_StringCache.end())
        it->second++;
      else
        it = m_StringCache.insert(map_t::value_type(str, 1)).first;
      
      return reinterpret_cast<const void*>(&it->first);
    }

    int ReleaseStringConstant(const void *str)
    {
      if (str == 0) { return asERROR; }
      int ret = asSUCCESS;
      
      map_t::iterator it = m_StringCache.find(*reinterpret_cast<const String*>(str));
      if (it == m_StringCache.end())
        ret = asERROR;
      else
      {
        it->second--;
        if (it->second == 0)
          m_StringCache.erase(it);
      }
      
      return ret;
    }

    int GetRawStringData(const void* str, char* data, asUINT* length) const
    {
      if (str == nullptr) { return asERROR; }

      if (length != nullptr)
      {
        *length = static_cast<asUINT>(reinterpret_cast<const String*>(str)->length());
      }

      if (data != nullptr)
      {
        memcpy(data, reinterpret_cast<const String*>(str)->c_str(), reinterpret_cast<const String*>(str)->length());
      }

      return asSUCCESS;
    }

    static ArduinoStringFactory& getSingelton()
    {
      static ArduinoStringFactory factory;
      return factory;
    }

  private:
    map_t m_StringCache;
};

void constructor_arduinoString(asIScriptGeneric* pointer)
{
	new(pointer->GetObject()) String();
}

void copyConstructor_arduinoString(asIScriptGeneric* pointer)
{
	String* string = static_cast<String*>(pointer->GetArgObject(0));
	new(pointer->GetObject()) String(*string);
}

void destructor_arduinoString(asIScriptGeneric* pointer)
{
	String* string = static_cast<String*>(pointer->GetObject());
	string->~String();
}

void assign_arduinoString(asIScriptGeneric *gen)
{
	String * a = static_cast<String *>(gen->GetArgObject(0));
	String * self = static_cast<String *>(gen->GetObject());
	*self = *a;
	gen->SetReturnAddress(self);
}

void addAssign_arduinoString(asIScriptGeneric *gen)
{
	String * a = static_cast<String *>(gen->GetArgObject(0));
	String * self = static_cast<String *>(gen->GetObject());
	*self += *a;
	gen->SetReturnAddress(self);
}

void equals_arduinoString(asIScriptGeneric * gen)
{
	String * a = static_cast<String *>(gen->GetObject());
	String * b = static_cast<String *>(gen->GetArgAddress(0));
	*reinterpret_cast<bool *>(gen->GetAddressOfReturnLocation()) = (*a == *b);
}

void compare_arduinoString(asIScriptGeneric * gen)
{
	String * a = static_cast<String *>(gen->GetObject());
	String * b = static_cast<String *>(gen->GetArgAddress(0));

	int cmp = 0;
	if( *a < *b ) cmp = -1;
	else if( *a > *b ) cmp = 1;

	*(int*)gen->GetAddressOfReturnLocation() = cmp;
}

void add_arduinoString(asIScriptGeneric * gen)
{
	String * a = static_cast<String *>(gen->GetObject());
	String * b = static_cast<String *>(gen->GetArgAddress(0));
	String ret_val = *a + *b;
	gen->SetReturnObject(&ret_val);
}

void length_arduinoString(asIScriptGeneric * gen)
{
	String * self = static_cast<String *>(gen->GetObject());
	*static_cast<asUINT *>(gen->GetAddressOfReturnLocation()) = (asUINT)self->length();
}

void isEmpty_arduinoString(asIScriptGeneric * gen)
{
	String * self = reinterpret_cast<String *>(gen->GetObject());
	*reinterpret_cast<bool *>(gen->GetAddressOfReturnLocation()) = (self->length() == 0);
}

void String_extension_resize(String* out_string, size_t in_targetSize)
{
  if (out_string->length() < in_targetSize)
  {
    for (size_t size = out_string->length(); size < in_targetSize; ++size)
    {
      out_string->concat('\0');
    }
  }
  else if (out_string->length() > in_targetSize)
  {
    out_string->remove(out_string->length() - in_targetSize, out_string->length() - in_targetSize);
  }
}

void resize_arduinoString(asIScriptGeneric * gen)
{
	String * self = static_cast<String *>(gen->GetObject());
	String_extension_resize(self, *static_cast<asUINT *>(gen->GetAddressOfArg(0)));
}

void register_arduinoString(asIScriptEngine* io_engine)
{
  int resultCode = io_engine->RegisterObjectType("String", sizeof(String), asOBJ_VALUE | asOBJ_APP_CLASS_CD); assert(resultCode >= 0);
  resultCode = io_engine->RegisterStringFactory("String", &ArduinoStringFactory::getSingelton()); assert(resultCode >= 0);

  resultCode = io_engine->RegisterObjectBehaviour("String", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(constructor_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
  resultCode = io_engine->RegisterObjectBehaviour("String", asBEHAVE_CONSTRUCT,  "void f(const String& in)", asFUNCTION(copyConstructor_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
  resultCode = io_engine->RegisterObjectBehaviour("String", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(destructor_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
  resultCode = io_engine->RegisterObjectMethod("String", "String &opAssign(const String &in)", asFUNCTION(assign_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterObjectMethod("String", "String &opAddAssign(const String &in)", asFUNCTION(addAssign_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);

	resultCode = io_engine->RegisterObjectMethod("String", "bool opEquals(const String &in) const", asFUNCTION(equals_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterObjectMethod("String", "int opCmp(const String &in) const", asFUNCTION(compare_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterObjectMethod("String", "String opAdd(const String &in) const", asFUNCTION(add_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
  
  resultCode = io_engine->RegisterObjectMethod("String", "uint length() const", asFUNCTION(length_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterObjectMethod("String", "bool isEmpty() const", asFUNCTION(isEmpty_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
	resultCode = io_engine->RegisterObjectMethod("String", "void resize(uint)",   asFUNCTION(resize_arduinoString), asCALL_GENERIC); assert(resultCode >= 0);
}
