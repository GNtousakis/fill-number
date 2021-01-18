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

NAN_METHOD(FillNumber) {
  Isolate* isolate = info.GetIsolate();
  
  /* Check arguments */
  if ((info.Length() != 2 && info.Length() != 3) || !info[0]->IsNumber() || !info[1]->IsNumber()) {
    
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass the correct input")));
    return;
  }
  
  int zeros = info[0]->NumberValue();
  int number = info[1]->NumberValue();
  std::ostringstream stream;
  
  if (info.Length() == 2) {
    /* Fill the number with the right padding */
    stream << std::setfill('0') << std::setw(zeros) << number;
  } else {
    String::Utf8Value tmp(info[2]->ToString());
    std::string str = std::string(*tmp);
    stream << std::setfill(str[0]) << std::setw(zeros) << number;
  }
  
  /* Revert back to String and return to Javascript */
  std::string str = stream.str(); 
  v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str.c_str(), v8::String::kNormalString);
  info.GetReturnValue().Set(v8String);
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT( target, FillNumber);
}

NODE_MODULE(FillNumber, Init)
