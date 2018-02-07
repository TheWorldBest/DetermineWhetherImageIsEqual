#include "datamineWhetherImageIsEqual.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
using namespace cv;
// ���캯��
ImgSameOrDiff::ImgSameOrDiff(std::string pathGallery1, std::string pathProble1, std::string pathSame1, std::string pathDiff1, string imgFormat1, std::string pathMix1)
{
	pathGallery = pathGallery1;
	pathProble = pathProble1;
	pathSame = pathSame1;
	pathDiff = pathDiff1;
	pathMix = pathMix1;
}

// ͨ��ͼ�����ز��ж���ͼ���Ƿ���ͬ��pathProble�µ�ͼ��Ϊ��ȡ����ROI���˴���δд�꣩
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

//  ͨ���ļ����ж�proble�ļ��Ƿ�Դ��gallery�ļ���proble�ļ�����gallery�ļ������ˡ�_****�����磺��134_0.jpg��Դ���ļ���134.jpg��
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
	//��ȡPorble�ļ�����nameMatP��
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
	//gallery�е��ļ���һ��proble�ļ����жԱȣ���gallery�����Ե�probleԴ�ļ�������·��pathSame�У���Դ�ļ�������pathDiff��
	while (!finG.eof())
	{
		bool isSame = false;  // �ж�gallery��ǰ�ļ��Ƿ�Ϊprobe��Դ�ļ�
		string line;
		getline(finG, line);
		if (line.empty())
		{
			continue;
		}
		
		//��λ���һ����."λ�ã����޳��ļ���׺
		int nG = line.rfind('.');
		string nameG = line.substr(0, nG);
		for (int i = 0; i < nameMatP.size(); i++)
		{
			//��λ���һ����_"λ��
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
			// ����ͼ��Ͷ�Ӧ��gt�ļ�
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathSame + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathSame + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
		else
		{
			// ����ͼ��Ͷ�Ӧ��gt�ļ�
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

////  ͨ���ļ����ж�gallery���Ƿ���ں�proble�ļ�ͬ�����ļ�
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
	//��ȡPorble�ļ�����nameMatP��
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
	//gallery�е��ļ���һ��proble�ļ����жԱȣ���gallery��ͬ����probleԴ�ļ�������·��pathSame�У������ļ�������pathDiff��
	while (!finG.eof())
	{
		bool isSame = false;  // �ж�gallery��ǰ�ļ��Ƿ�Ϊprobe��Դ�ļ�
		string line;
		getline(finG, line);
		if (line.empty())
		{
			continue;
		}

		//��λ���һ����."λ�ã����޳��ļ���׺
		int nG = line.rfind('.');
		string nameG = line.substr(0, nG);
		for (int i = 0; i < nameMatP.size(); i++)
		{
			//��λ���һ����."λ��
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
			// ����ͼ��Ͷ�Ӧ��gt�ļ�
			wstring pathS = StringToWString(pathGallery + "/" + line);
			wstring pathD = StringToWString(pathSame + "/" + line);
			CopyFile(pathS.c_str(), pathD.c_str(), false);
			pathS = StringToWString(pathGallery + "/" + nameG + ".txt");
			pathD = StringToWString(pathSame + "/" + nameG + ".txt");
			CopyFile(pathS.c_str(), pathD.c_str(), false);
		}
		else
		{
			// ����ͼ��Ͷ�Ӧ��gt�ļ�
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

//stringת����wstring  
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