#ifndef _datamineWhetherImageIsEqual_h_
#define _datamineWhetherImageIsEqual_h_

#include <string>

////wstringת����string  
//std::string WChar2Ansi(LPCWSTR pwszSrc);
//stringת����wstring  
std::wstring  StringToWString(const std::string& s);

// ���ж�����ͼ���Ƿ���ͬ
class ImgSameOrDiff
{
public:
	ImgSameOrDiff(std::string pathGallery1, std::string pathProble1, std::string pathSame1, std::string pathDiff1, std::string imgFormat1=".jpg", std::string pathMix1 = "./");

	std::string pathGallery;  // ���Ƚϵ�ͼ��·��������·���µ�ͼ���к�pathProble����ͬ�ģ����Ƶ�pathSame·���£������Ƶ�pathDiff�¡�
	std::string pathProble;  // ̽��ͼ��·��
	std::string pathSame;  // pathGallery��pathProble����ͬ�ļ����·��
	std::string pathDiff;  // pathGallery��pathProble�в�ͬ�ļ����·��
	std::string pathMix;  // pathGallery��pathProble�в���ROI��ͬ�����ֲ�ͬͼ��Ĵ��·��

	//  ͨ��ͼ�����ز��ж���ͼ���Ƿ���ͬ.pathProble�µ�ͼ��Ϊ��ȡ����ROI
	void imgRoIFromPixel();
	//  ͨ���ļ����ж�proble�ļ��Ƿ�Դ��gallery�ļ���proble�ļ�����gallery�ļ������ˡ�_****�����磺��134_0.jpg��Դ���ļ���134.jpg��
	void imgRoIFromFileName();
};

#endif