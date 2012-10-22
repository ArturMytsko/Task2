/**
 * @file   Functions.h
 * @brief  Implement function to solve the task(I/O, sort...)
 * @author Arthur Mytsko
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <memory.h>
#include "Functions.h"

UI InputTriangleCount()
{	
	char cBuffer[100];
	char cTempBuffer[10];
	UCH cInputCount;
	UI uiTriangleCount = 0;


	printf("Enter a number of triangles(1 - 100): ");
	while(true)
	{
		gets_s(cBuffer);
		cInputCount = sscanf_s(cBuffer, "%d%s", &uiTriangleCount, cTempBuffer);
		if ( (cInputCount != 1) || (uiTriangleCount < 1) || 
			 (uiTriangleCount > 100))
		{
			printf("Wrong number.. try again\n");
			continue;
		}
		break;
	}
	return uiTriangleCount;
}

void FillData(Triangle *pTriangle,  UI uiCount)
{
	char cBuffer[100];
	char cTempBuffer[50];
	UI uiTriangleNumber = 1; // current number of triangle
	UCH cInputCount = 0;

	system("cls");
	printf("Enter coordinates in format: x1 y1 x2 y2 x3 y3\n");
	_getch();
	while(uiTriangleNumber <= uiCount)
	{
		system("cls");
		printf("Triangle %d:  ", uiTriangleNumber);
		gets_s(cBuffer);

		//read inputing coordinates
		cInputCount = sscanf_s(cBuffer, "%d %d %d %d %d %d %s", &pTriangle->Point[0].x, 
							&pTriangle->Point[0].y, &pTriangle->Point[1].x, 
							&pTriangle->Point[1].y, &pTriangle->Point[2].x,
							&pTriangle->Point[2].y, cTempBuffer);
		if(cInputCount == 6)
		{
			if(SetPerimeter(pTriangle) )
			{
				uiTriangleNumber++;
				pTriangle += 1;
				continue;
			}
		}

		printf("Wrong input data.. try again");
		_getch();
		
	}

}

bool SetPerimeter(Triangle *pTriangle)
{
	int x1 = pTriangle->Point[0].x;
	int x2 = pTriangle->Point[1].x;
	int x3 = pTriangle->Point[2].x;
	int y1 = pTriangle->Point[0].y;
	int y2 = pTriangle->Point[1].y;
	int y3 = pTriangle->Point[2].y;

	float fSide1 = sqrt((float)( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) ) );
	float fSide2 = sqrt((float)( (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) ) );
	float fSide3 = sqrt((float)( (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) ) );

	if(fSide1 && fSide2 && fSide3 && (fSide1 < fSide2 + fSide3) &&
	  (fSide2 < fSide1 + fSide3)  && (fSide3 < fSide1 + fSide2) )
	{
		pTriangle->fPerimeter = fSide1 + fSide2 + fSide3;
		return true;
	}
	else
		return false;
}

void SortData(Triangle *pTriangle, UI uiCount)
{
	UCH ucSize = sizeof(Triangle);
	Triangle *pTmpTriangle = (Triangle*)malloc(ucSize);
	for(int i = 0; i < uiCount - 1; i++)
	{
		for(int j = 0; j < uiCount - i; j++)
		{
			if( (pTriangle + j)->fPerimeter < (pTriangle + j + 1)->fPerimeter)
			{
				memcpy(pTmpTriangle, pTriangle + j, ucSize);
				memcpy(pTriangle + j, pTriangle + j + 1, ucSize);
				memcpy(pTriangle + j + 1, pTmpTriangle, ucSize);
			}
		}
	}
}

void PrintTable(Triangle *pTriangle, UI uiCount)
{
	system("cls");
	printf(" #   ( x1, y1) ( x2, y2) ( x3, y3)   Perimeter\n");
	for(int i = 0; i < uiCount; i++)
	{
		printf("%2d.  (%3d,%3d) (%3d,%3d) (%3d,%3d) %8.3f\n", 
			i, (pTriangle + i)->Point[0].x, (pTriangle + i)->Point[0].y,
			(pTriangle + i)->Point[1].x, (pTriangle + i)->Point[1].y,
			(pTriangle + i)->Point[2].x, (pTriangle + i)->Point[2].y,
			(pTriangle + i)->fPerimeter);
	}
	printf("\n");
}

float GetMinP2xCount(Triangle *pTriangle, UI uiCount)
{
	float fMin2xPer = 2 * (pTriangle + uiCount - 1)->fPerimeter;

	UCH i = 0;	
	while( (pTriangle + i)->fPerimeter > fMin2xPer)
		i++;
	
	return (float)i / (float)uiCount * 100;
}

