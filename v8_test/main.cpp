//
//  main.cpp
//  v8_test
//
//  Created by fisher on 14/12/29.
//  Copyright (c) 2014年 bitsuperlab. All rights reserved.
//

#include "v8.h"
// #include "libplatform/libplatform.h"

using namespace v8;

int main(int argc, char* argv[]) {
    // Create a stack-allocated handle scope.
    HandleScope handle_scope;
    // Create a new context.
    Handle<Context> context = Context::New();
    // Enter the created context for compiling and
    // running the hello world script.
    Context::Scope context_scope(context);
    // Create a string containing the JavaScript source code.
    Handle<String> source = String::New("'Hello' + ', World!'");
    // Compile the source code.
    Handle<Script> script = Script::Compile(source);
    // Run the script to get the result.
    Handle<Value> result = script->Run();
    // Convert the result to an ASCII string and print it.
    String::AsciiValue ascii(result);
    printf("%s\n",*ascii);
    return 0;
}
