#include "Triangle.h"
Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle::~Triangle()
{}

bool Triangle::IsINSHAPE(Point test) {

	float area_T, area1, area2, area3,sum_area;
	area_T = tri_area(Corner1, Corner2, Corner3);
	area1= tri_area(Corner1, Corner2, test);
	area2 = tri_area(Corner1, Corner3, test);
	area3 = tri_area(Corner3, Corner2, test);
	sum_area = area1 + area2 + area3;

	if ( area_T==sum_area ) {

		return true;
	}
	else
		return false;
}


void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pUI->DrawTri(Corner1, Corner2,Corner3, ShpGfxInfo);
}
string Triangle::save(ofstream& savefile, string filename, string fcl, string drc, string pnw) {
	if (ShpGfxInfo.isFilled = true) {
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = colortostring(ShpGfxInfo.FillClr);
		string info = "Triangle " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Corner3.x) + " " + to_string(Corner3.y) + " " + x + " " + y;
		return info;
	}
	else

	{
		string x = colortostring(ShpGfxInfo.DrawClr);
		string y = "NO_FILL";
		string info = "Triangle " + to_string(Corner1.x) + " " + to_string(Corner1.y) + " " + to_string(Corner2.x) + " " + to_string(Corner2.y) + " " + to_string(Corner3.x) + " " + to_string(Corner3.y) + " " + x + " " + y;
		return info;
	}
}
