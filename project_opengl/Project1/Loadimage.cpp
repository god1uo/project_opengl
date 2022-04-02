#include "Loadimage.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Loadimage::Loadimage(const std::string& Path, const std::string& Path2) {

	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &m_Texture1);
	//生成纹理数量,储存在第二个参数的unsigned int数组中
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture1);
	//绑定到GL_TEXTURE_2D

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/*
	纹理环绕方式
	环绕方式	描述
	GL_REPEAT			对纹理的默认行为。重复纹理图像。
	GL_MIRRORED_REPEAT	和GL_REPEAT一样，但每次重复图片是镜像放置的。
	GL_CLAMP_TO_EDGE	纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
	GL_CLAMP_TO_BORDER	超出的坐标为用户指定的边缘颜色。
	纹理过滤
	GL_NEAREST	选择中心点最接近纹理坐标的那个像素
	GL_LINEAR	基于纹理坐标附近的纹理像素，计算出一个插值
	多级渐远纹理 过滤方式	描述
	GL_NEAREST_MIPMAP_NEAREST	使用最邻近的多级渐远纹理来匹配像素大小，并使用邻近插值进行纹理采样
	GL_LINEAR_MIPMAP_NEAREST	使用最邻近的多级渐远纹理级别，并使用线性插值进行采样
	GL_NEAREST_MIPMAP_LINEAR	在两个最匹配像素大小的多级渐远纹理之间进行线性插值，使用邻近插值进行采样
	GL_LINEAR_MIPMAP_LINEAR		在两个邻近的多级渐远纹理之间使用线性插值，并使用线性插值进行采样
	*/
	m_Data = stbi_load(Path.c_str(), &m_Width, &m_Height, &m_Nrchannel/*颜色通道的个数*/, 0);
	if (!m_Data) {
		std::cout << "Failed to load texture" << std::endl;
	}else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		//纹理目标,定多级渐远纹理级别,储存格式,宽度,高度,0（历史遗留的问题）,格式,数据类型,图像数据
		glGenerateMipmap(GL_TEXTURE_2D);
		//为当前绑定的纹理自动生成所有需要的多级渐远纹理
	}
	stbi_image_free(m_Data);


	glGenTextures(1, &m_Texture2);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_Texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	/*float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_Data = stbi_load(Path2.c_str(), &m_Width, &m_Height, &m_Nrchannel/*颜色通道的个数*/, 0);
	if (!m_Data) {
		std::cout << "Failed to load texture" << std::endl;
	}else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		//纹理目标,定多级渐远纹理级别,储存格式,宽度,高度,0（历史遗留的问题）,格式,数据类型,图像数据
		glGenerateMipmap(GL_TEXTURE_2D);
		//为当前绑定的纹理自动生成所有需要的多级渐远纹理
	}
	stbi_image_free(m_Data);
}