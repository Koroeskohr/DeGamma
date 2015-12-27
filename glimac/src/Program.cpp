#include "Program.hpp"


namespace glimac {

bool Program::link() {
	glLinkProgram(m_nGLId);
	GLint status;
	glGetProgramiv(m_nGLId, GL_LINK_STATUS, &status);
	return status == GL_TRUE;
}

const std::string Program::getInfoLog() const {
	GLint length;
	glGetProgramiv(m_nGLId, GL_INFO_LOG_LENGTH, &length);
	char* log = new char[length];
	glGetProgramInfoLog(m_nGLId, length, 0, log);
	std::string logString(log);
	delete [] log;
	return logString;
}

// Build a GLSL program from source code
Program buildProgram(const GLchar* vsSrc, const GLchar* fsSrc) {
	Shader vs(GL_VERTEX_SHADER);
	vs.setSource(vsSrc);

	if(!vs.compile()) {
		throw std::runtime_error("Compilation error for vertex shader: " + vs.getInfoLog());
	}

	Shader fs(GL_FRAGMENT_SHADER);
	fs.setSource(fsSrc);

	if(!fs.compile()) {
		throw std::runtime_error("Compilation error for fragment shader: " + fs.getInfoLog());
	}

	Program program;
	program.attachShader(vs);
	program.attachShader(fs);

	if(!program.link()) {
		throw std::runtime_error("Link error: " + program.getInfoLog());
	}

	return program;
}

// Load source code from files and build a GLSL program
Program * loadProgram(const FilePath& vsFile, const FilePath& fsFile) {
	Shader vs = loadShader(GL_VERTEX_SHADER, vsFile);
	Shader fs = loadShader(GL_FRAGMENT_SHADER, fsFile);

	if(!vs.compile()) {
		throw std::runtime_error("Compilation error for vertex shader (from file " + std::string(vsFile) + "): " + vs.getInfoLog());
	}

	if(!fs.compile()) {
		throw std::runtime_error("Compilation error for fragment shader (from file " + std::string(fsFile) + "): " + fs.getInfoLog());
	}

	Program * program = new Program;
	program->attachShader(vs);
	program->attachShader(fs);

	if(!program->link()) {
        throw std::runtime_error("Link error (for files " + vsFile.str() + " and " + fsFile.str() + "): " + program->getInfoLog());
	}

	return program;
}

bool Program::isCurrent(){
	GLint current = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &current);
	return current == m_nGLId;
}

GLint Program::uniform (const GLchar *name) const {
	if (!name) {
		throw std::runtime_error("Program::uniform : name was empty or pointer was null");
	}

	GLint uniform = glGetUniformLocation(m_nGLId, name);

	if (uniform == -1) {
		std::stringstream msg;
		msg << "Uniform in program " << m_nGLId << " not found: " << name << std::endl;
		throw std::runtime_error(msg.str().c_str());
	}

	return uniform;
}

void Program::setUniform (const GLchar *name, GLfloat v0) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform1f(uniform(name), v0);
}

void Program::setUniform (const GLchar *name, GLfloat v0, GLfloat v1) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform2f(uniform(name), v0, v1);
}

void Program::setUniform (const GLchar *name, GLfloat v0, GLfloat v1, GLfloat v2) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform3f(uniform(name), v0, v1, v2);
}

void Program::setUniform (const GLchar *name, const glm::vec3 &v) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform3f(uniform(name), v.x, v.y, v.z);
}

void Program::setUniform (const GLchar *name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform4f(uniform(name), v0, v1, v2, v3);
}

void Program::setUniform (const GLchar *name, const glm::vec4 &v) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniform4f(uniform(name), v.x, v.y, v.z, v.w);
}

void Program::setUniformMatrix2 (const GLchar *name, const glm::mat2 &v) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniformMatrix2fv(uniform(name), 1, GL_FALSE, glm::value_ptr(v));
}

void Program::setUniformMatrix3 (const GLchar *name, const glm::mat3 &v) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniformMatrix3fv(uniform(name), 1, GL_FALSE, glm::value_ptr(v));
}

void Program::setUniformMatrix4 (const GLchar *name, const glm::mat4 &v) {
	if(!isCurrent())
		throw std::runtime_error("A uniform tried to be set to a non-current program");
	glUniformMatrix4fv(uniform(name), 1, GL_FALSE, glm::value_ptr(v));
}
}
