#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>; // ����glad����ȡ���еı���OpenGLͷ�ļ�

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Loadimage.h"

class LoadShader
{
	unsigned int m_ID{};
	Loadimage m_image;
public:
	// ����ID

	// ��������ȡ��������ɫ��
	LoadShader(const char* vertexPath, const char* fragmentPath);
	~LoadShader();
	// ʹ��/�������
	void use();
	// uniform���ߺ���
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};

#endif
