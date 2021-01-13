#include <nan.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

void FillZero(const FunctionCallbackInfo<Value>& args){
  Isolate* isolate = args.GetIsolate();
  
  /* Check arguments */
  if ((args.Length() != 2 && args.Length() != 3) || !args[0]->IsNumber() || !args[1]->IsNumber()) {
    
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass the correct input")));
    return;
  }
  
  int zeros = args[0]->NumberValue();
  int number = args[1]->NumberValue();
  std::ostringstream stream;
  
  if (args.Length() == 2) {
    /* Fill the number with the right padding */
    stream << std::setfill('0') << std::setw(zeros) << number;
  } else {
    String::Utf8Value tmp(args[2]->ToString());
    std::string str = std::string(*tmp);
    stream << std::setfill(str[0]) << std::setw(zeros) << number;
  }
  
  /* Revert back to String and return to Javascript */
  std::string str = stream.str(); 
  v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str.c_str(), v8::String::kNormalString);
  args.GetReturnValue().Set(v8String);
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "FillZero", FillZero);
}

NODE_MODULE(FillZero, Init)
