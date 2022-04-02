#include "Loadimage.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Loadimage::Loadimage(const std::string& Path, const std::string& Path2) {

	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &m_Texture1);
	//������������,�����ڵڶ���������unsigned int������
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture1);
	//�󶨵�GL_TEXTURE_2D

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/*
	�����Ʒ�ʽ
	���Ʒ�ʽ	����
	GL_REPEAT			�������Ĭ����Ϊ���ظ�����ͼ��
	GL_MIRRORED_REPEAT	��GL_REPEATһ������ÿ���ظ�ͼƬ�Ǿ�����õġ�
	GL_CLAMP_TO_EDGE	��������ᱻԼ����0��1֮�䣬�����Ĳ��ֻ��ظ���������ı�Ե������һ�ֱ�Ե�������Ч����
	GL_CLAMP_TO_BORDER	����������Ϊ�û�ָ���ı�Ե��ɫ��
	�������
	GL_NEAREST	ѡ�����ĵ���ӽ�����������Ǹ�����
	GL_LINEAR	�����������긽�����������أ������һ����ֵ
	�༶��Զ���� ���˷�ʽ	����
	GL_NEAREST_MIPMAP_NEAREST	ʹ�����ڽ��Ķ༶��Զ������ƥ�����ش�С����ʹ���ڽ���ֵ�����������
	GL_LINEAR_MIPMAP_NEAREST	ʹ�����ڽ��Ķ༶��Զ�����𣬲�ʹ�����Բ�ֵ���в���
	GL_NEAREST_MIPMAP_LINEAR	��������ƥ�����ش�С�Ķ༶��Զ����֮��������Բ�ֵ��ʹ���ڽ���ֵ���в���
	GL_LINEAR_MIPMAP_LINEAR		�������ڽ��Ķ༶��Զ����֮��ʹ�����Բ�ֵ����ʹ�����Բ�ֵ���в���
	*/
	m_Data = stbi_load(Path.c_str(), &m_Width, &m_Height, &m_Nrchannel/*��ɫͨ���ĸ���*/, 0);
	if (!m_Data) {
		std::cout << "Failed to load texture" << std::endl;
	}else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		//����Ŀ��,���༶��Զ������,�����ʽ,���,�߶�,0����ʷ���������⣩,��ʽ,��������,ͼ������
		glGenerateMipmap(GL_TEXTURE_2D);
		//Ϊ��ǰ�󶨵������Զ�����������Ҫ�Ķ༶��Զ����
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

	m_Data = stbi_load(Path2.c_str(), &m_Width, &m_Height, &m_Nrchannel/*��ɫͨ���ĸ���*/, 0);
	if (!m_Data) {
		std::cout << "Failed to load texture" << std::endl;
	}else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
		//����Ŀ��,���༶��Զ������,�����ʽ,���,�߶�,0����ʷ���������⣩,��ʽ,��������,ͼ������
		glGenerateMipmap(GL_TEXTURE_2D);
		//Ϊ��ǰ�󶨵������Զ�����������Ҫ�Ķ༶��Զ����
	}
	stbi_image_free(m_Data);
}