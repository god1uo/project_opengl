#include "LoadShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

LoadShader::LoadShader(const char* vertexPath, const char* fragmentPath)
{
	// 1. 从文件路径中获取顶点/片段着色器
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// 保证ifstream对象可以抛出异常：
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// 打开文件
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// 读取文件的缓冲内容到数据流中
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// 关闭文件处理器
		vShaderFile.close();
		fShaderFile.close();
		// 转换数据流到string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// 顶点着色器
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// 打印编译错误（如果有的话）
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, nullptr);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	

	// 着色器程序
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);
	glLinkProgram(m_ID);
	// 打印连接错误（如果有的话）
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

LoadShader::~LoadShader() {
	int success;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (success) {
		glDeleteShader(m_ID);
	}
}

void LoadShader::use() {
	glUseProgram(m_ID);
}

void LoadShader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void LoadShader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void LoadShader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void LoadShader::setVec3(const std::string& name, glm::vec3 value) const{
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), value.x, value.y, value.z);
}

void LoadShader::setVec3(const std::string& name, float value1, float value2, float value3) const {
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), value1, value2, value3);
}

void LoadShader::setMat4(const std::string& name, int num, bool isnorm, glm::mat4 mat) const{
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), num, isnorm, glm::value_ptr(mat));
}