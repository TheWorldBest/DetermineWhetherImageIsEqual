#include "datamineWhetherImageIsEqual.h"
#include <string>

using namespace std;

int main()
{
	string pathGallery = "F:\\����\\zww\\call20180129.rar��2���ļ�\\call20180129\\posRaw";  // fullͼ���gt�ļ�·��������data.txt�ļ�����¼����ͼ����
	string pathProble = "D:\\Database\\Yaw_smoke_phone\\phone\\train\\full\\pos";  // ����Ϊtest��ROIͼ��·��
	string pathSame = "F:\\����\\zww\\call20180129.rar��2���ļ�\\call20180129\\delete";  // ��pathProbleһ������Ϊ���Լ�
	string pathDiff = "F:\\����\\zww\\call20180129.rar��2���ļ�\\call20180129\\pos";  //��pathProble��ͬ����Ϊѵ����
	
	ImgSameOrDiff imgSameDiff(pathGallery, pathProble, pathSame, pathDiff);
	//// ͨ���ļ����ж�proble�ļ��Ƿ�Դ��gallery�ļ���proble�ļ�����gallery�ļ������ˡ�_****�����磺��134_0.jpg��Դ���ļ���134.jpg��
	//imgSameDiff.imgRoIFromFileName();  

	//  ͨ���ļ����ж�gallery���Ƿ���ں�proble�ļ�ͬ�����ļ�
	imgSameDiff.imgIsSameByName();
	return 0;
}