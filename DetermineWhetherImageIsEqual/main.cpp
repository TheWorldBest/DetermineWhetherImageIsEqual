#include "datamineWhetherImageIsEqual.h"
#include <string>

using namespace std;

int main()
{
	string pathGallery = "F:\\接收\\zww\\call20180129.rar等2个文件\\call20180129\\posRaw";  // full图像和gt文件路径，包含data.txt文件，记录所有图像名
	string pathProble = "D:\\Database\\Yaw_smoke_phone\\phone\\train\\full\\pos";  // 分类为test的ROI图像路径
	string pathSame = "F:\\接收\\zww\\call20180129.rar等2个文件\\call20180129\\delete";  // 和pathProble一样，归为测试集
	string pathDiff = "F:\\接收\\zww\\call20180129.rar等2个文件\\call20180129\\pos";  //和pathProble不同，归为训练集
	
	ImgSameOrDiff imgSameDiff(pathGallery, pathProble, pathSame, pathDiff);
	//// 通过文件名判断proble文件是否源自gallery文件，proble文件名比gallery文件名多了“_****”，如：“134_0.jpg”源自文件“134.jpg”
	//imgSameDiff.imgRoIFromFileName();  

	//  通过文件名判断gallery中是否存在和proble文件同名的文件
	imgSameDiff.imgIsSameByName();
	return 0;
}