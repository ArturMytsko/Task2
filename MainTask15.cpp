/**
 * @file   MainTask15.cpp
 * @brief  Implement main function
 * @author Arthur Mytsko
 */
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include "Functions.h"


 /**
   * @brief      Main function
   * @return	 0
   */
int main(void)
{
	Triangle *TrianArray;
	UI uiCount;

	uiCount = InputTriangleCount() ;
	//create 'n' structures 'Triangle'
	TrianArray = (Triangle*)malloc(sizeof(Triangle) * uiCount);

	FillData(TrianArray, uiCount);

	SortData(TrianArray, uiCount);

	PrintTable(TrianArray, uiCount);

	printf("Percent of triangles with above that 2xMinP:%3.2f\%", 
			GetMinP2xCount(TrianArray, uiCount) );

	_getch();
	return 0;
}
