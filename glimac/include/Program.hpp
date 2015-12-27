#pragma once

#include <GL/glew.h>
#include "glm.hpp"
#include "Shader.hpp"
#include "FilePath.hpp"
#include <stdexcept>
#include <sstream>

namespace glimac {

class Program {
public:
	Program(): m_nGLId(glCreateProgram()) {
	}

	~Program() {
		glDeleteProgram(m_nGLId);
	}

	Program(Program&& rvalue): m_nGLId(rvalue.m_nGLId) {
		rvalue.m_nGLId = 0;
	}

	Program& operator =(Program&& rvalue) {
		m_nGLId = rvalue.m_nGLId;
		rvalue.m_nGLId = 0;
		return *this;
	}

	GLuint getGLId() const {
		return m_nGLId;
	}

	void attachShader(const Shader& shader) {
		glAttachShader(m_nGLId, shader.getGLId());
	}

	bool link();

	const std::string getInfoLog() const;

	void use() const {
		glUseProgram(m_nGLId);
	}

	bool isCurrent();

	GLint uniform(const GLchar * name) const;

	void setUniform(const GLchar* name, GLfloat v0);
	void setUniform(const GLchar* name, GLfloat v0, GLfloat v1);
	void setUniform(const GLchar* name, GLfloat v0, GLfloat v1, GLfloat v2);
	void setUniform(const GLchar* name, const glm::vec3& v);
	void setUniform(const GLchar* name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void setUniform(const GLchar* name, const glm::vec4& v);
	void setUniformMatrix2(const GLchar* name, const glm::mat2& v);
	void setUniformMatrix3(const GLchar* name, const glm::mat3& v);
	void setUniformMatrix4(const GLchar* name, const glm::mat4& v);



	Program(const Program&);
	Program& operator =(const Program&);

private:


	GLuint m_nGLId;
};

// Build a GLSL program from source code
Program buildProgram(const GLchar* vsSrc, const GLchar* fsSrc);

// Load source code from files and build a GLSL program
Program * loadProgram(const FilePath& vsFile, const FilePath& fsFile);


}
