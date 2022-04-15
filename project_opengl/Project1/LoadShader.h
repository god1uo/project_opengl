#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>; // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class LoadShader
{
	unsigned int m_ID{};
public:
	// 程序ID

	// 构造器读取并构建着色器
	LoadShader(const char* vertexPath, const char* fragmentPath);
	~LoadShader();
	// 使用/激活程序
	void use();
	// uniform工具函数
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec3(const std::string& name, glm::vec3 value)const;
	void setVec3(const std::string& name, float value1, float value2, float value3)const;
	void setMat4(const std::string& name, int num, bool isnorm, glm::mat4 mat)const;
};

#endif
