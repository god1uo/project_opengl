
#include <string>

class Loadimage
{
	int m_Width{};
	int m_Height{};
	int m_Nrchannel{};
	unsigned char* m_Data{ nullptr };
	unsigned int m_Texture1{};
	unsigned int m_Texture2{};
public:
	Loadimage(const std::string&, const std::string&);
};

