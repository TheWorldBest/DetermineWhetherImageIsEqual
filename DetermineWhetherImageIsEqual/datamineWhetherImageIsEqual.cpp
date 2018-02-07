#include "datamineWhetherImageIsEqual.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
using namespace cv;
// 构造函数
ImgSameOrDiff::ImgSameOrDiff(std::string pathGallery1, std::string pathProble1, std::string pathSame1, std::string pathDiff1, string imgFormat1, std::string pathMix1)
{
	pathGallery = pathGallery1;
	pathProble = pathProble1;
	pathSame = pathSame1;
	pathDiff = pathDiff1;
	pathMix = pathMix1;
}

// 通过图像像素差判断两图像是否相同，pathProble下的图像为截取到的ROI（此代码未写完）
void ImgSameOrDiff::imgRoIFromPixel()
{
	ifstream finG(pathGallery + "/data.txt"); 
	ifstream finP(pathProble + "/data.txt");
	vector<Mat> imgMatP;
	if (!finG.is_open())
	{
		cout << "fail to open file: " + pathGallery + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	if (!finP.is_open())
	{
		cout << "fail to open file: " + pathProble + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	while (finG.eof())
	{
		string line;
		getline(finP, line);
		Mat img = imread(pathGallery + "/" + line);
	}

}

//  通过文件名判断proble文件是否源自gallery文件，proble文件名比gallery文件名多了“_****”，如：“134_0.jpg”源自文件“134.jpg”
void ImgSameOrDiff::imgRoIFromFileName()
{
	ifstream finG(pathGallery + "/data.txt");
	ifstream finP(pathProble + "/data.txt");
	vector<string> nameMatP;
	if (!finG.is_open())
	{
		cout << "fail to open file: " + pathGallery + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	if (!finP.is_open())
	{
		cout << "fail to open file: " + pathProble + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	//读取Porble文件名到nameMatP中
	while (!finP.eof())
	{
		string line;
		getline(finP, line);
		if (line.empty())
		{
			continue;
		}
		nameMatP.push_back(line);
	}
	finP.close();
	//gallery中的文件逐一和proble文件进行对比，将gallery中所以的proble源文件拷贝到路径pathSame中，非源文件拷贝到pathDiff中
	while (!finG.eof())
	{
		bool isSame = false;  // 判断gallery当前文件是否为probe的源文件
		string line;
		getline(finG, line);
		if (line.empty())
		{
			continue;
		}
		
		//定位最后一个“."位置，以剔除文件后缀
		int nG = line.rfind('.');
		string nameG = line.substr(0, nG);
		for (int i = 0; i < nameMatP.size(); i++)
		{
			//定位最后一个“_"位置
			int nP = nameMatP[i].rfind('_');
			string nameP = nameMatP[i].substr(0, nP);
			if (!strcmp(nameG.c_str(), nameP.c_str()))
			{
				isSame = true;
				break;
			}
		}

		if (isSame)
		{
			// 拷贝图像和对应的gt文件
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathSame + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathSame + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
		else
		{
			// 拷贝图像和对应的gt文件
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathDiff + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathDiff + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
	}
	finG.close();
}

////  通过文件名判断gallery中是否存在和proble文件同名的文件
void ImgSameOrDiff::imgIsSameByName()
{
	ifstream finG(pathGallery + "/data.txt");
	ifstream finP(pathProble + "/data.txt");
	vector<string> nameMatP;
	if (!finG.is_open())
	{
		cout << "fail to open file: " + pathGallery + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	if (!finP.is_open())
	{
		cout << "fail to open file: " + pathProble + "/data.txt" << endl;
		system("pause");
		exit(0);
	}
	//读取Porble文件名到nameMatP中
	while (!finP.eof())
	{
		string line;
		getline(finP, line);
		if (line.empty())
		{
			continue;
		}
		nameMatP.push_back(line);
	}
	finP.close();
	//gallery中的文件逐一和proble文件进行对比，将gallery中同名的proble源文件拷贝到路径pathSame中，其他文件拷贝到pathDiff中
	while (!finG.eof())
	{
		bool isSame = false;  // 判断gallery当前文件是否为probe的源文件
		string line;
		getline(finG, line);
		if (line.empty())
		{
			continue;
		}

		//定位最后一个“."位置，以剔除文件后缀
		int nG = line.rfind('.');
		string nameG = line.substr(0, nG);
		for (int i = 0; i < nameMatP.size(); i++)
		{
			//定位最后一个“."位置
			int nP = nameMatP[i].rfind('.');
			string nameP = nameMatP[i].substr(0, nP);
			if (!strcmp(nameG.c_str(), nameP.c_str()))
			{
				isSame = true;
				break;
			}
		}

		if (isSame)
		{
			// 拷贝图像和对应的gt文件
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathSame + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathSame + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
		else
		{
			// 拷贝图像和对应的gt文件
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathDiff + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathDiff + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
	}
	finG.close();
}

//string转换车wstring  
std::wstring  StringToWString(const std::string& s)
{
	std::wstring wszStr;

	int nLength = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, NULL);
	wszStr.resize(nLength);
	LPWSTR lpwszStr = new wchar_t[nLength];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, lpwszStr, nLength);
	wszStr = lpwszStr;
	delete[] lpwszStr;
	return wszStr;
}