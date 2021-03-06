//
//

#include "util.h"
#include "../graphics/common.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void _logGlErrors(const int line, const char *file) {
    string prefix = string(file) + ":" + std::to_string(line) + ":";
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        cout << prefix;
        switch (err) {
            case GL_NO_ERROR:
                cout << "GL_NO_ERROR" << endl;
                break;
            case GL_INVALID_ENUM:
                cout << "GL_INVALID_ENUM" << endl;
                break;
            case GL_INVALID_VALUE:
                cout << "GL_INVALID_VALUE" << endl;
                break;
            case GL_INVALID_OPERATION:
                cout << "GL_INVALID_OPERATION" << endl;
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                cout << "GL_INVALID_FRAMEBUFFER_OPERATION" << endl;
                break;
            case GL_OUT_OF_MEMORY:
                cout << "GL_OUT_OF_MEMORY" << endl;
                break;
        }
    }
}

namespace pixel::util
{

struct pixelerror : std::exception
{
    std::string _msg;
    explicit pixelerror(std::string msg) : _msg(std::move(msg))
    {
    }

    const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};

bool file_exists(const std::string &path)
{
    ifstream file(path);
    return file.good();
}

void _error(const int line, const char *file, const std::string &msg)
{
    string prefix = string(file) + ":" + std::to_string(line) + ":";
    cout << prefix << msg << endl;
    throw pixelerror(msg);
}

void _error_if(const int line, const char *file, bool expr, const std::string &msg)
{
   if (expr) {
       _error(line, file, msg);
   }
}

};
