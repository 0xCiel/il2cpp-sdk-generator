```markdown
# Dump.cs to C++ SDK Generator

A tool that converts Dump.cs to C++ SDK with complete type definition and method stubs.

## Features

- Converts IL2CPP metadata to C++ headers and source files
- Generates complete class hierarchies with inheritance
- Creates ready-to-implement method stubs with IL2CPP API calls
- Handles namespaces, static methods, and virtual functions
- Includes automatic generation of required IL2CPP headers
- Produces detailed generation reports with timestamps

## Prerequisites

- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake 3.12+ (optional, for build integration)
- IL2CPP dump.cs file
```
# Usage
## Basic Conversion
```bash
testDumper.exe dump.cs output_directory
```

## Example Output Structure
```
output_directory/
├── include/
│   ├── SDK.hpp
│   ├── YourClass1.hpp
│   ├── YourClass2.hpp
│   └── il2cpp/
│       ├── il2cpp-api.h
│       ├── il2cpp-class.h
│       └── il2cpp-object-internals.h
└── src/
    ├── YourClass1.cpp
    └── YourClass2.cpp
```

## Using the Generated SDK

1. Include the main SDK header in your project:

```cpp

#include "SDK.hpp"
```
2. Implement method stubs as needed. Example for a generated class:
```cpp

// In YourClass.cpp
#include "YourClass.hpp"

int32_t YourClass::GetValue() {
    Il2CppClass* klass = il2cpp_class_from_name("Assembly-CSharp", "", "YourClass");
    const MethodInfo* method = il2cpp_class_get_method_from_name(klass, "GetValue", 0);
    return *static_cast<int32_t*>(il2cpp_runtime_invoke(method, this, nullptr, nullptr));
}
```

## Function Hooking Example

The generated SDK provides perfect integration points for function hooking. Here's a complete example:

### 1. Generated SDK Header (`Player.hpp`)
```cpp
#pragma once
#include <il2cpp/il2cpp-api.h>

namespace Game {
    class Player {
    public:
        int32_t GetHealth();
        void SetHealth(int32_t newHealth);
    };
}
```
### 2. Hook Implementation (hooks.cpp)
```cpp
#include "Player.hpp"
#include <MinHook.h>

// Original function pointers
int32_t (*original_GetHealth)(Game::Player* thisPtr);
void (*original_SetHealth)(Game::Player* thisPtr, int32_t newHealth);

// Hook for GetHealth
int32_t hooked_GetHealth(Game::Player* thisPtr) {
    std::cout << "[Hook] GetHealth called!\n";
    
    // Call original and modify return value
    int32_t health = original_GetHealth(thisPtr);
    return health + 100; // God mode effect
}

// Hook for SetHealth
void hooked_SetHealth(Game::Player* thisPtr, int32_t newHealth) {
    std::cout << "[Hook] SetHealth called with value: " << newHealth << "\n";
    
    // Block any damage (only allow healing)
    if (newHealth < thisPtr->GetHealth()) {
        std::cout << "[Hook] Blocking damage!\n";
        return;
    }
    original_SetHealth(thisPtr, newHealth);
}

void InstallHooks() {
    MH_Initialize();
    
    // Hook GetHealth
    auto getHealthAddr = il2cpp_resolve_icall("Game.Player::GetHealth");
    MH_CreateHook(
        (LPVOID)getHealthAddr,
        (LPVOID)&hooked_GetHealth,
        (LPVOID*)&original_GetHealth
    );
    
    // Hook SetHealth
    auto setHealthAddr = il2cpp_resolve_icall("Game.Player::SetHealth");
    MH_CreateHook(
        (LPVOID)setHealthAddr,
        (LPVOID)&hooked_SetHealth,
        (LPVOID*)&original_SetHealth
    );
    
    MH_EnableHook(MH_ALL_HOOKS);
}
```
### 3. DLL Main Entry Point (dllmain.cpp)
```cpp

#include "hooks.hpp"
#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, [](LPVOID) -> DWORD {
            InstallHooks();
            return 0;
        }, nullptr, 0, nullptr);
    }
    return TRUE;
}
```

# License
```
MIT License

Copyright (c) 2025 Ciel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

# TODO
* Internal Dumper
