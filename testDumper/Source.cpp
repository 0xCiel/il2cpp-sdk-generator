#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <memory>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <iomanip>
#include <ctime>
#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#define MKDIR(dir) _mkdir(dir)
#define PATH_SEPARATOR "\\"
#else
#include <sys/stat.h>
#include <sys/types.h>
#define MKDIR(dir) mkdir(dir, 0755)
#define PATH_SEPARATOR "/"
#endif
#pragma region IL2CPP_Defines
#define FIELD_ATTRIBUTE_FIELD_ACCESS_MASK     0x0007
#define FIELD_ATTRIBUTE_COMPILER_CONTROLLED   0x0000
#define FIELD_ATTRIBUTE_PRIVATE               0x0001
#define FIELD_ATTRIBUTE_FAM_AND_ASSEM         0x0002
#define FIELD_ATTRIBUTE_ASSEMBLY              0x0003
#define FIELD_ATTRIBUTE_FAMILY                0x0004
#define FIELD_ATTRIBUTE_FAM_OR_ASSEM          0x0005
#define FIELD_ATTRIBUTE_PUBLIC                0x0006

#define FIELD_ATTRIBUTE_STATIC                0x0010
#define FIELD_ATTRIBUTE_INIT_ONLY             0x0020
#define FIELD_ATTRIBUTE_LITERAL               0x0040
#define FIELD_ATTRIBUTE_NOT_SERIALIZED        0x0080
#define FIELD_ATTRIBUTE_SPECIAL_NAME          0x0200
#define FIELD_ATTRIBUTE_PINVOKE_IMPL          0x2000

/* For runtime use only */
#define FIELD_ATTRIBUTE_RESERVED_MASK         0x9500
#define FIELD_ATTRIBUTE_RT_SPECIAL_NAME       0x0400
#define FIELD_ATTRIBUTE_HAS_FIELD_MARSHAL     0x1000
#define FIELD_ATTRIBUTE_HAS_DEFAULT           0x8000
#define FIELD_ATTRIBUTE_HAS_FIELD_RVA         0x0100

/*
 * Method Attributes (22.1.9)
 */

#define METHOD_IMPL_ATTRIBUTE_CODE_TYPE_MASK       0x0003
#define METHOD_IMPL_ATTRIBUTE_IL                   0x0000
#define METHOD_IMPL_ATTRIBUTE_NATIVE               0x0001
#define METHOD_IMPL_ATTRIBUTE_OPTIL                0x0002
#define METHOD_IMPL_ATTRIBUTE_RUNTIME              0x0003

#define METHOD_IMPL_ATTRIBUTE_MANAGED_MASK         0x0004
#define METHOD_IMPL_ATTRIBUTE_UNMANAGED            0x0004
#define METHOD_IMPL_ATTRIBUTE_MANAGED              0x0000

#define METHOD_IMPL_ATTRIBUTE_FORWARD_REF          0x0010
#define METHOD_IMPL_ATTRIBUTE_PRESERVE_SIG         0x0080
#define METHOD_IMPL_ATTRIBUTE_INTERNAL_CALL        0x1000
#define METHOD_IMPL_ATTRIBUTE_SYNCHRONIZED         0x0020
#define METHOD_IMPL_ATTRIBUTE_NOINLINING           0x0008
#define METHOD_IMPL_ATTRIBUTE_MAX_METHOD_IMPL_VAL  0xffff

#define METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK        0x0007
#define METHOD_ATTRIBUTE_COMPILER_CONTROLLED       0x0000
#define METHOD_ATTRIBUTE_PRIVATE                   0x0001
#define METHOD_ATTRIBUTE_FAM_AND_ASSEM             0x0002
#define METHOD_ATTRIBUTE_ASSEM                     0x0003
#define METHOD_ATTRIBUTE_FAMILY                    0x0004
#define METHOD_ATTRIBUTE_FAM_OR_ASSEM              0x0005
#define METHOD_ATTRIBUTE_PUBLIC                    0x0006

#define METHOD_ATTRIBUTE_STATIC                    0x0010
#define METHOD_ATTRIBUTE_FINAL                     0x0020
#define METHOD_ATTRIBUTE_VIRTUAL                   0x0040
#define METHOD_ATTRIBUTE_HIDE_BY_SIG               0x0080

#define METHOD_ATTRIBUTE_VTABLE_LAYOUT_MASK        0x0100
#define METHOD_ATTRIBUTE_REUSE_SLOT                0x0000
#define METHOD_ATTRIBUTE_NEW_SLOT                  0x0100

#define METHOD_ATTRIBUTE_STRICT                    0x0200
#define METHOD_ATTRIBUTE_ABSTRACT                  0x0400
#define METHOD_ATTRIBUTE_SPECIAL_NAME              0x0800

#define METHOD_ATTRIBUTE_PINVOKE_IMPL              0x2000
#define METHOD_ATTRIBUTE_UNMANAGED_EXPORT          0x0008

 /*
  * For runtime use only
  */
#define METHOD_ATTRIBUTE_RESERVED_MASK             0xd000
#define METHOD_ATTRIBUTE_RT_SPECIAL_NAME           0x1000
#define METHOD_ATTRIBUTE_HAS_SECURITY              0x4000
#define METHOD_ATTRIBUTE_REQUIRE_SEC_OBJECT        0x8000

  /*
  * Type Attributes (21.1.13).
  */
#define TYPE_ATTRIBUTE_VISIBILITY_MASK       0x00000007
#define TYPE_ATTRIBUTE_NOT_PUBLIC            0x00000000
#define TYPE_ATTRIBUTE_PUBLIC                0x00000001
#define TYPE_ATTRIBUTE_NESTED_PUBLIC         0x00000002
#define TYPE_ATTRIBUTE_NESTED_PRIVATE        0x00000003
#define TYPE_ATTRIBUTE_NESTED_FAMILY         0x00000004
#define TYPE_ATTRIBUTE_NESTED_ASSEMBLY       0x00000005
#define TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM  0x00000006
#define TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM   0x00000007

#define TYPE_ATTRIBUTE_LAYOUT_MASK           0x00000018
#define TYPE_ATTRIBUTE_AUTO_LAYOUT           0x00000000
#define TYPE_ATTRIBUTE_SEQUENTIAL_LAYOUT     0x00000008
#define TYPE_ATTRIBUTE_EXPLICIT_LAYOUT       0x00000010

#define TYPE_ATTRIBUTE_CLASS_SEMANTIC_MASK   0x00000020
#define TYPE_ATTRIBUTE_CLASS                 0x00000000
#define TYPE_ATTRIBUTE_INTERFACE             0x00000020

#define TYPE_ATTRIBUTE_ABSTRACT              0x00000080
#define TYPE_ATTRIBUTE_SEALED                0x00000100
#define TYPE_ATTRIBUTE_SPECIAL_NAME          0x00000400

#define TYPE_ATTRIBUTE_IMPORT                0x00001000
#define TYPE_ATTRIBUTE_SERIALIZABLE          0x00002000

#define TYPE_ATTRIBUTE_STRING_FORMAT_MASK    0x00030000
#define TYPE_ATTRIBUTE_ANSI_CLASS            0x00000000
#define TYPE_ATTRIBUTE_UNICODE_CLASS         0x00010000
#define TYPE_ATTRIBUTE_AUTO_CLASS            0x00020000

#define TYPE_ATTRIBUTE_BEFORE_FIELD_INIT     0x00100000
#define TYPE_ATTRIBUTE_FORWARDER             0x00200000

#define TYPE_ATTRIBUTE_RESERVED_MASK         0x00040800
#define TYPE_ATTRIBUTE_RT_SPECIAL_NAME       0x00000800
#define TYPE_ATTRIBUTE_HAS_SECURITY          0x00040000

  /*
  * Flags for Params (22.1.12)
  */
#define PARAM_ATTRIBUTE_IN                 0x0001
#define PARAM_ATTRIBUTE_OUT                0x0002
#define PARAM_ATTRIBUTE_OPTIONAL           0x0010
#define PARAM_ATTRIBUTE_RESERVED_MASK      0xf000
#define PARAM_ATTRIBUTE_HAS_DEFAULT        0x1000
#define PARAM_ATTRIBUTE_HAS_FIELD_MARSHAL  0x2000
#define PARAM_ATTRIBUTE_UNUSED             0xcfe0

  // Flags for Generic Parameters (II.23.1.7)
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NON_VARIANT                           0x00
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_COVARIANT                             0x01
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_CONTRAVARIANT                         0x02
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_VARIANCE_MASK                         0x03
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_REFERENCE_TYPE_CONSTRAINT             0x04
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT    0x08
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_DEFAULT_CONSTRUCTOR_CONSTRAINT        0x10
#define IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_SPECIAL_CONSTRAINT_MASK               0x1C

/**
 * 21.5 AssemblyRefs
 */
#define ASSEMBLYREF_FULL_PUBLIC_KEY_FLAG      0x00000001
#define ASSEMBLYREF_RETARGETABLE_FLAG         0x00000100
#define ASSEMBLYREF_ENABLEJITCOMPILE_TRACKING_FLAG 0x00008000
#define ASSEMBLYREF_DISABLEJITCOMPILE_OPTIMIZER_FLAG 0x00004000
#pragma endregion IL2CPP_Defines

class BeeByteDeobfuscator {
private:
    std::unordered_map<std::string, std::string> m_classMap;
    std::unordered_map<std::string, std::string> m_fieldMap;
    std::unordered_map<std::string, std::string> m_methodMap;
    int m_classCount = 0;
    int m_fieldCount = 0;
    int m_methodCount = 0;
    std::regex m_nameRegex{ "[a-zA-Z0-9_]+" };

public:
    std::string DeobfuscateClass(const std::string& name) {
        if (std::regex_match(name, m_nameRegex)) {
            return name;
        }

        auto it = m_classMap.find(name);
        if (it != m_classMap.end()) {
            return it->second;
        }

        std::string newName = "Class" + std::to_string(m_classCount++);
        m_classMap[name] = newName;
        return newName;
    }

    std::string DeobfuscateField(const std::string& name) {
        if (std::regex_match(name, m_nameRegex)) {
            return name;
        }

        auto it = m_fieldMap.find(name);
        if (it != m_fieldMap.end()) {
            return it->second;
        }

        std::string newName = "Field" + std::to_string(m_fieldCount++);
        m_fieldMap[name] = newName;
        return newName;
    }

    std::string DeobfuscateMethod(const std::string& name) {
        if (std::regex_match(name, m_nameRegex)) {
            return name;
        }

        auto it = m_methodMap.find(name);
        if (it != m_methodMap.end()) {
            return it->second;
        }

        std::string newName = "Method" + std::to_string(m_methodCount++);
        m_methodMap[name] = newName;
        return newName;
    }

    void PrintStats() const {
        std::cout << "[Deobfuscator] Renamed " << m_classMap.size() << " classes, "
            << m_fieldMap.size() << " fields, " << m_methodMap.size() << " methods\n";
    }
};



class IL2CPPConverter {
public:
    IL2CPPConverter(const std::string& inputPath, const std::string& outputPath)
        : m_inputPath(inputPath), m_outputPath(outputPath) {
        if (!m_outputPath.empty() &&
            m_outputPath.back() != PATH_SEPARATOR[0]) {
            m_outputPath += PATH_SEPARATOR;
        }
    }

    bool Convert() {
        if (!ValidatePaths()) {
            return false;
        }

        if (!CreateOutputStructure()) {
            return false;
        }

        if (!ParseInputFile()) {
            std::cerr << "[ERROR] Failed to parse input file" << std::endl;
            return false;
        }

        if (!GenerateSDK()) {
            std::cerr << "[ERROR] Failed to generate SDK" << std::endl;
            return false;
        }

        std::cout << "[SUCCESS] SDK generated at: " << m_outputPath << std::endl;
        return true;
    }

private:
    struct FieldInfo {
        std::string type;
        std::string name;
        uint32_t attributes;
        std::string defaultValue;
        std::string marshalInfo;
    };

    struct ParameterInfo {
        std::string type;
        std::string name;
        uint32_t attributes;
    };

    struct MethodInfo {
        std::string returnType;
        std::string name;
        std::vector<ParameterInfo> parameters;
        uint32_t attributes;
        uint32_t implAttributes;
        bool isGeneric;
        std::vector<std::string> genericParameters;
    };

    struct PropertyInfo {
        std::string type;
        std::string name;
        MethodInfo* getter;
        MethodInfo* setter;
        uint32_t attributes;
    };

    struct EventInfo {
        std::string type;
        std::string name;
        MethodInfo* addMethod;
        MethodInfo* removeMethod;
        MethodInfo* raiseMethod;
        uint32_t attributes;
    };

    struct ClassInfo {
        std::string name;
        std::string namespaceName;
        std::string assemblyName;
        std::string parentClass;
        std::vector<std::string> interfaces;
        uint32_t attributes;
        std::vector<FieldInfo> fields;
        std::vector<MethodInfo> methods;
        std::vector<PropertyInfo> properties;
        std::vector<EventInfo> events;
        bool isGeneric;
        std::vector<std::string> genericParameters;
    };

    std::string m_inputPath;
    std::string m_outputPath;
    std::vector<ClassInfo> m_classes;
    std::map<std::string, std::vector<std::string>> m_namespaces;
    BeeByteDeobfuscator m_deobfuscator;
    bool ValidatePaths() {
        std::ifstream testFile(m_inputPath);
        if (!testFile.good()) {
            std::cerr << "[ERROR] Input file does not exist or is not accessible: "
                << m_inputPath << std::endl;
            return false;
        }
        testFile.close();
        return true;
    }

    bool CreateOutputStructure() {
        if (!CreateDirectoryRecursive(m_outputPath)) {
            std::cerr << "[ERROR] Failed to create output directory: "
                << m_outputPath << std::endl;
            return false;
        }

        std::string srcDir = m_outputPath + "src" + PATH_SEPARATOR;
        if (!CreateDirectoryRecursive(srcDir)) {
            std::cerr << "[ERROR] Failed to create source directory: "
                << srcDir << std::endl;
            return false;
        }

        std::string includeDir = m_outputPath + "include" + PATH_SEPARATOR;
        if (!CreateDirectoryRecursive(includeDir)) {
            std::cerr << "[ERROR] Failed to create include directory: "
                << includeDir << std::endl;
            return false;
        }

        return true;
    }

    bool CreateDirectoryRecursive(const std::string& path) {
        size_t pos = 0;
        std::string dir;
        int mdret;

        if (path[path.size() - 1] != PATH_SEPARATOR[0]) {
            dir = path + PATH_SEPARATOR;
        }
        else {
            dir = path;
        }

        while ((pos = dir.find_first_of(PATH_SEPARATOR, pos + 1)) != std::string::npos) {
            std::string subdir = dir.substr(0, pos);
            if (subdir.empty()) continue;

#ifdef _WIN32
            mdret = MKDIR(subdir.c_str());
#else
            mdret = MKDIR(subdir.c_str(), 0755);
#endif
            if (mdret != 0 && errno != EEXIST) {
                return false;
            }
        }

        return true;
    }

    std::string SanitizeIdentifier(const std::string& identifier) {
        std::string sanitized = identifier;
        size_t genericPos = sanitized.find('`');
        if (genericPos != std::string::npos) {
            sanitized = sanitized.substr(0, genericPos);
        }
        std::replace_if(sanitized.begin(), sanitized.end(),
            [](char c) { return !isalnum(c) && c != '_'; }, '_');
        if (!sanitized.empty() && !isalpha(sanitized[0]) && sanitized[0] != '_') {
            sanitized = "_" + sanitized;
        }

        return sanitized;
    }

    std::string GetTypeAttributesString(uint32_t attributes) {
        std::ostringstream oss;
        switch (attributes & TYPE_ATTRIBUTE_VISIBILITY_MASK) {
        case TYPE_ATTRIBUTE_NOT_PUBLIC: oss << "private "; break;
        case TYPE_ATTRIBUTE_PUBLIC: oss << "public "; break;
        case TYPE_ATTRIBUTE_NESTED_PUBLIC: oss << "public "; break;
        case TYPE_ATTRIBUTE_NESTED_PRIVATE: oss << "private "; break;
        case TYPE_ATTRIBUTE_NESTED_FAMILY: oss << "protected "; break;
        case TYPE_ATTRIBUTE_NESTED_ASSEMBLY: oss << "internal "; break;
        case TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM: oss << "protected internal "; break;
        case TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM: oss << "protected internal "; break;
        }
        if (attributes & TYPE_ATTRIBUTE_INTERFACE) {
            oss << "interface ";
        }
        else {
            oss << "class ";
        }
        if (attributes & TYPE_ATTRIBUTE_ABSTRACT) oss << "abstract ";
        if (attributes & TYPE_ATTRIBUTE_SEALED) oss << "sealed ";
        if (attributes & TYPE_ATTRIBUTE_SERIALIZABLE) oss << "[Serializable] ";

        return oss.str();
    }

    std::string GetFieldAttributesString(uint32_t attributes) {
        std::ostringstream oss;
        switch (attributes & FIELD_ATTRIBUTE_FIELD_ACCESS_MASK) {
        case FIELD_ATTRIBUTE_PRIVATE: oss << "private "; break;
        case FIELD_ATTRIBUTE_FAM_AND_ASSEM: oss << "protected internal "; break;
        case FIELD_ATTRIBUTE_ASSEMBLY: oss << "internal "; break;
        case FIELD_ATTRIBUTE_FAMILY: oss << "protected "; break;
        case FIELD_ATTRIBUTE_FAM_OR_ASSEM: oss << "protected internal "; break;
        case FIELD_ATTRIBUTE_PUBLIC: oss << "public "; break;
        }
        if (attributes & FIELD_ATTRIBUTE_STATIC) oss << "static ";
        if (attributes & FIELD_ATTRIBUTE_INIT_ONLY) oss << "readonly ";
        if (attributes & FIELD_ATTRIBUTE_LITERAL) oss << "const ";

        return oss.str();
    }

    std::string GetMethodAttributesString(uint32_t attributes) {
        std::ostringstream oss;
        switch (attributes & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) {
        case METHOD_ATTRIBUTE_PRIVATE: oss << "private "; break;
        case METHOD_ATTRIBUTE_FAM_AND_ASSEM: oss << "protected internal "; break;
        case METHOD_ATTRIBUTE_ASSEM: oss << "internal "; break;
        case METHOD_ATTRIBUTE_FAMILY: oss << "protected "; break;
        case METHOD_ATTRIBUTE_FAM_OR_ASSEM: oss << "protected internal "; break;
        case METHOD_ATTRIBUTE_PUBLIC: oss << "public "; break;
        }
        if (attributes & METHOD_ATTRIBUTE_STATIC) oss << "static ";
        if (attributes & METHOD_ATTRIBUTE_VIRTUAL) oss << "virtual ";
        if (attributes & METHOD_ATTRIBUTE_ABSTRACT) oss << "abstract ";
        if (attributes & METHOD_ATTRIBUTE_FINAL) oss << "sealed ";
        if (attributes & METHOD_ATTRIBUTE_HIDE_BY_SIG) oss << "new ";

        return oss.str();
    }

    bool ParseInputFile() {
        std::ifstream file(m_inputPath);
        if (!file.is_open()) {
            std::cerr << "[ERROR] Could not open input file: " << m_inputPath << std::endl;
            return false;
        }

        std::string line;
        ClassInfo currentClass;
        bool inClass = false;
        bool inNamespace = false;
        int lineNumber = 0;

        while (std::getline(file, line)) {
            lineNumber++;
            line = Trim(line);
            if (line.empty() || line.find("//") == 0) {
                continue;
            }
            if (line.find("namespace ") == 0) {
                if (inClass) {
                    m_classes.push_back(currentClass);
                    currentClass = ClassInfo();
                    inClass = false;
                }

                size_t start = 10;
                size_t end = line.find_first_of(" {", start);
                currentClass.namespaceName = line.substr(start, end - start);
                inNamespace = true;
                continue;
            }
            if (line.find("class ") != std::string::npos ||
                line.find("struct ") != std::string::npos) {
                if (inClass) {
                    m_classes.push_back(currentClass);
                }

                currentClass = ClassInfo();
                currentClass.namespaceName = inNamespace ? currentClass.namespaceName : "";
                size_t classPos = line.find("class ");
                if (classPos == std::string::npos) {
                    classPos = line.find("struct ");
                }
                size_t nameStart = classPos + (line.find("class ") != std::string::npos ? 6 : 7);
                size_t nameEnd = line.find_first_of(" :<{", nameStart);
                currentClass.name = line.substr(nameStart, nameEnd - nameStart);
                if (line.find("public ") != std::string::npos) {
                    currentClass.attributes |= TYPE_ATTRIBUTE_PUBLIC;
                }
                if (line.find("abstract ") != std::string::npos) {
                    currentClass.attributes |= TYPE_ATTRIBUTE_ABSTRACT;
                }
                if (line.find("sealed ") != std::string::npos) {
                    currentClass.attributes |= TYPE_ATTRIBUTE_SEALED;
                }
                if (line.find("interface ") != std::string::npos) {
                    currentClass.attributes |= TYPE_ATTRIBUTE_INTERFACE;
                }

                inClass = true;
                continue;
            }
            if (inClass && line.find(';') != std::string::npos &&
                line.find('(') == std::string::npos &&
                line.find(')') == std::string::npos) {
                FieldInfo field;
                size_t lastSpace = line.find_last_of(' ');
                if (lastSpace != std::string::npos) {
                    field.type = line.substr(0, lastSpace);
                    field.name = line.substr(lastSpace + 1, line.find(';') - lastSpace - 1);
                    if (line.find("public ") != std::string::npos) {
                        field.attributes |= FIELD_ATTRIBUTE_PUBLIC;
                    }
                    if (line.find("static ") != std::string::npos) {
                        field.attributes |= FIELD_ATTRIBUTE_STATIC;
                    }
                    if (line.find("const ") != std::string::npos) {
                        field.attributes |= FIELD_ATTRIBUTE_LITERAL;
                    }
                    if (line.find("readonly ") != std::string::npos) {
                        field.attributes |= FIELD_ATTRIBUTE_INIT_ONLY;
                    }

                    currentClass.fields.push_back(field);
                }
                continue;
            }
            if (inClass && line.find('(') != std::string::npos &&
                line.find(')') != std::string::npos) {
                MethodInfo method;
                size_t parenStart = line.find('(');
                size_t lastSpace = line.substr(0, parenStart).find_last_of(' ');

                if (lastSpace != std::string::npos) {
                    method.returnType = line.substr(0, lastSpace);
                    method.name = line.substr(lastSpace + 1, parenStart - lastSpace - 1);
                    if (line.find("public ") != std::string::npos) {
                        method.attributes |= METHOD_ATTRIBUTE_PUBLIC;
                    }
                    if (line.find("static ") != std::string::npos) {
                        method.attributes |= METHOD_ATTRIBUTE_STATIC;
                    }
                    if (line.find("virtual ") != std::string::npos) {
                        method.attributes |= METHOD_ATTRIBUTE_VIRTUAL;
                    }
                    if (line.find("abstract ") != std::string::npos) {
                        method.attributes |= METHOD_ATTRIBUTE_ABSTRACT;
                    }

                    currentClass.methods.push_back(method);
                }
                continue;
            }
            if (line.find('}') != std::string::npos) {
                if (inClass) {
                    m_classes.push_back(currentClass);
                    currentClass = ClassInfo();
                    inClass = false;
                }
                if (inNamespace) {
                    inNamespace = false;
                }
            }
        }

        file.close();
        return true;
    }

    std::string Trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, (last - first + 1));
    }

    bool GenerateSDK() {
        auto startTime = std::chrono::system_clock::now();
        if (!GenerateIL2CPPHeaders()) {
            std::cerr << "[ERROR] Failed to generate IL2CPP headers" << std::endl;
            return false;
        }
        std::string sdkHeaderPath = m_outputPath + "include" + PATH_SEPARATOR + "SDK.hpp";
        std::ofstream sdkHeader(sdkHeaderPath);
        if (!sdkHeader.is_open()) {
            std::cerr << "[ERROR] Could not create SDK header: " << sdkHeaderPath << std::endl;
            return false;
        }
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::tm tm = *std::localtime(&in_time_t);
        std::ostringstream timeStream;
        timeStream << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        std::string timestamp = timeStream.str();
        sdkHeader << "#pragma once\n\n";
        sdkHeader << "// IL2CPP Generated SDK by Ciel | @0xciel\n";
        sdkHeader << "// Generated on: " << timestamp << "\n";
        sdkHeader << "// Source: " << m_inputPath << "\n";
        sdkHeader << "// Total classes: " << m_classes.size() << "\n\n";
        int generatedClasses = 0;

        for (const auto& cls : m_classes) {
            if (GenerateClassHeader(cls, timestamp)) {
                generatedClasses++;
            }
            else {
                std::cerr << "[WARNING] Failed to generate header for class: " << cls.name << std::endl;
            }
        }
        int generatedSources = 0;
        for (const auto& cls : m_classes) {
            if (GenerateClassSource(cls)) {  
                generatedSources++;
            }
            else {
                std::cerr << "[WARNING] Failed to generate source for class: " << cls.name << std::endl;
            }
        }
        for (const auto& cls : m_classes) {
            std::string headerName = SanitizeIdentifier(cls.name) + ".hpp";
            sdkHeader << "#include \"" << headerName << "\"\n";
        }

        sdkHeader << "\n// Generation completed successfully\n";
        sdkHeader << "// Classes: " << generatedClasses << "/" << m_classes.size() << "\n";
        sdkHeader << "// Sources: " << generatedSources << "/" << m_classes.size() << "\n";
        sdkHeader.close();
        auto endTime = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        std::string reportPath = m_outputPath + "generation_report.txt";
        std::ofstream report(reportPath);
        if (report.is_open()) {
            report << "Ciel IL2CPP SDK Generation Report\n";
            report << "==========================\n";
            report << "Timestamp: " << timestamp << "\n";
            report << "Source file: " << m_inputPath << "\n";
            report << "Output directory: " << m_outputPath << "\n";
            report << "Generation time: " << duration.count() << "ms\n";
            report << "Classes processed: " << m_classes.size() << "\n";
            report << "Headers generated: " << generatedClasses << "\n";
            report << "Sources generated: " << generatedSources << "\n";
            report << "Success rate: "
                << std::fixed << std::setprecision(1)
                << ((float)generatedClasses / m_classes.size() * 100) << "%\n";
            report.close();
        }
        m_deobfuscator.PrintStats();
        std::cout << "\n[SUCCESS] SDK generation completed!\n";
        std::cout << "Timestamp: " << timestamp << "\n";
        std::cout << "Processed " << m_classes.size() << " classes in "
            << duration.count() << "ms\n";
        std::cout << "Generation report saved to: " << reportPath << "\n";

        return true;
    }
    bool GenerateIL2CPPHeaders() {
        std::string il2cppDir = m_outputPath + "include" + PATH_SEPARATOR + "il2cpp" + PATH_SEPARATOR;
        if (!CreateDirectoryRecursive(il2cppDir)) {
            std::cerr << "[ERROR] Failed to create il2cpp include directory" << std::endl;
            return false;
        }
        std::ofstream apiHeader(il2cppDir + "il2cpp-api.h");
        if (!apiHeader.is_open()) return false;

        apiHeader << R"(#pragma once
// IL2CPP API Header
// Automatically generated by Ciel IL2CPP SDK Generator

#ifndef __IL2CPP_API_H__
#define __IL2CPP_API_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Basic Types
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppObject Il2CppObject;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;

// Class API
Il2CppClass* il2cpp_class_from_name(const char* assemblyName, const char* namespaze, const char* className);
const MethodInfo* il2cpp_class_get_method_from_name(Il2CppClass* klass, const char* name, int argsCount);

// Runtime Invocation
void* il2cpp_runtime_invoke(const MethodInfo* method, void* obj, void** params, void** exc);

// Object API
Il2CppObject* il2cpp_object_new(const Il2CppClass* klass);

#ifdef __cplusplus
}
#endif

#endif // __IL2CPP_API_H__
)";
        apiHeader.close();
        std::ofstream classHeader(il2cppDir + "il2cpp-class.h");
        if (!classHeader.is_open()) return false;

        classHeader << R"(#pragma once
// IL2CPP Class Header
// Automatically generated by Ciel IL2CPP SDK Generator

#ifndef __IL2CPP_CLASS_H__
#define __IL2CPP_CLASS_H__

#include "il2cpp-api.h"

typedef struct Il2CppClass {
    const char* name;
    const char* namespaze;
    Il2CppClass* parent;
    Il2CppClass** implementedInterfaces;
    uint32_t interface_offsets_count;
    uint32_t method_count;
    uint32_t field_count;
    uint32_t property_count;
    uint32_t event_count;
} Il2CppClass;

#endif // __IL2CPP_CLASS_H__
)";
        classHeader.close();
        std::ofstream objInternalsHeader(il2cppDir + "il2cpp-object-internals.h");
        if (!objInternalsHeader.is_open()) return false;

        objInternalsHeader << R"(#pragma once
// IL2CPP Object Internals Header
// Automatically generated by Ciel IL2CPP SDK Generator

#ifndef __IL2CPP_OBJECT_INTERNALS_H__
#define __IL2CPP_OBJECT_INTERNALS_H__

#include "il2cpp-api.h"

typedef struct Il2CppObject {
    Il2CppClass *klass;
    void *monitor;
} Il2CppObject;

#endif // __IL2CPP_OBJECT_INTERNALS_H__
)";
        objInternalsHeader.close();

        return true;
    }
    bool GenerateClassHeader(const ClassInfo& cls, const std::string& timestamp) {
        std::string headerName = m_deobfuscator.DeobfuscateClass(cls.name) + ".hpp";
        std::string headerPath = m_outputPath + "include" + PATH_SEPARATOR + headerName;

        std::ofstream header(headerPath);
        if (!header.is_open()) return false;

        std::string className = m_deobfuscator.DeobfuscateClass(cls.name);
        std::string guard = "__" + SanitizeIdentifier(className) + "_HPP__";
        std::transform(guard.begin(), guard.end(), guard.begin(), ::toupper);

        header << "#pragma once\n";
        header << "// Original IL2CPP Name: " << cls.name << "\n";
        header << "// Deobfuscated Name: " << className << "\n\n";
        header << "#ifndef " << guard << "\n";
        header << "#define " << guard << "\n\n";
        header << "#include <cstdint>\n";
        header << "#include <string>\n";
        header << "#include <vector>\n\n";
        if (!cls.namespaceName.empty()) {
            header << "namespace " << cls.namespaceName << " {\n\n";
        }
        header << "// Original IL2CPP Type: " << cls.name << "\n";
        if (cls.attributes & TYPE_ATTRIBUTE_INTERFACE) {
            header << "struct ";
        }
        else {
            header << "class ";
        }
        header << SanitizeIdentifier(cls.name);
        if (!cls.parentClass.empty()) {
            header << " : public " << SanitizeIdentifier(cls.parentClass);
        }
        header << " {\n";
        if ((cls.attributes & TYPE_ATTRIBUTE_VISIBILITY_MASK) == TYPE_ATTRIBUTE_PUBLIC) {
            header << "public:\n";
        }
        else {
            header << "private:\n";
        }
        for (const auto& field : cls.fields) {
            std::string fieldName = m_deobfuscator.DeobfuscateField(field.name);
            header << "    " << field.type << " " << SanitizeIdentifier(fieldName) << ";\n";
        }

        if (!cls.fields.empty() && !cls.methods.empty()) {
            header << "\n";
        }
        for (const auto& method : cls.methods) {
            std::string methodName = m_deobfuscator.DeobfuscateMethod(method.name);
            header << "    " << method.returnType << " "
                << SanitizeIdentifier(methodName) << "(";
            header << ");\n";
        }

        header << "#endif // " << guard << "\n";
        header.close();
        return true;
    }


    bool GenerateClassSource(const ClassInfo& cls) {
        std::string className = m_deobfuscator.DeobfuscateClass(cls.name);
        std::string srcName = className + ".cpp";
        std::string srcPath = m_outputPath + "src" + PATH_SEPARATOR + srcName;

        std::ofstream source(srcPath);
        if (!source.is_open()) return false;

        source << "#include \"../include/" << className << ".hpp\"\n";
        source << "// Original IL2CPP Class Name: " << cls.name << "\n\n";

        for (const auto& method : cls.methods) {
            std::string methodName = m_deobfuscator.DeobfuscateMethod(method.name);
            source << method.returnType << " " << className << "::"
                << SanitizeIdentifier(methodName) << "(";
            source << ") {\n";
            source << "    const MethodInfo* methodInfo = il2cpp_class_get_method_from_name(klass, \""
                << method.name << "\", " << method.parameters.size() << ");\n";
            source << "}\n\n";
        }

        source.close();
        return true;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_dump_file> <output_directory>\n";
        std::cerr << "Example: " << argv[0] << " dump.cs sdk_output\n";
        return 1;
    }

    IL2CPPConverter converter(argv[1], argv[2]);
    return converter.Convert() ? 0 : 1;
}