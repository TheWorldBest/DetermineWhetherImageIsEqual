#ifndef _datamineWhetherImageIsEqual_h_
#define _datamineWhetherImageIsEqual_h_

#include <string>

////wstring转换成string  
//std::string WChar2Ansi(LPCWSTR pwszSrc);
//string转换车wstring  
std::wstring  StringToWString(const std::string& s);

// 将判断两个图像是否相同
class ImgSameOrDiff
{
public:
	ImgSameOrDiff(std::string pathGallery1, std::string pathProble1, std::string pathSame1, std::string pathDiff1, std::string imgFormat1=".jpg", std::string pathMix1 = "./");

	std::string pathGallery;  // 待比较的图像集路径，若该路径下的图像有和pathProble中相同的，则复制到pathSame路径下，否则复制到pathDiff下。
	std::string pathProble;  // 探针图像路径
	std::string pathSame;  // pathGallery和pathProble中相同文件存放路径
	std::string pathDiff;  // pathGallery和pathProble中不同文件存放路径
	std::string pathMix;  // pathGallery和pathProble中部分ROI相同、部分不同图像的存放路径

	//  通过图像像素差判断两图像是否相同.pathProble下的图像为截取到的ROI
	void imgRoIFromPixel();
	//  通过文件名判断proble文件是否源自gallery文件，proble文件名比gallery文件名多了“_****”，如：“134_0.jpg”源自文件“134.jpg”
	void imgRoIFromFileName();
};

#endif