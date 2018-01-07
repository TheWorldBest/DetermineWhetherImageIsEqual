#include "datamineWhetherImageIsEqual.h"
#include <string>

using namespace std;

int main()
{
	string pathGallery = "F:\\Ω” ’\\zww\\≥È—Ã\\label";
	string pathProble = "D:\\Database\\Yaw_smoke_phone\\smoke\\test\\pos";
	string pathSame = "D:\\Database\\Yaw_smoke_phone\\smoke\\test\\full";
	string pathDiff = "D:\\Database\\Yaw_smoke_phone\\smoke\\train\\full";
	
	ImgSameOrDiff imgSameDiff(pathGallery, pathProble, pathSame, pathDiff);
	imgSameDiff.imgRoIFromFileName();
	return 0;
}